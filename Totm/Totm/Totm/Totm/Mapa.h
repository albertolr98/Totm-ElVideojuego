#pragma once
#include"Casilla.h"
#include<iostream>
class Mapa
{
 private:
	int N;
	int M;
	Casilla** casillas;
 public:
	Mapa(int N, int M);
	~Mapa();
	void SetPared(int N, int M);
	void SetLibre(int N, int M);
	void SetJugador(int N, int M);
	void freeCasilla(int N, int M);
	bool isPared(int N, int M) const;
	bool isLibre(int N, int M) const;
	bool isJugador(int N, int M) const;
	int getN() const;
	int getM() const;

	std::ostream& print(std::ostream& = std::cout) const;
};

