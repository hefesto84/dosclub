#include <stdio.h>
#include "rdengine.h"

RDEngine::RDEngine(){}

void RDEngine::Init()
{
	this->buffer_width = kWidth;
	this->buffer_height = kHeight;
	this->offset_x = 0;
	this->offset_y = 0;
	this->isQuit = false;

	allegro_init();
	install_keyboard();
	install_timer();

	set_color_depth(32);

	set_gfx_mode(GFX_AUTODETECT_WINDOWED, kWidth, kHeight, 0, 0);

	tiles = load_bitmap("Debug/tiles.bmp", NULL);

	playerTile = create_bitmap(kTileWidth,kTileHeight);

	buffer = create_bitmap(this->buffer_width, this->buffer_height);

	init_player();
	init_entities();
	init_viewport();
	
}

bool RDEngine::ShouldClose()
{
	return this->isQuit;
}

void RDEngine::Update()
{
	if(key[KEY_ESC]) isQuit = true;

	try_move_player();
	
}

void RDEngine::Render()
{
	masked_blit(tiles, buffer, offset_x, offset_y, 0, 0, kWidth, kHeight);
	
	render_player();
	render_entities();

	blit(buffer, screen, 0,0,0,0,kWidth,kHeight);

	debug_player();
	
	clear_bitmap(buffer);
}

void RDEngine::Rest(int milliseconds)
{
	rest(milliseconds);
}

void RDEngine::init_viewport()
{
	viewport = new RDViewport(this->player->x,this->player->y,kWidth, kHeight);
}

void RDEngine::init_player()
{
	player = new RDPlayer(tiles, buffer, kWidth/2 - kTileWidth, kHeight/2 - kTileHeight);
}

void RDEngine::init_entities()
{
	entities = (RDEntity**)malloc(3*sizeof(RDEntity*));

	for(int i = 0; i<3; i++)
	{
		entities[i] = new RDEntity(this->tiles, this->buffer, 5, 5, i*3*kTileWidth, i*3*kTileHeight);
	}
}

void RDEngine::update_entities(int x, int y)
{
	for(int i = 0; i<3; i++)
	{
		entities[i]->x += x;
		entities[i]->y += y;
	}
}

void RDEngine::try_move_player()
{
	if(key[KEY_RIGHT])
	{
		player->rx+=player->speed;

		if(offset_x > (tiles->w - kWidth)-2) 
			player->x +=player->speed;
		else
		{
			if(player->x < kWidth/2) 
				player->x+=player->speed;
			else
			{
				offset_x +=player->speed;
				update_entities(-player->speed, 0);
			}
		}
	}

	if(key[KEY_LEFT])
	{
		player->rx-=player->speed;

		if(offset_x < 2) 
			player->x -=player->speed;
		else
		{
			if(player->x > kWidth/2) 
				player->x-=player->speed; 
			else 
			{
				offset_x -=player->speed;
				update_entities(player->speed, 0);
			}
		}
	}

	if(key[KEY_DOWN])
	{
		player->ry+=player->speed;

		if(offset_y > (tiles->h - kHeight)-2) 
			player->y +=player->speed;
		else
		{
			if(player->y < kHeight/2) 
				player->y+=player->speed;
			else
			{
				offset_y +=player->speed;	
				update_entities(0,-player->speed);
			}
		}
	}

	if(key[KEY_UP])
	{
		player->ry-=player->speed;

		if(offset_y < 2) 
			player->y -=player->speed;
		else
		{
			if(player->y > kHeight/2) 
				player->y-=player->speed;
			else 
			{
				offset_y -=player->speed;	
				update_entities(0,player->speed);
			}
		}
	}

}

void RDEngine::render_player()
{
	player->Render();
}

void RDEngine::debug_player()
{
	player->RenderDebug();
}

void RDEngine::render_entities()
{
	for(int i = 0; i<3; i++)
	{
		entities[i]->Render();
	}
}