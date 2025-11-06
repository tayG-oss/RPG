//Fill out this comment with your names and which bullet points you did
//Partners: Giulliana Tayona, 
//Bullet Points: 1
//Extra Credit: 
//URL to cover art and music: 

#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
using namespace std;

vector<string> worldMap = {

	"------------------------",
	"|                      |",
	"|		    			|",
	"|                      |",
	"|                      |",
    "|                      |",
    "|                      |",
	"------------------------"
}

char getLocation (size_t row, size_t column) {
	if (row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void setLocation (size_t row, size_t column) {
	if (row >= world_map.size()) return ' ';
    if (col >= world_map.at(row).size()) return ' ';
	worldMap.at(row).at(c) = 'G'
}

void printMap (size_t playRow, size_t playColumn) {
	clearscreen();
	for (int i = 0; i < worldMap.size(); i++) { // rows
		for (int j = 0; j < worldMap.size(); j++) { // columns
			if (i = playRow and j = playColumn) 
				cout << "G";
			else cout << worldMap.at(i).at(j);
		
		}
		
		cout << endl;
	}
	
}


int main() {
	const int ROWS = worldMap.size();
	const int COLUMNS = worldMap.at(0).size();
	int rows = ROWS/2; int columns = COLUMNS/2;
	int prevRow = -1; int prevCol = -1; //previous positions
	set_raw_mode(true);
	show_cursor(false);

	
	

}
