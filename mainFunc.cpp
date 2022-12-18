#pragma once
#include "mainFunc.h"

Sprite NextSprite(Tyle tl) {
	switch (tl.getPl()) {
	case 1:
		switch (tl.getCount()) {
		case 1:
			tl.sprite.setTextureRect(IntRect(100, 0, 50, 50)); break;
		case 2:
			tl.sprite.setTextureRect(IntRect(0, 0, 50, 50)); break;
		case 3:
			tl.sprite.setTextureRect(IntRect(50, 0, 50, 50)); break;
		case 4:
			tl.sprite.setTextureRect(IntRect(150, 0, 50, 50)); break;
		default: break;
		}
		break;
	case 2:
		switch (tl.getCount()) {
		case 1:
			tl.sprite.setTextureRect(IntRect(100, 150, 50, 50)); break;
		case 2:
			tl.sprite.setTextureRect(IntRect(0, 150, 50, 50)); break;
		case 3:
			tl.sprite.setTextureRect(IntRect(50, 150, 50, 50)); break;
		case 4:
			tl.sprite.setTextureRect(IntRect(150, 150, 50, 50)); break;
		default: break;
		}
		break;
	case 3:
		switch (tl.getCount()) {
		case 1:
			tl.sprite.setTextureRect(IntRect(100, 100, 50, 50)); break;
		case 2:
			tl.sprite.setTextureRect(IntRect(0, 100, 50, 50)); break;
		case 3:
			tl.sprite.setTextureRect(IntRect(50, 100, 50, 50)); break;
		case 4:
			tl.sprite.setTextureRect(IntRect(150, 100, 50, 50)); break;
		default: break;
		}
		break;
	case 4:
		switch (tl.getCount()) {
		case 1:
			tl.sprite.setTextureRect(IntRect(100, 50, 50, 50)); break;
		case 2:
			tl.sprite.setTextureRect(IntRect(0, 50, 50, 50)); break;
		case 3:
			tl.sprite.setTextureRect(IntRect(50, 50, 50, 50)); break;
		case 4:
			tl.sprite.setTextureRect(IntRect(150, 50, 50, 50)); break;
		default: break;
		}
		break;
	default: break;
	}
	return tl.sprite;
}

void WinPrint(RenderWindow& window, Sprite BackgroundSpr, vector<Tyle> Tyles) {
	window.clear();
	window.draw(BackgroundSpr);
	for (int i = 0; i < Tyles.size(); i++)
		window.draw(Tyles[i].sprite);
	window.display();
}


bool menu(RenderWindow& window){
	bool NewOrCont = false;
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	//aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/menuBackground.jpg");
	Sprite menu1(menuTexture1), menu3(menuTexture3),menu2(menuTexture2), about(aboutTexture), menuBg(menuBackground); 
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(250, 200);
	menu2.setPosition(250, 275);
	menu3.setPosition(250, 350);

	//////////////////////////////МЕНЮ//////////////////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		//window.clear(Color(129, 181, 221));

		if (IntRect(250, 200, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(250, 275, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(250, 350, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { NewOrCont = true; isMenu = false; }
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
	return NewOrCont;
	////////////////////////////////////////////////////
}