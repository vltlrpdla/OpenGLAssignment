#include<gl\glut.h>

#define Width 4
#define Height 4
//텍셀 버텍스 벨 뷰볼륨
float TxVal = 1.f, VtxVal = 4.0f, VvVal = 8.0f;

GLubyte MyTexture [Width][Height][3];


void FillMyTexture(){
	int s,t;
	for(s = 0 ; s < Width ; s++)
	{
		for(t = 0; t < Height ; t++)
		{
			GLubyte Intensity = (( s+t ) %2) * 255;// 0은 흑색, 255는 백색
			MyTexture[s][t][0] = Intensity;
			MyTexture[s][t][1] = Intensity;
			MyTexture[s][t][2] = Intensity;
		}
	}
}

void MyInit(){
	glClearColor( 0.0 , 0.0 , 0.0 ,0.0);
	FillMyTexture();

	glTexImage2D(GL_TEXTURE_2D, 0, 3, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);//여길

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER , GL_LINEAR);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER , GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER , GL_LINEAR);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	// 마지막 파라미터를 섞을 것인지 말 것인지 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glEnable(GL_TEXTURE_2D);
}

void MyDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1., 1., 0.);

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0, 0.0); glVertex3f( -1.*VtxVal , -1.*VtxVal, 0.0);
		glTexCoord2f(TxVal, 0.0); glVertex3f( VtxVal , -1.*VtxVal, 0.0);
		glTexCoord2f(TxVal, TxVal); glVertex3f( VtxVal , VtxVal, 0.0);
		glTexCoord2f(0.0, TxVal); glVertex3f( -1.*VtxVal , VtxVal, 0.0);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("텍스처 매핑");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glOrtho(-1*VvVal, VvVal, -1*VvVal, VvVal, -1*VvVal, VvVal);
	glutMainLoop();
	return 0;
}
	
