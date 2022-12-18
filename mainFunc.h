#pragma once
#include "Tyle.h"
#include <iostream>
#include <fstream>

Sprite NextSprite(Tyle tl);

void WinPrint(RenderWindow& window, Sprite BackgroundSpr, vector<Tyle> Tyles);

bool menu(RenderWindow& window);