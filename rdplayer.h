#include <allegro.h>
#include "rdconstants.h"

class RDPlayer
{
private:
	BITMAP *data;
	BITMAP *buffer;
	char tile_position_text[25];

public:
	int x;
	int y;
	int rx;
	int ry;
	int speed;
	RDPlayer(BITMAP *data, BITMAP *buffer, int x, int y);
	void Render();
	void RenderDebug();
};