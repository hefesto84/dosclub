#include "rdentity.h"

RDEntity::RDEntity(BITMAP *data, BITMAP *buffer, int tile_x, int tile_y, int x, int y)
{
	this->data = data;
	this->buffer = buffer;
	this->x = x;
	this->y = y;
	this->tile_x = tile_x % kTilesPerColumn; 
	this->tile_y = tile_y / kTilesPerRow; 
}

void RDEntity::Render()
{
	masked_blit(this->data, this->buffer, kTileWidth*tile_x, kTileHeight*tile_y, this->x, this->y, kTileWidth, kTileHeight);
}