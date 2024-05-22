#include <iostream>
#include "Application.hpp"

int main(int argc, char* args[]) {
	Application app;

	app.loop();
	app.draw();

	return 0;
}