/*Klasa gracza, która odpowiada zarówno za poruszanie się nim
jak i za określenie położenia kamery, przez którą będą rzucane promienie*/
#pragma once
#include "Biblioteki.h"
class Raycaster{
private:
	/*pozycje startowe*/
	double posX;
	double posY;
	
	/*początkowy wektor kierunku*/
	double dirX;
	double dirY;

	/*dwuwymiarowa wersja raycastera planszy kamery*/
	double planeX;
	double planeY;

	double time;	//czas aktualnej klatki
	double oldTime;	//czas poprzedniej klatki

	double moveSpeed;
	double rotSpeed;
	int tab[mapWidth][mapHeight];
	int heigh[mapWidth][mapHeight];
	Texture texture[9];
	RectangleShape line2;
	
	Color color;
	Clock timer;
public:
	void render();
	void update();
	void move();
	Raycaster();
};