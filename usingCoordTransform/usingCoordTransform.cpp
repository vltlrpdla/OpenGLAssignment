#include<gl\glut.h>
#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846

//Created by 201116896 Lee Jung Hoon
static int beforeDegree = 45;
double Init_coordLeng = sqrt(2.0) / 2.0;
double degreeToRadian(int degree);


void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);

	int degree = beforeDegree % 90;
	double calculatedRadian1 = degreeToRadian( degree % 90);
	double calculatedRadian2 = degreeToRadian( (90 - degree) % 90 );
	double calculatedRadian3 = degreeToRadian( degree % 90 );
	double calculatedRadian4 = degreeToRadian( (90 - degree) % 90 );
	

	glBegin(GL_POLYGON);
		glVertex3f(-Init_coordLeng*cos(calculatedRadian3),-Init_coordLeng*sin(calculatedRadian3),0.0);
		glVertex3f(Init_coordLeng*cos(calculatedRadian4),-Init_coordLeng*sin(calculatedRadian4),0.0);
		glVertex3f(Init_coordLeng*cos(calculatedRadian1),Init_coordLeng*sin(calculatedRadian1),0.0);
		glVertex3f(-Init_coordLeng*cos(calculatedRadian2),Init_coordLeng*sin(calculatedRadian2),0.0);
	glEnd();

	glFlush();// i don't know this exactly 2016-03-29 by Lee , Checked
}


//Using geometric transformaion
void MyKeyboard (unsigned char Key, int X, int Y){

	switch (Key){
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27 : exit(0); break;
	//case 'r': glRotatef(10.,0.,0.,1.); printf("pressed r key\n");  break;
	//case 'R': glRotatef(-10.,0.,0.,1.); printf("pressed R key\n"); break;
		
	case 'r': beforeDegree += 10; printf("pressed r key\n");  break;
	case 'R': beforeDegree -= 10; printf("pressed R key\n");  break;
	default : printf("%c", Key);

	}

	glutPostRedisplay();// marks the current window as needing to be redisplayed

}

double degreeToRadian(int degree){
	double radian;

	radian = degree * (M_PI/180);
	return radian;
}


void main(){
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
}

