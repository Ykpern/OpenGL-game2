
#define _CRT_SECURE_NO_DEPRECATE
#include <GL/glut.h>
#include <windows.h>
#include <math.h> 
#include <GL/glu.h>
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

bool lights = false;
int Xindex = 0;
bool right = false;
float eye_x, eye_y, eye_z;
float robotx = 0, roboty = 0;
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 10.0f, z = 5.0f;
bool top1 = false, top2 = false, top3=false;
bool top1return = false, top2return = false, top3return=false;
#define	HEIGHT	20
#define	WIDTH	20

static GLubyte	pattern[WIDTH][HEIGHT][4]; //height, width, RGBA
unsigned char* pattern2;
static GLuint	texName[10];
unsigned long	width, height;

float _light_position[4];
float _spotlight_position[4];




void init(void) {

 
  
    glEnable(GL_COLOR_MATERIAL);

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
   
    


    glClearColor(1.0, 1.0, 1.0, 0.0);  // Set display-window color to white.

    glMatrixMode(GL_PROJECTION);  
    glClearColor(0, 0, 0, 1);    // Set projection parameters.
    glLoadIdentity();
    gluPerspective(80.0, 1, 1, 500.0);	// degree, aspect, near, far 
    
    glMatrixMode(GL_MODELVIEW);
    eye_x = eye_y = eye_z = 20;
    //gluLookAt(90, 150, 50, 0, 0, 0, 0, 0, 1); 
    //    // eye, look-at, view-up

    
}
bool game = false;
int R = 0;
int G = 0;
int B = 0;

void display()
{
    GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };


    if (lights == true) {
        GLfloat light_ambient[] = { 1, 100, 1, 1.0 };
    }
    else {
        GLfloat light_ambient[] = { 0.5, 100, 0.5, 1.0 };
    }

    GLfloat light_specular[] = { 255, 255, 255, 1 };

    _light_position[0] = 0.0;
    _light_position[1] = 0;
    _light_position[2] = 150;
    _light_position[3] = 0.0;

    _spotlight_position[0] = 0.0;
    _spotlight_position[1] = 0.0;
    _spotlight_position[2] = 10.0;

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, _light_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, _spotlight_position);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();   
    

    if (game == false) {
        gluLookAt(x, z, 10,
            x + lx, z + lz, 10,
            0.0f, 0.0f, 1.0f);
        /*gluLookAt(0, 0, 200,
                    0,-1, 1,
                    0.0f, 0.0f, 1.0f);*/
    }
    else {
        gluLookAt(20, -70, 30,
            20 + lx, -70 + lz, 30,
            0.0f, 0.0f, 1.0f);

    }
    
    

    glMatrixMode(GL_MODELVIEW);

  
    
   

    glBegin(GL_QUADS);
        glColor3ub(0, 150, 255);

        glVertex3i(100, -100, 0);
        glVertex3i(-100, -100, 0);
        glVertex3i(-100, -100, 100);
        glVertex3i(100, -100, 100);

    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(60, 255, 20);

    glVertex3i(100, -100, 0);
    glVertex3i(-100, -100, 0);
    glVertex3i(-100, 100, 0);
    glVertex3i(100, 100, 0);

    glEnd();




    
    


   

    glPushMatrix();

    glTranslatef(-50, +85, 0);
    glColor3ub(155, 0, 0);
    glutSolidCube(10);
    
    glPopMatrix();
    //CUbe and CUBE WWIRE
    glPushMatrix();

    glTranslatef(-50, +85, 0);
    glColor3ub(0, 0, 0);
    glutWireCube(10);

    glPopMatrix();
    /////////////////////////////////////////////////////
    glBegin(GL_TRIANGLES);
    
    glColor3ub(255, 153, 51); 
    glVertex3f(-45,80,5);   //V0(red)
     glVertex3f(-50, 85, 20);   //V1(green)
     glVertex3f(-55, 80, 5);   //V2(blue)
    //Triangle 2
     glColor3ub(255, 153, 51); 
     glVertex3f(-55, 80, 5);   //V0(red)
     glVertex3f(-50, 85, 20);   //V2(blue)
     glVertex3f(-55, 90, 5);   //V3(green)
    //Triangle 3
    glColor3ub(255, 153, 51); 
    glVertex3f(-55, 90, 5);   //V0(red)
     glVertex3f(-50, 85, 20);   //V3(green)
     glVertex3f(-45, 90, 5);   //V4(blue)
    //Triangle 4
    glColor3ub(255, 153, 51); 
    glVertex3f(-45, 90, 5);   //V0(red)
     glVertex3f(-50, 85, 20);   //V4(blue)
     glVertex3f(-45, 80, 5);   //V1(green)
    glEnd();
    
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex3f(-50, 85, 20);   //V4(blue)
    glVertex3f(-45, 80, 5);   //V1(green)

    glColor3ub(0, 0, 0);
    glVertex3f(-50, 85, 20);   //V3(green)
    glVertex3f(-45, 90, 5);   //V4(blue)

    glColor3ub(0, 0, 0);
    glVertex3f(-50, 85, 20);   //V2(blue)
    glVertex3f(-55, 90, 5);   //V3(green)

    glColor3ub(0, 0, 0);
    glVertex3f(-50, 85, 20);   //V1(green)
    glVertex3f(-55, 80, 5);   //V2(blue)
    glEnd();

    /////////////////////////////////////////////////////
    
    

    glPushMatrix();
    glTranslatef(80, -85, 0);
    glScaled(10, 10, 20);
    glColor3ub(153, 76, 0);
    glutSolidCube(1);

    glPopMatrix();
    //cylinder  
    glPushMatrix();

    glTranslatef(80, -85, 0);
    glScaled(10, 10, 20);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();
    /////////////////////////////////////////////////////
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(80, -85, 10);
    glutSolidCone(10, 30, 10, 10);
    glPopMatrix();
    //COne And cone Wire on top
    glPushMatrix();

    glTranslatef(80, -85, 10);
    glColor3ub(0, 0, 0);
    glutWireCone(10, 30, 10, 10);

    glPopMatrix();

    /////////////////////////////////////////////////////

    glPushMatrix();
    glTranslatef(90, -65, 0);
    glScaled(5, 5, 20);
    glColor3ub(153, 76, 0);
    glutSolidCube(1);

    glPopMatrix();
    //DAIRENIN ALTI 
    glPushMatrix();

    glTranslatef(90, -65, 0);
    glScaled(5, 5, 20);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();

    /////////////////////////////////////////////////////
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(90, -65, 10);
    glutSolidSphere(10, 10, 10);
    glPopMatrix();

    //DAIRENIN 
    glPushMatrix();

    glTranslatef(90, -65, 10);
    glColor3ub(0, 0, 0);
    glutWireSphere(10, 10, 10);

    glPopMatrix();
   
    /////////////////////////////////////////////////////
   
    glPushMatrix();
    glColor3ub(160, 106, 50);
    glTranslatef(-70+Xindex, -95, 85);

    
    glutSolidTorus(10, 20, 10,10);
    glPopMatrix();
    //torus and wire 
    glPushMatrix();

    glTranslatef(-70 + Xindex, -95, 85);
    glColor3ub(0, 0, 0);
    glutWireTorus(10, 20, 10,10);

    glPopMatrix();
    /////////////////////////////////////////////////////
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(-70 + Xindex, -95, 90);

    glColor3ub(255, 0, 0);
    glutSolidSphere(10, 50, 100);
    glPopMatrix();
    //sphere and wire
    glPushMatrix();

    glTranslatef(-70 + Xindex, -95, 90);
    glColor3ub(0, 0, 0);
    glutWireSphere(10, 5, 10);

    glPopMatrix();
    ////////////////////////////////////////////////////
    glPushMatrix();
    glScalef(0.4, 0.4, 0.4);
    glColor3ub(0, 102, 204);
    glTranslatef(200, 200, 0);
    glutSolidTorus(10, 20, 10, 10);
    glPopMatrix();

    //torus and wire ALONE
    glPushMatrix();
    glScalef(0.4,0.4,0.4);
    glTranslatef(200, 200, 0);
    glColor3ub(0, 0, 0);
    glutWireTorus(10, 20, 10, 10);

    glPopMatrix();
    ////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////
    //KALE

    glPushMatrix();
    glTranslatef(0, -85, 0);
    glScaled(40, 13, 20);
    glColor3ub(255, 153, 255);
    glutSolidCube(1);

    glPopMatrix();
    //cylinder  
    glPushMatrix();

    glTranslatef(0, -85, 0);
    glScaled(40, 13, 20);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 204, 204);
    glTranslatef(0, -85, 10);
    glutSolidCone(10, 30, 10, 10);
    glPopMatrix();
    //COne And cone Wire on top
    glPushMatrix();

    glTranslatef(0, -85, 10);
    glColor3ub(0, 0, 0);
    glutWireCone(10, 30, 5, 5);

    glPopMatrix();

                        ///////////////////
    glPushMatrix();
    glTranslatef(40, -85, 0);
    glScaled(40, 13, 20);
    glColor3ub(255,153,255);
    glutSolidCube(1);

    glPopMatrix();
    //cylinder  
    glPushMatrix();

    glTranslatef(40, -85, 0);
    glScaled(40, 13, 20);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(0, 204, 204);
    glTranslatef(40, -85, 10);
    glutSolidCone(10, 30, 10, 10);
    glPopMatrix();
    //COne And cone Wire on top
    glPushMatrix();

    glTranslatef(40, -85, 10);
    glColor3ub(0, 0, 0);
    glutWireCone(10, 30, 5, 5);

    glPopMatrix();

                                            //////

    glPushMatrix();
    glTranslatef(20, -85, 15);
    glScaled(13, 13, 50);
    glColor3ub(255, 153, 255);
    glutSolidCube(1);

    glPopMatrix();
    //cylinder  
    glPushMatrix();

    glTranslatef(20, -85, 15);
    glScaled(13, 13, 50);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 204, 204);
    glTranslatef(20, -85, 35);

    glutSolidCone(10, 30, 10, 10);
    glPopMatrix();
    //COne And cone Wire on top
    glPushMatrix();

    glTranslatef(20, -85, 35);
    glColor3ub(0, 0, 0);
    glutWireCone(10, 30, 5, 5);

    glPopMatrix();


    //////////////////////////////////
    //////////////////////////////
    ////////////////////////
    glPushMatrix();
    glTranslatef(60, -85+6.5, 0);
    glColor3ub(100, 153, 100);
    glutSolidCube(1);

    glPopMatrix();;


                        //////////////

    glPushMatrix();
    glTranslatef(40 + robotx, 60 + roboty, 0);
    glScaled(5, 5, 20);
    glColor3ub(160, 160, 160);
    glutSolidCube(1);

    glPopMatrix();
    //robot vvucut  
    glPushMatrix();

    glTranslatef(40 + robotx, 60 + roboty, 0);
    glScaled(5, 5, 20);
    glColor3ub(0, 0, 0);
    glutWireCube(1);

    glPopMatrix();
    ///////////////////////////////////////////////////

    glPushMatrix();
    glColor3ub(160, 160, 160);
    glTranslatef(40 + robotx, 60 + roboty, 13);


    glutSolidSphere(4, 50, 100);
    glPopMatrix();
    //Robot kafa
    glPushMatrix();

    glTranslatef(40 + robotx, 60 + roboty, 13);
    glColor3ub(0, 0, 0);
    glutWireSphere(4, 5, 5);

    glPopMatrix();



    ////////////////////////////////////////////////////
    glPushMatrix();
        
    glColor3ub(160, 160, 160);
    glTranslatef(-80, -40, 0);
    ///robot çarpma top

    glutSolidSphere(6, 50, 100);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-80, -40, 0);
    glColor3ub(0, 0, 0);
    glutWireSphere(6, 5, 5);

    glPopMatrix();
    ///////////////////////////////////////////////////////////
    glPushMatrix();

    glColor3ub(160, 160, 160);
    glTranslatef(-40, -40, 0);
    ///robot çarpma top

    glutSolidSphere(6, 50, 100);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-40, -40, 0);
    glColor3ub(0, 0, 0);
    glutWireSphere(6, 5, 5);

    glPopMatrix();
    //////////////////////////////////////////////////////////
    glPushMatrix();

    glColor3ub(160, 160, 160);
    glTranslatef(-80, 0, 0);
    ///robot çarpma top

    glutSolidSphere(6, 50, 100);
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-80, 0, 0);
    glColor3ub(0, 0, 0);
    glutWireSphere(6, 5, 5);

    glPopMatrix();

    int collisioncube = 0;
    if (top1 == true) {
        
        top1return = true;
        glPushMatrix();

        glTranslatef(20, -65, 0+collisioncube);
        glColor3ub(155, 155, 0);
        glutSolidCube(10);

        glPopMatrix();
        //CUbe and CUBE WWIRE
        glPushMatrix();

        glTranslatef(20, -65, 0 + collisioncube);
        glColor3ub(0, 0, 0);
        glutWireCube(10);

        glPopMatrix();
        collisioncube += 10;


    }
    if (top2 == true) {
        
        top2return = true;
        glPushMatrix();

        glTranslatef(20, -65, 0 + collisioncube);
        glColor3ub(155, 155, 0);
        glutSolidCube(10);

        glPopMatrix();
        //CUbe and CUBE WWIRE
        glPushMatrix();

        glTranslatef(20, -65, 0 + collisioncube);
        glColor3ub(0, 0, 0);
        glutWireCube(10);

        glPopMatrix();
        collisioncube += 10;
    }
    if (top3 == true) {
        
        top3return = true;
        glPushMatrix();

        glTranslatef(+20, -65, 0 + collisioncube);
        glColor3ub(155, 155, 0);
        glutSolidCube(10);

        glPopMatrix();
        //CUbe and CUBE WWIRE
        glPushMatrix();

        glTranslatef(20, -65, 0 + collisioncube);
        glColor3ub(0, 0, 0);
        glutWireCube(10);
        collisioncube += 10;

        glPopMatrix();
    }
    if (collisioncube == 30) {

        game = true;
        lights = true;

        glBegin(GL_POLYGON);
        glColor3ub(255, 23, 150);
        glVertex3i(15, -65, 40);
        glVertex3i(15, -65, 30);
        glVertex3i(25, -65, 30);
        glVertex3i(25, -65, 40);
        glEnd();

        glFlush();

    }
    
    
    /////////////////////////////////////////////////////
    glutSwapBuffers();

}



void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void timer(int extra)
{
    if (right == false) {
        if (Xindex < -80) {
            right = true;
        }
        else {
            Xindex -= 5;
        }
        

    }
    if (right == true) {
        if (Xindex > 140) {
            right = false;
        }
        else {
            Xindex += 5;
        }
        
    }
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}
void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 1;

    switch (key) {
    case GLUT_KEY_RIGHT:
        angle -= 0.1f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_LEFT:
        angle += 0.1f;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_UP:
        x += lx * fraction;
        z += lz * fraction;
        break;
    case GLUT_KEY_DOWN:
        x -= lx * fraction;
        z -= lz * fraction;
        break;
    }
}
void keybrd(GLubyte key, GLint xmouse, GLint ymouse) {
    float fraction = 0.1f;
    switch (key) {

    case 'x': { exit(0);

    }
   
    case 'r': {
        
        robotx -= 2.5;
        if ((60 > robotx + 40 - 5 &&
            robotx + 45 >= -20 &&
            -85 + 6.5 > roboty + 60 &&
            roboty + 60 > -85 - 6.5) ||

            (-76 > robotx + 40 - 5 &&
                robotx + 45 > -84 &&
                -36 > roboty + 60 &&
                roboty + 60 > -44))

        {
            robotx += 2.5;
            if (top1return == false) {
                top1 = true;
            }
        }
        else if((-36 > robotx + 40 - 5 &&
            robotx + 45 > -44 &&
            -36 > roboty + 60 &&
            roboty + 60 > -44))
        {
            robotx += 2.5;
            if (top2return == false) {
                top2 = true;
            }
        }
        else if ((-76 > robotx + 40 - 5 &&
            robotx + 45 > -84 &&
            4 > roboty + 60 &&
            roboty + 60 > -4))
        {
            robotx += 2.5;
            if (top3return == false) {
                top3 = true;
            }
                
        }
        else {
            
            glutPostRedisplay();
        }
            
        break;
    }case 'l': {

        robotx += 2.5;
        if ((60 > robotx + 40 - 5 &&
            robotx + 45 >= -20 &&
            -85 + 6.5 > roboty + 60 &&
            roboty + 60 > -85 - 6.5) ||

            (-76 > robotx + 40 - 5 &&
                robotx + 45 > -84 &&
                -36 > roboty + 60 &&
                roboty + 60 > -44))


        {
            if (top1return == false) {
                top1 = true;
            }
            robotx -= 2.5;
        }
        else if ((-36 > robotx + 40 - 5 &&
            robotx + 45 > -44 &&
            -36 > roboty + 60 &&
            roboty + 60 > -44))
        {
            robotx -= 2.5;
            if (top2return == false) {
                top2 = true;
            }
        }
        else if ((-76 > robotx + 40 - 5 &&
            robotx + 45 > -84 &&
            4 > roboty + 60 &&
            roboty + 60 > -4))
        {
            robotx -= 2.5;
            if (top3return == false) {
                top3 = true;
            }
        }
    
        else
        {
            
            glutPostRedisplay();
        }
            

        break;
    }case 'f': {
    
        roboty -= 5;
        if ((60 > robotx + 40 - 5 &&
            robotx + 45 >= -20 &&
            -85 + 6.5 > roboty + 60 - 5 &&
            roboty + 60+ 5 > -85 - 6.5) ||

            (-76 > robotx + 40 - 5 &&
                robotx + 45 > -84 &&
                -36 > roboty + 60 &&
                roboty + 60 > -44))


        {
            if (top1return == false) {
                top1 = true;
            }
            roboty += 5;
        }
        else if ((-36 > robotx + 40 - 5 &&
            robotx + 45 > -44 &&
            -36 > roboty + 60 &&
            roboty + 60 > -44))
        {
            roboty += 5;
            if (top2return == false) {
                top2 = true;
            }
        }
        else if ((-76 > robotx + 40 - 5 &&
            robotx + 45 > -84 &&
            4 > roboty + 60 &&
            roboty + 60 > -4))
        {
            roboty += 5;
            if (top3return == false) {
                top3 = true;
            }
        }
        else
        {
            
            glutPostRedisplay();
        }
           

        break;
    }case 'b': {
        roboty += 5;
        if ((60 > robotx + 40 - 5 &&
            robotx + 45 >= -20 &&
            -85 + 6.5 > roboty + 60 &&
            roboty + 60 > -85 - 6.5) ||

            (-76 > robotx + 40 - 5 &&
                robotx + 45 > -84 &&
                -36 > roboty + 60 &&
                roboty + 60 > -44))


        {
            if (top1return == false) {
                top1 = true;
            }
            roboty -= 5;
        }
        else if ((-36 > robotx + 40 - 5 &&
            robotx + 45 > -44 &&
            -36 > roboty + 60 &&
            roboty + 60 > -44))
        {
            roboty -= 5;
            if (top2return == false) {
                top2 = true;
            }
        }
        else if ((-76 > robotx + 40 - 5 &&
            robotx + 45 > -84 &&
            4 > roboty + 60 &&
            roboty + 60 > -4))
        {
            roboty -= 5;
            if (top3return == false) {
                top3 = true;
            }
        }

            
        else
        {
            
            glutPostRedisplay();
        }
    }
    default:
        break;
    }

}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200, 700);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("CUBES");
    glutKeyboardFunc(keybrd);
    glutSpecialFunc(processSpecialKeys);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    init();

    glutMainLoop();
    return 0;
}