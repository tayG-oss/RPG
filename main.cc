//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;



//Class for miniboss
class Bosses {
	//basic stats for miniboss
  private:
	int maxHealth;
	int curHealth;
	int ATTDamage;
//	int damageTaken; not sure if this is necessary
	//initialization
  public:
	Bosses() {
		maxHealth = 100;
		ATTDamage = 20;
		curHealth = maxHealth;
	}
};
//Class for main character
class playerCharacter {
	//basic stats for main character
  private:
	int maxHealth;
	int curHealth;
	int attDamage;
	string name;

//	int damageTaken;
	//initialization
  public:
	string getName() const;
	int getAttDamage() const;
	int getMaxHealth() const;

	playerCharacter() {
		maxHealth = 10;
		attDamage = 10;
		curHealth = maxHealth;
	}
	playerCharacter(string name, int maxHealth, int attDamage) {
		setName(name); //Set the player character's name
		setMaxHealth(maxHealth); // Health
		setAttDamage(attDamage); // Attack damage
	}

	void setName(string newName) {
		if (!cin) {
			throw runtime_error("You have a wrong name");
		} else
			name = newName;
	}

	void setMaxHealth(int newHealth) {
		if (newHealth <= 0) {
			throw runtime_error("Your health can't be lower than 1");
		} else
			maxHealth = newHealth;
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
int playerCharacter::getMaxHealth() const {
	return maxHealth;
}

//Exit the game when called
void OnDeath() {
	cout << "YOU DIED\n";
	exit(0);
}

//Attack system.. not sure how to work with this yet.
int OnAttack(int ATTDamage, int curHealth) {
	if (ATTDamage > 0) {
		if (curHealth == 0) {
			OnDeath();
		}
		return curHealth - ATTDamage;
	} else {
		cout << ("You are doing nothing");
		return 0;
	}

}


vector<string> worldMap = {
	"-----------------------------------------",
	"|    c                                  |",
	"|                               e       |",
	"|                                       |",
	"|                                       |",
	"|***************************************|",
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
	int rows = ROWS / 2, columns = COLUMNS / 2;
	int prevRow = -1, prevCol = -1; //previous positions
	int choice = 0; //User input choice
	int wall = 0; // Might get rid of later idk
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

		if (getLocation(rows, columns) == 'e') { //Enemy encounter
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "ENEMY ENCOUNTERED\n";
			battle = true;
		}

		//Dumb wall easter egg, don't worry about it
		if (getLocation(rows, columns) == '-' or getLocation(rows, columns) == '|') {
			movecursor(2, COLUMNS + 5);
			cout << "That's a wall\n";
		} else if (getLocation(rows, columns) == '*') {
            movecursor(2, COLUMNS + 5);
            cout << "You may not enter this area yet. Please [insert action]\n";
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


		if (getLocation(rows, columns) == 'c') { //Temp end goal of the game. Stops game
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
