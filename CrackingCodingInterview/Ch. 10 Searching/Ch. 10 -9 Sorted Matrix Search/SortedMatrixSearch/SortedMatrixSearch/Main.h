#pragma once
class Main
{
public:
	Main();
	~Main();
};

const int ROWSIZE = 4;
const int COLSIZE = 7;
void naiveBinarySearch(int (&matrix)[ROWSIZE][COLSIZE], int const & target);

