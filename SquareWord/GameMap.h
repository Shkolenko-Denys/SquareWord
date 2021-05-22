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
	int correct_chars;
	char** map;
	std::vector<coord> const_chars;
	std::vector<coord> conflict_chars;

public:
	GameMap();
	~GameMap();
	void SetMap(int);
	void correct() { ++correct_chars; }
	void incorrect() { --correct_chars; }
	void check(int, int, char);
	void set_position(int, int, char);
	int get_size() const { return size; }
	char get_value(int i, int j) const { return map[i][j]; }
	bool isConst(const coord&);
	int get_conflict_size() const { return conflict_chars.size(); }
	int get_conflict_row(int i) const { return conflict_chars[i].x; };
	int get_conflict_col(int i) const { return conflict_chars[i].y; };
};