#pragma once

#include"Jugador.h"
#include<iostream>

struct coordenadas_t {
	int x;
	int y;
};

class Casilla
{
private:
	int estado;// 0 es libre y 1 pared
	struct coordenadas_t coordenadas;

public:
	void SetPared();
	void SetLibre();
	bool isLibre();
};

