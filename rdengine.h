#include <allegro.h>
#include "rdconstants.h"
#include "rdviewport.h"
#include "rdplayer.h"
#include "rdentity.h"
#include "rdmap.h"

class RDEngine
{
private:
	int buffer_width;
	int buffer_height;
	int offset_x;
	int offset_y;
	int scroll_x;
	int scroll_y;
	bool isQuit;

	BITMAP *buffer;
	BITMAP *tiles;
	BITMAP *playerTile;
	RDViewport *viewport;
	RDPlayer *player;
	RDEntity **entities;
	RDMap *map;

	void init_viewport();
	void init_player();
	void init_map();
	//void try_move_player();
	void init_entities();
	void update_entities(int x, int y);
	//void update_map();
	void render_entities();
	//void render_player();
	//void render_map();
	void debug_player();

public:
	RDEngine();
	void Init();
	bool ShouldClose();
	void Rest(int milliseconds);
	void Update();
	void Render();
};
