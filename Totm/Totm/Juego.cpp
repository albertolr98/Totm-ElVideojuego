#include"Mapa.h"
#include"glut.h"

int unit_test_crear_mapa() {
	Mapa mapita(5, 5);
	mapita.print();
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

	mapita.print();
	return 0;
}



//int main() {
//	
//	//if (unit_test_crear_mapa) { std::cout << "fallo en crear mapa" << std::endl; }
//	if (unit_test_asignar_casilla()) { std::cout << "fallo en asignar casilla" << std::endl; }
//
//	system("PAUSE");
//	return 0;
//}