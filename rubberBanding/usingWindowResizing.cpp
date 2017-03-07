#include<gl\glut.h>
#include<stdio.h>
#include<math.h>


//2016-04-04 Created by Jung Hoon this is using Window Resizing 
GLint X1,Y1,X2,Y2;
GLfloat NX1,NY1,NX2,NY2,
		GlobalWidth, GlobalHeight;

void MyDisplay(){
	//glViewport(0,0,300,300);
	glClear(GL_COLOR_BUFFER_BIT);	glColor3f(0.5,0.5,0.5);
	glEnable(GL_CULL_FACE);

	NX1 = X1 / GlobalWidth;	NY1 = (GlobalHeight - Y1) / GlobalHeight;
	NX2 = X2 / GlobalWidth;	NY2 = (GlobalHeight - Y2) / GlobalHeight;

	glBegin(GL_POLYGON);
		glVertex3f(NX1, NY1, 0.0);	glVertex3f(NX1, NY2, 0.0);
		glVertex3f(NX2, NY2, 0.0);	glVertex3f(NX2, NY1, 0.0);
	glEnd();
	glFlush();
}


void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
	if ( Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN )
	{
		X1 = X; Y1 = Y;
	}
}

void MyMouseMove(GLint X, GLint Y){
	X2 = X; Y2 = Y;
	glutPostRedisplay();
}

void MyReshape(int NewWidth, int NewHeight){
	glViewport(0,0,NewWidth,NewHeight);
	GlobalWidth = NewWidth;
	GlobalHeight = NewHeight;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho( 0.0 , 1.0, 0.0, 1.0, 0.0, 1.0);
	MyDisplay();
}

int main(){
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(0,0);
	glutCreateWindow("OGL Drawing");

	glClearColor(1.0, 1.0 ,1.0,1.0);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho( 0.0 , 1.0, 0.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutReshapeFunc(MyReshape);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);

	glutMainLoop();
	return 0;
}