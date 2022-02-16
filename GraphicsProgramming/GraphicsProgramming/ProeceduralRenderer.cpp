#include "ProeceduralRenderer.h"

ProeceduralRenderer::ProeceduralRenderer()
{
	//constructor
}

void ProeceduralRenderer::RenderDisk(int sides)
{
	float interval = (2 * M_PI) / sides;
	float angle = 0.0f;

	glBegin(GL_TRIANGLES);
		for (int i = 0; i < sides; i++)
		{
			//texture vertex
			glTexCoord2f(0.5,- 0.5);
			glNormal3f(0.0f, 1.0f, 0.0f);
			//create center vertice
			glVertex3f(0, 0, 0);

			//texture vertex		
			glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
			glNormal3f(0.0f, 1.0f, 0.0f);
			//create first outer vertex
			glVertex3f(cos(angle), sin(angle), 0);

			//texture vertex
			glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
			glNormal3f(0.0f, 1.0f, 0.0f);
			//based on angle create other vertex
			glVertex3f(cos(angle + interval), sin(angle + interval), 0);

			angle += interval;
		}
		//texture Final vertex
		//create final vertex
		glVertex3f(cos(0), sin(0), 0);
	glEnd();

}

void ProeceduralRenderer::RenderSphere(int sides)
{		
	float value = 1/sides;
	float theta = (2 * M_PI) / sides; //latangle
	float delta = M_PI / sides;//lonangle

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)//this is longitude
	{
		for (int j = 0; j < sides; j++) //this is lattitute 
		{
			//texture vertex
			glTexCoord2f(j *value, i*value);
			//create vertex for 1st triangle
			glVertex3f(cos(j*theta)*sin(i *delta)			  //X value for 1st vertice
				, cos(i * delta)							  //Y value for 1st vertice
				,sin(j*theta) * sin(i *delta));			      //Z value for 1st vertice

			//texture vertex
			glTexCoord2f((1 + j)*value,i * value);

			glVertex3f(cos((1+ j)*theta)*sin(i *delta)	     //X value for 2nd vertice
				, cos(i * delta)							 //Y value for 2nd vertice
				, sin((1 + j) * theta) * sin(i *delta));	 //Z value for 2nd vertice

			//texture vertex
			glTexCoord2f((1 + j)*value, (1 + i) *value);

			glVertex3f(cos((1 + j)*theta)*sin((1+i) *delta)  //X value for 3rd vertice
				, cos((1+i) * delta)						 //Y value for 3rd vertice
				, sin((1 + j) * theta) * sin((1+i) *delta)); //Z value for 3rd vertice

			//texture vertex
			glTexCoord2f((1 + j)*value,(1 + i) * value);

			//2nd triangle
			glVertex3f(cos((1 + j)*theta)*sin((1 + i) *delta) //X value for 1st vertice
				, cos((1 + i) * delta)						  //Y value for 1st vertice
				, sin((1 + j) * theta) * sin((1 + i) *delta));//Z value for 1st vertice

			//texture vertex
			glTexCoord2f((1 + i) *value,(1 + i) * value);

			glVertex3f(cos(j*theta)*sin((1 + i) *delta)		 //X value for 2nd vertice
				, cos((1 + i) * delta)						 //Y value for 2nd vertice
				, sin(j * theta) * sin((1 + i) *delta));	 //Z value for 2nd vertice

			//texture vertex
			glTexCoord2f(j*value,i * value);

			glVertex3f(cos(j*theta)*sin(i *delta)			 //X value for 3rd vertice
				, cos(i * delta)						     //Y value for 3rd vertice
				, sin(j*theta) * sin(i *delta));		     //Z value for 3rd vertice
		}
	}
	glEnd();	
}

void ProeceduralRenderer::RenderCylinder(int sides, int height)
{
	float interval = (2 * M_PI) / sides;
	float angle = 0.0f;
	float xValue = 1 / sides; 
	float yValue = 1 / height;
	//create the bottom
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)
	{
		//texture vertex
		glTexCoord2f(0.5, -0.5);
		glNormal3f(0.0f, -1.0f, 0.0f);
		//create center vertice
		glVertex3f(0, 0, 0);

		//texture vertex		
		glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create first outer vertex
		glVertex3f(cos(angle), sin(angle), 0);

		//texture vertex
		glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//based on angle create other vertex
		glVertex3f(cos(angle + interval), sin(angle + interval), 0);

		angle += interval;
	}
	//texture Final vertex
	//create final vertex
	glVertex3f(cos(0), sin(0), 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < height; i++)
	{
		angle = 0.0f; //reset angle for each layer
		for (int j = 0; j < sides; j++)
		{
			glNormal3f(cos(angle), sin(angle), i);
			//texture vertex
			glTexCoord2f(0,0);
			//create first outer vertex
			glVertex3f(cos(angle), sin(angle), i);

			glNormal3f(cos(angle + interval), sin(angle + interval), i);
			//texture vertex
			glTexCoord2f(1,0);
			//based on angle create other vertex
			glVertex3f(cos(angle + interval), sin(angle + interval), i);

			glNormal3f(cos(angle + interval), sin(angle + interval), i + 1);
			//texture vertex
			glTexCoord2f(1,1);
			glVertex3f(cos(angle + interval), sin(angle + interval), i + 1);

			//new triangle
			glNormal3f(cos(angle + interval), sin(angle + interval), i + 1);
			//texture vertex
			glTexCoord2f(1,1);
			glVertex3f(cos(angle + interval), sin(angle + interval), i + 1);

			glNormal3f(cos(angle), sin(angle), i + 1);
			//texture vertex
			glTexCoord2f(0,1);
			glVertex3f(cos(angle), sin(angle), i + 1);

			glNormal3f(cos(angle), sin(angle), i);
			//texture vertex
			glTexCoord2f(0,0);
			glVertex3f(cos(angle), sin(angle), i);

			angle += interval;
		}
	}
	glEnd();

	//create the top
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < sides; i++)
	{
		//texture vertex
		glTexCoord2f(0.5, -0.5);
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create center vertice
		glVertex3f(0, 0, height);

		//texture vertex		
		glTexCoord2f(cos(angle) / 2 + 0.5, -(sin(angle) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//create first outer vertex
		glVertex3f(cos(angle), sin(angle), height);

		//texture vertex
		glTexCoord2f(cos(angle + interval) / 2 + 0.5, -(sin(angle + interval) / 2 + 0.5));
		glNormal3f(0.0f, 1.0f, 0.0f);
		//based on angle create other vertex
		glVertex3f(cos(angle + interval), sin(angle + interval), height);

		angle += interval;
	}
	//texture Final vertex
	//create final vertex
	glVertex3f(cos(0), sin(0), 0);
	glEnd();

}
void ProeceduralRenderer::renderCube(float x, float y, float z, float val, GLuint texture)
{
	glEnable(GL_TEXTURE_2D); //activate the texture
	glBindTexture(GL_TEXTURE_2D, texture); //tell opengl which texture I want
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_TRIANGLES);
	//front face
	//set normal
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z); //bottom left corner

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y + val, z);//top left corner

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z);//top right

	//repeat this point
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z);//top right

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y, z);//bottom right corner

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z); //bottom left corner

	//rear face
	//set normal
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z - val); //bottom left corner

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y + val, z - val);//top left corner

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z - val);//top right

	//repeat this point
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z - val);//top right

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y, z - val);//bottom right corner

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z - val); //bottom left corner

	//left face
	//set normal
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x, y, z - val); //bottom left corner

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z);//top left corner

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y + val, z);//top right

	//repeat this point
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y + val, z);//top right

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x, y + val, z - val);//bottom right corner

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x, y, z - val); //bottom left corner

	//right face
	//set normal
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y, z - val); //bottom left corner

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x + val, y, z);//top left corner

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x + val, y + val, z);//top right

	//repeat this point
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x + val, y + val, z);//top right

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z - val);//bottom right corner

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y, z - val); //bottom left corner

	//top face
	//set normal
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y + val, z - val); //rear left corner

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y + val, z);//front left corner

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z);//front  right
	
	//repeat this point
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y + val, z);//front right

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y + val, z - val);//rear right corner

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y + val, z - val); //rear left corner

	//bottom face
	//set normal
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z - val); //rear left corner

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x, y);
	glVertex3f(x, y, z);//front left corner

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y, z);//front  right

	//repeat this point
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x + val, y);
	glVertex3f(x + val, y, z);//front right

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x + val, y + val);
	glVertex3f(x + val, y, z - val);//rear right corner

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(x, y + val);
	glVertex3f(x, y, z - val); //rear left corner

	glEnd();
}

void ProeceduralRenderer::renderPlane(double x, double y, double z,double val, GLuint texture)
{
	glEnable(GL_TEXTURE_2D); //activate the texture
	glBindTexture(GL_TEXTURE_2D, texture); //tell opengl which texture I want
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_TRIANGLES);
	//set normal
	glNormal3f(0.0f, 1.0f, 0.0f);
	//draw plane
	glTexCoord2f(0, 1);
	glVertex3f(x, y, z - val);
	glTexCoord2f(0, 0);
	glVertex3f(x, y, z);
	glTexCoord2f(1, 0);
	glVertex3f(x + val, y, z);

	glTexCoord2f(1, 0);
	glVertex3f(x + val, y, z);
	glTexCoord2f(1, 1);
	glVertex3f(x + val, y, z - val);
	glTexCoord2f(0, 1);
	glVertex3f(x, y, z - val);

	glEnd();
}


