#include"Main_Window.h"

MainWindow::MainWindow(){
	cout << "Creating App Window\n";
	window = new RenderWindow(VideoMode(SZER, WYS), "Demo - Praca dyplomowa - Adam Chabros", Style::Close);	//utworzenie okna aplikacji i określenie podstawowych ustawień
	//window->setFramerateLimit(30);	//ograniczenie częstotliwości wyświetlania 
	cout << "success\n";
}

MainWindow::~MainWindow(){
	cout << "Destruktor MainWindow\n";
	delete window;
	delete instance;
}

MainWindow* MainWindow::instance = 0;

MainWindow* MainWindow::getMainWindow(){
	if (instance == 0)
		instance = new MainWindow();
	return instance;
}

RenderWindow* MainWindow::getWindow(){
	return window;
}