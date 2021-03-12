#include "Path.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#include <iostream>


void Path::Initialize(void)
{
    /*
    //Set up texturing for train/cube
    ubyte* image_data;
    int	    image_height, image_width;

    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if (!(image_data = (ubyte*)tga_load("pebble.tga", &image_width,
        &image_height, TGA_TRUECOLOR_24)))
    {
        fprintf(stderr, "Path::Initialize: Couldn't load pebble.tga\n");
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

    // Set up the train. At this point a cube is drawn. NOTE: The
    // x-axis will be aligned to point along the track. The origin of the
    // train is assumed to be at the bottom of the train.
    display_list = glGenLists(1);
    glNewList(display_list, GL_COMPILE);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_obj);

    glBegin(GL_QUADS);

    //top
	glNormal3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0f, -3.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0f, 3.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 3.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f, -3.0f, 1.0f);


    //bottom
    glNormal3f(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0f, -3.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f, -3.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 3.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0f, 3.0f, 0.0f);

    //front
    glNormal3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(50.0f, 3.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(50.0f, 3.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0f, -3.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0f, -3.0f, 0.0f);

    //back
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 3.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 3.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0f, -3.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f, -3.0f, 1.0f);

    //right
	glNormal3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0f, 3.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0f, 3.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 3.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 3.0f, 1.0f);

    //left
	glNormal3f(0.0f, -1.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(50.0f, -3.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(50.0f, -3.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, -3.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, -3.0f, 0.0f);
    glEnd();
    // Turn texturing off again, because we don't want everything else to
    // be textured.
    glDisable(GL_TEXTURE_2D);
    glEndList();
*/
}


void Path::Draw(void)
{
    glPushMatrix();
    glTranslatef(0, 5.0, 3);
    glCallList(display_list);
    glPopMatrix();


}

void Path::Draw(float length, float width, float height, float x, float y, float z)
{

    glPushMatrix();
   // glCallList(display_list);
    glPopMatrix();

}