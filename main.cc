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
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <cmath>
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
	int curHealth;
	int ATTDamage;
	string Name;
//	int damageTaken; not sure if this is necessary
	//initialization
  public:
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
	int curHealth;
	int attDamage;
	string name;

//	int damageTaken;
	//initialization
  public:
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

//Attack system.. not sure how to work with this yet.
/* void OnAttack(int attDamage, const int& other) {

	if (attDamage > 0) {
		curHealth = curHealth - attDamage;
	}

} */


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

	int lowerBound = 1;
	int upperBound = 6;
	int numRectangles = 5;
	int answer = 0;

	double result;

	result = leftriemannSum(lowerBound, upperBound, numRectangles); // Answer is 979 for future reference.

	// Puzzle #1:
	cout << "Using Left Riemann Sum, integrate x^4 from 1 to 6 with 5 rectangles" << endl;

	int count = 0;


	//  No clue if an attempt limit will be added in future development, only added here for testing
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

	int userhealth, userAtt;
	string userName;
	bool isCombat = true;

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

	//Combat System
	while (isCombat) {
		int i = 0;
		cout << "1. Attack\n";
		cout << "2. Dodge\n";
		cout << "3. My Stats\n";
		cout << "4. Enemy Stats\n";
		cout << "-1 to run away\n";
		cin >> i;

		if (i == -1) {
			isCombat = false;
		}/* else if (i == 1) {
			OnAttack(Mario.getAttDamage(), firstBoss.getHealth());
		}*/ else if (i == 3) {
			cout << "Name: " << Mario.getName() << endl;
			cout << "Attack Damage: " << Mario.getAttDamage() << endl;
			cout << "HP: " << Mario.getHealth() << endl;
		} else if (i == 4) {
			cout << "Name: " << firstBoss.getName() << endl;
			cout << "Attack Damage: " << firstBoss.getAttDamage() << endl;
			cout << "HP: " << firstBoss.getHealth() << endl;
		}
	}/*
	// puzzle 2:
	int start = 1;
	int end = 30;
	int attempts = 0;
	int max_attempts = 5;
	int mistake = 0;

	vector<string> sequence(30);

	for (int i = start; i <= end; i++) {
		if (i % 15 == 0) {
			sequence.at(i - 1) = "fizzbuzz";
		} else if (i % 14 == 0) {
			sequence.at(i - 1) = "3x + 2 = 44";
		} else if (i % 13 == 0) {
			sequence.at(i - 1) = "deurtuahtiang";
		} else if (i % 11 == 0) {
			sequence.at(i - 1) = "uh-lehvuhntean";
		} else if (i % 5 == 0) {
			sequence.at(i - 1) = "buzz";
		} else if (i % 3 == 0) {
			sequence.at(i - 1) = "fizz";
		} else {
			sequence.at(i - 1) = to_string(i);
		}
	}

	cout << "FizzBuzz again...But with a really really really fun twist :D" << endl;
	cout << "New Ruels: " << endl;
	cout << "Numbers divisible by 11 are now uh-lehvuhntean" << endl;
	cout << "Numbers divisible by 13 are now deurtuahtiang" << endl;
	cout << "Numbers divisible by 14 are now 3x + 2 = 44" << endl;
	cout << "good luck :)" << endl;
	cout << "Complete the sequence in one shot from " << start << " to " << end << ":" << endl;

	while (attempts < max_attempts) {
		for (int i = 0; i < sequence.size(); i++) {
			string fb;
			getline(cin, fb);
			if (fb != sequence.at(i)) {
				mistake++;
			}
		}

		if (mistake == 0) {
			cout << "Congrats, you did it!" << endl;
			break;
		} else {
			attempts++;
		}
		if (attempts < max_attempts) {
			cout << "Redo the fizzbuzz sequence from " << start << " to " << end << ":" << endl;
		} else {
			cout << "You failed the sequence :(...womp womp" << endl;
		}
	}

	// puzzle 3:
	string word1 = "cabbage";
	string w1;
	string word2 = "abbreviation";
	string w2;
	string word3 = "discombobulated";
	string w3;
	string word4 = "deinstitutionalisation";
	string w4;
	int mistakes = 0;

	cout << "Four words to unscramble...Good luck" << endl;

	cout << "Unscramble aeagbcb" << endl;

	while (true) {
		cin >> w1;
		for (char &c : w1) c = tolower(c);

		if (w1 == word1) {
			cout << "Good job, next word" << endl;
			break;
		} else {
			mistakes++;
		}
	}

	cout << "Unscramble nrvbeiiaobat" << endl;

	while (true) {
		cin >> w2;
		for (char &c : w2) c = tolower(c);

		if (w2 == word2) {
			cout << "Good job, next word" << endl;
			break;
		} else {
			mistakes++;
		}
	}

	cout << "Unscramble toaoddbibesmcul" << endl;

	while (true) {
		cin >> w3;
		for (char &c : w3) c = tolower(c);

		if (w3 == word3) {
			cout << "Good job, next word" << endl;
			break;
		} else {
			mistakes++;
		}
	}

	cout << "Unscramble ztonniiiotiseuditalant" << endl;

	while (true) {
		cin >> w4;
		for (char &c : w4) c = tolower(c);

		if (w4 == word4) {
			cout << "Good job, next word" << endl;
			break;
		} else {
			mistakes++;
		}
	}
	if (mistakes == 0) {
		cout << "Hooray no mistakes :DD" << endl;
	} else if (mistakes == 1) {
		cout << "You made one mistake :)" << endl;
	} else {
		cout << "You made " << mistakes << " mistakes ;(" << endl;
	}*/

}
