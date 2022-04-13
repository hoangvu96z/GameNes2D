#include "Camera.h"
#include "GraphicsDevice.h"

Camera::Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors)
{
	this->width = width;
	this->height = height;
	this->angle = angle;
	this->scaleFactors = scaleFactors;

	D3DXMatrixOrthoLH(&orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
	cameraX = this->width / 2;
	cameraY = this->height / 2;
}

Camera::~Camera()
{
}

void Camera::Update(float gameTime)
{
	int speed = 10;
	D3DXVECTOR3 velocity;
	D3DXVECTOR3 movementVector(0, 0, 0);

	if (GetAsyncKeyState(VK_UP))
	{
		if (cameraY >= height / 2)
			cameraY -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (cameraY <= 875 - height / 2)
			cameraY += speed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (cameraX >= width / 2)
			cameraX -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (cameraX <= 1103 - width / 2)
			cameraX += speed;
	}

	//cameraY = 0;
	this->viewMatrix = D3DXMATRIX(
		scaleFactors.x * cos(angle), scaleFactors.x * sin(angle), 0, 0,
		-scaleFactors.y * sin(angle), scaleFactors.y * cos(angle), 0, 0,
		0, 0, scaleFactors.z, 0,
		-cameraX * scaleFactors.x * cos(angle) + cameraY * scaleFactors.y * sin(angle), -cameraX * scaleFactors.y * sin(angle) - cameraY * scaleFactors.y * cos(angle), 0, 1
	);
}

void Camera::HandleInput()
{
	
}


void Camera::SetTransform(GraphicsDevice* gDevice) const
{
	gDevice->device->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	gDevice->device->SetTransform(D3DTS_WORLD, &identityMatrix);
	gDevice->device->SetTransform(D3DTS_VIEW, &viewMatrix);
}






