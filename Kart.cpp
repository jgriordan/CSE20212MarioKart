#include "Kart.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

Kart :: Kart(){
	choice = 1;
	mushroom = 1;
}

Kart :: Kart(int c){
	if (c > 4 || c < 1){
		cout <<"Invalid choice! Defaulting to Kart 1." <<  endl;
		choice = 1;
	}
	else
		choice = c;
	mushroom = 1;
}

void Kart :: DrawKart(){
	FILE * object;
	//vector< glm::vec3 > vertices;
	//vector< glm::vec2 > uvs;
	//vector< glm::vec3 > normals; // Won't be used at the moment.
	switch (choice){
		case 1:
			glutSolidTeapot(1.);
			//bool res = objloader("Kart1.obj", vertices, uvs, normals);
			//if (res == false){
			//	cout << "Could not draw obj" << endl;
			//}
			//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
			break;
		case 2:
			/*//bool res = objloader("Kart2.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 3:
			/*//bool res = objloader("Kart3.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
		case 4:
			/*bool res = objloader("Kart4.obj", vertices, uvs, normals);
                        if (res == false){
                                cout << "Could not draw obj" << endl;
                        }
                        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);*/
                        break;
	}
		
}

/*bool objloader(const char* path, vector < glm::vec3 > & out_vertices, vector < glm::vec2 > & out_uvs, vector < glm::vec3 > & out_normals){
	vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	vector< glm::vec3 > temp_vertices;
	vector< glm::vec2 > temp_uvs;
	vector< glm::vec3 > temp_normals;
	FILE * file = fopen(path, "r");
	if( file == NULL ){
    		cout << "Impossible to open the file !" << endl;
    		return false;
	}
	while( 1 ){
 
    		char lineHeader[128];
    		// read the first word of the line
    		int res = fscanf(file, "%s", lineHeader);
    		if (res == EOF)
        		break; // EOF = End Of File. Quit the loop.
 
    		// else : parse lineHeader
		if ( strcmp( lineHeader, "v" ) == 0 ){
    			glm::vec3 vertex;
    			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
    			temp_vertices.push_back(vertex);
		}
		else if ( strcmp( lineHeader, "vt" ) == 0 ){
    			glm::vec2 uv;
    			fscanf(file, "%f %f\n", &uv.x, &uv.y );
    			temp_uvs.push_back(uv);
		}
		else if ( strcmp( lineHeader, "f" ) == 0 ){
    			string vertex1, vertex2, vertex3;
    			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
    			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
    			if (matches != 9){
        			cout << "File can't be read by our simple parser : ( Try exporting with other options)" << endl;
        			return false;
    			}
			for (int count = 0; count < (matches/3-1); count ++)
    				vertexIndices.push_back(vertexIndex[count]);
    				uvIndices    .push_back(uvIndex[count]);
    				normalIndices.push_back(normalIndex[count]);
			for( unsigned int i=0; i<vertexIndices.size(); i++ ){
				unsigned int vertexIndex = vertexIndices[i];
				glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];
				out_vertices.push_back(vertex);
			}
		}
	}
	
}*/

			

float Kart :: getX(){
	return x_pos;
}

float Kart :: getY(){
	return y_pos;
}

float Kart :: getZ(){
	return z_pos;
}

void Kart :: setX(float x){
	x_pos=x;
}

void Kart :: setY(float y){
	y_pos=y;
}

void Kart :: setZ(float z){
	z_pos=z;
}
