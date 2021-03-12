//Mushroom.h: Header file for Mushroom class

#include <FL/gl.h>
#include "TargaImage.h"

class Mushroom
{
	public:
		Mushroom(void);
		~Mushroom(void);
		bool Initialize(void);
		void Draw(void);
		void Draw(float base_height, float base_rad, float top_rad, float x, float y, float z);
		void DrawHalfSphere(int scaley, int scalex, GLfloat r);
		void DrawCircle(float cx, float cy, float r, int num_segments);
		void CalcNormal(float p1_x, float p1_y, float p1_z, float p2_x, float p2_y, float p2_z, float p3_x, float p3_y, float p3_z, float normal[3]);

	private:
		bool initialized;
		GLubyte display_list;   // The display list that does all the work.
		GLuint  texture_obj;    // The object for the grass texture.
		
};