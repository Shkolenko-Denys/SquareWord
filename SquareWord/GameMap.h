#pragma once

class GameMap
{
private:
	int size;
	char** map;

public:
	GameMap(int);
	~GameMap();
	bool check(int, int, char);
	void set_position(int, int, char);
};

