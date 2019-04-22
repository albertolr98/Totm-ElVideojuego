#pragma once

enum direccion_t { ARRIBA = 0, ABAJO, IZQUIERDA, DERECHA };

class Jugador
{
	enum direccion_t direccion;
public:
	Jugador();
	~Jugador();
};

