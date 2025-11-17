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

//World Map
vector<string> worldMap = {
	"               -----------               ",
	"              |c          |              ",
	"              |     D     |              ", //Captured Dragon, game ends when dragon is saved!
	"              |           |              ",
	"           |------*****------|           ",
	"           |                 |           ",
	"           |        P        |           ", //Princess Boss Fight (
	"           |                 |           ", // Stage 4 (Final)
	"           |-------| |-------|           ",
	"                 |q    |                 ",
	"                 |     |                 ",
	"                 |*****|                 ",
	"        |--------|     |--------|        ",
	"        |                       |        ",
	"        |      V    H    V      |        ", //Hero Boss Fight, 2 puzzles
	"        |                       |        ", // Stage 3
	"        |                      c|        ",
	"        |---------|   |---------|        ",
	"                  | q |                  ",
	"      |-----------|   |-----------|      ",
	"      |                           |      ",
	"      |    V                c     |      ",
	"      |                           |      ",
	"      |-----------     -----------|      ",
	"                 |     |                 ",
	"      |----------|*****|----------|      ",
	"      |     g                     |      ",
	"      |                         g |      ",
	"      |                       V   |      ",
	"|-----|               g           |-----|", //Basic enemies, 2 puzzles
	"|          V                            |", // Stage 2
	"|                            g          |",
	"|                                       |",
	"| L q                              V    |",
	"|                                       |",
	"|----------------|     |----------------|",
	"                 |  q  |                 ",
	"                 |     |                 ",
	"|----------------|*****|----------------|",
	"| g            L       q                |",
	"|                               V       |", //Tutorial Puzzle, tutorial battle(?), ~Start of adventure~
	"|                                       |", // Stage 1
	"|-----|        V                  |-----|",
	"      |                           |      ", //SYMBOL LEGEND
	"      |                  g        |      ",  // D - Dragon, P - Princess, H - Hero
	"|-----|                           |-----|",  // V - Human Villagers, c - cat:D, g - Goblin Friends
	"|   V                                   |",  // L - Gate Lock, q - Guide Goblins
	"|                                 V     |",
	"|c             g                        |",
	"|-----------------*****-----------------|",
	"                 |    q|               c ",
	"   g             |     |  g              ",
	"                 |     |                 ",
	"                 |*****|                 ",
	"                q              g         ",
	"      g                                  ", //Player Start point (Stage 0)
	"                                         ",

};

//Gets player's location
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
//Constantly updates map/player movement
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
	movecursor(0, 0);
	clearscreen();

	/*int lowerBound = 1;
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
	}*/

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


	const int ROWS = worldMap.size();
	const int COLUMNS = worldMap.at(0).size();

	int rows = 56, columns = 20; //Starting position numbers
	int prevRow = -1, prevCol = -1; //previous positions for printing map
	int barRow = 0, barCol = 0; //previous positions for barriers
	int choice = 0; //User input choice
	int stage = 0; // Player is on current stage
	int completedTask = 0;
	bool battle = false; //Battle mode
	bool stageClear = false; //Whether or not the player has meet the requirements to move on

	set_raw_mode(true);
	show_cursor(false);

	while (true) {
		int c = toupper(quick_read());
		barRow = rows;
		barCol = columns;
		if (c == 'W' or c == UP_ARROW) rows--;
		if (c == 'S' or c == DOWN_ARROW) rows++;
		if (c == 'A' or c == LEFT_ARROW) columns--;
		if (c == 'D' or c == RIGHT_ARROW) columns++;
		if (!(rows == prevRow and columns == prevCol)) {
			printMap(rows, columns);
			prevRow = rows;
			prevCol = columns;
			movecursor(ROWS + 2, 0);
			cout << YELLOW << "ROW: " << rows << RED << " COL: " << columns << RESET; //Temporary line for positions
			cout << YELLOW << " PREVROW: " << barRow << RED << " PREVCOL: " << barCol << RESET; //Temporary line for positions
			movecursor(ROWS + 3, 0);
			cout << YELLOW << "STAGE: " << stage << RED << " Tasks completed: " << completedTask << RESET; //Temporary line for positions
			cout.flush();
		}


		//WALL BARRIERS AND GATES
		if (getLocation(rows, columns) == '-') { //Bottoms and tops
			if (rows == 0) rows++;
			else if (rows == 56) rows--;
			else if (rows == 49) {
				if (barRow == rows - 1) rows--;
				else if (barRow == rows + 1) rows++;
			}
		}  else if (getLocation(rows, columns) == '|') { //Side walls
			if ((columns == 17 or columns == 23) and barCol == columns - 1) columns--;

			else if ((columns == 17 or columns == 23) and rows == 53 and barRow == rows + 1) rows++;

			else if ((columns == 17 or columns == 23) and barCol == columns + 1) columns++;

			else if (columns == 0 or columns == 6 or columns == 18 or columns == 8 or columns == 19 or columns == 11 or columns == 14) columns++;

			else if (columns == 40 or columns == 34 or columns == 22 or columns == 21 or columns == 29 or columns == 26 or columns == 32) columns--;

		} /*else if (getLocation(rows, columns) == '*') { //Gates
			if (completedTask == 0 && stage == 0) {
				movecursor(2, COLUMNS + 5);
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(35, i + 18, ' ');
				completedTask = 0;
				stage = 1;
			} else {
				rows++;
				movecursor(2, COLUMNS + 5);
				cout << "You cannot enter this area yet, the gate is locked.\n";
				usleep(1'000'000);
			}
		} */

		//CHARACTERS AND OBJECTS
		if (getLocation(rows, columns) == 'D') { //End goal/Dragon is saved
			movecursor(2, COLUMNS + 5);
			cout << "Congratulations!!! You've saved the dragon from the evil princess!\n";
			movecursor(3, COLUMNS + 5);
			cout << "The dragon gives you a ride back to your small town village\n and you lived happily ever after!\n";
			movecursor(4, COLUMNS + 5);
			cout << BOLDWHITE << "Thank you for playing our game!\n";
			usleep(5'000'000);
			break;
		}

		if (getLocation(rows, columns) == 'V') { //Enemy encounter
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "You encountered a human villager! They want to fight!\n";
			//battle = true;
		}

		if (getLocation(rows, columns) == 'q') { //Guide Goblins (ones/with neccessary info)
			movecursor(2, COLUMNS + 5);
			if (rows == 54 and columns == 16) { //Outside Goblin
				cout << BOLDGREEN << "COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Oh villager! What are you doing here? It's dangerous to be here right now.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "The knightly goblins are doing a rescure mission to save the dragon from the tyrranical human princess under the Goblin King's orders!\n";
				movecursor(5, COLUMNS + 5);
				cout << WHITE << "You should go back to the village, where it's safe. The knights will handle the mission and claim the gold rew-\n";
				movecursor(6, COLUMNS + 5);
				cout << WHITE << "I MEAN- Save the dragon and recieve NO REWARD whatsoever. Hahaha...\n";
			} else if (rows == 50 and columns == 22) {
				cout << BOLDGREEN << "SELFISH COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "What's a villager doing here?\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "We don't need a random villager to take the gold reward. Leave this instant and go back to the village!\n";
				completedTask = 1;
			}
		}

		if (getLocation(rows, columns) == 'c') { //cat
			if (rows == 50 and columns == 39) { // Outside cat
				movecursor(2, COLUMNS + 5);
				cout << BOLDRED << "SUSPICIOUS CAT:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "You should totally trust me when I say that there's a luck system.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, you're luck has mysteriously gone down.\n";
			}


		}

		/*
		if (getLocation(rows, columns) == 'L') { //Puzzle Lock

		}

		if (getLocation(rows, columns) == 'H') { //Hero encounter

		}

		if (getLocation(rows, columns) == 'P') { // Princess encounter

		}

		*/

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
	}

}
