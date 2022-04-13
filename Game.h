#ifndef GAME_H
#define GAME_H

#include "GraphicsDevice.h"
#include "GameSprite.h"
#include "GameTime.h"
#include "Camera.h"

class Game
{
public:
	// Constructors and Destructor
	Game();
	~Game();
	
	//Game Functions
	bool Initialize(HWND hWnd, int width, int height);
	void Run();
	void Update(float gameTime);
	void Draw(float gameTime);
private:
	Camera *camera;

	GraphicsDevice *gDevice;

	GameSprite *background;

	GameTime *gameTime;

	int width;
	int height;
};

#endif /* GAME_H */