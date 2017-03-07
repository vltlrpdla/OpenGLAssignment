#include <gl\glut.h>

GLfloat mat_diffuse[] = { 0., 0., 1., 0.};
GLfloat mat_specular[] = { 1., 1., 1., 0.};
GLfloat light_position[] = { 10., 10., 20., 1.};


//GLfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };

//GLfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.5 };
GLfloat ref_plane[] = { 1.0 , 0.0 , 0.0, 0.0 };//REPEAT의개념
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };
//glfloat ref_plane[] = { 0.0 , 0.0 , 1.0, 0.0 };

unsigned int MyTextureObject;

#define stripeImageWidth 32

GLubyte stripeImage [4 * stripeImageWidth ] ;

void MyStripeImage(){

	for ( int j = 0 ; j < stripeImageWidth ; j++){

		stripeImage[4*j] = 255;
		stripeImage[4*j+1] = (j < 8) ? 0 : 255;
		stripeImage[4*j+2] = (j < 8) ? 0 : 255;
		stripeImage[4*j+3] = 0;
	}
}


void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindTexture(GL_TEXTURE_1D, MyTextureObject);


	glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
	glEnd();

	glutSwapBuffers();
}

void Init(){

	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,light_position);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	MyStripeImage();

	glGenTextures(1, &MyTextureObject);

	glBindTexture(GL_TEXTURE_1D, MyTextureObject);

	glTexImage1D(GL_TEXTURE_1D, 0, 4, stripeImageWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);

	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, ref_plane);

	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_1D);

}


void MyReshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40., (GLfloat)w/(GLfloat)h, 1., 10.);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.,0.,5.,0.,0.,0.,0.,1.,0.);
}

void main(){
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("텍스처");
	glutReshapeFunc(MyReshape);
	glutDisplayFunc(MyDisplay);
	Init();
	glutMainLoop();
}

