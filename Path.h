#include <Fl/gl.h>


class Path
{
	public:
		void Initialize(void);
		void Draw(void);
		void Draw(float length, float width, float height, float x, float y, float z);

	private:
		GLuint  texture_obj;
		GLubyte display_list;	 
};