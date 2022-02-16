#pragma once

//include neccesary files
#include "Vector3.h";

class Camera {
	//functions
public:
	//constructor for the class
	Camera();

	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);

	// Get position function
	Vector3 GetPosition();

	// Get Look at function, where the camera is looking
	Vector3 GetLookAt();

	//Get up function, gets what values are used for the Up axis
	Vector3 GetUpAxis();

	//Get Forward vector function, gets what values are used for the forward vector
	Vector3 GetForwardVector();

	//set position in the world
	void SetPosition(Vector3 NewPosition);
	

	//set position in the world
	void SetLookAt(Vector3 NewPosition);

	//function for moving around the world
	void Move(float valueX, float valueY, float valueZ, float dt);
	
	//function for rotating the camera in x
	void RotateCameraPitch(float degrees);

	//function for rotating the camera in y
	void RotateCameraYaw(float degrees);

	//function for rotating the camera in z
	void RotateCameraRoll(float degrees);
//data
private:
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Forward;
	Vector3 LookAt;
	Vector3 UpAxis;

	float Roll;
	float Pitch;
	float Yaw;
};
