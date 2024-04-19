#include <allegro.h>

class RDEngine
{
private:
	bool isQuit;
	int width;
	int height;
	short offset_x;
	short offset_y;
	short max_offset_x;
	short max_offset_y;
	short movement_speed;
	BITMAP* tiles;
	BITMAP* buffer;
	char debug_buffer[256];
	void initBuffer();
	void move_window();
	void correct_window_coordinates();
public:
	RDEngine();
	void Setup(int width, int height);
	bool ShouldClose();
	void Rest(int milliseconds);
	void Update();
	void Render();
};