#include "Mushroom.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES
#include <math.h>

//Constructor
Mushroom::Mushroom(void)
{

	
}

//Destructor
Mushroom::~Mushroom(void)
{
    //delete mem

}

//Initializer
bool Mushroom::Initialize(void)
{

	initialized = true;
	return true;
}

//Draws a small mushroom in the center of the map
void Mushroom::Draw(void)
{
    //Draw cylinder for base
    glPushMatrix();
	glColor3f(244, 235, 186);
	GLUquadric* cylinder = gluNewQuadric();
	gluCylinder(cylinder, 1, 0.8, 3, 15, 15);
    glPopMatrix();

    //Draw circle (base for top of mushroom)
    glPushMatrix();
    glColor3f(255, 0, 0);
    glTranslatef(0, 0, 3);
    DrawCircle(0, 0, 2, 8);
    glPopMatrix();

    //Draw half-sphere for top
    glPushMatrix();
    glColor3f(255, 0, 0);
    glTranslatef(0, 0, 3);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(5.0f, 5.0f, 2);
	glPopMatrix();
    
}

//Draws a mushroom based on given parameters
void Mushroom::Draw(float base_height, float base_rad, float top_rad, float x, float y, float z)
{
    //Draw cylinder for base
    glPushMatrix();
    glColor3f(244, 235, 186);
    glTranslatef(x, y, z);
    GLUquadric* cylinder = gluNewQuadric();
    gluCylinder(cylinder, base_rad, base_rad * 0.75, base_height, 10, 10);
    glPopMatrix();

    //Draw circle (base for top of mushroom)
    glPushMatrix();
    glColor3f(255, 0, 0);
    glTranslatef(x, y, z + base_height);
    DrawCircle(0, 0, top_rad, 8);
    glPopMatrix();

    //Draw half-sphere for top
    glPushMatrix();
    glColor3f(255, 0, 0);
    glTranslatef(x, y, z + base_height);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(5, 5, top_rad);
    glPopMatrix();

}

//Draw method for half a sphere
//Code taken from https://community.khronos.org/t/half-sphere/49408/3
void Mushroom::DrawHalfSphere(int scaley, int scalex, GLfloat r) {
    int i, j;
    int size = scalex * scaley;
    GLfloat ** v = new GLfloat*[size];
   
    for (int i = 0; i < size; ++i) {
        v[i] = new GLfloat[3];
    }

    for (i = 0; i < scalex; ++i) {
        for (j = 0; j < scaley; ++j) {
            v[i * scaley + j][0] = r * cos(j * 2 * M_PI / scaley) * cos(i * M_PI / (2 * scalex));
            v[i * scaley + j][1] = r * sin(i * M_PI / (2 * scalex));
            v[i * scaley + j][2] = r * sin(j * 2 * M_PI / scaley) * cos(i * M_PI / (2 * scalex));
        }
    }

    glBegin(GL_QUADS);
    for (i = 0; i < scalex - 1; ++i) {
        for (j = 0; j < scaley; ++j) {
            glVertex3fv(v[i * scaley + j]);
            glVertex3fv(v[i * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + j]);
        }
    }
    glEnd();
}

//Draws a red circle
//Code modified from: http://slabode.exofire.net/circle_draw.shtml
void Mushroom::DrawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / float(num_segments);
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = r;//we start at angle = 0 
    float y = 0;

    glColor3f(255, 0, 0);
    glBegin(GL_LINE_LOOP);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();

    glColor3f(255, 0, 0);
    glBegin(GL_POLYGON);
    for (int ii = 0; ii < num_segments; ii++)
    {
        glVertex2f(x + cx, y + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
}