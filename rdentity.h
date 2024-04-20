#include <allegro.h>
#include "rdconstants.h"

class RDEntity
{
private:
	BITMAP *data;
	BITMAP *buffer;
public:
	int x;
	int y;
	int tile_x;
	int tile_y;
	RDEntity(BITMAP *data, BITMAP *buffer, int tile_x, int tile_y, int x, int y);
	void Update(int x, int y);
	void Render();
};