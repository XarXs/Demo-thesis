/*Główna pętla dema*/
#pragma once
#include "Biblioteki.h"

class Demo{
	friend class Raycaster;
private:
	Raycaster *raycaster;
	//główne metody pętli
	void proccesEvents();
	void update();
	void render();

public:
	//uruchumienie głównej pętli
	void run();

	//konstruktor i destruktor
	Demo();
	~Demo();
};