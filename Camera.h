#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>
#include "GameSprite.h"

class GraphicsDevice;

class Camera
{
public:
	// Constructors and Destructor
	Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors);
	~Camera();

	//Game Functions
	void Update(float gametime);
	void HandleInput();
	void SetTransform(GraphicsDevice *gDevice) const;

private:
	float angle;
	DirectX::XMFLOAT3 scaleFactors;
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	GameSprite *following;

	int width;
	int height;
	int cameraX, cameraY;
};

#endif /* CAMERA_H */
