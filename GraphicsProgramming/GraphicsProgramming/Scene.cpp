#include "Scene.h"

// Scene constructor, initilises OpenGL
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
		
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);   //uses two constants to determine how the blending function works
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Other OpenGL / render setting should be applied here.
	glEnable(GL_TEXTURE_2D);

	CrateTexture = SOIL_load_OGL_texture
	(
		"gfx/crate.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
		
	LucyTexture = SOIL_load_OGL_texture
	(
		"Models/Lucy.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	NatsuTexture = SOIL_load_OGL_texture
	(
		"Models/Natsu.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	GrayTexture = SOIL_load_OGL_texture
	(
		"Models/Gray.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	MikuIzayoiTexture = SOIL_load_OGL_texture
	(
		"Models/MikuIzayoiAlt2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	Body1Texture = SOIL_load_OGL_texture
	(
		"Models/body.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	Body2Texture = SOIL_load_OGL_texture
	(
		"Models/body2.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	WingsTexture = SOIL_load_OGL_texture
	(
		"Models/wings.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	TableTexture = SOIL_load_OGL_texture
	(
		"Models/Table.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	DeskTexture = SOIL_load_OGL_texture
	(
		"Models/DeskUV.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	PoolTableTexture = SOIL_load_OGL_texture
	(
		"Models/PoolTable.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	BluePegasusBannerTexture = SOIL_load_OGL_texture
	(
		"gfx/BluePegasusBanner.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	StoneTexture = SOIL_load_OGL_texture
	(
		"gfx/Stone.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	BrickTexture = SOIL_load_OGL_texture
	(
		"gfx/Brick.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	PaintTexture = SOIL_load_OGL_texture
	(
		"gfx/WallPaint.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	WindowTexture = SOIL_load_OGL_texture
	(
		"gfx/WallPaintWindow.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	RoofTileTexture = SOIL_load_OGL_texture
	(
		"gfx/RoofTile.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	WoodTexture = SOIL_load_OGL_texture
	(
		"gfx/Wood.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	DoorTexture = SOIL_load_OGL_texture
	(
		"gfx/Door.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	FairyTailBannerTexture = SOIL_load_OGL_texture
	(
		"gfx/FairyTailBanner.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	OracienSiesBannerTexture = SOIL_load_OGL_texture
	(
		"gfx/OracienSiesBanner.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);


	BluePegasusBannerTexture = SOIL_load_OGL_texture
	(
		"gfx/BluePegasusBanner.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	BlackTexture = SOIL_load_OGL_texture
	(
		"gfx/BlackTexture.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	PurpleTexture = SOIL_load_OGL_texture
	(
		"gfx/PurpleTexture.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	StonePillarTexture = SOIL_load_OGL_texture
	(
		"gfx/StonePillarTexture.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	ShadowTexture = SOIL_load_OGL_texture
	(
		"gfx/imposter.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	FlameTexture = SOIL_load_OGL_texture
	(
		"gfx/FlameTexture.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	ClothTexture = SOIL_load_OGL_texture
	(
		"gfx/cloth.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	FloatingStoneTexture = SOIL_load_OGL_texture
	(
		"gfx/FloatingStoneTexture.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	PoolTableTexture = SOIL_load_OGL_texture
	(
		"Models/PoolTable.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	//load models
	Lucy.load("Models/Lucy.obj", "gfx/Lucy.png");
	Natsu.load("Models/Natsu.obj", "gfx/Natsu.png");
	Gray.load("Models/Gray.obj", "gfx/Gray.png");
	MikuIzayoi.load("Models/MikuIzayoi.obj", "gfx/MikuIzayoi.png");
	AcnologiaBody.load("Models/AcnologiaBody.obj", "Models/body.png");
	AcnologiaBody2.load("Models/AcnologiaBody2.obj", "Models/body2.png");
	AcnologiaWings.load("Models/AcnologiaWings.obj", "Models/wings.png");
	Table.load("Models/Table.obj", "Models/Table.png");
	Crystal.load("Models/Crystal.obj", "Models/Crystal.jpg");
	Desk.load("Models/Desk2.obj", "Models/DeskUV.jpg");
	Bar.load("Models/Bar.obj", "Models/Table.png");
	Bed.load("Models/Bed.obj", "Models/Table.png");
	PoolTable.load("Models/PoolTable2.obj", "Models/Table.png");
	Divider.load("Models/Screen.obj", "Models/Table.png");
	MovementToggle = false;

	// Initialise scene variables

	//Point type for corsor details
	//stores values as X,Y
	Cursor = { 0,0 };
	glutSetCursor(GLUT_CURSOR_NONE);

	//camera's
	camera0.SetPosition(Vector3(0, 1, 9)); //moving camera
	camera0.SetLookAt(Vector3(0, 1, 7));

	camera1.SetPosition(Vector3(0, 0.5, 5)); //floor 1
	camera1.SetLookAt(Vector3(0, 0.5, -2));

	camera2.SetPosition(Vector3(-0.25, 2.5, 3)); //floor 2
	camera2.SetLookAt(Vector3(-0.25, 2.5, -3));

	camera3.SetPosition(Vector3(-0.5, 4, 2.5)); //floor 3
	camera3.SetLookAt(Vector3(-0.5, 4, -3.5));

	camera4.SetPosition(Vector3(0.25, -3, 8)); //basement
	camera4.SetLookAt(Vector3(0.25, -3, 2));

	camera5.SetPosition(Vector3(0, 1, 2)); //rotating camera
	camera5.SetLookAt(Vector3(0, 1, -5));

	ActiveCamera = &camera0;
}

void Scene::handleInput(float dt)
{
	// Handle user input
	if (input->isKeyDown('r'))
	{
		glGetIntegerv(GL_POLYGON_MODE, &polygonMode);
		if (polygonMode == GL_FILL)
		{
			//enable wireframe mode
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		}
		else
		{
			//enable wireframe mode
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		input->SetKeyUp('r');
	}
	if (input->isKeyDown('t'))
	{
		//set up camera render mode
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
	if (input->isKeyDown('f'))
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}

	if (ActiveCamera == &camera0) //if the active camera is the original, allow it to move
	{
		//player movement Using: W,A,S,D,Q,E
		//move into the scene
		if (input->isKeyDown('w'))
		{
			camera0.Move(camera0.GetForwardVector().x, camera0.GetForwardVector().y, camera0.GetForwardVector().z, dt);
			MovementToggle = true;
		}
		//move back from the screen
		if (input->isKeyDown('s'))
		{
			camera0.Move(-camera0.GetForwardVector().x, -camera0.GetForwardVector().y, -camera0.GetForwardVector().z, dt);
			MovementToggle = true;
		}

		//rotate in the Y axis from where we are, like a spinning chair
		if (input->isKeyDown('a'))
		{
			camera0.RotateCameraYaw(-2.5f);
			MovementToggle = true;
		}

		if (input->isKeyDown('d'))
		{
			camera0.RotateCameraYaw(2.5f);
			MovementToggle = true;
		}

		//move up in Y
		if (input->isKeyDown('q'))
		{
			camera0.Move(camera0.GetUpAxis().x, camera0.GetUpAxis().y, camera0.GetUpAxis().z, dt);
			MovementToggle = true;
		}
		//move down in Y
		if (input->isKeyDown('e'))
		{
			camera0.Move(-camera0.GetUpAxis().x, -camera0.GetUpAxis().y, -camera0.GetUpAxis().z, dt);
			MovementToggle = true;
		}

		//player rotation Using: I,J,K,L,U,O
		if (input->isKeyDown('i'))
		{
			//move forward in Z
			camera0.RotateCameraRoll(-2.5f);
			MovementToggle = true; //set the toggle
		}
		if (input->isKeyDown('k'))
		{
			//move backward in Z
			camera0.RotateCameraRoll(2.5f);
			MovementToggle = true; //set the toggle
		}

		if (input->isKeyDown('j'))
		{
			//move left in x
			camera0.RotateCameraPitch(-2.5f);
			MovementToggle = true; //set the toggle
		}
		if (input->isKeyDown('l'))
		{
			//move right in x
			camera0.RotateCameraPitch(2.5f);
			MovementToggle = true; //set the toggle
		}
		if (input->isKeyDown('u'))
		{
			//move up in y
			camera0.RotateCameraYaw(2.5f);
			MovementToggle = true; //set the toggle
		}
		if (input->isKeyDown('o'))
		{
			//move down in y
			camera0.RotateCameraYaw(-2.5f);
			MovementToggle = true; //set the toggle
		}

		//put mouse controls here

		//calculate the difference in X since last frame
		if ((width / 2 - Cursor.x) > 0)
		{
			//rotate  in Y axis clockwise
			camera0.RotateCameraYaw(-2.5f);
			MovementToggle = true; //set the toggle
		}
		if ((width / 2 - Cursor.x) < 0)
		{
			//rotate  in Y axis anti-clockwise
			camera0.RotateCameraYaw(2.5f);
			MovementToggle = true; //set the toggle
		}

		//calculate the difference in y since the last frame
		if ((height / 2 - Cursor.y) > 0)
		{
			//rotate  in X axis clockwise
			camera0.RotateCameraPitch(2.5f);
			MovementToggle = true; //set the toggle
		}
		if ((height / 2 - Cursor.y) < 0)
		{
			//rotate  in X axis anti-clockwise
			camera0.RotateCameraPitch(-2.5f);
			MovementToggle = true; //set the toggle
		}
	}
	//update camera's
	if (input->isKeyDown('0'))
	{
		ActiveCamera = &camera0;//set the active camera to the default one
		input->SetKeyUp('0');
	}

	if (input->isKeyDown('1'))
	{
		ActiveCamera = &camera1;//set the active camera to the first floor one
		input->SetKeyUp('1');
	}

	if (input->isKeyDown('2'))
	{
		ActiveCamera = &camera2;//set the active camera to the second floor one
		input->SetKeyUp('2');
	}

	if (input->isKeyDown('3'))
	{
		ActiveCamera = &camera3;//set the active camera to the third floor one
		input->SetKeyUp('3');
	}

	if (input->isKeyDown('4'))
	{
		ActiveCamera = &camera4;//set the active camera to the basement one
		input->SetKeyUp('4');
	}

	if (input->isKeyDown('5'))
	{
		ActiveCamera = &camera5;//set the active camera to the basement one
		input->SetKeyUp('5');
	}

	//Control Day/Night
	if (input->isKeyDown('p'))
	{
		Pause = true;
	}
	else
	{
		Pause = false;
	}
}

void Scene::update(float dt)
{
	// update scene related variables.
	glutWarpPointer(width / 2, height / 2); //reset pointer back to the center of the screen every frame
	Cursor = { input->getMouseX(),input->getMouseY() }; //reset the values of the curor each frame

	if (MovementToggle)
	{
		camera0.update(dt); //update the camera
	}
	camera5.update(dt);

	MovementToggle = false;
	if (!Pause)
	{
		Orbit += 10 * dt; //increase the day cycle
	}
		
	//---- CAMERA----
	if (ActiveCamera == &camera5)
	{
		//Spining camera
		camera5.RotateCameraYaw(0.25);
	}

	// Calculate FPS for output
	calculateFPS();
}

void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	Vector3 CameraPosition = ActiveCamera->GetPosition();
	Vector3 CameraLookAt = ActiveCamera->GetLookAt();
	Vector3 CameraUpAxis = ActiveCamera->GetUpAxis();

	gluLookAt(CameraPosition.x, CameraPosition.y, CameraPosition.z,
		CameraLookAt.x, CameraLookAt.y, CameraLookAt.z,
		CameraUpAxis.x, CameraUpAxis.y, CameraUpAxis.z);

	//Lighting--------
	glEnable(GL_LIGHTING);
		//set lighting variables

		//day/Night cycle
	glPushMatrix();//origin
		 //rotate around the Z axis by 10' * dt every frame
		glRotatef(Orbit, 0, 0, 1);
			glPushMatrix();//light 0 sun
				glTranslatef(0, 10, 0);				
				GLfloat Light_Ambient[] = { 0.2f,0.2f,0.2f,1.0f };
				GLfloat Light_Diffuse[] = { 0.80f,0.75f,0.75f,1.0f };
				GLfloat Light_Specular[] = { 1.0f,1.0f,1.0f,1.0f };
				GLfloat Light_Position[] = { 0.0f, 0.0f, 0.0f,1.0f };
				GLfloat LightDirection[] = { 0.0f,0.0,-1.0f,1.0f };

				glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
				glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
				glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

				glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
				glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
				glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, LightDirection);
				glEnable(GL_LIGHT0);
			glPopMatrix();

		glPushMatrix();	//light 1 moon
			glTranslatef(0, -10, 0);
			GLfloat Light_Diffuse1[] = { 0.25f,0.25f,0.35f,1.0f };
			GLfloat LightDirection1[] = { 0.0f,0.0,1.0f,1.0f };

			glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
			glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.2);
			glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);

			glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse1);
			glLightfv(GL_LIGHT1, GL_POSITION, Light_Position);
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);
			glEnable(GL_LIGHT1);
		glPopMatrix();
	glPopMatrix();

		//light 2 floor 1	
		GLfloat Light_Position2[] = { 0.0f, 1.0f, 0.0f,1.0f };
		GLfloat LightDirection2[] = { 0.0f,-1.0,0.0f,1.0f };

		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT2, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, Light_Diffuse);
		glLightfv(GL_LIGHT2, GL_POSITION, Light_Position2);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, LightDirection2);
		
		//light 3 floor 2
		GLfloat Light_Position3[] = { -0.25f, 3.0f, 0.0f,1.0f };
		GLfloat LightDirection3[] = { 0.0f,-1.0,0.0f,1.0f };

		glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT3, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT3, GL_DIFFUSE, Light_Diffuse);
		glLightfv(GL_LIGHT3, GL_POSITION, Light_Position3);
		glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, LightDirection3);

		//light 4 floor 3
		GLfloat Light_Position4[] = { -0.5f, 4.5f, 0.0f,1.0f };
		GLfloat LightDirection4[] = { 0.0f,-1.0,0.0f,1.0f };

		glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT4, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT4, GL_DIFFUSE, Light_Diffuse);
		glLightfv(GL_LIGHT4, GL_POSITION, Light_Position4);
		glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, LightDirection4);

		//light 5 basement
		GLfloat Light_Diffuse5[] = { 1.0f,0.0f,1.0f,1.0f };
		GLfloat Light_Position5[] = { 0.5f, -3.4, -0.50f,1.0f };
		GLfloat LightDirection5[] = { 0.0f,0.0,1.0f,0.0f };

		glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT5, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT5, GL_DIFFUSE, Light_Diffuse5);
		glLightfv(GL_LIGHT5, GL_POSITION, Light_Position5);
		glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, LightDirection5);

		//light 6 natsu
		GLfloat Light_Diffuse6[] = { 0.5f,0.0f,0.0f,1.0f };
		GLfloat Light_Position6[] = { -4.0, 4.0, 8.0,1.0f };
		GLfloat LightDirection6[] = { 0.0f,0.0,-1.0f};
		GLfloat Cutoff[] = { 25.0f };
		GLfloat Exponent[] = { 50.0f };

		glLightfv(GL_LIGHT6, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT6, GL_DIFFUSE, Light_Diffuse6);
		glLightfv(GL_LIGHT6, GL_POSITION, Light_Position6);
		glLightfv(GL_LIGHT6, GL_SPOT_CUTOFF, Cutoff);
		glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, LightDirection6);
		glLightfv(GL_LIGHT6, GL_SPOT_EXPONENT, Exponent);

		glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.0);

		//light 7 gray
		GLfloat Light_Diffuse7[] = { 0.0f,0.0f,0.35f,1.0f };
		GLfloat Light_Position7[] = { -4.5, 0.25, 8.75,1.0f };
		GLfloat LightDirection7[] = { 1.0f,0.0,0.0f};

		glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.2);
		glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.0);

		glLightfv(GL_LIGHT7, GL_AMBIENT, Light_Ambient);
		glLightfv(GL_LIGHT7, GL_DIFFUSE, Light_Diffuse7);
		glLightfv(GL_LIGHT7, GL_POSITION, Light_Position7);
		glLightfv(GL_LIGHT7, GL_SPOT_CUTOFF, Cutoff);
		glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, LightDirection7);
		glLightfv(GL_LIGHT7, GL_SPOT_EXPONENT, Exponent);


		//-----=SKYBOX=------
	glPushMatrix();
		//translate to camera position
		glTranslatef(ActiveCamera->GetPosition().x, ActiveCamera->GetPosition().y, ActiveCamera->GetPosition().z + 1);
		//disable depth test and lighting
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		//draw skybox
		skybox.renderSky(-0.5, -0.5, -0.5, 1);
		//enable depth test and lighting
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
	//pop matrix
	glPopMatrix();

	//draw the rest of the scene

	// Render geometry/scene here -------------------------------------
	
	//Models
	glPushMatrix();
		//Render floor 1 && outter walls
		glEnable(GL_LIGHT2);
		for (int i = -8; i < 8; i += 1)
		{
			for (int j = -11; j < 11; j += 1)
			{
				if ((i >= -4 && i < 3) && (j >= -7 && j < 7)) //inside the building boundary
				{
					if ((i >= -3 && i < 2) && (j >= -6 && j < 6)) //inside the building
					{
						ProRender.renderPlane(i, 0.0f, j, 1, WoodTexture);						
					}
					else if (i==-1 && j==6) //door
					{
						glScalef(1, 1.25, 1);
						ProRender.renderCube(i, 0.0f, j, 1, DoorTexture);
						glScalef(1, 0.8, 1);
					}//render the walls
					else
					{
						glScalef(1, 0.25, 1);
						ProRender.renderCube(i, 0.0f, j, 1, BrickTexture);
						glScalef(1, 4, 1);
						glTranslatef(0, 0.25, 0);
						if (i % 2 != 0 || j % 2 != 0)
						{
							ProRender.renderCube(i, 0.0f, j, 1, PaintTexture);
						}
						else
						{
							ProRender.renderCube(i, 0.0f, j, 1, WindowTexture);
						}						
						glTranslatef(0, -0.25, 0);
					}
				}
				else if((i >= -5 && i < 5) && (j >= -9 && j < 8) )
				{

					ProRender.renderPlane(i, 0.0f, j, 1, StoneTexture);
					glScalef(0.9, 0.9, 0.9);
					if (i != 3 && j!=6)//prevent duplicate pillars
					{					
						glTranslatef(i, 1, j);
						glRotatef(90, 1, 0, 0);
						glScalef(0.10, 0.10, 0.10);
						ProRender.RenderCylinder(10, 10);
						glScalef(10, 10, 10);
						glRotatef(-90, 1, 0, 0);
						glTranslatef(-i, -1, -j);
					}
					else if ((i==-5 && j == 6) || (i==4 && j == 6)) //render the special cases
					{
						glTranslatef(i, 1, j);
						glRotatef(90, 1, 0, 0);
						glScalef(0.10, 0.10, 0.10);
						ProRender.RenderCylinder(10, 10);
						glScalef(10, 10, 10);
						glRotatef(-90, 1, 0, 0);
						glTranslatef(-i, -1, -j);

					}
					glScalef(1.111111111111111, 1.111111111111111, 1.111111111111111);
				}
				else//render the stone outside
				{
					ProRender.renderPlane(i, 0.0f, j, 1, StoneTexture);
				}
			}
		}
	glPopMatrix();

	glPushMatrix(); //at origin	
	//Floor 1 roof----------

		glPushMatrix();//render right roof
			glTranslatef(2, 2.25, 5);
			glRotatef(315, 0, 0, 1);
			glScalef(2, 1, 12);
			ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
		glPopMatrix();
			
		glPushMatrix();//render rear roof
			glTranslatef(-3, 2.25, -7);
			glRotatef(315, 1, 0, 0);
			glScalef(5, 1, 2);
			ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
		glPopMatrix();
		glPushMatrix();//render left roof
			glTranslatef(-4.425, 0.84, 5);
			glRotatef(45, 0, 0, 1);
			glScalef(2, 1, 12);
			ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
		glPopMatrix();

		glPushMatrix();//render front roof
			glTranslatef(-3, 0.84, 6.415);
			glRotatef(45, 1, 0, 0);
			glScalef(5, 1, 2);
			ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
		glPopMatrix();

	glPopMatrix();

	//Banners
	glPushMatrix();
		glTranslatef(-1, 5.25, 4.01);
		glRotatef(270, 1, 0, 0);
		glScalef(2, 1, 2);
		ProRender.renderPlane(0, 0, 0, 0.5, FairyTailBannerTexture);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-2, 5.25, 4.01);
		glRotatef(270, 1, 0, 0);
		glScalef(2, 1, 2);
		ProRender.renderPlane(0, 0, 0, 0.5, OracienSiesBannerTexture);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 5.25, 4.01);
		glRotatef(270, 1, 0, 0);
		glScalef(2, 1, 2);
		ProRender.renderPlane(0, 0, 0, 0.5, BluePegasusBannerTexture);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0, 1.25, 0);
		//Render floor 2 && upper walls
		glEnable(GL_LIGHT3);
		for (int i = -3; i < 2; i += 1)
		{
			for (int j = -6; j < 6; j += 1)
			{
					if ((i >= -2 && i < 1) && (j >= -5 && j < 5)) //inside the building
					{
						ProRender.renderPlane(i, 0.0f, j, 1, WoodTexture);

					}
					else //render the walls
					{
						ProRender.renderCube(i, 0.0f, j, 1, PaintTexture);
						ProRender.renderCube(i, 1.0f, j, 1, WindowTexture);
					
					}			
			}
		}
	glPopMatrix();

	//Floor 2 roof----------
	glPushMatrix();//render right roof
		glTranslatef(1, 4.25, 4);
		glRotatef(315, 0, 0, 1);
		glScalef(2, 1, 10);
		ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
	glPopMatrix();

	glPushMatrix();//render rear roof
		glTranslatef(-2, 4.25, -6);
		glRotatef(315, 1, 0, 0);
		glScalef(3, 1, 2);
		ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
	glPopMatrix();
	glPushMatrix();//render left roof
		glTranslatef(-3.4, 2.85, 4);
		glRotatef(45, 0, 0, 1);
		glScalef(2, 1, 10);
		ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
	glPopMatrix();

	glPushMatrix();//render front roof
		glTranslatef(-2, 2.85, 5.5);
		glRotatef(45, 1, 0, 0);
		glScalef(3, 1, 2);
		ProRender.renderPlane(0, 0, 0, 1, RoofTileTexture);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 3.25, 0);
		//Render floor 3 && top walls
		glEnable(GL_LIGHT4);
		for (int i = -2; i < 1; i += 1)
		{
			for (int j = -5; j < 5; j += 1)
			{
				if ((i >= -1 && i < 0) && (j >= -4 && j < 4)) //inside the building
				{
					ProRender.renderPlane(i, 0.0f, j, 1, WoodTexture);					
				}
				else //render the walls
				{
				
					ProRender.renderCube(i, 0.0f, j, 1, PaintTexture);
					ProRender.renderCube(i, 1.0f, j, 1, WindowTexture);			
				
				}
			}
		}		
	glPopMatrix();

	//--=MATERIALS=------
	//set material variables
	GLfloat no_mat[] = { 0.0f,0.0f,0.0f,0.0f };
	GLfloat mat_ambient_colour[] = { 0.8f,0.8f,0.8f,1.0f };
	GLfloat mat_diff_gold[] = { 0.63f,0.49f,0.02f,1.0f };

	GLfloat mat_specular[] = { 1.0f,1.0f,1.0f,1.0f };
	GLfloat high_shininess[] = { 100 };
	
	//Sphere on the roof
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
		glTranslatef(-0.5, 6, 0);
		glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,mat_diff_gold);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
		ProRender.RenderSphere(20); 
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient_colour);
	glPopMatrix();

	//Create skylight
	glPushMatrix();
	glTranslatef(0, 3.25, 0);
		for (int i = -1; i < 0; i += 1)
	{
		for (int j = -4; j < 4; j += 1)
		{
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_LIGHTING);
			glEnable(GL_BLEND);
			glColor4f(0.50f, 0.50f, 0.75f, 0.2f);
			glBegin(GL_TRIANGLES);
			//set normal
			glNormal3f(0.0f, 1.0f, 0.0f);
			//draw plane
			glTexCoord2f(0, 1);
			glVertex3f(i, 2.0, j - 1);
			glTexCoord2f(0, 0);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(i, 2.0, j);
			glTexCoord2f(1, 0);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(i + 1, 2.0, j);

			glTexCoord2f(1, 0);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(i + 1, 2.0, j);
			glTexCoord2f(1, 1);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(i + 1, 2.0, j - 1);
			glTexCoord2f(0, 1);
			glNormal3f(0.0f, 1.0f, 0.0f);
			glVertex3f(i, 2.0, j - 1);
			glEnd();
			glColor4f(1.0, 1.0, 1.0, 1.0);
			glDisable(GL_BLEND);
			glEnable(GL_LIGHTING);
		}
	}
		glPopMatrix();

	//render basement
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
	glPushMatrix();
		glEnable(GL_TEXTURE_2D); //activate the texture
		glBindTexture(GL_TEXTURE_2D, BlackTexture); //tell opengl which texture I want
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glScalef(0.5, 0.5, 0.5);
		glTranslatef(0, -4.01, 2);
		glScalef(8, 4, 14);
		Shapes.render2(); //render a cube using an vertex arrays
	glPopMatrix();

	glPushMatrix();
		glEnable(GL_TEXTURE_2D); //activate the texture
		glBindTexture(GL_TEXTURE_2D, StonePillarTexture); //tell opengl which texture I want
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTranslatef(0, -4, -4);
		glScalef(2, 0.5, 4);
		ProRender.RenderCylinder(6,3);
	glPopMatrix();

	glPushMatrix();//floating stone tablets
		glTranslatef(0.5f, -1.6, -3.10f);
		glPushMatrix();	
				glTranslatef(2, 0, 0);
				glRotatef(Orbit, 0, 1, 0);
				glRotatef(270, 1, 0, 0);
				glRotatef(25, 0, 1, 0);
				glScalef(1, 0.5, 1);
				ProRender.renderCube(0, 0, 0, 0.5, FloatingStoneTexture);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-2, 0, 0);
				glRotatef(Orbit, 0, 1, 0);
				glRotatef(270, 1, 0, 0);
				glRotatef(335, 0, 1, 0);
				glScalef(1, 0.5, 1);
				ProRender.renderCube(0, 0, 0, 0.5, FloatingStoneTexture);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(4, 0, 0);
				glRotatef(Orbit, 0, 1, 0);
				glRotatef(270, 1, 0, 0);
				glRotatef(25, 0, 1, 0);
				glScalef(1, 0.5, 1);
				ProRender.renderCube(0, 0, 0, 0.5, FloatingStoneTexture);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-5, 0, 0);
				glRotatef(Orbit, 0, 1, 0);
				glRotatef(270, 1, 0, 0);
				glRotatef(335, 0, 1, 0);
				glScalef(1, 0.5, 1);
				ProRender.renderCube(0, 0, 0, 0.5, FloatingStoneTexture);
			glPopMatrix();
	glPopMatrix();

	for (int i = -1; i < 4; i+=2)
	{
		glPushMatrix();
			glEnable(GL_TEXTURE_2D); //activate the texture
			glBindTexture(GL_TEXTURE_2D, PurpleTexture); //tell opengl which texture I want
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTranslatef(-1, -2.35, i +2);
			glRotatef(30, 0, 1.5, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(0.10, 0.10, 0.20);
			ProRender.RenderCylinder(4, 7);
		glPopMatrix();

		glPushMatrix();
			glEnable(GL_TEXTURE_2D); //activate the texture
			glBindTexture(GL_TEXTURE_2D, PurpleTexture); //tell opengl which texture I want
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTranslatef(1, -2.35, i+2);
			glRotatef(30, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(0.10, 0.10, 0.20);
			ProRender.RenderCylinder(4, 7);
		glPopMatrix();
	}

	glBindTexture(GL_TEXTURE_2D, PurpleTexture); //tell opengl which texture I want
	glDisable(GL_TEXTURE_2D);

	//Mirror trick With Mavis in the crystal

	//turn off writing to the frame buffer
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	//enable the stencil test
	glEnable(GL_STENCIL_TEST);
	//set the stencil function to always pass
	glStencilFunc(GL_ALWAYS, 1, 1);
	//set the stencil operation to replace values when the test passes
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	//Disable the depth test (we don't want to store depths values while writing to the stencil buffer)
	glDisable(GL_DEPTH_TEST);
	//draw floor object
	glPushMatrix(); // remember were we are, The origin
		glTranslatef(0.5f, -3.6, -3.10f);
		glRotatef(45, 0, 1, 0);
		glScalef(0.02, 0.02, 0.02);
		Crystal.render();
	glPopMatrix(); //return to the origin

	//enable the depth test
	glEnable(GL_DEPTH_TEST);
	//turn on rendering to the frame buffer
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	//set stencil function to test if the value is 1
	glStencilFunc(GL_EQUAL, 1, 1);
	//set the stencil operation to keep all values(we don't want to change the stencil)
	glStencilOp(GL_TRUE, GL_TRUE, GL_TRUE);

	//MIRROR WORLD!

	glPushMatrix(); //draw object in "mirror"
		glTranslatef(0.1f, -3.0, -3.035);
		glEnable(GL_TEXTURE_2D); //activate the texture
		glBindTexture(GL_TEXTURE_2D, MikuIzayoiTexture); //tell opengl which texture I want
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glScalef(0.009, 0.009, 0.008);
		MikuIzayoi.render();
	glPopMatrix();	//return to the origin

	//disable stencil test(no longer needed)
	glDisable(GL_STENCIL_TEST);
	//enable alpha blending (to combine the floor object with model)
	glEnable(GL_BLEND);

	//disable texture
	glDisable(GL_TEXTURE_2D);
	//disable lighting (100% reflective object)
	glDisable(GL_LIGHTING);
	//set colour of floor object
	glColor4f(0.75f, 0.0f, 0.75f, 0.2f);

	//draw floor object
	glPushMatrix(); // remember were we are, The origin
		glTranslatef(0.5f, -3.6, -3.10f);
		glRotatef(45, 0, 1, 0);
		glScalef(0.02, 0.02, 0.02);
		Crystal.render();
	glPopMatrix(); //return to the origin

	//enable lighting (rest of scene is lit correctly)
	glEnable(GL_LIGHTING);
	//disable blend (no longer blending)
	glDisable(GL_BLEND);

	glDisable(GL_LIGHT5);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT6);

	//----------=Render models=--------------
	glEnable(GL_TEXTURE_2D);

	glPushMatrix(); //Acnologia model and shadow
		glPushMatrix();
			glTranslatef(-5, 3, 7);
			glScalef(0.05, 0.05, 0.05);
			glRotatef(65, 0, 1, 0);
			glBindTexture(GL_TEXTURE_2D, Body1Texture); //tell opengl which texture I want
			AcnologiaBody.render();
			glBindTexture(GL_TEXTURE_2D, Body2Texture); //tell opengl which texture I want
			AcnologiaBody2.render();
			glBindTexture(GL_TEXTURE_2D, WingsTexture); //tell opengl which texture I want
			AcnologiaWings.render();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-7, 0.01, 8);
			glScalef(3, 1,3 );
			glEnable(GL_BLEND);
			ProRender.renderPlane(0, 0, 0, 1, ShadowTexture);
			glDisable(GL_BLEND);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Lucy model and shadow
		glPushMatrix();
			glTranslatef(-2, 0, 8.5);
			glRotatef(250, 0, 1, 0);
			glScalef(0.015, 0.015, 0.015);
			glBindTexture(GL_TEXTURE_2D, LucyTexture); //tell opengl which texture I want
			Lucy.render();		
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.25, 0.01,8.75);
			glScalef(0.5, 1, 0.5);
			glEnable(GL_BLEND);
			ProRender.renderPlane(0, 0, 0, 1, ShadowTexture);
			glDisable(GL_BLEND);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Natsu model and shadow
		glTranslatef(-4, 4, 6.5);
		glPushMatrix();			
			glRotatef(10, 0, 1, 0);
			glRotatef(15, 1, 0, 0);
			glScalef(0.015, 0.015, 0.015);
			glBindTexture(GL_TEXTURE_2D, NatsuTexture); //tell opengl which texture I want
			Natsu.render();			
		glPopMatrix();

		glPushMatrix();
			glEnable(GL_TEXTURE_2D); //activate the texture
			glBindTexture(GL_TEXTURE_2D, FlameTexture); //tell opengl which texture I want
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glRotatef(15, 1, 0, 0);
			glScalef(0.0375, 0.025, 0.0375);
			glTranslatef(0, -1, 0);
			Shapes.render2(); //render a cube using an vertex arrays
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Gray model and shadow
		glEnable(GL_LIGHT7);
		glTranslatef(-3.5, 0, 8.5);
		glPushMatrix();
			glRotatef(250, 0, 1, 0);
			glScalef(0.015, 0.015, 0.015);
			glBindTexture(GL_TEXTURE_2D, GrayTexture); //tell opengl which texture I want
			Gray.render();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.25, 0.01, 0.25);
			glScalef(0.5, 1, 0.5);
			glEnable(GL_BLEND);
			ProRender.renderPlane(0, 0, 0, 1, ShadowTexture);
			glDisable(GL_BLEND);
		glPopMatrix();
	glPopMatrix();

	//floor 1 models
	glPushMatrix();
		//(i >= -3 && i < 2)
		glPushMatrix(); //tables
			glTranslatef(0, 0.1, -1);
			for (int i = -2; i < 2; i+=3)//this is X coordinate
			{
				for (int j = 1 ; j < 5; j++) //this is Y coordinate in a 2D world
				{
					glPushMatrix();
					glTranslatef(i, 0.05, j );
					glScalef(0.25, 0.125, 0.25);
					glBindTexture(GL_TEXTURE_2D, TableTexture); //tell opengl which texture I want
					Table.render();
					glPopMatrix();
				}			
			}		
		glPopMatrix();

		glPushMatrix();//bar
			glTranslatef(1, 0.1, -1);
			glScalef(0.75, 0.5, 0.5);
			glRotatef(270, 0, 1, 0);
			Bar.render();
		glPopMatrix();
	glPopMatrix();
	//floor 2 models
	glPushMatrix();
		glTranslatef(0.5, 1.6, 0);
		glPushMatrix(); //tables
			glTranslatef(0, 0, -1);
			for (int i = -4; i < 5; i +=2)//this is X coordinate
			{
				for (int j = -2; j < 1; j+=1.2) //this is Y coordinate in a 2D world
				{
					glPushMatrix();
					glRotatef(90, 0, 1, 0);
						glTranslatef(i, 0.05, j);
						glScalef(0.0095, 0.0125, 0.0095);
						glBindTexture(GL_TEXTURE_2D, ClothTexture); //tell opengl which texture I want
						Bed.render();
					glRotatef(90, 0, -1, 0);
					glPopMatrix();
				}
			}
		glPopMatrix();
		for (int i = -5; i < 5; i++)
		{
			glPushMatrix();
				glTranslatef(-1, -0.25, i);
				glRotatef(90, 0, 1, 0);
				glScalef(0.0125, 0.00625, 0.0125);
				glBindTexture(GL_TEXTURE_2D, ClothTexture);
				Divider.render();
			glPopMatrix();
		}

	glPopMatrix();

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT6);
	glDisable(GL_LIGHT7);
	//floor 3 models
	glPushMatrix();
		glTranslatef(-0.2, 3.25, 0);
		glPushMatrix();
			glTranslatef(-0.2, -0.05, 2);
			glRotatef(180, 0, 1, 0);
			glScalef(0.000625, 0.000625, 0.000625);
			glBindTexture(GL_TEXTURE_2D, WoodTexture);
			Desk.render();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-0.35, 0.1, -2.5);
			glRotatef(90, 0, 1, 0);
			glScalef(0.0125, 0.00625, 0.0125);
			glBindTexture(GL_TEXTURE_2D, FairyTailBannerTexture);
			PoolTable.render();
		glPopMatrix();
	glPopMatrix();
	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);	
}

// Calculates FPS
void Scene::calculateFPS()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
	
	sprintf_s(Controls,"Controls: WASD, Move camera 0");
	displayText(-1.f, 0.84f, 1.f, 0.f, 0.f, Controls);
	sprintf_s(RotationControls, "Rotation:IJKLUO, Rotate camera 0");
	displayText(-1.f, 0.78f, 1.f, 0.f, 0.f, RotationControls);
	sprintf_s(CameraControl, "Camera's:012345, to swap");
	displayText(-1.f, 0.72f, 1.f, 0.f, 0.f, CameraControl);
	sprintf_s(PlayerInteraction, "p pauses the day/night cycle. f/t change camera type");
	displayText(-1.f, 0.67f, 1.f, 0.f, 0.f, PlayerInteraction);
	sprintf_s(EscInteraction, "Esc to quit");
	displayText(-1.f, 0.62f, 1.f, 0.f, 0.f, PlayerInteraction);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
