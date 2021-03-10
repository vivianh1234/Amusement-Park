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
		//Texturing
		bool ResizeImage(TargaImage* image);
		void LoadTexture(const char* filename);

	private:
		bool initialized;
		unsigned int   textureId;
};