#include <stdio.h>
#include "rdengine.h"

RDEngine::RDEngine(){}

void RDEngine::Init(int width, int height)
{
	this->screen_width = width;
	this->screen_height = height;
	this->buffer_width = this->screen_width;
	this->buffer_height = this->screen_height;
	this->offset_x = 0;
	this->offset_y = 0;
	this->tile_width = 32;
	this->tile_height = 32;

	
	this->isQuit = false;

	allegro_init();
	install_keyboard();
	install_timer();

	set_color_depth(32);

	set_gfx_mode(GFX_AUTODETECT_WINDOWED, this->screen_width, this->screen_height, 0, 0);

	tiles = load_bitmap("Debug/tiles.bmp", NULL);

	playerTile = create_bitmap(this->tile_width,this->tile_height);

	buffer = create_bitmap(this->buffer_width, this->buffer_height);

	init_player();
	init_entity();
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

void RDEngine::try_move_player()
{
	if(key[KEY_RIGHT])
	{
		if(offset_x > (tiles->w - this->screen_width)-2) 
			player->x +=player->speed;
		else
		{
			if(player->x < this->screen_width/2) 
				player->x+=player->speed;
			else
			{
				offset_x +=player->speed;
				entity->x -= player->speed;
			}
		}
	}

	if(key[KEY_LEFT])
	{
		if(offset_x < 2) 
			player->x -=4;
		else
		{
			if(player->x > this->screen_width/2) 
				player->x-=player->speed; 
			else 
			{
				offset_x -=player->speed;
				entity->x += player->speed;
			}
		}
	}

	if(key[KEY_DOWN])
	{
		if(offset_y > (tiles->h - this->screen_height)-2) 
			player->y +=player->speed;
		else
		{
			if(player->y < this->screen_height/2) 
				player->y+=player->speed;
			else
			{
				offset_y +=player->speed;	
				entity->y -= player->speed;
			}
		}
	}

	if(key[KEY_UP])
	{
		if(offset_y < 2) 
			player->y -=player->speed;
		else
		{
			if(player->y > this->screen_height/2) 
				player->y-=player->speed;
			else 
			{
				offset_y -=player->speed;	
				entity->y += player->speed;
			}
		}
	}
}

void RDEngine::Render()
{
	masked_blit(tiles, buffer, offset_x, offset_y, 0, 0, this->screen_width, this->screen_height);
	masked_blit(tiles, buffer, 0,0,player->x, player->y, this->tile_width, this->tile_height);
	masked_blit(tiles, buffer, 32, 64, entity->x, entity->y, this->tile_width, this->tile_height);

	blit(buffer, screen, 0,0,0,0,this->screen_width,this->screen_height);
	
	clear_bitmap(buffer);
}

void RDEngine::Rest(int milliseconds)
{
	rest(milliseconds);
}

void RDEngine::init_viewport()
{
	viewport = new RDViewport(this->player->x,this->player->y,this->screen_width, this->screen_height);
}

void RDEngine::init_player()
{
	player = new RDPlayer(this->screen_width/2 - this->tile_width, this->screen_height/2 - this->tile_height);
}

void RDEngine::init_entity()
{
	entity = new RDEntity(100,100);
}