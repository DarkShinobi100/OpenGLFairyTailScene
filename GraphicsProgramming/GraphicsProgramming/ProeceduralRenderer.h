#pragma once
// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#define _USE_MATH_DEFINES
#include<math.h>

class ProeceduralRenderer
{
public:
	ProeceduralRenderer();
	void RenderDisk(int sides);
	void RenderSphere(int sides);
	void RenderCylinder(int sides,int height);
	void renderCube(float x, float y, float z, float val, GLuint texture);
	void renderPlane(double x, double y, double z, double val, GLuint texture);
};

