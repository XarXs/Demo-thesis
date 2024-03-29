#include"Demo.h"


Demo::Demo(){
	cout << "Creating Raycaster\n";
	raycaster = new Raycaster();
	cout << "success\n";
}



Demo::~Demo(){
	cout << "Destructor Demo\n";
	delete raycaster;
}


//główna pętla dema
void Demo::run(){
	cout << "Running main loop\n";
	while (MainWindow::getMainWindow()->getWindow()->isOpen()){
		proccesEvents();
		update();
		render();
	}//koniec pętli while
	cout << "Exiting main loop\n";
}

//Wydarzenia
void Demo::proccesEvents(){
	Event events;
	while (MainWindow::getMainWindow()->getWindow()->pollEvent(events)){
		switch (events.type){
		case Event::Closed:
			MainWindow::getMainWindow()->getWindow()->close();
			break;
		}//koniec switcha
	}//koniec pętli while
}

//Aktualizacja
void Demo::update(){
	raycaster->update();
	raycaster->move();
}

//Renderowanie Obrazu
void Demo::render(){
	//czyszczenie ekranu
	MainWindow::getMainWindow()->getWindow()->clear();

	//rysowanie poszczególnych elementów
	RectangleShape rectangle(Vector2f(640, 190));
	rectangle.setPosition(0, 190);
	rectangle.setFillColor(Color(100, 50, 80, 255));
	MainWindow::getMainWindow()->getWindow()->draw(rectangle);
	rectangle.setPosition(0, 0);
	rectangle.setFillColor(Color(80, 30, 60, 100));
	MainWindow::getMainWindow()->getWindow()->draw(rectangle);
	raycaster->render();

	//wyświetlanie
	MainWindow::getMainWindow()->getWindow()->display();

}