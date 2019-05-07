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
	int getN() const;
	int getM() const;

	std::ostream& print(std::ostream& = std::cout) const;
};

