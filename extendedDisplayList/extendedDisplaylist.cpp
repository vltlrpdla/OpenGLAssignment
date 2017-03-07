
#include <gl\glut.h>

int MyListID;
int secondListID;

void MyCreateList(){
	
	MyListID = glGenLists(2);
	glNewList(MyListID, GL_COMPILE);
	glBegin(GL_POLYGON);
	//glColor3f(1.,0.,0.);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,-0.5,0.0);
	glVertex3f(0.5,0.5,0.0);
	glVertex3f(-0.5,0.5,0.0);
	glEnd();
	glEndList();

	secondListID = MyListID + 1;
	glNewList(secondListID, GL_COMPILE);
	//glColor3f(1.,0.,0.);
	glutWireTeapot(.2);
	glEndList();

	

}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); glLoadIdentity();
	glViewport(0,0,300,300);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
	glColor3f(0.,0.,1.);
	glRotatef(45,0,0,1);
	glCallList(MyListID);
	glPopMatrix();

	glPushMatrix(); glLoadIdentity();
	glViewport(150,150,300,300);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
	glColor3f(1.,0.,0.);
	glRotatef(55,0,0,1);
	glTranslatef(-0.7, 0., 0.);
	glCallList(MyListID);
	glPopMatrix();

	glPushMatrix(); glLoadIdentity();
	glViewport(0,150,300,300);
	glColor3f(1.,0.5,0.);
	glCallList(secondListID);
	glPopMatrix();

	glPushMatrix(); glLoadIdentity();
	glViewport(150,0,300,300);	
	glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
	glColor3f(1.,0.,1.);
	glRotatef(65,0,0,1);
	glCallList(MyListID);
	glPopMatrix();

	
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