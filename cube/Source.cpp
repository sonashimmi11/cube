
#include <GL\glut.h>
#include <math.h>
// Global variables 
GLfloat xRotated = 0, yRotated = 0, zRotated =0;
 GLfloat xscale, yscale, zscale;
 int mode=3; // 1- points, 2- wireframe, 3- shaded
 GLfloat offset =35;
 GLfloat xposition = offset , yposition=0 ,zposition=0;
 GLfloat theta = 0;
void init(void)
{
glClearColor(1,1,1,0);
xscale=1;
yscale=1;zscale=1;

 
}

void DrawCube(void)
{

     glMatrixMode(GL_PROJECTION);
    // clear the drawing buffer.
	 
	// gluLookAt(xposition, yposition, zposition, /* look from camera XYZ */ 
       //  0, 0, 0,  /* look at the origin */ 
    //     0, 1, 0); /* positive Y up vector */
	
     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
	 
    glClear(GL_COLOR_BUFFER_BIT);   
   //glLoadIdentity();
    glTranslatef(0.0,0.0,1.5);
	//glTranslatef(1.0,2.0,-8.5);
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
	glScalef(xscale,yscale,zscale);
    glRotatef(zRotated,0.0,0.0,1.0);
	if(mode==1)
	glBegin(GL_POINTS);// Draw The Cube Using quads
    if(mode==2)
	glBegin(GL_LINE_LOOP);// Draw The Cube Using quads
    if(mode==3)
	glBegin(GL_QUADS);// Draw The Cube Using quads
    glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color Red    
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube
glFlush();
}
    


void animation(void)
{
 
   yRotated += 0.00;
  xRotated += 0.00;
   //DrawCube();
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(70.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
	else if (key=='r') {
		yRotated += 30;	}
	
	else if (key=='q') {
		zRotated += 20;}
	
	else if (key=='w') {
		xRotated += 10;	}
	else if (key=='v'){
		xscale++;
	yscale++;
	zscale++;
	}
	else if (key=='b') {
		xscale--;
		yscale--;
		zscale--;
		
	} 
	else if(key =='p'){
		mode = 1;
		} 
	else if(key =='l'){
		mode = 2;
			} 
	else if(key =='o'){
		mode = 3;

	}
	else if (key== 'c'){
		theta += 5;
		xposition =offset  *cos(3.14/180*theta);
		zposition=-offset *sin(3.14/180*theta);
	}
	glutPostRedisplay();
}
void mouseinput (int button, int state, int x, int y){
	  if (button == GLUT_LEFT_BUTTON)  {
	xscale++;
	yscale++;
	zscale++;
	}
	  if (button == GLUT_RIGHT_BUTTON) {
    xscale--;
	yscale--;
	zscale--;
	}
}
int main(int argc, char** argv){

glutInit(&argc, argv);
//we initizlilze the glut. functions
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(DrawCube);
glutCreateWindow(argv[0]);
init();
glutDisplayFunc(DrawCube);
//glutIdleFunc(animation);
glutReshapeFunc(reshape);
glutKeyboardFunc(processNormalKeys);
glutMouseFunc(mouseinput); 
//Set the function for the animation.
glutMainLoop();
return 0;
}
 