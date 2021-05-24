#pragma once

#include <vector>
#include <set>
#include <iterator>

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
	std::set<char> conf_chars;

public:
	GameMap(int);
	~GameMap();
	void SetMap(int);

	void check(const coord&, char);
	void check(const coord&);

	void set_position(const coord&, char);
	bool isConst(const coord&);

	int get_size() const { return size; }
	char get_value(int i, int j) const { return map[i][j]; }

	int get_conflict_size() const { return conflict_chars.size(); }
	int get_correct_size() const { return correct_chars.size(); }
	int get_conf_size() const { return conf_chars.size(); }

	void correct(const coord& crd) { correct_chars.insert(crd); }
	void incorrect(const coord &crd) { correct_chars.erase(crd); }

	int get_conflict_row(int i) const { return conflict_chars[i].x; }
	int get_conflict_col(int i) const { return conflict_chars[i].y; }
	char get_conf_char(int i) const;
};