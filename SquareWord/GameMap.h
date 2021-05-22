#pragma once

#include <vector>
#include <set>

struct coord {
	int x, y;
	bool operator == (const coord&) const;
	bool operator< (const coord&) const;
};

class GameMap
{
private:
	int size;
	char** map;
	std::vector<coord> const_chars;
	std::vector<coord> conflict_chars;
	std::set<coord> correct_chars;

public:
	GameMap();
	~GameMap();
	void SetMap(int);
	void check(int, int, char);
	void set_position(int, int, char);
	int get_size() const { return size; }
	char get_value(int i, int j) const { return map[i][j]; }
	bool isConst(const coord&);
	int get_conflict_size() const { return conflict_chars.size(); }
	int get_correct_size() const { return correct_chars.size(); }
	void correct(const coord& crd) { correct_chars.insert(crd); }
	void incorrect(const coord &crd) { correct_chars.erase(crd); }
	int get_conflict_row(int i) const { return conflict_chars[i].x; };
	int get_conflict_col(int i) const { return conflict_chars[i].y; };
};