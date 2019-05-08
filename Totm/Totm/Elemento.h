#pragma once

#include"Jugador.h"
#include<iostream>



class Elemento
{
private:
	int estado;// 0 es libre, 1 pared, 2 meta
	struct coordenadas_t coordenadas;

public:
	void setPared();
	void setLibre();
	bool isLibre();
	void asignarCoord(coordenadas_t pos);

};

