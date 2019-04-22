#include"Mapa.h"


int unit_test_crear_mapa() {
	int N = 40, M = 50;
	Mapa mapita(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1) { if (!mapita.isPared(i, j)) { return 1; } }
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
	if (!mapita.isPared(0, 0)) { return 1; }

	mapita.SetLibre(0, 0);
	if (!mapita.isLibre(0, 0)) { return 1; }

	mapita.SetLibre(0, 0);
	if (!mapita.isLibre(0, 0)) { return 1; }

	mapita.SetJugador(3, 3);
	if (!mapita.isJugador(3, 3)) { return 1; }

	return 0;
}



int maint() {
	
	if (unit_test_crear_mapa()) { std::cout << "fallo al crear mapa" << std::endl; }
	if (unit_test_asignar_casilla()) { std::cout << "fallo en asignar casilla" << std::endl; }

	system("PAUSE");
	return 0;
}