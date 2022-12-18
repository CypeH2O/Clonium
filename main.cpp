#pragma once
#include <thread>
#include "Tyle.h"
#include "mainFunc.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(700, 600), "Clonium");
    window.setFramerateLimit(60);
	

    Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("images/map.png");
    Sprite BackgroundSpr;
    BackgroundSpr.setTexture(BackgroundTexture);
    window.draw(BackgroundSpr); //14*12 квадратов 700*600 пикселей
    
    vector<Tyle> Tyles;
	int PlayersCount = 2;
	int turn = 0;
	int Winner=0;
	menu(window);
	///----------------------------------|
	/// Заполняем Вектор из файла.       |
	///----------------------------------|
	bool NextOrCont=false;
	while (menu(window))
	{
		ifstream ifile("save.txt");

		if (ifile)
		{
			ifile >> turn;
			Tyle tilek;
			while (ifile >> tilek)
			{
				tilek.texture.loadFromFile("images/playerSpr.png");
				tilek.sprite.setPosition(tilek.getX(), tilek.getY());
				Tyles.emplace_back(move(tilek));
			}
			NextOrCont = true;
			break;
		}
	} 
	if (!NextOrCont) {
		Tyles.push_back(Tyle(1, 150, 150));
		Tyles.push_back(Tyle(2, 500, 400));
	}
	
    
	for (int i = 0; i < Tyles.size(); i++) { 
		Tyles[i].sprite.setTexture(Tyles[i].texture); 
		Tyles[i].sprite = NextSprite(Tyles[i]);
	}
    for (int i = 0; i < Tyles.size(); i++)
        window.draw(Tyles[i].sprite);
	
    Event event; 
    while (window.isOpen())
    {

		while (window.pollEvent(event))
		{
			
			if (Mouse::isButtonPressed(Mouse::Left)) {

				int Xpos = Mouse::getPosition(window).x / 50 * 50; int Ypos = Mouse::getPosition(window).y / 50 * 50;
				int n = Tyle::Loc(Tyles, Xpos, Ypos);
				if (n != -1 && Tyles[n].getPl()==turn+1) {
					Tyles[n].countUp(); Tyles[n].sprite = NextSprite(Tyles[n]);
					if (Tyles[n].getCount() == 4) {
						Tyles = Tyles[n].Cloning(Tyles, n);
						for (int i = 0; i < Tyles.size(); i++) {
							Tyles[i].sprite.setTexture(Tyles[i].texture);
							Tyles[i].sprite = NextSprite(Tyles[i]);
						}
						WinPrint(window, BackgroundSpr, Tyles);
					}

					turn = (turn + 1) % PlayersCount; 
				}

			}

			
			while (find_if(Tyles.begin(), Tyles.end(), [](Tyle i1) {return i1.getCount() >= 4; }) != Tyles.end()) {
				auto TylesIter = find_if(Tyles.begin(), Tyles.end(), [](Tyle i1) {return i1.getCount() >= 4; });
				Tyles = ((*TylesIter).Cloning(Tyles, TylesIter - Tyles.begin()));
				for (int i = 0; i < Tyles.size(); i++) {
					Tyles[i].sprite.setTexture(Tyles[i].texture);
					Tyles[i].sprite = NextSprite(Tyles[i]);
				}
				sleep(milliseconds(300));
				WinPrint(window, BackgroundSpr, Tyles);
			}
			if (find_if(Tyles.begin(), Tyles.end(), [](Tyle i1) {return i1.getPl() > 1; }) == Tyles.end()) {
				Winner=1; 
				sleep(milliseconds(300));
				event.type = Event::Closed;
			}
			else if (find_if(Tyles.begin(), Tyles.end(), [](Tyle i1) {return i1.getPl() == 1; }) == Tyles.end()) {
				Winner = 2;
				sleep(milliseconds(300));
				event.type = Event::Closed;
			}
			
			if (event.type == Event::Closed)
				window.close();
		}

		WinPrint(window, BackgroundSpr, Tyles);
    }
	
	system("cls");
	switch (Winner) {
	case 1:
		system("color 4F");
		cout << "Red win"; remove("save.txt"); break;
	case 2:
		system("color 1F");
		cout << "blue win"; remove("save.txt"); break;
	default:
		std::ofstream ofile("save.txt");
		ofile << turn << "\n";
		for (auto e : Tyles)
		{
			ofile << e;
		}
		ofile.close();
		break;
	}

	return 0;
}
