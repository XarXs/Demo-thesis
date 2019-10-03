#include "Biblioteki.h"

int main()
{
	cout << "Dwuwymiarowe metody i techniki imitacji przestrzeni trojwymiarowej\nAdam Chabros\n104033\nDemo - Praca dyplomowa\n";
	Demo* demo = new Demo();
	demo->run();

	delete demo;
	delete MainWindow::getMainWindow();
	return 0;
}