#pragma once
// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
class SkyBox
{
public:
	SkyBox();
	~SkyBox();
	void renderSky(float x, float y, float z, float val);
protected:
	//Textures
	GLuint SkyBoxTexture;
	POINT Cursor;
};

