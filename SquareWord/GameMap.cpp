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
		map[0][0] = 'Ñ';
		map[0][1] = 'Ë';
		map[0][2] = 'Å';
		map[0][3] = 'Ç';
		map[0][4] = 'À';

		map[2][2] = 'Ë';
		map[2][3] = 'Å';
		map[2][4] = 'Ñ';
	}
	else if (size == 6)
	{
		map[0][0] = 'Ã';
		map[0][1] = 'Ë';
		map[0][2] = 'Î';
		map[0][3] = 'Á';
		map[0][4] = 'Ó';
		map[0][5] = 'Ñ';

		map[2][2] = 'Ë';
		map[2][3] = 'Ó';
		map[2][4] = 'Ã';

		map[4][3] = 'Ã';
		map[4][4] = 'Î';
		map[4][5] = 'Ë';
	}
	else if (size == 7)
	{
		map[0][0] = 'Ð';
		map[0][1] = 'È';
		map[0][2] = 'Ñ';
		map[0][3] = 'Ó';
		map[0][4] = 'Í';
		map[0][5] = 'Î';
		map[0][6] = 'Ê';

		map[2][3] = 'Ñ';
		map[2][4] = 'Ó';
		map[2][5] = 'Ê';

		map[4][3] = 'Í';
		map[4][4] = 'Î';
		map[4][5] = 'Ñ';

		map[6][4] = 'Ð';
		map[6][5] = 'È';
		map[6][6] = 'Ñ';
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
