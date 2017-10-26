

#include "escena.h"
#include <iostream>
#include "PeMundo.h"
#include <chrono>
#include <time.h>
#include <cstdint>

using namespace std::chrono;

int frames = 0;
double tiempo = 0;
double tPframe = 0;
double acum = 0;
bool stop = false;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)


//Escena

PeMundo* p;

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 

//BUCLE PRINCIPAL
double contSeg = glutGet(GLUT_ELAPSED_TIME);
double lastFrame = glutGet(GLUT_ELAPSED_TIME);
const float FPS = 1 / 60; 
void loop();



//OPENGL ----------------------------------------------------------------------------------------------------

void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	p = new PeMundo();
	
	

}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
	glFrustum(xLeft, xRight, yBot, yTop, N, F);
	//glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	
 }

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	 
	glMatrixMode(GL_MODELVIEW);	 
	glPushMatrix();	 
		// Rotating the scene
		glRotatef(angX, 1.0f, 0.0f, 0.0f);
        glRotatef(angY, 0.0f, 1.0f, 0.0f);
        glRotatef(angZ, 0.0f, 0.0f, 1.0f);
		
		glLineWidth(1.5f);
		// Drawing axes
		glBegin( GL_LINES );			
			glColor3f(1.0,0.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(20, 0, 0);	     
	 
			glColor3f(0.0,1.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 20, 0);	 
	 
			glColor3f(0.0,0.0,1.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 20);	     
		glEnd();
		 		
		// Drawing the scene	 		 
		glColor3f(0.2, 1.0, 1.0);
		//glutSolidSphere(6, 50, 60); //Sphere: radius=6, meridians=50, parallels=60
		
		p->dibuja();
		//gluPartialDisk(q, 2, 20, 20, 10, 60, 90);
		
		//gluSphere(q,6, 20, 20);

		
	glPopMatrix();
 
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop ();
			stop = true;
			
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;  		 
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
	//glutIdleFunc(loop);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	contSeg = glutGet(GLUT_ELAPSED_TIME);
	lastFrame = glutGet(GLUT_ELAPSED_TIME);
	tPframe = glutGet(GLUT_ELAPSED_TIME);

	// Classic glut's main loop can be stopped in freeglut using (*)

	double delta = 0;

	while (!stop){
		delta = glutGet(GLUT_ELAPSED_TIME) - contSeg;
		contSeg = glutGet(GLUT_ELAPSED_TIME);
		acum += delta;
		

		while(acum > (0.016 * 1000))
		{
			p->simula();
			acum -= (0.016 * 1000);
			frames++;

			if (frames == 60){
				tiempo = glutGet(GLUT_ELAPSED_TIME) - tPframe;
				std::cout << tiempo << endl;
				tPframe = glutGet(GLUT_ELAPSED_TIME);
				frames = 0;
			}
		}

		
		glutMainLoopEvent();

		
		glutPostRedisplay();
	}

	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}

//MOTOR FÍSICA----------------------------------------------------------------------------------------------
void loop(){}
	
	
	