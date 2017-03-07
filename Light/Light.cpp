#include<gl\glut.h>

static int SpinAngle = 0;
static int SpinAngle2 = 0;


void InitLight(){

	
	GLfloat light0_ambient[] = {0.5 , 0.5, 0.5 , 1.0};
	GLfloat light0_diffuse[] = {0.4, 0.4, 0.0 , 1.0};
	GLfloat light0_specular[] ={0.0, 0.0, 0.0, 1.0};
	
	/*
	GLfloat light0_ambient[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat light0_diffuse[] = {1.0, 0.0, 0.0, 1.0};
    GLfloat light0_specular[] = {0.0, 0.0, 1.0, 1.0};
	*/
	GLfloat light1_ambient[] = {0.3 , 0.3, 0.3 , 1.0};
	GLfloat light1_diffuse[] = {0.0, 0.4, 0.4 , 1.0};
	GLfloat light1_specular[] ={0.0, 0.0, 0.0, 1.0};

	GLfloat light2_ambient[] = {0.3 , 0.3, 0.3 , 1.0};
	GLfloat light2_diffuse[] = {0.4, 0.0, 0.4 , 1.0};
	GLfloat light2_specular[] ={0.0, 0.0, 0.0, 1.0};

	GLfloat light3_ambient[] = {0.3 , 0.3, 0.3 , 1.0};
	GLfloat light3_diffuse[] = {0.0, 0.4, 0.4 , 1.0};
	GLfloat light3_specular[] ={0.0, 0.0, 0.0, 1.0};

	GLfloat material_ambient[] = {0.4, 0.4, 0.4, 1.0};
	GLfloat material_diffuse[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat material_specular[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat material_shininess[] = {60.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_shininess);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
}

void MyDisplay(){

	GLfloat LightPosition0[] = { 0.0, 0.0 , 0.5, 1.0};
	GLfloat LightPosition1[] = { 0.5, 0.0 , 0.0, 1.0};
	GLfloat LightPosition2[] = { 0.0, 0.5 , 0.0, 1.0};
	GLfloat LightPosition3[] = { 0.0, 0.0 , 0.5, 1.0};                  

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

		glTranslatef(0.0, 0.0, -5.0);
		


	
		glPushMatrix();
			glRotatef(SpinAngle, 1.0, 0.0, 0.0);
			glLightfv(GL_LIGHT0, GL_POSITION, LightPosition0);

			glTranslatef(0.0, 0.0, 1.2);

			glDisable(GL_LIGHTING);
			glColor3f(1.0,1.0,0.0);
			glutSolidSphere(0.06, 10, 10);

			glEnable(GL_LIGHTING);

			
				glRotatef(SpinAngle2, 0.0, 1.0, 0.0);
				glLightfv(GL_LIGHT3, GL_POSITION, LightPosition3);
				glTranslatef(0.0, 0.0, 0.2);

				glDisable(GL_LIGHTING);
				glColor3f(0.0,1.0,1.0);
				glutSolidSphere(0.03, 10, 10);

				glEnable(GL_LIGHTING);
			

		glPopMatrix();

		glPushMatrix();
			glRotatef(SpinAngle, 0.0, 1.0, 0.0);
			glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

			glTranslatef(1.2, 0.0, 0.0);

			glDisable(GL_LIGHTING);
			glColor3f(0.0,1.0,1.0);
			glutSolidSphere(0.06, 10, 10);

			glEnable(GL_LIGHTING);

				glRotatef(SpinAngle2, 0.0, 1.0, 0.0);
				glLightfv(GL_LIGHT3, GL_POSITION, LightPosition3);
				glTranslatef(0.2, 0.0, 0.0);

				glDisable(GL_LIGHTING);
				glColor3f(1.0,0.0,1.0);
				glutSolidSphere(0.03, 10, 10);

				glEnable(GL_LIGHTING);
			
		glPopMatrix();

		glPushMatrix();
			glRotatef(SpinAngle, 0.0, 0.0, 1.0);
			glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2);

			glTranslatef(0.0, 1.2, 0.0);

			glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,1.0);
			glutSolidSphere(0.06, 10, 10);

			glEnable(GL_LIGHTING);
						
				glRotatef(SpinAngle2, 0.0, 0.0, 1.0);
				glLightfv(GL_LIGHT3, GL_POSITION, LightPosition3);
				glTranslatef(0.0, 0.2, 0.0);

				glDisable(GL_LIGHTING);
				glColor3f(1.0,1.0,0.0);
				glutSolidSphere(0.03, 10, 10);

				glEnable(GL_LIGHTING);
				
		glPopMatrix();


		
		glutSolidSphere(0.8, 50, 50);


		//back
		glPushMatrix();
			glTranslatef(0.0,0.0, -2.0);
			glBegin(GL_POLYGON);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
			glEnd( ); 
		glPopMatrix();

		//right
		glPushMatrix();
			glTranslatef(2.0,0.0, 0.0);
			glRotatef(-90 , 0.0, 1.0, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
			glEnd( ); 
		glPopMatrix();

		//left
		glPushMatrix();
			glTranslatef(-2.0, 0.0, 0.0);
			glRotatef(90 , 0.0, 1.0, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
			glEnd( ); 
		glPopMatrix();

		//up
		glPushMatrix();
			glTranslatef(0.0,2.0, 0.0);
			glRotatef(90 , 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
			glEnd( ); 
		glPopMatrix();


		//down
		glPushMatrix();
			glTranslatef(0.0,-2.0, 0.0);
			glRotatef(-90 , 1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
				glVertex3f(-2.0, -2.0, 0.0);
				glVertex3f(2.0, -2.0, 0.0);
				glVertex3f(2.0, 2.0, 0.0);
				glVertex3f(-2.0, 2.0, 0.0);
			glEnd( ); 
		glPopMatrix();

	glPopMatrix();

	


	glutSwapBuffers();
}
void MyReshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyTimer(int Value){
	SpinAngle = (SpinAngle + 1) % 360;
	SpinAngle2 = (SpinAngle2 + 10) % 360;

	glutPostRedisplay();
	glutTimerFunc(20,MyTimer, 0);
}
/*
void MyMouse(int button, int state, int x, int y){
	switch( button ){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){
			SpinAngle = (SpinAngle +15 ) % 360;
			glutPostRedisplay();
			}
			break;
		default:
		break;
}

}
*/


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("open");
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	//glutMouseFunc(MyMouse);
	glutTimerFunc(0,MyTimer,0);
	glutMainLoop();
	return 0;
}