//Mushroom.h: Header file for Mushroom class

#include <FL/gl.h>

class Mushroom
{
	public:
		Mushroom(void);
		~Mushroom(void);
		bool Initialize(void);
		void Draw(void);
		void Draw(float height, float radius, float x, float y, float z);
		void drawHalfSphere(int scaley, int scalex, GLfloat r);
		void DrawCircle(float cx, float cy, float r, int num_segments);

	private:
		//GLubyte display_list;
		bool initialized;

};