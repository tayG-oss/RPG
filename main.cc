//Fill out this comment with your names and which bullet points you did
//Partners: Je-heon Oh, giulls, Dom
//Bullet Points: 1,2,3,4,5
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <cctype>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdlib>
using namespace std;
//Puzzle 1 functions
double f(double x) {
	return x * x * x * x;
}

double leftriemannSum(int a, int b, int numRectangles) {

	double rectangleWidth = (b - a) / numRectangles;
	double sum = 0;

	for (int i = 0; i < numRectangles; i++) {
		double xi = a + i * rectangleWidth;
		sum += f(xi) * rectangleWidth;
	}

	return sum;
}



//Class for miniboss
class Bosses {
	//basic stats for miniboss
  private:
	int maxHealth;
	string Name;
//	int damageTaken; not sure if this is necessary
	//initialization
  public:
	int ATTDamage;
	int curHealth;
	int getHealth() const;
	string getName() const;
	int getAttDamage() const;
	Bosses() {
		maxHealth = 100;
		ATTDamage = 20;
		curHealth = maxHealth;
		Name = "Noname";
	}
};

int Bosses::getHealth() const {
	return curHealth;
}
string Bosses::getName() const {
	return Name;
}
int Bosses::getAttDamage() const {
	return ATTDamage;
}

//Class for main character
class playerCharacter {
	//basic stats for main character
  private:
	int maxHealth;
	string name;

//	int damageTaken;
	//initialization
  public:
	int curHealth;
	int attDamage;
	string getName() const;
	int getAttDamage() const;
	int getHealth() const;

	playerCharacter() {
		maxHealth = 10;
		attDamage = 10;
		curHealth = 10;
	}
	playerCharacter(string name, int maxHealth, int attDamage) {
		setName(name); //Set the player character's name
		setHealth(maxHealth); // Health
		setAttDamage(attDamage); // Attack damage
	}

	void setName(string newName) {
		if (!cin) {
			throw runtime_error("You have a wrong name");
		} else
			name = newName;
	}

	void setHealth(int newHealth) {
		if (newHealth <= 0) {
			throw runtime_error("Your health can't be lower than 1");
		} else
			maxHealth = newHealth;
		curHealth = maxHealth;
	}

	void setAttDamage(int newDamage) {
		if (newDamage <= 0) {
			throw runtime_error("Your damage can't be lower than 1");
		} else
			attDamage = newDamage;
	}
};
//Return stats if asked
string playerCharacter::getName() const {
	return name;
}
int playerCharacter::getAttDamage() const {
	return attDamage;
}
int playerCharacter::getHealth() const {
	return curHealth;
}



//Exit the game when called
void OnDeath() {
	cout << "YOU DIED\n";
	exit(0);
}


int operator- (Bosses& bos, playerCharacter& pla) {


	bos.curHealth -= pla.attDamage;
	return bos.curHealth;
}

int operator+ (Bosses& boss, playerCharacter& play) {

	play.curHealth -= boss.ATTDamage;

	return play.curHealth;

}

//Attack system.. not sure how to work with this yet.


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

	int userhealth, userAtt;
	string userName;

	Bosses firstBoss;

	cout << "Character stats" << endl;
	//Declare playercharacter class
	playerCharacter Mario;

	cout << "What's your name" << endl;
	cin >> userName;
	Mario.setName(userName);

	cout << "Attack Damage" << endl;
	cin >> userAtt;
	Mario.setAttDamage(userAtt);

	cout << "HP" << endl;
	cin >> userhealth;
	Mario.setHealth(userhealth);

	bool battle = false;
	const int ROWS = worldMap.size();
	const int COLUMNS = worldMap.at(0).size();
	int rows = ROWS / 2;
	int columns = COLUMNS / 2;
	int prevRow = -1;
	int prevCol = -1; //previous positions
	int wall = 0;
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
			wall++;/
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
			int choice = 0;
			int loc = 3;
			movecursor(loc, COLUMNS + 5);
			loc++;
			cout << WHITE << "What would you like to do?\n";
			movecursor(loc, COLUMNS + 5);
			loc++;
			cout << RED << "1) Attack " << BLUE << " 2) Dodge\n";
			cin >> choice;
			if (choice == 1) {
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << WHITE << "You chose to attack!" << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << "Boss HP: " << firstBoss - Mario << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << firstBoss.getName() << " Attacked you!\n";
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << "Your HP: " << firstBoss + Mario << endl;
			} else if (choice == 2) {
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << WHITE << "You chose to dodge!" << endl;
			}
		}

	} // while }



	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();

	int lowerBound = 1;
	int upperBound = 6;
	int numRectangles = 5;
	int answer = 0;

	double result;

	result = leftriemannSum(lowerBound, upperBound, numRectangles); // Answer is 979 for future reference.

	cout << "Using Left Riemann Sum, integrate x^4 from 1 to 6 with 5 rectangles" << endl;

	int count = 0;


//	No clue if an attempt limit will be added in future development, only added here for testing purposes




	while (count != 3) {
		cout << "Enter answer: ";
		cin >> answer;
		if (result == answer) {
			cout << "Yippee you did it :DD" << endl;
			return 0;
		} else {
			cout << "womp womp :(, try again" << endl;
		}

		count++;
	}

	if (count == 3) {
		cout << "You failed, try again" << endl;
	}


}
