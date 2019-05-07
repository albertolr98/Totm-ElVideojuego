#include "Casilla.h"



void Casilla::SetPared()
{
	estado = 1;
}

void Casilla::SetLibre()
{
	estado = 0;
}


bool Casilla::isLibre()
{
	return !estado;
}


