#include<gl\glut.h>
#include<stdio.h>

//Created by 201116896 Lee Jung Hoon



void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);

	

	glBegin(GL_POLYGON);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,-0.5,0.0);
		glVertex3f(0.5,0.5,0.0);
		glVertex3f(-0.5,0.5,0.0);
	glEnd();

	glFlush();// i don't know this exactly 2016-03-29 by Lee , Checked
}



void MyKeyboard (unsigned char Key, int X, int Y){

	switch (Key){
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 27 : exit(0); break;
	//Using geometric transformaion
	case 'r': glRotatef(10.,0.,0.,1.); printf("pressed r key\n");  break;
	case 'R': glRotatef(-10.,0.,0.,1.); printf("pressed R key\n"); break;	
	default : printf("%c", Key);

	}

	glutPostRedisplay();// marks the current window as needing to be redisplayed

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

