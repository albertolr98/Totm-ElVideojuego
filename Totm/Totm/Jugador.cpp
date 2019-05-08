#include "Jugador.h"





coordenadas_t Jugador::getPos()
{
	return posicion;
}

void Jugador::setDir(direccion_t dir)
{
	direccion = dir;
}

bool Jugador::isParado()
{

	return parado;
}

void Jugador::para(bool p)
{
	parado =p;
}

void Jugador::setPos(int i, int j)
{
	coordenadas_t aux(i, j);
	posicion = aux;
}

direccion_t Jugador::getDir()
{
	return direccion;
}

void Jugador::Mover()
{
	if (direccion == ARRIBA) {				//ARRIBA = 0
		posicion.y++;
	}
	else if (direccion == ABAJO) {			//ABAJO = 1
		posicion.y--;
	}
	else if (direccion == IZQUIERDA) {		//IZQUIERDA = 2
		posicion.x--;
	}
	else if (direccion == DERECHA) {		//DERECHA = 3
		posicion.x++;
	}
}