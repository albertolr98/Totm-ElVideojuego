#include "Mapa.h"
#include <fstream>
#include <sstream>
#include <string>


Mapa::Mapa(int N,int M) : N(N), M(M)
{
	//reservamos memoria para las casillas
	casillas = new Casilla*[N];
	for (int i = 0; i < N; i++) {
		casillas[i] = new Casilla[M];
	}
	//asignamos todas las casillas como libres salvo los bordes
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N-1 || j == 0 || j == M-1) { SetPared(i,j); }
			else { SetLibre(i,j); }
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
	
	casillas = new Casilla*[N];
	for (int i = 0; i < N; i++) {
		casillas[i] = new Casilla[M];
	}
	
	//Limpia el flujo de entrada
	infile.ignore();
		for (int i = 0; i < N; i++) {
			//lee una linea del fichero y pone las casillas en el estado que le corresponda
			std::getline(infile, buffer);
			for (int j = 0; j < N; j++) {
				
				if (buffer[2 * j] == 'L') {
					SetLibre(i, j);
				}
				else if(buffer[2 * j] == 'P'){
					SetPared(i, j);
				}
				else if (buffer[2 * j] == 'J') {
					SetJugador(i, j);
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
void Mapa::SetPared(int N, int M)
{
	if (!isPared(N,M)) {	//si la casilla no es pared

		freeCasilla(N,M);	//libera lo que sea 
		casillas[N][M].SetPared();		//asigna pared
		return;
	}

	//mensaje para depuracion
	//std::cout << "ya es pared" << std::endl;
}


//pone en libre la casilla
void Mapa::SetLibre(int N, int M)
{
	if (!isLibre(N,M)) {	//si la casilla no es libre

		freeCasilla(N,M);	//libera lo que sea
		casillas[N][M].SetLibre();		//asigna libre
		return;
	}

	//mensaje para depuracion
	//std::cout << "ya es libre" << std::endl;
}


//pone jugador en la casilla
void Mapa::SetJugador(int N, int M)
{
	if (!isJugador(N,M)) {	//si la casilla no es jugador

		freeCasilla(N,M);	//libera lo que sea
		casillas[N][M].SetJugador();//asigna jugador
		return;
	}

	//mensaje para depuracion
	//std::cout << "ya es jugador" << std::endl;
}

//libera la casilla
void Mapa::freeCasilla(int N, int M)
{
	casillas[N][M].freeCasilla();
}


//comprueba si es pared
bool Mapa::isPared(int N, int M) const
{
	if (casillas[N][M].isPared()) { return true; }
	return false;
}


//comprueba si es libre
bool Mapa::isLibre(int N, int M) const
{
	if (casillas[N][M].isLibre()) { return true; }
	return false;
}


//comprueba si es jugador
bool Mapa::isJugador(int N, int M) const
{
	if (casillas[N][M].isJugador()) { return true; }
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


//funcion que imprime el mapa en el flujo
std::ostream & Mapa::print(std::ostream & o) const
{
	o << "N " << N << std::endl << "M " << M << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isPared(i,j)) { o << "P"; }
			if (isLibre(i, j)) { o << "L"; }
			if (isJugador(i, j)) { o << "J"; }

			o << " ";
		}
		o << std::endl;
	}
	return o;
}
