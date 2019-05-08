#pragma once

enum direccion_t { ARRIBA = 0, ABAJO, IZQUIERDA, DERECHA };
struct coordenadas_t {
	int x;
	int y;

	coordenadas_t(int i = 0, int j = 0) :x(i), y(j) { ; }
};


class Jugador
{
	enum direccion_t direccion;
	coordenadas_t posicion;
	bool parado;
	
public:
	

	void Mover();
	coordenadas_t getPos();
	void setDir(direccion_t dir);
	bool isParado();
	void para(bool);
	void setPos(int, int);
	direccion_t getDir();
};

