#include "Casilla.h"

Casilla::Casilla() : pared(NULL), libre(NULL), jugador(NULL){}

Casilla::~Casilla()
{
	freeCasilla();
}

void Casilla::SetPared()
{
	freeCasilla();	//libera la casilla
	if (!pared) { pared = new Pared; }
}

void Casilla::SetLibre()
{
	freeCasilla();						//libera la casilla
	if (!libre) { libre = new Libre; }
}

void Casilla::SetJugador()
{
	freeCasilla();
	if (!jugador) { jugador = new Jugador; }
}

void Casilla::freeCasilla()
{
	//libera la casilla
	pared = NULL;
	libre = NULL;
	jugador = NULL;
}

bool Casilla::isPared()
{
	if (pared) { return true; }
	return false;
}

bool Casilla::isLibre()
{
	if (libre) { return true; }
	return false;
}

bool Casilla::isJugador()
{
	if (jugador) { return true; }
	return false;
}
