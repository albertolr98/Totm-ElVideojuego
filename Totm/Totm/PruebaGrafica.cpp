#include"Mapa.h"

//es importante que glut.h vaya la ultima
#include "glut.h"



#define ANCHO_BLOQUE 10
double acercar = 100;
Mapa mapa("mifichero.txt");
static double x = (mapa.getM()*ANCHO_BLOQUE) / 2;
static double y = (-mapa.getN()*ANCHO_BLOQUE) / 2;


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


	gluLookAt(x, y, 300,
		x, y, 0.0, 
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	//aqui es donde hay que poner el código de dibujo

	
	
	//dibujamos el mapa
	
	glBegin(GL_QUADS);

	for (int i = 0; i < mapa.getN(); i++) {
		for (int j = 0; j < mapa.getM(); j++) {
			if (mapa.isLibre(i, j)) {
				glColor3ub(255, 255, 255);
				glVertex2f(static_cast<float>(j*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
			}
			else if (mapa.isPared(i, j)) {
				glColor3ub(150, 0, 255);
				glVertex2f(static_cast<float>(j*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i + 1) * ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j + 1)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
				glVertex2f(static_cast<float>((j)*ANCHO_BLOQUE), static_cast<float>(-(i)* ANCHO_BLOQUE));
			}
			else if (mapa.isJugador(i, j)) {
				glColor3ub(0, 255, 255);
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
	case 'a':
		x--;
		break;
	case 's':
		y--;
		break;
	case 'd':
		x++;
		break;
	case 'w':
		y++;
		break;
	}
	glutPostRedisplay();
}
void OnSpecialKeyboardDown(int key, int x_t, int y_t) {
	
	switch (key) {
	case GLUT_KEY_UP:
		y++;
		break;
	case GLUT_KEY_DOWN:
		y--;
		break;
	case GLUT_KEY_RIGHT:
		x++;
		break;
	case GLUT_KEY_LEFT:
		x--;
		break;
	}
	glutPostRedisplay();
}

void OnTimer(int value)
{
	
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
