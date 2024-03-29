/*Główne okno aplikacji w postaci singletonu*/

#pragma once
#include "Biblioteki.h"

class MainWindow{
private:
	/*adres do singletonu*/
	static MainWindow* instance;
	/*prywatny konstruktor domyśl do zapobiegania powstania nowych instancji*/
	MainWindow();

	/*obiekty głównego okna*/
	RenderWindow *window;
public:
	/*dostęp do instancji*/
	static MainWindow* getMainWindow();

	/*Dostęp do głównego okna*/
	RenderWindow* getWindow();

	~MainWindow(); //destruktor
};