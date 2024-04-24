#ifndef RDMAP_H
#define RDMAP_H

#include <allegro.h>
#include <stdio.h>
#include "rdconstants.h"

class RDMap
{
private:
	int *offset_x;
	int *offset_y;
	BITMAP *buffer;
	BITMAP *tile_data;
	void initialize(char *tile_data_path, char *data_path);
public:
	int layers;
	int width;
	int height;
	int rows;
	int cols;
	RDMap(BITMAP *buffer, char *tile_data_path, char *tile_path);
	void Update(int *offset_x, int *offset_y);
	void Render(int layer);
};

#endif