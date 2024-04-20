#include <allegro.h>
#include "rdconstants.h"
#include "rdviewport.h"
#include "rdplayer.h"
#include "rdentity.h"

class RDEngine
{
private:
	int buffer_width;
	int buffer_height;
	int offset_x;
	int offset_y;
	bool isQuit;

	BITMAP *buffer;
	BITMAP *tiles;
	BITMAP *playerTile;
	//BITMAP *entityTile;
	RDViewport *viewport;
	RDPlayer *player;
	RDEntity **entities;

	void init_viewport();
	void init_player();
	void try_move_player();
	void init_entities();
	void update_entities(int x, int y);
	void render_entities();
	void render_player();
	void debug_player();

public:
	RDEngine();
	void Init();
	bool ShouldClose();
	void Rest(int milliseconds);
	void Update();
	void Render();
};