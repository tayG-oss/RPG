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
	"-----------------------------------------",
	"|    c                                  |",
	"|                               e       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                       |",
	"|                                 e     |",
	"|          |-----------------------------",
	"|          |                             ",
	"|     e    |                             ",
	"|          |                             ",
	"------------                             ",
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
	movecursor(0, 1);
	for (size_t i = 0; i < worldMap.size(); i++) { // rows
		for (size_t j = 0; j < worldMap.at(i).size(); j++) { // columns
			if (i == playRow and j == playColumn)
				cout << GREEN << "G";
			else cout << WHITE << worldMap.at(i).at(j);
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
	int choice = 0;
	int wall = 0;
	bool battle = false;
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
			movecursor(2, COLUMNS + 5);
			movecursor(ROWS + 2, 0);
			cout.flush();
		}

		if (getLocation(rows, columns) == 'e') {
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "ENEMY ENCOUNTERED\n";
			battle = true;
		}

		//Dumb wall easter egg, don't worry about it
		if (getLocation(rows, columns) == '-' or getLocation(rows, columns) == '|') {
			movecursor(2, COLUMNS + 5);
			cout << "That's a wall\n";
		}
		/*if (wall == 20) {
			cout << "You have been determined to be drunk, and therefore cannot defeat the princess\n";
			cout << "Please sober up before proceeding\n";
			break;
		} else if (wall <= 5 or wall >= 11) {
			cout << "You have hit a wall\n";
			wall++;
		} else if (wall >= 6) {
			cout << "Stop hitting the wall\n";
			wall++;
		} else if (wall == 10) {
			cout << "Are you perhaps drunk?\n";
			wall++;
		}
		} */


		if (getLocation(rows, columns) == 'c') {
			movecursor(ROWS + 2, 0);
			cout << "Completed Test\n";
			usleep(2'000'000);
			break;
		}

		while (battle == true) {
			movecursor(3, COLUMNS + 5);
			cout << WHITE << "What would you like to do?\n";
			movecursor(4, COLUMNS + 5);
			cout << RED << "1) Attack " << BLUE << " 2) Dodge\n";
			cin >> choice;

			movecursor(5, COLUMNS + 5);
			if (choice == 1) {
				cout << WHITE << "You chose to attack!" << endl;
			}
			if (choice == 2) {
				cout << WHITE << "You chose to dodge!" << endl;
			}

			battle = false;
		}


	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();


}
