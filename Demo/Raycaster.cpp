#include "Raycaster.h"

Raycaster::Raycaster(){
	posX = 21;
	posY = 1.5;

	dirX = -1;
	dirY = 0;

	planeX = 0;
	planeY = 0.66;

	time = oldTime = 0;

	int worldMap[mapWidth][mapHeight] =
	{
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7 },
		{ 4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7 },
		{ 4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7 },
		{ 4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7 },
		{ 4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7 },
		{ 4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1 },
		{ 4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8 },
		{ 4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1 },
		{ 4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8 },
		{ 4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1 },
		{ 4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1 },
		{ 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
		{ 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4 },
		{ 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
		{ 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2 },
		{ 4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2 },
		{ 4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2 },
		{ 4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2 },
		{ 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2 },
		{ 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3 }
	};

	for (int i = 0; i < mapWidth; i++){
		for (int j = 0; j < mapHeight; j++){
			tab[i][j] = worldMap[i][j];
		}
	}
	//
	if (!texture[0].loadFromFile("texture/1.jpg")) { 
		cout << "Error: 1.jpg not found\n"; 
	}
	cout << "success: Loading texture - 1.jpg\n";
	if (!texture[1].loadFromFile("texture/2.jpg")) {
		cout << "Error: 2.jpg not found\n";
	}
	cout << "success: Loading texture - 2.jpg\n";
	if (!texture[2].loadFromFile("texture/3.jpg")) {
		cout << "Error: 3.jpg not found\n";
	}
	cout << "success: Loading texture - 3.jpg\n";
	if (!texture[3].loadFromFile("texture/4.jpg")) {
		cout << "Error: 4.jpg not found\n";
	}
	cout << "success: Loading texture - 4.jpg\n";
	if (!texture[4].loadFromFile("texture/5.jpg")) {
		cout << "Error: 5.jpg not found\n";
	}
	cout << "success: Loading texture - 5.jpg\n";
	if (!texture[5].loadFromFile("texture/6.jpg")) {
		cout << "Error: 6.jpg not found\n";
	}
	cout << "success: Loading texture - 6.jpg\n";
	if (!texture[6].loadFromFile("texture/7.jpg")) {
		cout << "Error: 7.jpg not found\n";
	}
	cout << "success: Loading texture - 7.jpg\n";
	if (!texture[7].loadFromFile("texture/8.jpg")) {
		cout << "Error: 8.jpg not found\n";
	}
	cout << "success: Loading texture - 8.jpg\n";
	texture[0].setRepeated(true);
	texture[1].setRepeated(true);
	texture[2].setRepeated(true);
	texture[3].setRepeated(true);
	texture[4].setRepeated(true);
	texture[5].setRepeated(true);
	texture[6].setRepeated(true);
	texture[7].setRepeated(true);
	//
	

	line2.setSize(Vector2f(1, 1));
	line2.setTexture(&texture[6]);
	color = Color(0, 10, 20, 100);

	Image img; img.loadFromFile("texture/heighmap.bmp");
	for (int i = 0; i < mapHeight; i++){
		for (int j = 0; j < mapWidth; j++){
			Color col = img.getPixel(i, j);
			heigh[i][j] = (int)(col.toInteger()/(pow(256, 3)));
			cout << heigh[i][j] << " ";
		}
		cout << endl;
	}
}

void Raycaster::render(){
	
	for (int x = 0; x < SZER; x++){
		vector<wall> wallList;
		/*obliczanie pozycji i kierunku promienia*/
		double cameraX = 2 * x / double(SZER) - 1;	//pozycja x w przestrzeni kamery
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		/*na którym polu mapy jesteśmy*/
		int mapX = int(posX);
		int mapY = int(posY);

		/*długość promienia z aktualnej pozaycji do następnego pola x (podłoga) lub y(ściana)*/
		double sideDistX;
		double sideDistY;

		/*długość promienia z pola x lub y do następnego pola x lub y*/
		double deltaDistX = abs(1 / rayDirX);
		double deltaDistY = abs(1 / rayDirY);
		double perpWallDist;

		/*jaki jest kierunke by wejść na pole x lub y (+1 lub -1)*/
		int stepX;
		int stepY;

		int hit = 0;	//czy jest kolizja ze ścianą?
		int side;		// czy to NS lub EW kolizja ze ściną?

		/*calculate step and initial sideDist*/
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		int drawEnd;
		double wallX; //where exactly the wall was hit
		/*DDA - co kolwiek to jest*/
		while (hit == 0){
			/*przeskoczenie do kolejnego pola mapy*/
			if (sideDistX < sideDistY){
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			/*sprawdzenie czy promień trafił w ścianę*/
			if (tab[mapX][mapY] > 0){
				wall wp;
				wp.mapX = mapX;
				wp.mapY = mapY;
				wp.side = side;


				if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
				else perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

				//texturing calculations
				int texNum = tab[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
				//calculate value of wallX
				if (side == 0) wallX = posY + perpWallDist * rayDirY;
				else           wallX = posX + perpWallDist * rayDirX;
				wallX -= floor((wallX));

				//x coordinate on the texture
				int texX = int(wallX * double(texWidth));
				texX = texWidth - texX - 1;

				/*obliczanie wysokości linni*/
				int lineHeight = (WYS * 0.5 + heigh[mapX][mapY]) / perpWallDist;

				/*obliczanie najniższego i najwyższego pixela do wyepłnienia w aktualnym pasku*/
				//int drawStart = -lineHeight / 2 + WYS / 2;
				//if (drawStart < 0) drawStart = 0;

				int lh = WYS / perpWallDist;
				//int drawEnd = lineHeight / 2 + WYS / 2;
				drawEnd = lh / 2 + WYS / 2;
				int drawStart = drawEnd - lineHeight;
				wp.drawStart = drawStart;
				wp.lineHeight = lineHeight;
				wp.perpWallDist = perpWallDist;
				wp.texNum = texNum;
				wp.texX = texX;
				if (wallList.empty()) wallList.push_back(wp);
				else if (drawStart < wallList.back().drawStart && heigh[mapX][mapY] < 256) wallList.push_back(wp);
			}
			if (mapX == 24 || mapY == 24 || mapX == 0 || mapY == 0 || heigh[mapX][mapY] == 255) hit = 1;
		}//pętla while
		
		for (int i = wallList.size()-1; i >= 0; i--){

			//if (drawEnd >= WYS) drawEnd = WYS - 1;
			//rysowanie
			RectangleShape line(Vector2f(wallList[i].lineHeight, 1));
			line.rotate(90.f);
			line.setPosition(x, wallList[i].drawStart);
			line.setTexture(&texture[wallList[i].texNum]);
			line.setTextureRect(IntRect(0, wallList[i].texX, 106, 1));

			MainWindow::getMainWindow()->getWindow()->draw(line);
			
			double v = 255 - (wallList[i].perpWallDist*(255/25));
			if (v < 0) v = 0;
			color = Color(v, v, v, 255);
			line.setFillColor(color);
			MainWindow::getMainWindow()->getWindow()->draw(line);
			
			if (wallList[i].side == 1){
				line.setFillColor(Color(0, 10, 20, 100));
				MainWindow::getMainWindow()->getWindow()->draw(line);
			}

		}
		/*
		if (floorcasting){
			//FLOOR CASTING
			double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

			//4 different wall directions possible
			if (side == 0 && rayDirX > 0)
			{
				floorXWall = mapX;
				floorYWall = mapY + wallX;
			}
			else if (side == 0 && rayDirX < 0)
			{
				floorXWall = mapX + 1.0;
				floorYWall = mapY + wallX;
			}
			else if (side == 1 && rayDirY > 0)
			{
				floorXWall = mapX + wallX;
				floorYWall = mapY;
			}
			else
			{
				floorXWall = mapX + wallX;
				floorYWall = mapY + 1.0;
			}

			double distWall, distPlayer, currentDist;

			distWall = perpWallDist;
			distPlayer = 0.0;

			if (drawEnd < 0) drawEnd = WYS; //becomes < 0 when the integer overflows

			for (int y = drawEnd + 1; y < WYS; y++)
			{
				currentDist = WYS / (2.0 * y - WYS); //you could make a small lookup table for this instead

				double weight = (currentDist - distPlayer) / (distWall - distPlayer);

				double currentFloorX = weight * floorXWall + (1.0 - weight) * posX;
				double currentFloorY = weight * floorYWall + (1.0 - weight) * posY;

				int floorTexX, floorTexY;
				floorTexX = int(currentFloorX * texWidth) % texWidth;
				floorTexY = int(currentFloorY * texHeight) % texHeight;


				line2.setPosition(x, y);
				line2.setTextureRect(IntRect(floorTexY, floorTexX, 1, 1));
				MainWindow::getMainWindow()->getWindow()->draw(line2);
			}//koniec floor casting
		}//koniec ifa floor casting
		*/
	} //pętla for
	
} //koniec funkcji


void Raycaster::update(){
	oldTime = time;
	time = timer.getElapsedTime().asMilliseconds();
	double frameTime = (time - oldTime) / 2000.0;

	moveSpeed = frameTime * 5.0;
	rotSpeed = frameTime * 3.0;
}

void Raycaster::move(){
	/*ruch do przodu*/
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		if (tab[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
		if (tab[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	/*ruch do tyłu*/
	if (Keyboard::isKeyPressed(Keyboard::Down)){
		if (tab[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
		if (tab[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}

	/*obrót w prawo*/
	if (Keyboard::isKeyPressed(Keyboard::Right)){
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	/*obrót w lewo*/
	if (Keyboard::isKeyPressed(Keyboard::Left)){
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}
}