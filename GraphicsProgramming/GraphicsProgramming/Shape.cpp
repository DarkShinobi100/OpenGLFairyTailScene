#include "shape.h"

	extern float verts[] = {	
								-1.0, 1.0, 1.0,			// Vertex #0
								-1.0, -1.0, 1.0,		// Vertex #1
								1.0,  -1.0, 1.0,		// Vertex #2
								1.0,  1.0, 1.0,			// Vertex #3
	
						};

extern float cubeverts[] = {	//front
							-1.0, 1.0, 1.0,			// Vertex #0
							-1.0, -1.0, 1.0,		// Vertex #1
							1.0,  -1.0, 1.0,		// Vertex #2
							1.0,  1.0, 1.0,			// Vertex #3

							//back
							-1.0, 1.0, -1.0,		// Vertex #0
							-1.0, -1.0, -1.0,		// Vertex #1
							1.0,  -1.0, -1.0,		// Vertex #2
							1.0,  1.0, -1.0,		// Vertex #3

							//left
							-1.0,-1.0,-1.0,			// Vertex #0
							-1.0,-1.0,1.0,			// Vertex #1
							-1.0,1.0,1.0,			// Vertex #2
							-1.0,1.0,-1.0,			// Vertex #3

							//right
							1.0,-1.0,-1.0,			// Vertex #0
							1.0,-1.0,1.0,			// Vertex #1
							1.0,1.0,1.0,			// Vertex #2
							1.0,1.0,-1.0,			// Vertex #3

							//top
							-1.0,1.0,-1.0,			// Vertex #0
							-1,1.0,1.0,				// Vertex #1
							1.0,1.0,1.0,			// Vertex #2
							1.0,1.0,-1.0,			// Vertex #3

							//bottom
							-1.0,-1.0,-1.0,			// Vertex #0
							-1,-1.0,1.0,			// Vertex #1
							1.0,-1.0,1.0,			// Vertex #2
							1.0,-1.0,-1.0,			// Vertex #3
						};

extern float norms[] = { 0.0, 0.0, 1.0,		//0
						0.0, 0.0, 1.0,		//1
 						0.0, 0.0, 1.0,		//2
						0.0, 0.0, 1.0,		//3
						};		

extern float cubenorms[] = {	//front 
								0.0, 0.0, 1.0,		//0
								0.0, 0.0, 1.0,		//1
								0.0, 0.0, 1.0,		//2
								0.0, 0.0, 1.0,		//3

								//back
								0.0, 0.0, -1.0,		//0
								0.0, 0.0, -1.0,		//1
								0.0, 0.0, -1.0,		//2
								0.0, 0.0, -1.0,		//3

								//left
								-1.0, 0.0, 0.0,		//0
								-1.0, 0.0, 0.0,		//1
								-1.0, 0.0, 0.0,		//2
								-1.0, 0.0, 0.0,		//3
								
								//right
								1.0, 0.0, 0.0,		//0
								1.0, 0.0, 0.0,		//1
								1.0, 0.0, 0.0,		//2
								1.0, 0.0, 0.0,		//3

								//top
								0.0, 1.0, 0.0,		//0
								0.0, 1.0, 0.0,		//1
								0.0, 1.0, 0.0,		//2
								0.0, 1.0, 0.0,		//3


								//bottom
								0.0, -1.0, 0.0,		//0
								0.0, -1.0, 0.0,		//1
								0.0, -1.0, 0.0,		//2
								0.0, -1.0, 0.0,		//3
};

extern float texcoords[]= {	0.0, 0.0, 		//0
							0.0, 1.0, 		//1
 							1.0, 1.0, 		//2
							1.0, 0.0, 		//3
							};

extern float cubetexcoords[] = {//front
									0.0, 0.0, 		//0
									0.0, 1.0, 		//1
									1.0, 1.0, 		//2
									1.0, 0.0, 		//3
								//back													
									0.0, 1.0, 		//0
									0.0, 0.0, 		//1
									1.0, 0.0, 		//2
									1.0, 1.0,		//3

								//left
									0.0, 0.0, 		//0
									0.0, 1.0, 		//1
									1.0, 1.0, 		//2
									1.0, 0.0, 		//3
								//right
									0.0, 0.0, 		//0
									0.0, 1.0, 		//1
									1.0, 1.0, 		//2
									1.0, 0.0, 		//3
								//top
									0.0, 0.0, 		//0
									0.0, 1.0, 		//1
									1.0, 1.0, 		//2
									1.0, 0.0, 		//3
								//bottom
									0.0, 0.0, 		//0
									0.0, 1.0, 		//1
									1.0, 1.0, 		//2
									1.0, 0.0, 		//3
};
extern GLubyte IndexArray[] = { 0,1,2,3 };//order to draw vertexes


void Shape::render1()
{
	// add code to render the cube (above) using method 1
	// glArrayElement()
	//create and fill arrays with vertex,normal and texture data

	//Enable the arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//specify data for the arrays
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer(GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	//dereferencing method of choice
	glBegin(GL_QUADS);
		glArrayElement(0);
		glArrayElement(1);
		glArrayElement(2);
		glArrayElement(3);
	glEnd();

	//turn off
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

void Shape::render2()
{
	//create and fill arrays with vertex,normal and texture data

	//Enable the arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//specify data for the arrays
	glVertexPointer(3, GL_FLOAT, 0, cubeverts);
	glNormalPointer(GL_FLOAT, 0, cubenorms);
	glTexCoordPointer(2, GL_FLOAT, 0, cubetexcoords);

	//dereferencing method of choice
	glDrawArrays(GL_QUADS, 0, 24);

	//turn off
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}

void Shape::render3()
{
	// add code to render the cube (above) using method 3

	//create and fill arrays with vertex,normal and texture data

	//Enable the arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	//specify data for the arrays
	glVertexPointer(3, GL_FLOAT, 0, verts);
	glNormalPointer(GL_FLOAT, 0, norms);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoords);

	//dereferencing method of choice
	glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, IndexArray);

	//turn off
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

}


