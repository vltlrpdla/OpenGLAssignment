#include<gl/glut.h>

//int shoulder = 0, elbow = 0;

int year = 0, day = 0;


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
	glutSolidSphere(1.0,20,16);
	glRotatef((GLfloat)year,0.0,1.0,0.0);
	glTranslatef(2.0,0.0,0.0);
	glRotatef((GLfloat)day,0.0,1.0,0.0);
	glutWireSphere(0.2,10,8);
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
	gluLookAt(0., 0., 5., 0., 0., 0., 0., 1., 0.);// ī�޶��� ���� (ī�޶��� ������, ī�޶��� ��Ŀ����ǥ, ���� y����⿡ �����ϰ� ���ִ� ī�޶��� ������ ���� y�� ���⿡ ��ġ���Ѷ�)
}

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

void main()// callback �Լ��� �켱���� �����غ���
{
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);// ���� ���۸�  ����Ʈ ���� �� ���� 
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Robot Arm");
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}


