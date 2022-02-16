#include "SkyBox.h"

SkyBox::SkyBox()
{
	//Texture setup
	glEnable(GL_TEXTURE_2D);
	SkyBoxTexture = SOIL_load_OGL_texture
	(
		"gfx/skybox.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
}


SkyBox::~SkyBox()
{
}

void SkyBox::renderSky(float x, float y, float z, float val)
{
	glEnable(GL_TEXTURE_2D); //activate the texture
	glBindTexture(GL_TEXTURE_2D, SkyBoxTexture); //tell opengl which texture I want
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glBegin(GL_TRIANGLES);
	//REAR face
	//set normal
	glNormal3f(0.0f, 0.0f, 1.0f);
	//draw plane
	glTexCoord2f(1.00, 0.50);
	glVertex3f(x, y, z); //bottom left corner

	glTexCoord2f(1.00, 0.25);
	glVertex3f(x, y + val, z);//top left corner

	glTexCoord2f(0.75, 0.25);
	glVertex3f(x + val, y + val, z);//top right

	glTexCoord2f(0.75, 0.25);
	glVertex3f(x + val, y + val, z);//top right

	glTexCoord2f(0.75, 0.50);
	glVertex3f(x + val, y, z);//bottom right corner

	glTexCoord2f(1.00, 0.50);
	glVertex3f(x, y, z); //bottom left corner

	//FRONT face
	//set normal
	glNormal3f(0.0f, 0.0f, -1.0f);
	//draw plane
	glTexCoord2f(0.25, 0.5);
	glVertex3f(x, y, z - val); //bottom left corner

	glTexCoord2f(0.25, 0.25);
	glVertex3f(x, y + val, z - val);//top left corner

	glTexCoord2f(0.50, 0.25);
	glVertex3f(x + val, y + val, z - val);//top right

	 //repeat this point
	glTexCoord2f(0.50, 0.25);
	glVertex3f(x + val, y + val, z - val);//top right

	glTexCoord2f(0.50, 0.50);
	glVertex3f(x + val, y, z - val);//bottom right corner

	glTexCoord2f(0.25, 0.50);
	glVertex3f(x, y, z - val); //bottom left corner

	//LEFT face
	//set normal
	glNormal3f(1.0f, 0.0f, 0.0f);
	//draw plane
	glTexCoord2f(0.25, 0.50);
	glVertex3f(x, y, z - val); //bottom left corner

	glTexCoord2f(0.00, 0.50);
	glVertex3f(x, y, z);//top left corner

	glTexCoord2f(0.00, 0.25);
	glVertex3f(x, y + val, z);//top right

	//repeat this point
	glTexCoord2f(0.00, 0.25);
	glVertex3f(x, y + val, z);//top right

	glTexCoord2f(0.25, 0.25);
	glVertex3f(x, y + val, z - val);//bottom right corner

	glTexCoord2f(0.25, 0.50);
	glVertex3f(x, y, z - val); //bottom left corner

	//RIGHT face
	//set normal
	glNormal3f(-1.0f, 0.0f, 0.0f);
	//draw plane
	glTexCoord2f(0.50, 0.50);
	glVertex3f(x + val, y, z - val); //bottom left corner

	glTexCoord2f(0.75, 0.50);
	glVertex3f(x + val, y, z);//top left corner

	glTexCoord2f(0.75, 0.25);
	glVertex3f(x + val, y + val, z);//top right

	//repeat this point
	glTexCoord2f(0.75, 0.25);
	glVertex3f(x + val, y + val, z);//top right

	glTexCoord2f(0.50, 0.25);
	glVertex3f(x + val, y + val, z - val);//bottom right corner

	glTexCoord2f(0.50, 0.50);
	glVertex3f(x + val, y, z - val); //bottom left corner

	//TOP face
	//set normal
	glNormal3f(0.0f, 1.0f, 0.0f);
	//draw plane
	glTexCoord2f(0.25, 0.25);
	glVertex3f(x, y + val, z - val); //bottom left corner

	glTexCoord2f(0.25, 0.001);
	glVertex3f(x, y + val, z);//top left corner

	glTexCoord2f(0.50, 0.001);
	glVertex3f(x + val, y + val, z);//top  right

	//repeat this point
	glTexCoord2f(0.50, 0.001);
	glVertex3f(x + val, y + val, z);//top right

	glTexCoord2f(0.50, 0.25);
	glVertex3f(x + val, y + val, z - val);//bottom right corner

	glTexCoord2f(0.25, 0.25);
	glVertex3f(x, y + val, z - val); //bottom left corner

	//BOTTOM face
	//set normal
	glNormal3f(0.0f, -1.0f, 0.0f);
	//draw plane
	glTexCoord2f(0.25, 0.75);
	glVertex3f(x, y, z - val); //bottom left corner

	glTexCoord2f(0.25, 0.5);
	glVertex3f(x, y, z);//top left corner

	glTexCoord2f(0.50, 0.50);
	glVertex3f(x + val, y, z);//top  right

	//repeat this point
	glTexCoord2f(0.50, 0.50);
	glVertex3f(x + val, y, z);//top right

	glTexCoord2f(0.50, 0.75);
	glVertex3f(x + val, y, z - val);//bottom right corner

	glTexCoord2f(0.25, 0.75);
	glVertex3f(x, y, z - val); //bottom left corner

	glEnd();

}
