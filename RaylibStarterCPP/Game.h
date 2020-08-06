#pragma once

#include "raylib-cpp.hpp"

#include <string>

class Game
{
public:
	Game();
	~Game();

	void Initalise();

	void Run();

	void Update(float deltaTime);

	void Draw();

	void Close();

private:

	raylib::Window* window;

	raylib::Color bgColour = RAYWHITE;

	unsigned int screenWidth = 640;
	unsigned int screenHeight = 480;

	char current = 'A';
	int charTime = 10;
	int timer = 0;

	bool hasAlreadyInput = false;

	std::string input;
};
