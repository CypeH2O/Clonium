#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;


class Tyle 
{
private:
	int player;
	int count;
	int X;
	int Y;
public:
	Sprite sprite;
	Texture texture;
	Tyle(): count(-1), X(0), Y(0), player(0){}
	Tyle(int pl, int x, int y);
	int getX() {return X;}
	int getY() {return Y;}
	int getPl() {return player;}
	int getCount() {return count;}
	void SetPos() {sprite.setPosition(X, Y);}
	int countUp() {return count++;}

	static int Loc(vector<Tyle> Tyles, int x, int y);//������� ����� ����� � ������� �� �� ��������������, ���� -1, ���� ����� ���

	vector<Tyle> Cloning(vector<Tyle> Tyles, int i);//���������� ������������ � �������� ���������

	vector<Tyle> mikroCloning(vector<Tyle> Tyles, int x, int y);//���� ������������ � ������

	friend std::ostream& operator<<(std::ostream& o, const Tyle& u);
	friend std::istream& operator>>(std::istream& o, Tyle& u);
};

