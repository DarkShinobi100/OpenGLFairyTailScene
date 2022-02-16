#include "camera.h";

Camera::Camera()
{
	//set default values for the camera
	Position = { 0.0f, 0.0f, 6.0f };
	Rotation = { 0.0f, 0.0f, 0.0f };//Pitch, Yaw, Roll
	LookAt = { 0.0f, 0.0f, 0.0f };
	UpAxis = { 0.0f, 1.0f, 0.0f };

	Yaw = 0.0f;
	Roll = 0.0f;
	Pitch = 0.0f;
}

void Camera::update(float dt)
{
	// update scene related variables.
	float CosR, CosP, CosY; //temp values for Sin/Cos from
	float SinR, SinP, SinY;
	//roll, pitch and Yaw are variables stored by the camera
	//handle rotation
	//only want to calculate these values once, when rotation changes, NOT every frame
	Yaw = Rotation.y;
	Pitch = Rotation.x;
	Roll = Rotation.z;

	CosY = cosf(Yaw*3.1415 / 180.f);
	CosP = cosf(Pitch*3.1415 / 180.f);
	CosR = cosf(Roll*3.1415 / 180.f);

	SinY = sinf(Yaw*3.1415 / 180.f);
	SinP = sin(Pitch*3.1415 / 180.f);
	SinR = sinf(Roll*3.1415 / 180.f);

	//this using the parametric equation of a sphere

	//calculate the three vectors to put into the Glu LookAt
	//look direction, poisition and the up vector
	//this function could also calculate the rght vector

	//forward vector
	Forward.x = SinY * CosP;
	Forward.y = SinP;
	Forward.z = CosP * -CosY;

	LookAt.x = Position.x + Forward.x;
	LookAt.y = Position.y + Forward.y;
	LookAt.z = Position.z + Forward.z;

	//Up vector
	UpAxis.x = -CosY * SinR - SinY * SinP * CosR;
	UpAxis.y = CosP * CosR;
	UpAxis.z = -SinY * SinR - SinP * CosR * -CosY;
}

Vector3 Camera::GetPosition()
{
	return Position;
}

Vector3 Camera::GetLookAt()
{
	return LookAt;
}

Vector3 Camera::GetUpAxis()
{
	return UpAxis;
}

Vector3 Camera::GetForwardVector()
{
	return Forward;
}

void Camera::SetPosition(Vector3 NewPosition)
{
	Position = NewPosition;
}

void Camera::SetLookAt(Vector3 NewPosition)
{
	LookAt = NewPosition;
}

void Camera::Move(float valueX, float valueY, float valueZ, float dt)
{
	Position.x += valueX * dt;
	Position.y += valueY * dt;
	Position.z += valueZ * dt;
}

void Camera::RotateCameraPitch(float degrees)
{
	Rotation.x += degrees;
}

void Camera::RotateCameraYaw(float degrees)
{
	Rotation.y += degrees;
}

void Camera::RotateCameraRoll(float degrees)
{
	Rotation.z += degrees;
}