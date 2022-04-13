#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

// d3d9.h is needed for the Direct3D logic
#include <d3d9.h>

class GraphicsDevice
{
public:
	GraphicsDevice();
	~GraphicsDevice();
	//Direct 3D functions
	bool Initialize(HWND hwnd, bool windowed);
	void Clear(D3DCOLOR color);
	void Begin();
	void End();
	void Present();

	//Public Pointers
	LPDIRECT3DDEVICE9 device;
private:
	//Private Pointers
	LPDIRECT3D9 direct3d;
};

#endif /* GRAPHICSDEVICE_H */