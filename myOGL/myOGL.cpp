#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>

int Width, Height;
GLfloat fovy, nearClip, farClip, distance, twistAngle,elevationAngle, azimAngle;
static GLint action;
GLdouble xStart = 0.0, yStart = 0.0;
enum actions{ MOVE_EYE, TWIST_EYE, ZOOM, MOVE_NONE };

GLvoid polarView( GLfloat, GLfloat, GLfloat, GLfloat );
GLvoid init( GLvoid );
GLvoid MyDisplay( GLvoid );
GLvoid reshape( GLsizei, GLsizei );
void resetView( GLvoid );
GLvoid mouse( GLint, GLint, GLint, GLint );
GLvoid motion( GLint, GLint );

void polarView( GLfloat distance, GLfloat azimuth,GLfloat elevation, GLfloat twist){

	glTranslatef( 0.0, 0.0, -distance);
	glRotatef( -twist, 0.0, 0.0, 1.0);
	glRotatef( -elevation, 1.0, 0.0, 0.0);
	//glRotatef( azimuth, 0.0, 0.0, 1.0); //
	//glRotatef( -azimuth, 0.0, 0.0, 1.0); //
	glRotatef( -azimuth, 0.0, 1.0, 0.0); //
}


GLvoid motion( GLint x, GLint y ) {
	switch (action) {
		case MOVE_EYE:
			azimAngle += (GLdouble) (x - xStart);
			elevationAngle += (GLdouble) (y - yStart);
			//azimAngle=fmod(azimAngle+(x-xStart),360.0);
			//incAngle=fmod(incAngle-(y-yStart),360.0);
		break;
		case TWIST_EYE:
			twistAngle = fmod(twistAngle+(x - xStart), 360.0); break;
		case ZOOM:
			distance += (GLdouble) (y - yStart)/10.0; break;
		default:
			printf("unknown action %d\n", action);
}

	xStart = x; yStart = y;
	glutPostRedisplay();
}

GLvoid mouse( GLint button, GLint state, GLint x, GLint y ) {
	static GLint buttons_down = 0;
	if (state == GLUT_DOWN) {
		switch (button) {
			case GLUT_LEFT_BUTTON:action = MOVE_EYE; break;
			case GLUT_MIDDLE_BUTTON:action = TWIST_EYE; break;
			case GLUT_RIGHT_BUTTON:action = ZOOM;break;
		}
		xStart = x;yStart = y;
	} else {
		if (--buttons_down == 0) action = MOVE_NONE;
	}

}

void resetView( GLvoid )
{
	distance = nearClip + (farClip - nearClip) / 2.0;
	// distance = ?
	twistAngle = 0.0; /* rotation of viewing volume(camera)*/
	elevationAngle = 0.0;
	azimAngle = 0.0;
}
	

void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity( );
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glEnable( GL_DEPTH_TEST ); //
	//fovy = 30; nearClip = 3.0; farClip = 50.0;
	//resetView();
}

//gluPerspective(30, 1.0, 3.0, 50.0);
void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);

	glPushMatrix();
		glTranslatef(0.0, -0.5, 0.0);
		glScalef ( 4.0, 0.5, 4.0 );
		glutWireCube(0.5);
	glPopMatrix();


	glColor3f(0.3, 0.3, 0.7);
	glPushMatrix();
		glTranslatef(0.0, 0.2, 0.0);
		glutWireTeapot(0.5);
	glPopMatrix();
} 

void MyDisplay() {

	GLdouble aspect;
	aspect = (GLdouble) Width/2 / (GLdouble) Height/2;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glViewport(0, 0, Width/2, Height/2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		//gluPerspective( 45, 1.0, 1.0, 400.0 );
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);
		
		glPushMatrix();
			gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			polarView( distance, azimAngle, elevationAngle, twistAngle );
			DrawScene();
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	
	glViewport(Width/2, 0, Width/2, Height/2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
			gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawScene();
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glViewport(0, Height/2, Width/2, Height/2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
			gluLookAt(0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
			DrawScene();
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glViewport(Width/2, Height/2, Width/2, Height/2);
	
	glMatrixMode(GL_PROJECTION);
	
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(30, 1.0, 3.0, 50.0);
		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
			gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			//glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
			
			DrawScene();
		glPopMatrix();

		glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}

void MyReshape(int w, int h) {
	Width = w;
	Height = h;	
}

int main(int argc, char** argv) {
	Width = 500;
	Height = 500;
	glutInitDisplayMode( GLUT_SINGLE |GLUT_RGBA );
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My OGL");
	Init();
	glutMouseFunc( mouse );
	glutMotionFunc( motion ); 
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}