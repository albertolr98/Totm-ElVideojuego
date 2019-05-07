#include"Mapa.h"
#include<fstream>


int unit_test_crear_mapa() {
	int N = 40, M = 50;
	Mapa mapita(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) { if (mapita.isLibre(i, j)) { return 1; } }
			else {
				if (!mapita.isLibre(i, j)) { return 1; }
			}
		}
	}
	return 0;
}
int unit_test_asignar_casilla() {
	Mapa mapita(20, 20);

	mapita.SetPared(0, 0);
	if (mapita.isLibre(0, 0)) { return 1; }

	mapita.SetLibre(0, 0);
	if (!mapita.isLibre(0, 0)) { return 1; }

	mapita.SetLibre(0, 0);
	if (!mapita.isLibre(0, 0)) { return 1; }

	

	return 0;
}
int unit_test_escribir_fichero() {
	std::ofstream fichero("mifichero.txt");
	if (!fichero) { return 1; }
	Mapa mapa(30, 30);
	mapa.print(fichero);
	fichero.close();
	return 0;
}
int unit_test_leer_fichero() {
	std::ofstream fichero("mifichero.txt");
	if (!fichero) { return 1; }
	Mapa mapa1(20, 20);
	mapa1.print(fichero);
	fichero.close();
	//comprueba si al cargar el mapa desde el fichero coincide con el anterior
	Mapa mapa2("mifichero.txt");

	//descomentar linea para forzar el fallo 
	//mapa2.SetJugador(2, 2);
	for (int i = 0; i < mapa2.getN(); i++) {
		for (int j = 0; j < mapa2.getM(); j++) {
			if (mapa1.isLibre(i, j)) {
				if (!mapa2.isLibre(i, j)) { return 1;}
			}
		}
	}
	return 0;
}

int maint() {
	
	/*if (unit_test_crear_mapa()) { std::cout << "fallo al crear mapa" << std::endl; }
	if (unit_test_asignar_casilla()) { std::cout << "fallo en asignar casilla" << std::endl; }
	if(unit_test_escribir_fichero()){ std::cout << "fallo al intentar escribir fichero" << std::endl; }
	if(unit_test_leer_fichero()){ std::cout << "fallo al intentar leer fichero" << std::endl; }*/
	
	system("PAUSE");
	return 0;
}