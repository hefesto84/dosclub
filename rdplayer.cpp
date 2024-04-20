#include <stdio.h>
#include "rdplayer.h"

RDPlayer::RDPlayer(BITMAP *data, BITMAP *buffer, int x, int y)
{
	this->data = data;
	this->buffer = buffer;
	this->x = x;
	this->y = y;
	this->rx = this->x / 32;
	this->ry = this->y / 32;
	this->speed = kPlayerSpeed;
}

void RDPlayer::Render()
{	
	masked_blit(this->data, this->buffer, 0,0,this->x, this->y, kTileWidth, kTileHeight);
}

void RDPlayer::RenderDebug()
{
	sprintf(this->tile_position_text, "%d - %d", this->x / 32, this->y / 32);
	textout_ex(screen, font, this->tile_position_text, 400,400,makecol(255,255,255),-1);
}