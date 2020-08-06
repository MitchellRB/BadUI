#include "Game.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

namespace rl = raylib;

Game::Game()
{

}

Game::~Game()
{

}

void Game::Initalise()
{
	window = new rl::Window(screenWidth, screenHeight, "Raylib C++");

	window->SetTargetFPS(60);

	input = "";
}

void Game::Run()
{
	while (!window->ShouldClose())
	{
		Update(GetFrameTime());

		Draw();
	}
}

void Game::Update(float deltaTime)
{
	timer++;

	if (timer > charTime)
	{
		timer = 0;
		current++;
		hasAlreadyInput = false;
	}

	if (current == 'Z' + 1)
	{
		current = 'A';
	}
	//if (current >= 'z' + 1)
	//{
	//	current = 'A';
	//}

	if (IsKeyPressed(KEY_SPACE) && !hasAlreadyInput)
	{
		input += current;
		hasAlreadyInput = true;
	}
	if (IsKeyPressed(KEY_BACKSPACE) && input.length() > 0)
	{
		input = input.substr(0, input.length() - 1);
	}
}

void Game::Draw()
{
	window->BeginDrawing();

	bgColour.ClearBackground();

	//Draw selection
	for (char i = 'A'; i < 'Z' + 1; i++)
	{
		std::string c;
		c += i;
		DrawText(c.c_str(), (i - 'A') * 20 + 10, 100, 20, BLACK);
		if (current == i)
		{
			if (!hasAlreadyInput)
			{
				DrawRectangleLines((i - 'A') * 20 + 5, 100, 20, 20, GRAY);
			}
			else
			{
				DrawRectangle((i - 'A') * 20 + 5, 100, 20, 20, BLACK);
			}
		}
	}

	DrawText("Enter your name:", 50, 195, 20, BLACK);
	//Draw input box
	DrawRectangle(50, 220, 400, 40, LIGHTGRAY);
	DrawRectangleLines(50, 220, 400, 40, BLACK);

	DrawText(input.c_str(), 60, 230, 20, BLACK);

	window->EndDrawing();
}

void Game::Close()
{
	delete window;
}
