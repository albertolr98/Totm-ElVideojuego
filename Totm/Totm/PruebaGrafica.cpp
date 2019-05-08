#include"Mapa.h"
#include<string>

//es importante que glut.h vaya la ultima
#include "glut.h"



#define ANCHO_BLOQUE 10
#define NUM_NIVELES 3

Mapa* niveles[NUM_NIVELES];
coordenadas_t ojo[NUM_NIVELES];
int nivelactual = 0;
const std::string nombreniveles[] = { "nivel1.txt","nivel2.txt","mifichero2.txt" };




//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x_t, int y_t);




int main(int argc, char* argv[])
{
	
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(960, 720);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Totm");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 1000);
	
	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutSpecialFunc(OnSpecialKeyboardDown);
	glutKeyboardFunc(OnKeyboardDown);


	//inicializacion de los niveles
	
	for (int i = 0; i < NUM_NIVELES; i++) {
		niveles[i] = new Mapa(nombreniveles[i]);
		ojo[i] = niveles[i]->getPosJugador();
	}

	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	gluLookAt(ojo[nivelactual].y*ANCHO_BLOQUE, -ojo[nivelactual].x*ANCHO_BLOQUE, 300,
		ojo[nivelactual].y*ANCHO_BLOQUE, -ojo[nivelactual].x*ANCHO_BLOQUE, 0.0,
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	//aqui es donde hay que poner el código de dibujo

	
	
	//dibujamos el mapa
	
	glBegin(GL_QUADS);

	for (int i = 0; i < niveles[nivelactual]->getN(); i++) {
		for (int j = 0; j < niveles[nivelactual]->getM(); j++) {
			if (niveles[nivelactual]->isLibre(i, j)) {
				glColor3ub(255, 255, 255);
				if (niveles[nivelactual]->isJugador(i, j)){
					glColor3ub(0, 255, 255);
				}

				glVertex2f(static_cast<float>(j*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
			}
			else if (!niveles[nivelactual]->isLibre(i, j)) {
				glColor3ub(150, 0, 255);
				
				glVertex2f(static_cast<float>(j*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
			}
			
		}
	}
	glEnd();

	
	

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	switch (key) {
	case '1':
		nivelactual = 0;
		
		break;
	case '2':
		nivelactual = 1;
		break;
	case '3':
		nivelactual = 2;
		break;
	case 'R':
		delete niveles[nivelactual];
		niveles[nivelactual]= new Mapa(nombreniveles[nivelactual]);
		
		break;
	}
	glutPostRedisplay();
}
void OnSpecialKeyboardDown(int key, int x_t, int y_t) {
	
	switch (key) {
	case GLUT_KEY_RIGHT:
		niveles[nivelactual]->dirigeJugador(DERECHA);
		
		break;
	case GLUT_KEY_LEFT:
		niveles[nivelactual]->dirigeJugador(IZQUIERDA);
		
		break;
	case GLUT_KEY_DOWN:
		niveles[nivelactual]->dirigeJugador(ABAJO);
		
		break;
	case GLUT_KEY_UP:
		niveles[nivelactual]->dirigeJugador(ARRIBA);
		
		break;
	}
	glutPostRedisplay();
}

void OnTimer(int value)
{
	niveles[nivelactual]->MoverJugador();
	ojo[nivelactual] = niveles[nivelactual]->getPosJugador();
	glutTimerFunc(15, OnTimer, 0);
	glutPostRedisplay();
}
