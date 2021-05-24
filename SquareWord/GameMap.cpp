#include "GameMap.h"

bool coord::operator== (const coord& obj) const
{
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

GameMap::GameMap(int size)
{
	this->size = size;
	// create matrix
	this->size = size;
	map = new char* [size];
	for (int i = 0; i < size; ++i) {
		map[i] = new char[size](); // zeroing
	}
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

void GameMap::check(const coord &crd, char ch)
{
	conflict_chars.clear();
	// check vertically
	for (int i = 0; i < size; ++i) {
		if (i == crd.x) {
			continue;
		}
		if (map[i][crd.y] == ch) {
			conflict_chars.push_back({ i, crd.y });
		}
	}
	// check horizontally
	for (int j = 0; j < size; ++j) {
		if (j == crd.y) {
			continue;
		}
		if (map[crd.x][j] == ch) {
			conflict_chars.push_back({ crd.x, j });
		}
	}
	if (crd.x == crd.y) {
		// main diagonal check
		for (int m = 0; m < size; m++) {
			if (m == crd.x) {
				continue;
			}
			if (map[m][m] == ch) {
				conflict_chars.push_back({ m, m });
			}
		}
	}
	if (crd.x == size - crd.y - 1) {
		// side diagonal check
		for (int s1 = size - 1, s2 = 0; s1 >= 0 && s2 < size; s1--, s2++) {
			if (s1 == crd.x && s2 == crd.y) {
				continue;
			}
			if (map[s1][s2] == ch) {
				conflict_chars.push_back({ s1, s2 });
			}
		}
	}
}

void GameMap::check(const coord &crd)
{
	conf_chars.clear();
	// check vertically
	for (int i = 0; i < size; ++i) {
		if (i == crd.x) {
			continue;
		}
		conf_chars.insert(map[i][crd.y]);
	}
	// check horizontally
	for (int j = 0; j < size; ++j) {
		if (j == crd.y) {
			continue;
		}
		conf_chars.insert(map[crd.x][j]);
	}
	if (crd.x == crd.y) {
		// main diagonal check
		for (int m = 0; m < size; m++) {
			if (m == crd.x) {
				continue;
			}
			conf_chars.insert(map[m][m]);
		}
	}
	if (crd.x == size - crd.y - 1) {
		// side diagonal check
		for (int s1 = size - 1, s2 = 0; s1 >= 0 && s2 < size; s1--, s2++) {
			if (s1 == crd.x && s2 == crd.y) {
				continue;
			}
			conf_chars.insert(map[s1][s2]);
		}
	}
}

void GameMap::set_position(const coord& crd, char ch)
{
	map[crd.x][crd.y] = ch;
}

bool GameMap::isConst(const coord &crd)
{
	return std::find(const_chars.begin(), const_chars.end(), crd) != const_chars.end();
}

char GameMap::get_conf_char(int i) const
{
	std::set<char>::iterator it = conf_chars.begin();
	std::advance(it, i);
	return *it;
}