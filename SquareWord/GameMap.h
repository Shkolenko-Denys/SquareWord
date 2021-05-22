#pragma once

#include <vector>

struct coord {
	int x, y;
	bool operator == (const coord&) const;
};

class GameMap
{
private:
	int size;
	char** map;
	std::vector<coord> const_chars;

public:
	GameMap();
	~GameMap();
	void SetMap(int);
	bool check(int, int, char);
	void set_position(int, int, char);
	int get_size() { return size; }
	char get_value(int i, int j) { return map[i][j]; }
	bool isConst(const coord&);
};