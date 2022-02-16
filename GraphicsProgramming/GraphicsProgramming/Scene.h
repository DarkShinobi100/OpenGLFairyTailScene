// Scene class. Configures a basic 3D scene.
// Interfaces with the Input class to handle user input
// Calculates and outputs Frames Per Second (FPS) rendered.
// Important functions are the constructor (initialising the scene), 
// update (for process user input and updating scene objects) and render (renders scene).
#ifndef _SCENE_H
#define _SCENE_H

// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include "Camera.h";
#include "SkyBox.h";
#include "model.h"
#include "Shape.h"
#include "ProeceduralRenderer.h"

class Scene{

public:
	Scene(Input *in);
	// Main render function
	void render();
	// Handle input function that receives delta time from parent.
	void handleInput(float dt);
	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);
	// Resizes the OpenGL output based on new window size.
	void resize(int w, int h);

protected:

	// Renders text (x, y positions, RGB colour of text, string of text to be rendered)
	void displayText(float x, float y, float r, float g, float b, char* string);
	// A function to collate all text output in a single location
	void renderTextOutput();
	void calculateFPS();

	// draw primitive functions	

	// For access to user input.
	Input* input;
		
	// For Window and frustum calculation.
	int width, height;
	float fov, nearPlane, farPlane;

	// For User interface.
	int frame = 0, time, timebase = 0;
	char fps[40];
	char mouseText[40];
	char Controls[40];
	char RotationControls[40];
	char CameraControl[40];
	char PlayerInteraction[60];
	char EscInteraction[40];

private:

	//Scene variables 
	GLint polygonMode; // save the polygon mode for the camera
	float Orbit = 0; //how far around the origin is the object
	bool Pause = false;//pause the game
	SkyBox skybox; //skybox for the camera
	POINT Cursor; // variable to store cursor values
	bool MovementToggle; //variable to store if we are moving
	Shape Shapes;// vertex arrays shapes
	ProeceduralRenderer ProRender; // Proecedural Renderer object

	//camera's
	Camera camera0;
	Camera camera1;
	Camera camera2;
	Camera camera3;
	Camera camera4;
	Camera camera5;
	Camera* ActiveCamera;

	//Model textures
	GLuint LucyTexture;
	GLuint NatsuTexture;
	GLuint GrayTexture;
	GLuint MikuIzayoiTexture;
	GLuint Body1Texture;
	GLuint Body2Texture;
	GLuint WingsTexture;
	GLuint StoolTexture;
	GLuint TableTexture;
	GLuint DeskTexture;
	GLuint PoolTableTexture;

	//geometry textures
	GLuint CrateTexture;
	GLuint StoneTexture;
	GLuint BrickTexture;
	GLuint PaintTexture;
	GLuint WindowTexture;
	GLuint RoofTileTexture;
	GLuint WoodTexture;
	GLuint DoorTexture;
	GLuint FairyTailBannerTexture;
	GLuint OracienSiesBannerTexture;
	GLuint BluePegasusBannerTexture;
	GLuint BlackTexture;
	GLuint PurpleTexture;
	GLuint StonePillarTexture;
	GLuint ShadowTexture;
	GLuint FlameTexture;
	GLuint ClothTexture;
	GLuint FloatingStoneTexture;
	
	//Models
	Model teapot; //create a model object called teapot
	Model Lucy; //create a model object called Lucy
	Model Natsu; //create a model object called Natsu
	Model Gray; //create a model object called Gray
	Model MikuIzayoi; //create a model object called MikuIzayoi
	Model AcnologiaBody; //create a model object called AcnologiaBody
	Model AcnologiaBody2; //create a model object called AcnologiaBody2
	Model AcnologiaWings; //create a model object called Acnologiawings
	Model Table; //create a model object called Table
	Model Crystal; //create a model object called Crystal
	Model Desk; //create a model object called Desk
	Model Bar; //create a model object called Bar
	Model Bed; //create a model object called Bed
	Model PoolTable; //create a model object called PoolTable
	Model Divider; //create a model object called Divider
};

#endif