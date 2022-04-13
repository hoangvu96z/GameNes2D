#include "Game.h"

Game::Game()
{
	// Constructor
}

bool Game::Initialize(HWND hWnd, int width, int height)
{
	gDevice = new GraphicsDevice();
	if(!gDevice->Initialize(hWnd, true))
	{
		return false;
	}

	camera = new Camera(width, height, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

	background = new GameSprite(0, 0);
	if(!background->Initialize(gDevice->device, "map.png", 1103, 875))
	{
		return false;
	}


	gameTime = new GameTime();
	if(!gameTime->Initialize())
	{
		return false;
	}

	return true;
}

void Game::Run()
{
	//Get game time then update + draw
	gameTime->Update();

	Update(gameTime->elapsedTime);
	Draw(gameTime->elapsedTime);
}

void Game::Update(float gameTime)
{
	if(GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}

	if(camera)
	{
		camera->Update(gameTime);
	}
}

void Game::Draw(float gameTime)
{
	//Simple RGB value for the background so use XRGB instead of ARGB.
	gDevice->Clear(D3DCOLOR_XRGB(0,100,100));
	gDevice->Begin();

	if(camera)
	{
		camera->SetTransform(gDevice);
	}

	if (background && background->IsInitialized()) background->Draw(gameTime);

	gDevice->End();
	gDevice->Present();
}

Game::~Game()
{
	if (camera) { delete camera; camera = nullptr; }
	if (background) { delete background; background = nullptr; }
	if(gDevice) { delete gDevice; gDevice = nullptr; }
	if(gameTime) { delete gameTime; gameTime = nullptr; }
}