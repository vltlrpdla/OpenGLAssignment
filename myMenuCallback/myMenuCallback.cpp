#include <gl\glut.h>

	GLint geoInt = 1;

	GLboolean IsSmall = true;
	GLboolean IsSolid = true;

	
void MyDisplay( ){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);

	switch (geoInt){

	case 1:
		if ((IsSolid) && (IsSmall))
			glutSolidSphere(0.2, 15, 15);
		else if ((!IsSolid) && (IsSmall))
			glutWireSphere(0.2, 15, 15);
		else if ((!IsSolid) && (!IsSmall))
			glutWireSphere(0.4, 15, 15);
		else glutSolidSphere(0.2, 15, 15);

		
		break;

	case 2:

		if ((IsSolid) && (IsSmall))
			glutSolidTorus(0.1, 0.3, 40, 20);
		else if ((!IsSolid) && (IsSmall))
			glutWireTorus(0.1, 0.3, 40, 20);
		else if ((!IsSolid) && (!IsSmall))
			glutWireTorus(0.2, 0.5, 40, 20); 
		else glutSolidTorus(0.2, 0.5, 40, 20); 

		break;

	case 3:
		if ((IsSolid) && (IsSmall))
			glutSolidCube(0.2);
		else if ((!IsSolid) && (IsSmall))
			glutWireCube(0.2);
		else if ((!IsSolid) && (!IsSmall))
			glutWireCube(0.4); 
		else glutSolidCube(0.4); 

		break;

	case 4:
		if ((IsSolid) && (IsSmall))
			glutSolidCone(.1, .2, 10, 10);
		else if ((!IsSolid) && (IsSmall))
			glutWireCone(.1, .2, 10, 10);
		else if ((!IsSolid) && (!IsSmall))
			glutWireCone(.2, .4, 10, 10);  
		else glutSolidCone(.2, .4, 10, 10); 

		break;

	case 5:
		if ((IsSolid) && (IsSmall))
			glutSolidTeapot(.2);
		else if ((!IsSolid) && (IsSmall))
			glutWireTeapot(.2);
		else if ((!IsSolid) && (!IsSmall))
			glutWireTeapot(.4);
		else glutSolidTeapot(.4);

		break;

	default :
		glutSolidSphere(0.2, 15, 15);
		

	}
	
	glFlush( );
}

void MyMainMenu(int entryID){
	if(entryID == 1) geoInt = 1;
	else if (entryID == 2) geoInt = 2;
	else if (entryID == 3) geoInt = 3;
	else if (entryID == 4) geoInt = 4;
	else if (entryID == 5) geoInt = 5;
	else if(entryID == 6) exit(0);
	glutPostRedisplay();
}

void MySubMenu(int entryID){
	if(entryID == 1) IsSmall = true;
	else if (entryID == 2) IsSmall = false;
	glutPostRedisplay();
}

void MySubMenu2(int entryID){
	if(entryID == 1) IsSolid = true;
	else if (entryID == 2) IsSolid = false;
	glutPostRedisplay();
}

int main() {

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example");
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity( );
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	GLint MySubMenuID = glutCreateMenu(MySubMenu);
	glutAddMenuEntry("Small One", 1);
	glutAddMenuEntry("Big One", 2);
	GLint MySubMenuID2 = glutCreateMenu(MySubMenu2);
	glutAddMenuEntry("Solid", 1);
	glutAddMenuEntry("Wire", 2);
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("Draw Cube", 3);
	glutAddMenuEntry("Draw Cone", 4);
	glutAddMenuEntry("Draw Teapot", 5);

	glutAddSubMenu("Change Size", MySubMenuID);
	glutAddSubMenu("Change Shape", MySubMenuID2);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(MyDisplay);
	glutMainLoop( );
	return 0;
}