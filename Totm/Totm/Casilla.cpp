#include "Elemento.h"



void Elemento::setPared()
{
	estado = 1;
}

void Elemento::setLibre()
{
	estado = 0;
}


bool Elemento::isLibre()
{
	return !estado;
}

void Elemento::asignarCoord(coordenadas_t pos)
{
	coordenadas = pos;
}


