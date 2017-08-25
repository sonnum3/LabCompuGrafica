//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): González Colín Fernando    ******//
//************** Ejercicio práctica número: 2			******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//Aunque se trabaje en 2D siempre se trabaja con se trabajan las coordenadas sobre los ejes X Y Z
	
	glPointSize(10);
	//	glBegin(GL_POINTS);	//Donde empieza, y modo de dibujo: 
	//	GL_POINTS, GL_LINES (lineas por pares de puntos), GL_LINE_LOOP (une todos los puntos en un lazo), GL_TRIANGLES (triangulos por tercias de puntos)
	//	
	//Iniciales:
		//F:
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(-9.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(-9.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(-12.0, 12.0, -1.2);	//x0,y0,z0
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(-12.0, 8.0, -1.2);	//x0,y0,z0
	glVertex3f(-13.0, 8.0, -1.2);	//x0,y0,z0
	glVertex3f(-13.0, 13.0, -1.2);	//x0,y0,z0
	glEnd();	

	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 11.0, -1.2);	//x0,y0,z0
	glVertex3f(-10.0, 11.0, -1.2);	//x0,y0,z0
	glVertex3f(-10.0, 10.0, -1.2);	//x0,y0,z0
	glVertex3f(-12.0, 10.0, -1.2);	//x0,y0,z0
	glEnd();

		//G:
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-6.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(-2.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(-2.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(-5.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(-5.0, 9.0, -1.2);	//x0,y0,z0
	glVertex3f(-3.0, 9.0, -1.2);	//x0,y0,z0
	glVertex3f(-3.0, 10.0, -1.2);	//x0,y0,z0
	glVertex3f(-4.0, 10.0, -1.2);	//x0,y0,z0
	glVertex3f(-4.0, 11.0, -1.2);	//x0,y0,z0
	glVertex3f(-2.0, 11.0, -1.2);	//x0,y0,z0
	glVertex3f(-2.0, 8.0, -1.2);	//x0,y0,z0
	glVertex3f(-6.0, 8.0, -1.2);	//x0,y0,z0
	glEnd();	//Donde termina

		//C:
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);	
	glVertex3f(1.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(5.0, 13.0, -1.2);	//x0,y0,z0
	glVertex3f(5.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(2.0, 12.0, -1.2);	//x0,y0,z0
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(2.0, 12.0, -1.2);	//x0,y0,z0
	glVertex3f(2.0, 9.0, -1.2);	//x0,y0,z0
	glVertex3f(1.0, 8.0, -1.2);	//x0,y0,z0
	glVertex3f(1.0, 13.0, -1.2);	//x0,y0,z0
	glEnd();	//Donde termina

	glBegin(GL_POLYGON);
	glVertex3f(2.0, 9.0, -1.2);	//x0,y0,z0
	glVertex3f(5.0, 9.0, -1.2);	//x0,y0,z0
	glVertex3f(5.0, 8.0, -1.2);	//x0,y0,z0
	glVertex3f(1.0, 8.0, -1.2);	//x0,y0,z0
	glEnd();	//Donde termina
	//Estrella:
	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 0.0, -1.2);	//x0,y0,z0
	glVertex3f(1.47, -2.02, -1.2);	//x0,y0,z0
	glVertex3f(0.0, -7.0, -1.2);	//x0,y0,z0
	glVertex3f(-1.47, -2.02, -1.2);	//x0,y0,z0
	glEnd();	//Donde termina

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 1.0);
	glVertex3f(0.0, 0.0, -1.2);	//x0,y0,z0
	glVertex3f(2.37, 0.77, -1.2);	//x0,y0,z0
	glVertex3f(6.65, -2.16, -1.2);	//x0,y0,z0
	glVertex3f(1.47, -2.02, -1.2);	//x0,y0,z0
	glEnd();	//Donde termina

	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.6, 1.0);
	glVertex3f(0.0, 0.0, -1.2);	//x0,y0,z0
	glVertex3f(0.0, 2.5, -1.2);	//x0,y0,z0
	glVertex3f(4.11, 5.66, -1.2);	//x0,y0,z0
	glVertex3f(2.37, 0.77, -1.2);	//x0,y0,z0
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.4, 1.0);
	glVertex3f(0.0, 0.0, -1.2);	//x0,y0,z0
	glVertex3f(0.0, 2.5, -1.2);	//x0,y0,z0
	glVertex3f(-4.11, 5.66, -1.2);	//x0,y0,z0
	glVertex3f(-2.37, 0.77, -1.2);	//x0,y0,z0
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 1.0);
	glVertex3f(0.0, 0.0, -1.2);	//x0,y0,z0
	glVertex3f(-2.37, 0.77, -1.2);	//x0,y0,z0
	glVertex3f(-6.65, -2.16, -1.2);	//x0,y0,z0
	glVertex3f(-1.47, -2.02, -1.2);	//x0,y0,z0
	glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal para desarrollo en 2D
	glOrtho(-15,15,-15,15,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

