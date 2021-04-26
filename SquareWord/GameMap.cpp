#include "GameMap.h"

GameMap::GameMap()
{
	size = 0;
}

GameMap::~GameMap()
{
	for (int i = 0; i < size; ++i) {
		delete[] map[i];
	}
	delete[] map;
}

void GameMap::SetMap(int size)
{
	// create matrix
	this->size = size;
	map = new char* [size];
	for (int i = 0; i < size; ++i) {
		map[i] = new char[size](); // zeroing
	}

	if (size == 5)
	{
		map[0][0] = '�';
		map[0][1] = '�';
		map[0][2] = '�';
		map[0][3] = '�';
		map[0][4] = '�';

		map[2][2] = '�';
		map[2][3] = '�';
		map[2][4] = '�';
	}
	else if (size == 6)
	{
		map[0][0] = '�';
		map[0][1] = '�';
		map[0][2] = '�';
		map[0][3] = '�';
		map[0][4] = '�';
		map[0][5] = '�';

		map[2][2] = '�';
		map[2][3] = '�';
		map[2][4] = '�';

		map[4][3] = '�';
		map[4][4] = '�';
		map[4][5] = '�';
	}
	else if (size == 7)
	{
		map[0][0] = '�';
		map[0][1] = '�';
		map[0][2] = '�';
		map[0][3] = '�';
		map[0][4] = '�';
		map[0][5] = '�';
		map[0][6] = '�';

		map[2][3] = '�';
		map[2][4] = '�';
		map[2][5] = '�';

		map[4][3] = '�';
		map[4][4] = '�';
		map[4][5] = '�';

		map[6][4] = '�';
		map[6][5] = '�';
		map[6][6] = '�';
	}
}

bool GameMap::check(int row, int column, char ch)
{
	// check vertically
	for (int i = 0; i < size; ++i) {
		if (i = row) {
			continue;
		}
		if (map[i][column] == ch) {
			return false;
		}
	}
	// check horizontally
	for (int j = 0; j < size; ++j) {
		if (j = column) {
			continue;
		}
		if (map[row][j] == ch) {
			return false;
		}
	}
	return true;
}

void GameMap::set_position(int row, int column, char ch)
{
	map[row][column] = ch;
}
