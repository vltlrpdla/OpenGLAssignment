#include <gl\glut.h>
int shoulder = 0, elbow = 0;
int firstJoint[4] = {0};
int secondJoint[4] = {0};


// 쉬프트키를 눌려서 구현했습니다 !! 


void drawFinger(double x, double y, int index){

			//두번째 손가락
		glPushMatrix();
		glTranslatef(x , y ,0.0);
		glRotatef((GLfloat) secondJoint[index], 1.0, 0.0, 0.0);

			//두번째 마디 !!
			glPushMatrix();
			glScalef(0.1,0.1,0.1);
			glutSolidSphere(1.0, 20, 10);
			glPopMatrix();

			glTranslatef(0.0, 0.3, 0.0);


			//두번째 가기전 사각형
			glPushMatrix();
			glScalef(0.3,0.3,0.3);
			glutSolidCube(1.0);
			glPopMatrix();

			glTranslatef(0.0 ,0.3 , 0.0);
			glRotatef((GLfloat) firstJoint[index], 1.0, 0.0, 0.0);

			//첫번째 마디 !!
			glPushMatrix();
			glScalef(0.1,0.1,0.1);
			glutSolidSphere(1.0, 20,10);
			glPopMatrix();

			glTranslatef(0.0 ,0.4 , 0.0);

			// 손끝 
			glPushMatrix();
			glScalef(0.2,0.5,0.1);
			glutSolidCube(1.0);
			glPopMatrix();

		glPopMatrix();

}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0); glShadeModel (GL_FLAT);
	glColor3f(0.0,1.0,0.0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
		glTranslatef (-1.0, 0.0, 0.0);
		glRotatef ((GLfloat) shoulder, 1.0, 0.0, 0.0);
		glTranslatef (1.0, 0.0, 0.0);
			glPushMatrix();
			glScalef (1.0, 2.0, 1.0);
			glutSolidCube (1.0);
			glPopMatrix();
		glTranslatef (0.0, 1.0, 0.0);
		glRotatef ((GLfloat) elbow, 1.0, 0.0, 0.0);
		glTranslatef (0.0, 0.5, 0.0);
	

		glPushMatrix();
		glScalef (0.5, 0.5, 0.5);
		glutSolidSphere (1.0, 20, 10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.0 , 1.0 ,0.0);
		glScalef (1.5, 1.0, 1.0);
		glutSolidCube(1.0);
		glPopMatrix();
	
	
	

		glPushMatrix();//손가락 그릴 기준 전역 좌표계 저장
			glTranslatef(0.0 , 1.0 ,0.0);	
			glTranslatef(-0.9, 0.0, 0.0);
			glRotatef((GLfloat) secondJoint[0], 0.0, 1.0, 0.0);

			//두번째 마디 !!
			glPushMatrix();
			glScalef(0.1,0.1,0.1);
			glutSolidSphere(1.0, 20, 10);
			glPopMatrix();

			glTranslatef(-0.3, 0.0, 0.0);


			//두번째 가기전 사각형
			glPushMatrix();
			glScalef(0.3,0.3,0.3);
			glutSolidCube(1.0);
			glPopMatrix();

			glTranslatef(-0.3 ,0.0 , 0.0);
			glRotatef((GLfloat) firstJoint[0], 0.0, 1.0, 0.0);

			//첫번째 마디 !!
			glPushMatrix();
			glScalef(0.1,0.1,0.1);
			glutSolidSphere(1.0, 20,10);
			glPopMatrix();

			glTranslatef(-0.4 ,0.0 , 0.0);

			// 손끝 
			glPushMatrix();
			glScalef(0.5,0.2,0.1);
			glutSolidCube(1.0);
			glPopMatrix();

		glPopMatrix();

		drawFinger(-0.5,1.6,1);
		drawFinger(-0.0,1.6,2);
		drawFinger(0.5,1.6,3);
		
		//다시 기준 전역 좌표계로 
	glPopMatrix();
		


	
		glutSwapBuffers();
}



void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	//gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 7.0);
	//gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 6.0);
	//gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 6.5);
	glOrtho(-6.0, 6.0, -6.0, 6.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0., 0., 6., 0., 0., 0., 0., 1., 0.);
}
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
	case 'y':
		firstJoint[0] = (firstJoint[0] + 5) % 360;
		glutPostRedisplay(); break;
	case 'h':
		secondJoint[0] = (secondJoint[0] + 5) % 360;
		glutPostRedisplay(); break;
	case 'Y':
		firstJoint[0] = (firstJoint[0] - 5) % 360;
		glutPostRedisplay(); break;
	case 'H':
		secondJoint[0] = (secondJoint[0] - 5) % 360;
		glutPostRedisplay(); break;
	case 'u':
		firstJoint[1] = (firstJoint[1] + 5) % 360;
		glutPostRedisplay(); break;
	case 'j':
		secondJoint[1] = (secondJoint[1] + 5) % 360;
		glutPostRedisplay(); break;
	case 'U':
		firstJoint[1] = (firstJoint[1] - 5) % 360;
		glutPostRedisplay(); break;
	case 'J':
		secondJoint[1] = (secondJoint[1] - 5) % 360;
		glutPostRedisplay(); break;
	case 'i':
		firstJoint[2] = (firstJoint[2] + 5) % 360;
		glutPostRedisplay(); break;
	case 'k':
		secondJoint[2] = (secondJoint[2] + 5) % 360;
		glutPostRedisplay(); break;
	case 'I':
		firstJoint[2] = (firstJoint[2] - 5) % 360;
		glutPostRedisplay(); break;
	case 'K':
		secondJoint[2] = (secondJoint[2] - 5) % 360;
		glutPostRedisplay(); break;
	case 'o':
		firstJoint[3] = (firstJoint[3] + 5) % 360;
		glutPostRedisplay(); break;
	case 'l':
		secondJoint[3] = (secondJoint[3] + 5) % 360;
		glutPostRedisplay(); break;
	case 'O':
		firstJoint[3] = (firstJoint[3] - 5) % 360;
		glutPostRedisplay(); break;
	case 'L':
		secondJoint[3] = (secondJoint[3] - 5) % 360;
		glutPostRedisplay(); break;
	case 27:
		exit(0); break;
	default: break;
	}
}


void main()
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Robot Arm");
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}