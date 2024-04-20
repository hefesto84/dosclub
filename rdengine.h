#include <allegro.h>
#include "rdviewport.h"
#include "rdplayer.h"
#include "rdentity.h"

class RDEngine
{
private:
	int screen_width;
	int screen_height;
	int buffer_width;
	int buffer_height;
	int offset_x;
	int offset_y;
	int tile_width;
	int tile_height;
	bool isQuit;

	BITMAP *buffer;
	BITMAP *tiles;
	BITMAP *playerTile;
	BITMAP *entityTile;
	RDViewport *viewport;
	RDPlayer *player;
	RDEntity *entity;

	void init_viewport();
	void init_player();
	void try_move_player();
	void init_entity();

public:
	RDEngine();
	void Init(int width, int height);
	bool ShouldClose();
	void Rest(int milliseconds);
	void Update();
	void Render();
};