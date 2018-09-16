#include "stdafx.h"
#include "Square.h"


Square::Square()
{
}


Square::Square(int newI, int newJ)
{
	i = newI;
	j = newJ;
	int num = rand() % 2;
	color = BLANK;
	//color = COLOR(num);
	/*std::cout << "[" << ((color == COLOR::BLACK) ? ("B") : ("W"));
	std::cout << "]";*/
}
Square::~Square()
{
}

void Square::flipColor() {
	color = COLOR((color + 1) % 2);
}
