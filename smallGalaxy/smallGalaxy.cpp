#include<gl/glut.h>

//int shoulder = 0, elbow = 0;

int year = 0, day = 0 , day2 = 0;


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);

	glPushMatrix();
	glColor3f(0.0,0.6,1.0);
	glutWireSphere(1.0,20,16);
	glRotatef((GLfloat)year,0.0,1.0,0.0);
	glTranslatef(2.0,0.0,0.0);
	glColor3f(0.7,0.2,1.0);
	glRotatef((GLfloat)day,0.0,1.0,0.0);
	glutWireSphere(0.2,10,8);
	glTranslatef(0.4,0.0,0.0);
	glRotatef((GLfloat)day2,0.0,1.0,0.0);
	glColor3f(1.0,0.2,0.4);
	glutWireSphere(0.1,10,8);
	glPopMatrix();
	glutSwapBuffers();

}


void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 7.0);
	//gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 6.0);
	//gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 6.5);
	//glOrtho(-4.0, 4.0, -4.0, 4.0, 1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0., 0., 5., 0., 0., 0., 0., 1., 0.);// 카메라의 시점 (카메라의 포지션, 카메라의 포커싱좌표, 양의 y축방향에 평행하게 서있다 카메라의 꼭지를 양의 y축 방향에 일치시켜라)
}
/*
void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'd':
			day = (day + 10) % 360;
			glutPostRedisplay(); break;
		case 'D':
			day = (day - 10) % 360;
			glutPostRedisplay(); break;
		case 'y':
			year = (year + 5) % 360;
			glutPostRedisplay(); break;
		case 'Y':
			year = (year - 5) % 360;
			glutPostRedisplay(); break;
		case 27:
			exit(0); break;
		default: break;
	}
}
*/
void MyTimer(int Value){


	day = (day + 10) % 360;
	day2 = (day + 10) % 360;
	year = (year + 5) % 360;
	
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1);
}

void main()// callback 함수의 우선순위 생각해보기 왜 reshape이 제일 먼저인가 ? 
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);// 이중 버퍼링  프론트 버퍼 백 버퍼 
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Small Galaxy");
	init ();

	glutTimerFunc(100, MyTimer, 1);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard);
	glutMainLoop();
}


