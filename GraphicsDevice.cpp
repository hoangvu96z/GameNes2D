#include "GraphicsDevice.h"

GraphicsDevice::GraphicsDevice()
{
	// Constructor
}

bool GraphicsDevice::Initialize(HWND hwnd, bool windowed)
{
	//Create Direct 3D Pointer
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS presentationParams;
	ZeroMemory(&presentationParams, sizeof(presentationParams));
	presentationParams.Windowed = windowed; //Boolean determines if we are running in Windowed mode.
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD; //fastest
	presentationParams.hDeviceWindow = hwnd; //use the window we set up
	
	//create the device
	//D3DADAPTER_DEFAULT = Primary display adapter (default graphics card)
	//D3DDEVTYPE_HAL = Hardware rasterization
	//D3DCREATE_MIXED_VERTEXPROCESSING = Uses both hardware and software for 3D calculations
	if(!SUCCEEDED(direct3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,
		hwnd, D3DCREATE_MIXED_VERTEXPROCESSING, &presentationParams, 
		&device)))
	{
		return false;
	}

	return true;
}

void GraphicsDevice::Clear(D3DCOLOR color)
{
	//2nd param 'NULL' clears the entire back buffer.
	device->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}

void GraphicsDevice::Begin()
{
	device->BeginScene();
}

void GraphicsDevice::End()
{
	device->EndScene();
}

void GraphicsDevice::Present()
{
	//Present our scene to the window.
	device->Present(NULL, NULL, NULL, NULL);
}

GraphicsDevice::~GraphicsDevice()
{
	if(device)
	{
		device->Release();
		device = 0;
	}

	if(direct3d)
	{
		direct3d->Release();
		direct3d = 0;
	}
}