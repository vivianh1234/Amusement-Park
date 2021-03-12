#include "Mushroom.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

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
   /* ubyte* image_data;
    int	    image_height, image_width;

    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if (!(image_data = (ubyte*)tga_load("mushroom_texture.tga", &image_width,
        &image_height, TGA_TRUECOLOR_24)))
    {
        fprintf(stderr, "Mushroom::Initialize: Couldn't load mushroom_texture.tga\n");
        return false;
    }

    // This creates a texture object and binds it, so the next few operations
    // apply to this texture.
    glGenTextures(1, &texture_obj);
    glBindTexture(GL_TEXTURE_2D, texture_obj);

    // This sets a parameter for how the texture is loaded and interpreted.
    // basically, it says that the data is packed tightly in the image array.
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // This sets up the texture with high quality filtering. First it builds
    // mipmaps from the image data, then it sets the filtering parameters
    // and the wrapping parameters. We want the grass to be repeated over the
    // ground.
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image_width, image_height,
        GL_RGB, GL_UNSIGNED_BYTE, image_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST_MIPMAP_LINEAR);

    // This says what to do with the texture. Modulate will multiply the
    // texture by the underlying color.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    */

	initialized = true;
	return true;
}

//Draws a small mushroom in the center of the map
void Mushroom::Draw(void)
{
    //Draw cylinder for base
    glPushMatrix();
    glColor3f(0.99, 0.99, 0.92);
	GLUquadric* cylinder = gluNewQuadric();
	gluCylinder(cylinder, 1, 0.8, 3, 15, 15);
    glPopMatrix();

    //Draw circle (base for top of mushroom)
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, 0, 3);
    DrawCircle(0, 0, 2, 8);
    glPopMatrix();

    //Draw half-sphere for top
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(0, 0, 3);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(5.0f, 5.0f, 2);
    //glCallList(display_list);
	glPopMatrix();
    
}

//Draws a mushroom based on given parameters
void Mushroom::Draw(float base_height, float base_rad, float top_rad, float x, float y, float z)
{
    //Draw cylinder for base
    glPushMatrix();
    glColor3f(0.99, 0.99, 0.92);
    glTranslatef(x, y, z);
    GLUquadric* cylinder = gluNewQuadric();
    gluCylinder(cylinder, base_rad, base_rad * 0.75, base_height, 10, 10);
    glPopMatrix();

    //Draw circle (base for top of mushroom)
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(x, y, z + base_height);
    DrawCircle(0, 0, top_rad, 8);
    glPopMatrix();

    //Draw half-sphere for top
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(x, y, z + base_height);
    glRotatef(90, 1, 0, 0);
    DrawHalfSphere(5, 5, top_rad);
    //glCallList(display_list);
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
   
  /*  //Texturing
    // Now do the geometry. Create the display list.
    display_list = glGenLists(1);
    glNewList(display_list, GL_COMPILE);
    // Use white, because the texture supplies the color.
    glColor3f(0, 255, 0);

    // The surface normal is up for the ground.
    //glNormal3f(0.0, 0.0, 1.0);

    // Turn on texturing and bind the texture.
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_obj);

    //glRotatef(90, 1, 0, 0);
    */

    glBegin(GL_QUADS);
    for (i = 0; i < scalex - 1; ++i) {
        for (j = 0; j < scaley; ++j) {
           /* glTexCoord2f(0, 1); glVertex3fv(v[i * scaley + j]);
            glTexCoord2f(0, 0); glVertex3fv(v[i * scaley + (j + 1) % scaley]);
            glTexCoord2f(1, 0); glVertex3fv(v[(i + 1) * scaley + (j + 1) % scaley]);
            glTexCoord2f(1, 1); glVertex3fv(v[(i + 1) * scaley + j]);*/
            glVertex3fv(v[i * scaley + j]);
            glVertex3fv(v[i * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + (j + 1) % scaley]);
            glVertex3fv(v[(i + 1) * scaley + j]);
        }
    }
    glEnd();

    //glDisable(GL_TEXTURE_2D);
    //glEndList();
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


