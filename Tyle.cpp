#include "Tyle.h"
#include <fstream>
#include "mainFunc.h"

Tyle::Tyle(int pl, int x, int y) {
	count = 1;
	X = x;
	Y = y;
	player = pl;

	this->texture.loadFromFile("images/playerSpr.png");
	switch (player) {
	case 1:
		this->sprite.setTextureRect(IntRect(100, 0, 50, 50)); break;
	case 2:
		this->sprite.setTextureRect(IntRect(100, 150, 50, 50)); break;
	case 3:
		this->sprite.setTextureRect(IntRect(100, 100, 50, 50)); break;
	case 4:
		this->sprite.setTextureRect(IntRect(100, 50, 50, 50)); break;
	default: break;
	}
	this->sprite.setPosition(X, Y);
}

int Tyle::Loc(vector<Tyle> Tyles, int x, int y) {//поиск нужного элемента в массиве
	for (int i = Tyles.size() - 1; i >= 0; i--) {
		if (Tyles[i].getX() == x && Tyles[i].getY() == y)
			return i;
	}
	return -1;
}

vector<Tyle> Tyle::Cloning(vector<Tyle> Tyles, int i) {
	if (X < 600) 
	{
		Tyles = this->mikroCloning(Tyles, this->X + 50, this->Y);
	}
	if (X > 50)
	{
		Tyles = this->mikroCloning(Tyles, this->X - 50, this->Y);
	}
	if (Y < 500)
	{
		Tyles = this->mikroCloning(Tyles, this->X, this->Y + 50);
	}
	if (Y > 50)
	{
		Tyles = this->mikroCloning(Tyles, this->X, this->Y - 50);
	}
	Tyles.erase(Tyles.begin() + i);
	return Tyles;
}

vector<Tyle> Tyle::mikroCloning(vector<Tyle> Tyles, int x, int y) {
	if (Loc(Tyles, x, y) == -1) {
		Tyle babyTyle = Tyle(this->player, x, y);
		Tyles.push_back(babyTyle);
	}
	else {
		Tyles[Loc(Tyles, x, y)].count++;
		if (Tyles[Loc(Tyles, x, y)].player != this->player) {
			Tyles[Loc(Tyles, x, y)].player = this->player;
			//Tyles[Loc(Tyles, x, y)].sprite = 
		}
	}
	return Tyles;
}

std::ostream& operator<<(std::ostream& o, const Tyle& u)
{
	o << u.player << " " << u.count << " " << u.X << " " << u.Y << "\n";
	return o;
}

std::istream& operator>>(std::istream& o, Tyle& u) {
	o >> u.player >> u.count >> u.X >> u.Y;
	return o;
}