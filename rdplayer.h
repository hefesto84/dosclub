#include <allegro.h>
#include "rdmap.h"
#include "rdconstants.h"

class RDPlayer
{
private:
	BITMAP *data;
	BITMAP *buffer;
	bool isScrollRequired;
	int scroll_x;
	int scroll_y;
	char tile_position_text[25];

public:
	int x;
	int y;
	int rx;
	int ry;
	int speed;
	RDPlayer(BITMAP *data, BITMAP *buffer, int x, int y);
	void Update(RDMap *map, int& offset_x, int& offset_y);
	bool TryGetScrollRequired(int& scroll_x, int& scroll_y);
	void Render();
	void RenderDebug();
};