//Tree.h: Header file for Tree class

#include <FL/gl.h>
#include "TargaImage.h"

class Tree
{
public:
	Tree(void);
	~Tree(void);
	bool Initialize(void);
	void Draw(void);
	//void Draw(float base_height, float base_rad, float top_rad, float x, float y, float z);
	void DrawCircle(float cx, float cy, float r, int num_segments);


private:
	bool initialized;
	GLubyte display_list;   // The display list that does all the work.
	//GLuint  texture_obj;    

};
