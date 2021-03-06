#include "Mapa.h"
#include <fstream>
#include <sstream>
#include <string>


Mapa::Mapa(int N,int M) : N(N), M(M)
{
	//reservamos memoria para las casillas
	casillas = new Elemento*[N];
	for (int i = 0; i < N; i++) {
		casillas[i] = new Elemento[M];
	}
	//asignamos todas las casillas como libres salvo los bordes
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			coordenadas_t c(i, j);
			casillas[i][j].asignarCoord(c);

			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {  setPared(i, j);  }
			else {  setLibre(i,j); }
		}
	}
}

Mapa::Mapa(std::string filename)
{
	std::ifstream infile;
	std::string buffer;
	
	infile.open(filename);

	if (!infile) {
		std::cout << "No se ha encontrado el archivo" << std::endl;
		return;
	}
	infile >> buffer >> N;
	infile >> buffer >> M;
	
	casillas = new Elemento *[N];
	for (int i = 0; i < N; i++) {
		casillas[i] = new Elemento[M];
	}
	
	//Limpia el flujo de entrada
	infile.ignore();
		for (int i = 0; i < N; i++) {
			//lee una linea del fichero y pone las casillas en el estado que le corresponda
			std::getline(infile, buffer);
			for (int j = 0; j < M; j++) {
				coordenadas_t c(i, j);
				casillas[i][j].asignarCoord(c);

				if (buffer[2 * j] == 'L') {
					setLibre(i, j);
				}
				else if(buffer[2 * j] == 'P'){
					setPared(i, j);
				}
				else if (buffer[2 * j] == 'J') {
					setLibre(i, j);
					jugador.setPos(i, j);
				}
				
			}	
		}
	

	//cierra el fichero
	infile.close();
}


Mapa::~Mapa()
{
	//liberamos el doble puntero
	for (int i = 0; i < N; i++) {
		delete[] casillas[i];
	}
	delete[] casillas;

	//ponemos a cero las variables
	N = 0;
	M = 0;
}



//pone en pared la casilla
void Mapa::setPared(int N, int M)
{
	if (isLibre(N,M)) {	//si la casilla no es pared

		
		casillas[N][M].setPared();		//asigna pared
		return;
	}

	//mensaje para depuracion
	//std::cout << "ya es pared" << std::endl;
}


//pone en libre la casilla
void Mapa::setLibre(int N, int M)
{
	if (!isLibre(N,M)) {	//si la casilla no es libre

		casillas[N][M].setLibre();		//asigna libre
		return;
	}

	//mensaje para depuracion
	//std::cout << "ya es libre" << std::endl;
}



//comprueba si es libre
bool Mapa::isLibre(int N, int M) const
{
	if (casillas[N][M].isLibre()) { return true; }
	return false;
}


//comprueba si la casilla es jugador
bool Mapa::isJugador(int N, int M)
{
	coordenadas_t aux = jugador.getPos();
	if (aux.x==N&&aux.y==M) { return true; }
	return false;
}




int Mapa::getN() const
{
	return N;
}

int Mapa::getM() const
{
	return M;
}


//funci�n que se encarga de mover el jugador si esta libre la casilla
void Mapa::MoverJugador()
{
	coordenadas_t aux = jugador.getPos();
	
	if (jugador.getDir() == ARRIBA) {
		if (isLibre(aux.x-1, aux.y))
			jugador.Mover();
		else {
			jugador.para(true);
		}
	}
	else if (jugador.getDir() == ABAJO) {
		if (isLibre(aux.x+1, aux.y))
			jugador.Mover();
		else {
			jugador.para(true);
		}
	}
	else if (jugador.getDir() == DERECHA) {
		if (isLibre(aux.x, aux.y+1))
			jugador.Mover();
		else {
			jugador.para(true);
		}
	}
	else if (jugador.getDir() == IZQUIERDA) {
		if (isLibre(aux.x , aux.y-1))
			jugador.Mover();
		else {
			jugador.para(true);
		}
	}
}

coordenadas_t Mapa::getPosJugador()
{
	return jugador.getPos();
}


//si el jugador ha tocado pared recibe la direccion
void Mapa::dirigeJugador(direccion_t direccion)
{
	if (jugador.isParado()) { jugador.setDir(direccion); jugador.para(false); }
}


//funcion que imprime el mapa en el flujo
std::ostream & Mapa::print(std::ostream & o) const
{
	o << "N " << N << std::endl << "M " << M << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!isLibre(i,j)) { o << "P"; }
			if (isLibre(i, j)) { o << "L"; }
			
			o << " ";
		}
		o << std::endl;
	}
	return o;
}
