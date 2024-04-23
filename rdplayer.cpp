#include <stdio.h>
#include "rdplayer.h"

RDPlayer::RDPlayer(BITMAP *data, BITMAP *buffer, int x, int y)
{
	this->data = data;
	this->buffer = buffer;
	this->x = x;
	this->y = y;
	this->rx = this->x;
	this->ry = this->y;
	this->scroll_x = 0;
	this->scroll_y = 0;
	this->isScrollRequired = false;
	this->speed = kPlayerSpeed;
}

void RDPlayer::Update(RDMap *map, int& offset_x, int& offset_y)
{
	
	this->scroll_x = 0;
	this->scroll_y = 0;

	if(key[KEY_RIGHT])
	{
		this->rx+=this->speed;

		if(offset_x > (map->width - kWidth)-2){ 
			this->x +=this->speed;
		}
		else
		{
			if(this->x < kWidth/2) 
				this->x+=this->speed;
			else
			{
				offset_x +=this->speed;
				this->scroll_x = -this->speed;
			}
		}
	}

	if(key[KEY_LEFT])
	{
		this->rx-=this->speed;

		if(offset_x < 2) 
			this->x -=this->speed;
		else
		{
			if(this->x > kWidth/2) 
				this->x-=this->speed; 
			else 
			{
				offset_x -=this->speed;
				this->scroll_x = this->speed;
			}
		}
	}

	if(key[KEY_DOWN])
	{
		this->ry+=this->speed;

		if(offset_y > (map->height - kHeight)-2) 
			this->y +=this->speed;
		else
		{
			if(this->y < kHeight/2) 
				this->y+=this->speed;
			else
			{
				offset_y +=this->speed;	
				this->scroll_y = -this->speed;
			}
		}
	}

	if(key[KEY_UP])
	{
		this->ry-=this->speed;

		if(offset_y < 2) 
			this->y -=this->speed;
		else
		{
			if(this->y > kHeight/2) 
				this->y-=this->speed;
			else 
			{
				offset_y -=this->speed;	
				this->scroll_y = this->speed;
			}
		}
	}
	

	this->isScrollRequired = (this->scroll_x != 0 || this->scroll_y !=0);
}

bool RDPlayer::TryGetScrollRequired(int& scroll_x, int& scroll_y)
{
	if(isScrollRequired)
	{
		scroll_x = this->scroll_x;
		scroll_y = this->scroll_y;

		return true;
	}

	isScrollRequired = false;

	return isScrollRequired;
}

void RDPlayer::Render()
{	
	masked_blit(this->data, this->buffer, 0,0,this->x, this->y, kTileWidth, kTileHeight);
}

void RDPlayer::RenderDebug()
{
	sprintf(this->tile_position_text, "%d - %d", this->rx / 32, this->ry / 32);
	textout_ex(screen, font, this->tile_position_text, 400,400,makecol(255,255,255),-1);
}