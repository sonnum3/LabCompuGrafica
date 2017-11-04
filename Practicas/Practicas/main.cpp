//Semestre 2018 - 1
  //************************************************************//
  //************************************************************//
//************** Alumno (s): González Colín Fernando	  ****//
//*************	 Ejercicio  práctica 11					  ****//
  //*************											******//
  //************************************************************//
/*
#######IMPORTANTE: Reproducir con n o N
#######LA SECUENCIA SE CARGA DESDE EL ARCHIVO: reg.txt

 +Teclas para mover la mano/brazo
 +
 +R,r	-> Hombro
 +F,f	-> Codo
 +T,t -> Muñeca
 +G,g -> Pulgar1
 +Y,y	-> Pulgar2
 +H,h	-> Indice1
 +U,u	-> Indice2
 +J,j	-> Indice3
 +I,i	-> Medio1
 +K.k	-> Medio2
 +O,o	-> Medio3
 +L,l	-> Anular1
 +P,p	-> Anular2
 +Z,z	-> Anular3
 +X,x	-> Meñique1
 +C,c	-> Meñique2
 +V,v	-> Meñique3
 
 Mayusculas movimiento positivo
 Minusculas movimiento negativo
*/
#include "Main.h"

#define MAX_FRAMES 50
int i_max_steps = 750;
int i_curr_steps = 0;
FILE *frms = fopen("reg.txt", "r");

typedef struct _frame
{
	float transZ, inctransZ;
	float transX, inctransX;
	float transY, inctransY;
	float angleX, incangleX;
	float angleY, incangleY;
	float angH, incangH;
	float angC, incangC;
	float angM, incangM;
	float angP, incangP;
	float angP2, incangP2;
	float angI, incangI;
	float angI2, incangI2;
	float angI3, incangI3;
	float angMe, incangMe;
	float angMe2, incangMe2;
	float angMe3, incangMe3;
	float angA, incangA;
	float angA2, incangA2;
	float angA3, incangA3;
	float angCh, incangCh;
	float angCh2, incangCh2;
	float angCh3, incangCh3;
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];


 float transZ = 0.0f;
 float transX = 0.0f;
 float transY = 0.0f;
 float angleX = 0.0f;
 float angleY = 0.0f;
 float angH = 0.0f;
 float angC = 0.0f;
 float angM = 0.0f;
 float angP = 0.0f;
 float angP2 = 0.0f;
 float angI = 0.0f;
 float angI2 = 0.0f;
 float angI3 = 0.0f;
 float angMe = 0.0f;
 float angMe2 = 0.0f;
 float angMe3 = 0.0f;
 float angA = 0.0f;
 float angA2 = 0.0f;
 float angA3 = 0.0f;
 float angCh = 0.0f;
 float angCh2 = 0.0f;
 float angCh3 = 0.0f;
 int screenW = 0.0;
 int screenH = 0.0;
  
  
 GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
 GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

 void saveFrame(void)
 {
	printf("frameindex %d\n", FrameIndex);
	KeyFrame[FrameIndex].angA = angA;
	KeyFrame[FrameIndex].angA2 = angA2;
	KeyFrame[FrameIndex].angA3 = angA3;
	KeyFrame[FrameIndex].angC = angC;
	KeyFrame[FrameIndex].angCh = angCh;
	KeyFrame[FrameIndex].angCh2 = angCh2;
	KeyFrame[FrameIndex].angCh3 = angCh3;
	KeyFrame[FrameIndex].angH = angH;
	KeyFrame[FrameIndex].angI = angI;
	KeyFrame[FrameIndex].angI2 = angI2;
	KeyFrame[FrameIndex].angI3 = angI3;
	KeyFrame[FrameIndex].angleX = angleX;
	KeyFrame[FrameIndex].angleY = angleY;
	KeyFrame[FrameIndex].angM = angM;
	KeyFrame[FrameIndex].angMe = angMe;
	KeyFrame[FrameIndex].angMe2 = angMe2;
	KeyFrame[FrameIndex].angMe3 = angMe3;
	KeyFrame[FrameIndex].angP = angP;
	KeyFrame[FrameIndex].angP2 = angP2;
	KeyFrame[FrameIndex].transX = transX;
	KeyFrame[FrameIndex].transY = transY;
	KeyFrame[FrameIndex].transZ = transZ;
	fprintf(frms,"%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",
		angA,angA2,angA3,angC,angCh,angCh2,angCh3,angH,angI,angI2,angI3,angleX,angleY,
		angM,angMe,angMe2,angMe3,angP,angP2,transX,transY,transZ);
	FrameIndex++;
 }
 
 void resetElements(void)
 {
	 angA=KeyFrame[0].angA;
	 angA2=KeyFrame[0].angA2;
	 angA3=KeyFrame[0].angA3;
	 angC=KeyFrame[0].angC;
	 angCh=KeyFrame[0].angCh;
	 angCh2=KeyFrame[0].angCh2;
	 angCh3=KeyFrame[0].angCh3;
	 angH=KeyFrame[0].angH;
	 angI=KeyFrame[0].angI;
	 angI2=KeyFrame[0].angI2;
	 angI3=KeyFrame[0].angI3;
	 angleX=KeyFrame[0].angleX;
	 angleY=KeyFrame[0].angleY;
	 angM=KeyFrame[0].angM;
	 angMe=KeyFrame[0].angMe;
	 angMe2=KeyFrame[0].angMe2;
	 angMe3=KeyFrame[0].angMe3;
	 angP=KeyFrame[0].angP;
	 angP2=KeyFrame[0].angP2;
	 transX=KeyFrame[0].transX;
	 transY=KeyFrame[0].transY;
	 transZ=KeyFrame[0].transZ;
 }

 void interpolation(void)
 {
	 KeyFrame[playIndex].incangA = (KeyFrame[playIndex + 1].angA - KeyFrame[playIndex].angA) / i_max_steps;
	 KeyFrame[playIndex].incangA2 = (KeyFrame[playIndex + 1].angA2 - KeyFrame[playIndex].angA2) / i_max_steps;
	 KeyFrame[playIndex].incangA3 = (KeyFrame[playIndex + 1].angA3 - KeyFrame[playIndex].angA3) / i_max_steps;
	 KeyFrame[playIndex].incangC = (KeyFrame[playIndex + 1].angC - KeyFrame[playIndex].angC) / i_max_steps;
	 KeyFrame[playIndex].incangCh = (KeyFrame[playIndex + 1].angCh - KeyFrame[playIndex].angCh) / i_max_steps;
	 KeyFrame[playIndex].incangCh2 = (KeyFrame[playIndex + 1].angCh2 - KeyFrame[playIndex].angCh2) / i_max_steps;
	 KeyFrame[playIndex].incangCh3 = (KeyFrame[playIndex + 1].angCh3 - KeyFrame[playIndex].angCh3) / i_max_steps;
	 KeyFrame[playIndex].incangH = (KeyFrame[playIndex + 1].angH - KeyFrame[playIndex].angH) / i_max_steps;
	 KeyFrame[playIndex].incangI = (KeyFrame[playIndex + 1].angI - KeyFrame[playIndex].angI) / i_max_steps;
	 KeyFrame[playIndex].incangI2 = (KeyFrame[playIndex + 1].angI2 - KeyFrame[playIndex].angI2) / i_max_steps;
	 KeyFrame[playIndex].incangI3 = (KeyFrame[playIndex + 1].angI3 - KeyFrame[playIndex].angI3) / i_max_steps;
	 KeyFrame[playIndex].incangleX = (KeyFrame[playIndex + 1].angleX - KeyFrame[playIndex].angleX) / i_max_steps;
	 KeyFrame[playIndex].incangleY = (KeyFrame[playIndex + 1].angleY - KeyFrame[playIndex].angleY) / i_max_steps;
	 KeyFrame[playIndex].incangM = (KeyFrame[playIndex + 1].angM - KeyFrame[playIndex].angM) / i_max_steps;
	 KeyFrame[playIndex].incangMe = (KeyFrame[playIndex + 1].angMe - KeyFrame[playIndex].angMe) / i_max_steps;
	 KeyFrame[playIndex].incangMe2 = (KeyFrame[playIndex + 1].angMe2 - KeyFrame[playIndex].angMe2) / i_max_steps;
	 KeyFrame[playIndex].incangMe3 = (KeyFrame[playIndex + 1].angMe3 - KeyFrame[playIndex].angMe3) / i_max_steps;
	 KeyFrame[playIndex].incangP = (KeyFrame[playIndex + 1].angP - KeyFrame[playIndex].angP) / i_max_steps;
	 KeyFrame[playIndex].incangP2 = (KeyFrame[playIndex + 1].angP2 - KeyFrame[playIndex].angP2) / i_max_steps;
	 KeyFrame[playIndex].inctransX = (KeyFrame[playIndex + 1].transX - KeyFrame[playIndex].transX) / i_max_steps;
	 KeyFrame[playIndex].inctransY = (KeyFrame[playIndex + 1].transY - KeyFrame[playIndex].transY) / i_max_steps;
	 KeyFrame[playIndex].inctransZ = (KeyFrame[playIndex + 1].transZ - KeyFrame[playIndex].transZ) / i_max_steps;
 }

  void InitGL ( void )     // Inicializamos parametros
  {
	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
  	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
  	glClearDepth(1.0f);									// Configuramos Depth Buffer
  	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

 	//Configuracion luz
 	glLightfv(GL_LIGHT0, GL_POSITION, Position);
 	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
 	glEnable(GL_LIGHTING);
 	glEnable(GL_LIGHT0);
 
 
  	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
  	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	while(!feof(frms)) {
		fscanf(frms,"%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n",
			&KeyFrame[FrameIndex].angA, &KeyFrame[FrameIndex].angA2, &KeyFrame[FrameIndex].angA3, &KeyFrame[FrameIndex].angC,
			&KeyFrame[FrameIndex].angCh, &KeyFrame[FrameIndex].angCh2, &KeyFrame[FrameIndex].angCh3, &KeyFrame[FrameIndex].angH,
			&KeyFrame[FrameIndex].angI, &KeyFrame[FrameIndex].angI2, &KeyFrame[FrameIndex].angI3, &KeyFrame[FrameIndex].angleX,
			&KeyFrame[FrameIndex].angleY, &KeyFrame[FrameIndex].angM, &KeyFrame[FrameIndex].angMe, &KeyFrame[FrameIndex].angMe2,
			&KeyFrame[FrameIndex].angMe3, &KeyFrame[FrameIndex].angP, &KeyFrame[FrameIndex].angP2, &KeyFrame[FrameIndex].transX,
			&KeyFrame[FrameIndex].transY, &KeyFrame[FrameIndex].transZ);
		FrameIndex++;
	}
  }
  
 void prisma(void)
 {
 	GLfloat vertice [8][3] = {
 				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
 				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
 				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
 				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
 				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
 				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
 				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
 				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
  				};
  
  		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
  			glVertex3fv(vertice[0]);
  			glVertex3fv(vertice[4]);
  			glVertex3fv(vertice[7]);
  			glVertex3fv(vertice[1]);
  		glEnd();
  
  		glBegin(GL_POLYGON);	//Right
  			glNormal3f( 1.0f, 0.0f, 0.0f);
  			glVertex3fv(vertice[0]);
  			glVertex3fv(vertice[3]);
  			glVertex3fv(vertice[5]);
  			glVertex3fv(vertice[4]);
  		glEnd();
  
  		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
  			glVertex3fv(vertice[6]);
  			glVertex3fv(vertice[5]);
  			glVertex3fv(vertice[3]);
  			glVertex3fv(vertice[2]);
  		glEnd();
  
  		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
  			glVertex3fv(vertice[1]);
  			glVertex3fv(vertice[7]);
  			glVertex3fv(vertice[6]);
  			glVertex3fv(vertice[2]);
  		glEnd();
  
  		glBegin(GL_POLYGON);  //Bottom
  			glNormal3f( 0.0f, -1.0f, 0.0f);
  			glVertex3fv(vertice[0]);
  			glVertex3fv(vertice[1]);
  			glVertex3fv(vertice[2]);
  			glVertex3fv(vertice[3]);
  		glEnd();
  
  		glBegin(GL_POLYGON);  //Top
  			glNormal3f( 0.0f, 1.0f, 0.0f);
  			glVertex3fv(vertice[4]);
  			glVertex3fv(vertice[5]);
  			glVertex3fv(vertice[6]);
 			glVertex3fv(vertice[7]);
 		glEnd();
 }
 
 void display ( void )   // Creamos la funcion donde se dibuja
 {
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
  	//glMatrixMode(GL_MODELVIEW);
  	glLoadIdentity();
  
	glTranslatef(transX, transY, transZ-5.0);
 	glRotatef(angleY, 0.0, 1.0, 0.0);
 	glRotatef(angleX, 1.0, 0.0, 0.0);
  
	
 
 	//Brazo izquierdo
 	//Poner Código Aquí.		
 	glPushMatrix(); //hombro >pivote
 	glColor3f(1.0,0.0,0.0);
 	glTranslatef(-0.5, 2.0, 0.0);
 	glScalef(0.5,0.5,0.5);
 	glRotatef(angH, 0.0, 0.0, 1.0);
 	prisma();
 		glPushMatrix(); //antebrazo
 		glColor3f(0.0,1.0,0.0);
 		glTranslatef(0.0, -1.5, 0.0);
		glScalef(1.0,2.0,1.0);
  		prisma();
  		glPopMatrix();
  
		glPushMatrix(); //codo >pivote
 		glColor3f(0.0,0.0,1.0);
 		glTranslatef(0.0, -3.0, 0.0);
 		glScalef(1.0,1.0,1.0);
 		glRotatef(angC, 0.0, 0.0, 1.0);
  		prisma();
			glPushMatrix(); //brazo
 			glColor3f(1.0,1.0,0.0);
 			glTranslatef(1.5, 0.0f, 0.0);
 			glScalef(2.0,1.0,1.0);
 			prisma();
 			glPopMatrix();
 
 			glPushMatrix(); //muñeca >pivote
 			glColor3f(1.0,0.0,1.0);
 			glTranslatef(3.0, 0.0f, 0.0);
 			glScalef(1.0,1.0,1.0);
 			glRotatef(angM, 0.0, 1.0, 0.0);
 			prisma();				
 				glPushMatrix(); //pulgar >pivote
 				glColor3f(1.0,0.0,0.0);
 				glTranslatef(0.25, 0.375, 0.25);
 				glRotatef(angP, 1.0, 0.0, 0.0);
 				glTranslatef(0.0, 0.375, 0.0);
 				glScalef(0.2,0.5,0.2);
 				glRotatef(angP, 1.0, 0.0, 0.0);
 				prisma();
 					glPushMatrix(); //pulgar2
 					glColor3f(0.0,1.0,0.0);
 					glTranslatef(0.0, 0.5, 0.0);
 					glRotatef(angP2, 1.0, 0.0, 0.0);
 					glTranslatef(0.0, 0.5, 0.0);
 					glScalef(1.0,1.0,1.0);						
 					prisma();
 					glPopMatrix();
 				glPopMatrix();
 				glPushMatrix(); //indice >pivote
 				glColor3f(0.0,0.0,1.0);
 				glTranslatef(0.375, 0.35, 0.25);
 				glRotatef(angI, 0.0, 1.0, 0.0);
 				glTranslatef(0.375, 0.0, 0.0);
 				glScalef(0.5,0.2,0.2);				
 				prisma();					
 					glPushMatrix(); //indice 2>pivote
 					glColor3f(0.8,0.0,0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glRotatef(angI2, 0.0, 1.0, 0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glScalef(1.0,1.0,1.0);					
 					prisma();
 						glPushMatrix(); //indice 3
 						glColor3f(0.0,0.8,0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glRotatef(angI3, 0.0, 1.0, 0.0);
 						glTranslatef(0.5, 0.0, 0.0);
						glScalef(1.0,1.0,1.0);					
 						prisma();
 						glPopMatrix();
 					glPopMatrix();					
 				glPopMatrix();
 
 				glPushMatrix(); //medio >pivote
 				glColor3f(0.0,0.0,0.8);
 				glTranslatef(0.375, 0.12, 0.25);
 				glRotatef(angMe, 0.0, 1.0, 0.0);
 				glTranslatef(0.375, 0.0, 0.0);
 				glScalef(0.5,0.2,0.2);				
 				prisma();					
 					glPushMatrix(); //medio2 2>pivote
 					glColor3f(0.6,0.0,0.0);
 					glTranslatef(0.5, 0.0, 0.0);					
 					glRotatef(angMe2, 0.0, 1.0, 0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glScalef(1.0, 1.0, 1.0);
 					prisma();
 						glPushMatrix(); //medio 3
 						glColor3f(0.0,0.6,0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glRotatef(angMe3, 0.0, 1.0, 0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glScalef(1.0,1.0,1.0);						
 						prisma();
 						glPopMatrix();
 					glPopMatrix();					
 				glPopMatrix();
 
 				glPushMatrix(); //anular >pivote
 				glColor3f(0.0,0.0,0.6);
 				glTranslatef(0.375, -0.12, 0.25);
 				glRotatef(angA, 0.0, 1.0, 0.0);
 				glTranslatef(0.375, 0.0, 0.0);
 				glScalef(0.5,0.2,0.2);				
 				prisma();					
 					glPushMatrix(); //anular2 2>pivote
 					glColor3f(0.4,0.0,0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glRotatef(angA2, 0.0, 1.0, 0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glScalef(1.0,1.0,1.0);					
 					prisma();
 						glPushMatrix(); //anular 3
 						glColor3f(0.0,0.4,0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glRotatef(angA3, 0.0, 1.0, 0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glScalef(1.0,1.0,1.0);						
 						prisma();
 						glPopMatrix();
 					glPopMatrix();					
 				glPopMatrix();
 
 				glPushMatrix(); //meñique >pivote
 				glColor3f(1.0,0.0,0.0);
 				glTranslatef(0.375, -0.35, 0.25);
 				glRotatef(angCh, 0.0, 1.0, 0.0);
 				glTranslatef(0.375, 0.0, 0.0);
 				glScalef(0.5,0.2,0.2);				
 				prisma();					
 					glPushMatrix(); //meñique 2>pivote
 					glColor3f(0.0,1.0,1.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glRotatef(angCh2, 0.0, 1.0, 0.0);
 					glTranslatef(0.5, 0.0, 0.0);
 					glScalef(1.0,1.0,1.0);					
 					prisma();
 						glPushMatrix(); //meñique 3
 						glColor3f(1.0,0.0,1.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glRotatef(angCh3, 0.0, 1.0, 0.0);
 						glTranslatef(0.5, 0.0, 0.0);
 						glScalef(1.0,1.0,1.0);						
 						prisma();
 						glPopMatrix();
 					glPopMatrix();					
 				glPopMatrix();
 			glPopMatrix();
 		glPopMatrix();	
 	glPopMatrix();
 
 	
 
 	glutSwapBuffers ( );
    // Swap The Buffers
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
 
 	// Tipo de Vista
 	//glOrtho(-5,5,-5,5,0.2,20);	
  	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
  
  	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
 	//glLoadIdentity();									
  }
  
  void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
  {
  	switch ( key ) {
 		case 'R':
 			if(angH <= 158.0)
 				angH +=2.0f;
 			break;
 		case 'r':
 			if (angH >= 2.0)				
 				angH -=2.0f;
 			break;
 		case 'F':
 			if (angC <= 48.0)
 				angC +=2.0f;
 			break;
 		case 'f':
 			if (angC >= -88.0)
 				angC -=2.0f;
 			break;
 		case 'T':
 			if (angM <= 38.0)
 				angM +=2.0f;
 			break;
 		case 't':
 			if (angM >= -48.0)
 				angM -=2.0f;
 			break;
 		case 'G':
 			if (angP <= 58.0)
 				angP +=2.0f;
 			break;
 		case 'g':
 			if (angP >= 2.0)
 				angP -=2.0f;
 			break;
 		case 'Y':
 			if (angP2 <= 88.0)
 				angP2 +=2.0f;
 			break;
 		case 'y':
 			if (angP2 >= 2.0)
 				angP2 -=2.0f;
 			break;
 		case 'H':
 			if (angI <= 8.0)
 				angI +=2.0f;
 			break;
 		case 'h':
 			if (angI >= -88.0)
 				angI -=2.0f;
 			break;
 		case 'U':
 			if (angI2 <= -2.0)
 				angI2 +=2.0f;
 			break;
 		case 'u':
 			if (angI2 >= -88.0)
 				angI2 -=2.0f;
 			break;
 		case 'J':
 			if (angI3 <= -2.0)
 				angI3 +=2.0f;
 			break;
 		case 'j':
 			if (angI3 >= -88.0)
 				angI3 -=2.0f;
 			break;
 		case 'I':
 			if (angMe <= 8.0)
 				angMe +=2.0f;
 			break;
 		case 'i':
 			if (angMe >= -88.0)
 				angMe -=2.0f;
 			break;
 		case 'K':
 			if (angMe2 <= -2.0)
 				angMe2 +=2.0f;
 			break;
 		case 'k':
 			if (angMe2 >= -88.0)
 				angMe2 -=2.0f;
 			break;
 		case 'O':
 			if (angMe3 <= -2.0)
 				angMe3 +=2.0f;
 			break;
 		case 'o':
 			if (angMe3 >= -88.0)
 				angMe3 -=2.0f;
 			break;
 		case 'L':
 			if (angA <= 8.0)
 				angA +=2.0f;
 			break;
 		case 'l':
 			if (angA >= -88.0)
 				angA -=2.0f;
 			break;
 		case 'P':
 			if (angA2 <= -2.0)
 				angA2 +=2.0f;
 			break;
 		case 'p':
 			if (angA2 >= -88.0)
 				angA2 -=2.0f;
 			break;
 		case 'Z':
 			if (angA3 <= -2.0)
 				angA3 +=2.0f;
 			break;
 		case 'z':
 			if (angA3 >= -88.0)
 				angA3 -=2.0f;
 			break;
 		case 'X':
 			if (angCh <= 8.0)
 				angCh +=2.0f;
 			break;
 		case 'x':
 			if (angCh >= -88.0)
 				angCh -=2.0f;
 			break;
 		case 'C':
 			if (angCh2 <= -2.0)
 				angCh2 +=2.0f;
 			break;
 		case 'c':
 			if (angCh2 >= -88.0)
 				angCh2 -=2.0f;
 			break;
 		case 'V':
 			if (angCh3 <= -2.0)
 				angCh3 +=2.0f;
 			break;
 		case 'v':
 			if (angCh3 >= -88.0)
				angCh3 -=2.0f;
			break;
		case 'b':		//
		case 'B':
			if (FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;
		case 'n':
		case 'N':
			if (play == false && (FrameIndex>1))
			{
				resetElements();
				//First Interpolation				
				interpolation();
				play = true;
				playIndex = 0;
				i_curr_steps = 0;
			}
			else
			{
				play = false;
			}
			break;
  		case 'w':
  		case 'W':
			transZ +=0.2f;
  			break;
  		case 's':
  		case 'S':
			transZ -=0.2f;
  			break;
		
		case 'a':
  		case 'A':
			transX -=0.2f;
 			break;
  		case 'd':
  		case 'D':
			transX +=0.2f;
 			break;
 		case 'q':
 		case 'Q':
 			transY -= 0.2f;
 			break;
 		case 'e':
 		case 'E':
 			transY += 0.2f;
  			break;
  		case 27:        // Cuando Esc es presionado...
  			exit ( 0 );   // Salimos del programa
 		break;        
 		default:        // Cualquier otra
 		break;
   }
 	glutPostRedisplay();
 }
 
 void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
  {
    switch ( a_keys ) {
      case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
  		break;
      case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
  		break;
  	case GLUT_KEY_LEFT:
		angleY +=2.0f;
  		break;
  	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
  		break;
      default:
        break;
   }
   glutPostRedisplay();
 }

 void animacion()
 {
	 //Movimiento del monito
	 if (play)
	 {
		 if (i_curr_steps >= i_max_steps) //end of animation between frames?
		 {
			 playIndex++;
			 if (playIndex>FrameIndex - 2)	//end of total animation?
			 {
				 printf("termina anim\n");
				 playIndex = 0;
				 play = false;
			 }
			 else //Next frame interpolations
			 {
				 i_curr_steps = 0; //Reset counter
								   //Interpolation
				 interpolation();

			 }
		 }
		 else
		 {
			 //Draw animation
			 angA += KeyFrame[playIndex].incangA;
			 angA2 += KeyFrame[playIndex].incangA2;
			 angA3 += KeyFrame[playIndex].incangA3;
			 angC += KeyFrame[playIndex].incangC;
			 angCh += KeyFrame[playIndex].incangCh;
			 angCh2 += KeyFrame[playIndex].incangCh2;
			 angCh3 += KeyFrame[playIndex].incangCh3;
			 angH += KeyFrame[playIndex].incangH;
			 angI += KeyFrame[playIndex].incangI;
			 angI2 += KeyFrame[playIndex].incangI2;
			 angI3 += KeyFrame[playIndex].incangI3;
			 angleX += KeyFrame[playIndex].incangleX;
			 angleY += KeyFrame[playIndex].incangleY;
			 angM += KeyFrame[playIndex].incangM;
			 angMe += KeyFrame[playIndex].incangMe;
			 angMe2 += KeyFrame[playIndex].incangMe2;
			 angMe3 += KeyFrame[playIndex].incangMe3;
			 angP += KeyFrame[playIndex].incangP;
			 angP2 += KeyFrame[playIndex].incangP2;
			 transX += KeyFrame[playIndex].inctransX;
			 transY += KeyFrame[playIndex].inctransY;
			 transZ += KeyFrame[playIndex].inctransZ;

			 i_curr_steps++;
		 }

	 }
	 glutPostRedisplay();
 }
 
 
  int main ( int argc, char** argv )   // Main Function
  {
    glutInit            (&argc, argv); // Inicializamos OpenGL
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
    screenW = glutGet(GLUT_SCREEN_WIDTH);
    screenH = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
    glutInitWindowPosition (0, 0);	//Posicion de la Ventana
    glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
    printf("Resolution H: %i \n", screenW);
    printf("Resolution V: %i \n", screenH);
    InitGL ();						// Parametros iniciales de la aplicacion
   glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
   glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
   glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
   glutSpecialFunc     ( arrow_keys );	//Otras
   glutIdleFunc(animacion);
   glutMainLoop        ( );          // 
   fclose(frms);
    return 0;
  }
