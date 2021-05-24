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
	std::vector<coord> const_ch_coord;		// track clicks on starting letters
	std::vector<coord> conflict_ch_coord;	// to mark conflict letters
	std::set<coord> correct_ch_coord;		// to track the victory
	std::set<char> conflict_chars;			// for hide buttons

public:
	GameMap(int);
	~GameMap();
	void SetMap();

	void check(const coord&, char);
	void check(const coord&);

	void set_position(const coord&, char);
	bool isConst(const coord&);

	char get_value(int i, int j) const { return map[i][j]; }

	int get_conflict_ch_coord_size() const { return conflict_ch_coord.size(); }
	int get_correct_ch_coord_size() const { return correct_ch_coord.size(); }
	int get_conflict_chars_size() const { return conflict_chars.size(); }

	void correct(const coord& crd) { correct_ch_coord.insert(crd); }
	void incorrect(const coord &crd) { correct_ch_coord.erase(crd); }

	int get_conflict_row(int i) const { return conflict_ch_coord[i].x; }
	int get_conflict_col(int i) const { return conflict_ch_coord[i].y; }
	char get_conflict_char(int i) const;
};