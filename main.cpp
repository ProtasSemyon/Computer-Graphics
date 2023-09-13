#include "src/window/Window.hpp"
#include "src/modes/lines/LineDDAMode/LineDDAMode.hpp"

int main( )
{
	Window window("Test Application");
	IMode *lineDDAMode = new LineDDAMode();
	window.setMode(lineDDAMode);
	window.startMainLoop();
	return 0;
}

