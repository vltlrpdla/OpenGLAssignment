#include<gl\glut.h>
#include<stdio.h>
#include<math.h>

int MyListID;
void MyCreateList(){
	MyListID = glGenLists(1);
	glNewList(MyListID,GL_COMPILE);
	glBegin(GL_POLYGON);
	//glColor3f(1.,0.,0.);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,-0.5,0.0);
	glVertex3f(0.5,0.5,0.0);
	glVertex3f(-0.5,0.5,0.0);
	glEnd();
	glEndList();

}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,200,200);
	glColor3f(1.,0.,0.);
	glCallList(MyListID);
	glViewport(200, 200, 200, 200);
	glColor3f(0.,1.,0.);
	glCallList(MyListID);
	glViewport(0, 200, 200, 200);
	glColor3f(0.,0.,1.);
	glCallList(MyListID);
	glViewport(100, 200, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glViewport(100, 100, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glViewport(200, 100, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glViewport(200, 0, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glViewport(100, 0, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glViewport(0, 100, 200, 200);
	glColor3f(1.,0.,1.);
	glCallList(MyListID);
	glFlush();
}
int main() {
glutInitDisplayMode(GLUT_RGB);
glutInitWindowSize(400, 400);
glutInitWindowPosition(0, 0);
glutCreateWindow("Dispalylist Example");
glClearColor (1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
glutDisplayFunc(MyDisplay);
MyCreateList();
glutMainLoop( );
return 0;
}