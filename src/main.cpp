#include <raylib.h>
#include "../assets/lonelyBoxColors.cpp"

typedef struct WindowSize {
	float windowWidth;
	float windowHeight;

	WindowSize(float val_windowWidth = 0, float val_windowHeight = 0) : windowWidth(val_windowWidth), windowHeight(val_windowHeight) {}
} WindowSize;

WindowSize GetRelativeWindowSize(float screenPercentage)
{
	// get our monitor size
	const int monitorWidth = GetMonitorWidth(0);
	const int monitorHeight = GetMonitorHeight(0);

	// get the proper window sizes for the game
	const int screenWidth = (int)(monitorWidth * screenPercentage);
	const int screenHeight = (int)(monitorHeight * screenPercentage);

	WindowSize gameSize = {GetMonitorWidth(0) * screenPercentage, GetMonitorHeight(0) * screenPercentage};

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	return gameSize;

}

int main(void)
{
    // get window consts
    const WindowSize SCREEN_SIZE = GetRelativeWindowSize(80);
    const int SCREEN_WIDTH = SCREEN_SIZE.windowWidth;
    const int SCREEN_HEIGHT = SCREEN_SIZE.windowHeight;
    const char* SCREEN_NAME = "lonelyBox";

    const int TITLE_RECT_WIDTH = SCREEN_WIDTH / 1.5;
    const int TITLE_RECT_HEIGHT = SCREEN_HEIGHT / 3;

    // initialize context
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_NAME);

    // set the fps
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose())
    {


        BeginDrawing();

        // clear background before drawing anything
        ClearBackground(DARKGRAY);

        DrawText("lonelyBox", 90, 200, 100, PINK);

        DrawRectangle(SCREEN_WIDTH - TITLE_RECT_WIDTH, SCREEN_HEIGHT - TITLE_RECT_HEIGHT, TITLE_RECT_WIDTH, TITLE_RECT_HEIGHT, SEWERGROUND);

        EndDrawing();
    }


    CloseWindow();
    return 0;
}
