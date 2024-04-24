#include "rdmap.h"

RDMap::RDMap(BITMAP *buffer, char *tile_data_path, char *data_path)
{
	this->buffer = buffer;

	this->initialize(tile_data_path, data_path);

	this->width = 1088;
	this->height = 1088;
}

void RDMap::initialize(char *tile_data_path, char *data_path)
{
	tile_data = load_bitmap(tile_data_path, NULL);

	FILE *data = fopen(data_path,"rb");

	int l = 0;
	int w = 0;
	int h = 0;

	fread(&l, sizeof(short), 1, data);
	fread(&w, sizeof(short), 1, data);
	fread(&h, sizeof(short), 1, data);

	this->layers = l;
	this->cols = w;
	this->rows = h;


	fclose(data);
}

void RDMap::Update(int *offset_x, int *offset_y)
{
	this->offset_x = offset_x;
	this->offset_y = offset_y;
}

void RDMap::Render(int layer)
{
	masked_blit(tile_data, buffer, *offset_x, *offset_y, 0, 0, kWidth, kHeight);
}