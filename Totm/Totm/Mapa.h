#pragma once
#include"Casilla.h"
#include<iostream>
class Mapa
{
 private:
	int N;
	int M;
	Casilla** casillas; 
	Jugador jugador;
 public:
	Mapa(int N, int M);
	Mapa(std::string);
	~Mapa();
	void SetPared(int N, int M);
	void SetLibre(int N, int M);
	bool isLibre(int N, int M) const;
	bool isJugador(int N, int M);
	int getN() const;
	int getM() const;
	void MoverJugador();
	coordenadas_t getPosJugador();
	void dirigeJugador(direccion_t direccion);

	std::ostream& print(std::ostream& = std::cout) const;
};

