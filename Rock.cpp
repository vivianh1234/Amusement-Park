#include "Rock.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

//Constructor
Rock::Rock(void)
{


}

//Destructor
Rock::~Rock(void)
{
    //delete mem

}

//Initializer
bool Rock::Initialize(void)
{

    initialized = true;
    return true;
}

//Draws a small rock in the center of the map
void Rock::Draw(void)
{
    //Draw circle (base for rock)
    glPushMatrix();
    glColor3f(0.71, 0.74, 0.8);
    glTranslatef(0, 0, 1);
    DrawCircle(0, 0, 2, 8);
    glPopMatrix();

    //Draw half sphere
    glPushMatrix();
    glColor3f(0.71, 0.74, 0.8);
    glTranslatef(0, 0, 2);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(10, 10, 1);
    glPopMatrix();
}

//Draws a rock based on given parameters
void Rock::Draw(float rad, float x, float y, float z)
{
    //Draw circle (base for rock)
    glPushMatrix();
    glColor3f(0.71, 0.74, 0.8);
    glTranslatef(x, y, z + 1);
    DrawCircle(0, 0, rad, 8);
    glPopMatrix();

    //Draw half sphere
    glPushMatrix();
    glColor3f(0.71, 0.74, 0.8);
    glTranslatef(x, y, z + 1);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(10, 10, rad);
    glPopMatrix();
}

//Draw method for half a sphere
//Code taken from https://community.khronos.org/t/half-sphere/49408/3
void Rock::DrawHalfSphere(int scaley, int scalex, GLfloat r) {
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

            //calc normals
            float normal[3];
            CalcNormal(v[i * scaley + j][0], v[i * scaley + j][1], v[i * scaley + j][2],
                v[i * scaley + (j + 1) % scaley][0], v[i * scaley + (j + 1) % scaley][1], v[i * scaley + (j + 1) % scaley][2],
                v[(i + 1) * scaley + j][0], v[(i + 1) * scaley + j][1], v[(i + 1) * scaley + j][2],
                normal);

            glNormal3f(normal[0], normal[1], normal[2]);

            glVertex3fv(v[i * scaley + j]);
            glVertex3fv(v[i * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + j]);
        }
    }
    glEnd();

}

//https://community.khronos.org/t/lighting-a-textured-sphere-calculating-normals/56197
void Rock::CalcNormal(float p1_x, float p1_y, float p1_z, float p2_x, float p2_y, float p2_z, float p3_x, float p3_y, float p3_z, float normal[3])
{
    // Calculate vectors
    float var1_x = p2_x - p1_x;
    float var1_y = p2_y - p1_y;
    float var1_z = p2_z - p1_z;

    float var2_x = p3_x - p1_x;
    float var2_y = p3_y - p1_y;
    float var2_z = p3_z - p1_z;

    // Get cross product of vectors
    normal[0] = (var1_y * var2_z) - (var2_y * var1_z);
    normal[1] = (var1_z * var2_x) - (var2_z * var1_x);
    normal[2] = (var1_x * var2_y) - (var2_x * var1_y);

    // Normalise final vector
    float vLen = sqrt((normal[0] * normal[0]) + (normal[1] * normal[1]) + (normal[2] * normal[2]));

   /* normal[0] = normal[0] / vLen;
    normal[1] = normal[1] / vLen;
    normal[2] = normal[2] / vLen;
    */
    normal[0] = -1 * (normal[0] / vLen);
    normal[1] = -1 * (normal[1] / vLen);
    normal[2] = -1 * (normal[2] / vLen);

}


//Draws a green circle
//Code modified from: http://slabode.exofire.net/circle_draw.shtml
void Rock::DrawCircle(float cx, float cy, float r, int num_segments)
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

