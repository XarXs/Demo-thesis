#pragma once
/*Wszystkie stałe dema*/

#define SZER 640
#define WYS 380

#define mapWidth 24
#define mapHeight 24

#define texWidth 106
#define texHeight 106

#define N 64

struct Floor{
	int x;
	int y;

	int floorX;
	int floorY;
};

struct wall{
	int mapX;
	int mapY;
	int side;
	int drawStart;
	int lineHeight;
	int perpWallDist;
	int texNum;
	int texX;
};