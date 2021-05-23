#include "GameMap.h"

bool coord::operator== (const coord& obj) const {
	return (x == obj.x) && (y == obj.y);
}

bool coord::operator< (const coord& obj) const
{
	if (x < obj.x) {
		return true;
	}
	else if (x == obj.x) {
		return y < obj.y;
	}
	return false;
}

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

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j]) {
				const_chars.push_back({ i, j });
				correct_chars.insert({i, j});
			}
		}
	}
}

void GameMap::check(int row, int column, char ch)
{
	conflict_chars.clear();
	// check vertically
	for (int i = 0; i < size; ++i) {
		if (i == row) {
			continue;
		}
		if (map[i][column] == ch) {
			conflict_chars.push_back({ i, column });
		}
	}
	// check horizontally
	for (int j = 0; j < size; ++j) {
		if (j == column) {
			continue;
		}
		if (map[row][j] == ch) {
			conflict_chars.push_back({ row, j });
		}
	}
	if (row == column) {
		// main diagonal check
		for (int m1 = 0, m2 = 0; m1 < size && m2 < size; m1++, m2++) {
			if (m1 == row && m2 == column) {
				continue;
			}
			if (map[m1][m2] == ch) {
				conflict_chars.push_back({ m1, m2 });
			}
		}
	}
	if (row == size - column - 1) {
		// side diagonal check
		for (int s1 = size - 1, s2 = 0; s1 >= 0 && s2 < size; s1--, s2++) {
			if (s1 == row && s2 == column) {
				continue;
			}
			if (map[s1][s2] == ch) {
				conflict_chars.push_back({ s1, s2 });
			}
		}
	}
}

void GameMap::check(int row, int column)
{
	conf_chars.clear();
	// check vertically
	for (int i = 0; i < size; ++i) {
		if (i == row) {
			continue;
		}
		conf_chars.insert(map[i][column]);
	}
	// check horizontally
	for (int j = 0; j < size; ++j) {
		if (j == column) {
			continue;
		}
		conf_chars.insert(map[row][j]);
	}
	if (row == column) {
		// main diagonal check
		for (int m1 = 0, m2 = 0; m1 < size && m2 < size; m1++, m2++) {
			if (m1 == row && m2 == column) {
				continue;
			}
			conf_chars.insert(map[m1][m2]);
		}
	}
	if (row == size - column - 1) {
		// side diagonal check
		for (int s1 = size - 1, s2 = 0; s1 >= 0 && s2 < size; s1--, s2++) {
			if (s1 == row && s2 == column) {
				continue;
			}
			conf_chars.insert(map[s1][s2]);
		}
	}
}

void GameMap::set_position(int row, int column, char ch)
{
	map[row][column] = ch;
}

bool GameMap::isConst(const coord &crd)
{
	return std::find(const_chars.begin(), const_chars.end(), crd) != const_chars.end();
}

char GameMap::get_conf_char(int i) const {
	std::set<char>::iterator it = conf_chars.begin();
	std::advance(it, i);
	return *it;
}