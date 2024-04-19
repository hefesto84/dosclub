#include "stdio.h"
#include "rdengine.h"

RDEngine::RDEngine(){}

void RDEngine::Setup(int width, int height)
{
	this->width = width;
	this->height = height;

	offset_x = 0;
	offset_y = 0;
	isQuit = false;

	movement_speed = 10;

	allegro_init();
	install_keyboard();
	install_timer();

	set_color_depth(32);
    
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,width,height,0,0);

	tiles = load_bitmap("Debug/tiles.bmp",NULL);

	initBuffer();
}

bool RDEngine::ShouldClose()
{
	return isQuit;
}

void RDEngine::Rest(int milliseconds)
{
	rest(milliseconds);
}

void RDEngine::Update()
{
	if(key[KEY_ESC]) isQuit = true;

	move_window();
}

void RDEngine::Render()
{
	masked_blit(tiles, buffer, offset_x,offset_y,0,0,(tiles->w)-offset_x, (tiles->h)-offset_y);

	sprintf(debug_buffer,"%d %d",offset_x, offset_y);

	textout_ex(buffer, font, debug_buffer, 400,400,makecol(255,255,255),-1);
	blit(buffer, screen, 0,0,0,0,640,480);
	clear_bitmap(buffer);
}

void RDEngine::initBuffer()
{
	buffer = create_bitmap(tiles->w,tiles->h);
	max_offset_x = buffer->w - width;
	max_offset_y = buffer->h - height;
}

void RDEngine::move_window()
{
	if(key[KEY_RIGHT])
	{
		offset_x+=movement_speed;
		
	}

	if(key[KEY_LEFT])
	{
		offset_x-=movement_speed;
		
	}

	if(key[KEY_UP])
	{
		offset_y-=movement_speed;
		
	}

	if(key[KEY_DOWN])
	{
		offset_y+=movement_speed;

	}


	correct_window_coordinates();
}

void RDEngine::correct_window_coordinates()
{
	if(offset_x < 0) offset_x = 0;
	if(offset_y < 0) offset_y = 0;

	offset_x = (offset_x > max_offset_x) ? max_offset_x : offset_x;
	offset_y = (offset_y > max_offset_y) ? max_offset_y : offset_y;
}