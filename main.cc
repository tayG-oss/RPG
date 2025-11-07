//Fill out this comment with your names and which bullet points you did
//Partners: Giulliana Tayona,
//Bullet Points: 1
//Extra Credit:
//URL to cover art and music:

#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

vector<string> worldMap = {
	"--------",
	"|  c   |",
	"| t    |",
	"|      |",
	"|      |",
	"|      |",
	"|      |",
	"--------"
};

char getLocation(size_t row, size_t column) {
	if (row >= worldMap.size()) return ' ';
	if (column >= worldMap.at(row).size()) return ' ';
	return worldMap.at(row).at(column);
}

void setLocation(size_t row, size_t column, char c) {
	if (row >= worldMap.size()) return;
	if (column >= worldMap.at(row).size()) return;
	worldMap.at(row).at(column) = c;
}

void printMap(size_t playRow, size_t playColumn) {
	clearscreen();
	movecursor(0, 0);
	for (int i = 0; i < worldMap.size(); i++) { // rows
		for (int j = 0; j < worldMap.size(); j++) { // columns
			if (i == playRow and j == playColumn)
				cout << "G";
			else cout << worldMap.at(i).at(j);
		}
		cout << endl;
	}

}


int main() {
	const int ROWS = worldMap.size();
	const int COLUMNS = worldMap.at(0).size();
	int rows = ROWS / 2;
	int columns = COLUMNS / 2;
	int prevRow = -1;
	int prevCol = -1; //previous positions
	set_raw_mode(true);
	show_cursor(false);

	while (true) {
		int c = toupper(quick_read());
		if (c == 'W' or c == UP_ARROW) rows--;
		if (c == 'S' or c == DOWN_ARROW) rows++;
		if (c == 'A' or c == LEFT_ARROW) columns--;
		if (c == 'D' or c == RIGHT_ARROW) columns++;

		if (!(rows == prevRow and columns == prevCol)) {
			printMap(rows, columns);
			prevRow = rows;
			prevCol = columns;
		}

		if (getLocation(rows, columns) == 't') {
			setLocation(rows, columns, ' ');
			movecursor(ROWS + 2, 0);
			cout << "Item pick up TEST\n";
		}
		if (getLocation(rows, columns) == 'c') {
			movecursor(ROWS + 2, 0);
			cout << "Completed Test\n";
			break;
		}


	}
	set_raw_mode(false);
	clearscreen();


}
