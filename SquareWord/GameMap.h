#pragma once

struct coord {
	int x, y;
};

class GameMap
{
private:
	int size;
	char** map;

public:
	GameMap();
	~GameMap();
	void SetMap(int);
	bool check(int, int, char);
	void set_position(int, int, char);
	int get_size() { return size; }
	char get_value(int i, int j) { return map[i][j]; }
};

