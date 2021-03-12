#include "Tree.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

//Constructor
Tree::Tree(void)
{


}

//Destructor
Tree::~Tree(void)
{
    //delete mem

}

//Initializer
bool Tree::Initialize(void)
{

    initialized = true;
    return true;
}

//Draws a small tree in the center of the map
void Tree::Draw(void)
{

    //Draw cylinder for base
    glPushMatrix();
    glColor3f(0.27, 0.15, 0.12);
    GLUquadric* cylinder = gluNewQuadric();
    gluCylinder(cylinder, 1, 1, 3, 15, 15);
    glPopMatrix();

    //Draw circle (base for top of tree)
    glPushMatrix();
    glColor3f(0.19, 0.35, 0.12);
    glTranslatef(0, 0, 3);
    DrawCircle(0, 0, 2, 8);
    glPopMatrix();

    //Draw cone for top
    glPushMatrix();
    glColor3f(0.19, 0.35, 0.12);
    glTranslatef(0, 0, 3);
    GLUquadric* cone = gluNewQuadric();
    gluCylinder(cone, 2, 0, 6, 15, 15);
    glPopMatrix();

}

//Draws a tree based on given parameters
void Tree::Draw(float base_height, float top_height, float base_rad, float top_rad, float x, float y, float z)
{
    //Draw cylinder for base
    glPushMatrix();
    glColor3f(0.27, 0.15, 0.12);
    glTranslatef(x, y, z);
    GLUquadric* cylinder = gluNewQuadric();
    gluCylinder(cylinder, base_rad, base_rad, base_height, 15, 15);
    glPopMatrix();

    //Draw circle (base for top of tree)
    glPushMatrix();
    glColor3f(0.19, 0.35, 0.12);
    glTranslatef(x, y, z + base_height);
    DrawCircle(0, 0, top_rad, 8);
    glPopMatrix();

    //Draw cone for top
    glPushMatrix();
    glColor3f(0.19, 0.35, 0.12);
    glTranslatef(x, y, z + base_height);
    GLUquadric* cone = gluNewQuadric();
    gluCylinder(cone, top_rad, 0, top_height, 15, 15);
    glPopMatrix();
}



//Draws a green circle
//Code modified from: http://slabode.exofire.net/circle_draw.shtml
void Tree::DrawCircle(float cx, float cy, float r, int num_segments)
{
    float theta = 2 * 3.1415926 / float(num_segments);
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = r;//we start at angle = 0 
    float y = 0;

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

