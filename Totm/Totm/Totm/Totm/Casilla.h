#pragma once
#include"Pared.h"
#include"Libre.h"
#include"Jugador.h"
#include<iostream>

class Casilla
{
	Pared* pared;
	Libre* libre;
	Jugador* jugador;

public:
	Casilla();
	~Casilla();

	void SetPared();
	void SetLibre();
	void SetJugador();
	void freeCasilla();
	bool isPared();
	bool isLibre();
	bool isJugador();
};

