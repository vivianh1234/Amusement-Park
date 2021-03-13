#include "Frog.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void Frog::Initialize()
{
	ifstream file;
	file.open("//thoth.cecs.pdx.edu/Home03/hvivian/Desktop/CompGraphics/Project2/frog.obj");
	if (file.is_open() == false)
	{
		std::cerr << "Couldn't open frog.obj\n";
		return;
	}
	else
	{
		std::cout << "File opened okay\n";
	}

	GLfloat v[6000][3];
	GLfloat vt[7000][2];
	GLfloat vn[5000][3];
	GLfloat f[12000][3][3];
	//indexes
	int v_i = 0;
	int vt_i = 0;
	int vn_i = 0;
	int f_i = 0;

	//Parse obj file
	string line;
	while (std::getline(file, line))
	{
		string header = line.substr(0, line.find(" "));
		
		if (header.compare("v") == 0)
		{
			int i = 0;
			istringstream ss(line);

			string word; // for storing each word 
		
			while (ss >> word)
			{
				cout << word << "\n";
				//convert string to float
				float temp = std::stof(word);	//This is throwing an exception
				v[v_i][i] = temp;
				++i;
			}

			++v_i;
		}
		else if (header.compare("vt") == 0)
		{
			int i = 0;
			istringstream ss(line);

			string word; // for storing each word 

			while (ss >> word)
			{
				//cout << word << "\n";
				//convert string to float
				float temp = std::stof(word);	
				v[vt_i][i] = temp;
				++i;
			}

			++vt_i;
		}
		else if (header.compare("vn") == 0)
		{
			int i = 0;
			istringstream ss(line);

			string word; // for storing each word 

			while (ss >> word)
			{
				//cout << word << "\n";
				//convert string to float
				float temp = std::stof(word);	
				v[vn_i][i] = temp;
				++i;
			}

			++vn_i;
		}
		else if (header.compare("f") == 0)
		{
			int i, j = 0;
			istringstream ss(line);

			string word; // for storing each word 

			//goes through each word - 5399/6229/4076
			while (ss >> word)
			{
				//cout << word << "\n";
				
				istringstream ss2(word);
				while (ss2.good())
				{
					string one_word;
					getline(ss2, one_word, ',');
				
					//convert string to float
					float temp = std::stof(one_word);	

					//store
					f[f_i][i][j] = temp;
					++j;
				}
				++i;
			}
			++f_i;
		}
	}
	file.close();

	//generate the model
	//go through each face and generate the corresponding vertices/normals
	for (int i = 0; i < f_i; ++i) {

		//vertex_index / texture_index / normal_index
		const int vert_ind = 0;
		const int text_ind = 1;
		const int norm_ind = 2;

		//vertices
		int vertex1 = f[i][0][vert_ind];
		int vertex2 = f[i][1][vert_ind];
		int vertex3 = f[i][2][vert_ind];

		//textures
		int texture1 = f[i][0][text_ind];
		int texture2 = f[i][1][text_ind];
		int texture3 = f[i][2][text_ind];

		//normals
		int normal1 = f[i][0][norm_ind];
		int normal2 = f[i][1][norm_ind];
		int normal3 = f[i][3][norm_ind];

		//make the face
		//set normal
		float normal[3];
		CalcNormal(v[vertex1][0], v[vertex1][1], v[vertex1][2],
					v[vertex2][0], v[vertex2][1], v[vertex2][2],
					v[vertex3][0], v[vertex3][1], v[vertex3][2], normal);
		glNormal3f(normal[0], normal[1], normal[2]);

		//set texture & set vertexes
		glTexCoord2f(0, 0); glVertex3f(v[vertex1][0], v[vertex1][1], v[vertex1][2]);
		glTexCoord2f(0, 1); glVertex3f(v[vertex2][0], v[vertex2][1], v[vertex2][2]);
		glTexCoord2f(1, 1); glVertex3f(v[vertex3][0], v[vertex3][1], v[vertex3][2]);
	}


}



void Frog::Draw()
{
	glPushMatrix();

	glPopMatrix();
}


//https://community.khronos.org/t/lighting-a-textured-sphere-calculating-normals/56197
void Frog::CalcNormal(float p1_x, float p1_y, float p1_z, float p2_x, float p2_y, float p2_z, float p3_x, float p3_y, float p3_z, float normal[3])
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
