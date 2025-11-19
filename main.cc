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

//Class for boss
class Villager {
	//basic stats for miniboss
  private:
	int maxHealth;
	string Name;
//  int damageTaken; not sure if this is necessary
	//initialization
  public:
	int ATTDamage;
	int curHealth;
	int getHealth() const;
	string getName() const;
	int getAttDamage() const;
	Villager() {
		maxHealth = 10;
		ATTDamage = 5;
		curHealth = maxHealth;
		Name = "Villager";
	}
};

int Villager::getHealth() const {
	return curHealth;
}
string Villager::getName() const {
	return Name;
}
int Villager::getAttDamage() const {
	return ATTDamage;
}

//Class for boss
class realBosses {
	//basic stats for miniboss
  private:
	int maxHealth;
	string Name;
//  int damageTaken; not sure if this is necessary
	//initialization
  public:
	int ATTDamage;
	int curHealth;
	int getHealth() const;
	string getName() const;
	int getAttDamage() const;
	realBosses() {
		maxHealth = 500;
		ATTDamage = 20;
		curHealth = maxHealth;
		Name = "Princess";
	}
};

int realBosses::getHealth() const {
	return curHealth;
}
string realBosses::getName() const {
	return Name;
}
int realBosses::getAttDamage() const {
	return ATTDamage;
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
		maxHealth = 20;
		ATTDamage = 10;
		curHealth = maxHealth;
		Name = "Hero";
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
	void levelUp(); //AI generated function
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
//AI generated function
void playerCharacter::levelUp() {
	maxHealth += 5; // Increase max HP
	curHealth = maxHealth; // Fully heal and set current HP to new max HP
	attDamage += 2; // Increase attack damage

	// Output confirmation (optional, but good for user feedback)
	cout << YELLOW << "\n*** " << name << " Leveled Up! ***" << RESET << endl;
	cout << "Max HP increased to: " << maxHealth << endl;
	cout << "Attack Damage increased to: " << attDamage << endl;
}

//OnBossDeath is AI generated function
void OnBossDeath(const Bosses& bos) {
	cout << bos.getName() << " has been deafeated! Battle won!\n";
}

void OnRealBossDeath(const realBosses& bos) {
	cout << bos.getName() << " has been deafeated! Battle won!\n";
}

void OnVillagerDeath(const Villager& bos) {
	cout << bos.getName() << " has been deafeated! Battle won!\n";
}

int operator- (Bosses& bos, playerCharacter& pla) {
	bos.curHealth -= pla.attDamage;
	return bos.curHealth;
}

int operator* (realBosses& realbos, playerCharacter& plaa) {
	realbos.curHealth -= plaa.attDamage;
	return realbos.curHealth;
}

int operator/ (realBosses& realboss, playerCharacter & plat) {
	plat.curHealth -= realboss.ATTDamage;
	return realboss.curHealth;
}

int operator% (Villager& vil, playerCharacter& plaaa) {
	vil.curHealth -= plaaa.attDamage;
	return vil.curHealth;
}


int operator+ (Bosses& boss, playerCharacter& play) {

	play.curHealth -= boss.ATTDamage;

	return play.curHealth;
}


//World Map


//Attack system.. not sure how to work with this yet.


vector<string> worldMap = {
	"               -----------               ",
	"              |c          |              ",
	"              |     D     |              ", //Captured Dragon, game ends when dragon is saved!
	"              |--|     |--|              ",
	"           |-----|*****|-----|           ",
	"           |                 |           ",
	"           |        P        |           ", //Princess Boss Fight (
	"           |                 |           ", // Stage 4 (Final)
	"           |-------| |-------|           ",
	"                 |q    |                 ",
	"                 |     |                 ",
	"                 |*****|                 ",
	"        |--------|  L  |--------|        ",
	"        |                       |        ",
	"        |      V    H    V      |        ", //Hero Boss Fight, 1 puzzle
	"        |                       |        ", // Stage 3
	"        |                      c|        ",
	"        |---------|   |---------|        ",
	"                  | q |                  ",
	"      |-----------|   |-----------|      ",
	"      |                           |      ",
	"      |    V                c     |      ",
	"      |                           |      ",
	"      |----------|     |----------|      ",
	"                 |     |                 ",
	"      |----------|*****|----------|      ",
	"      |     g                     |      ",
	"      |                         g |      ",
	"      |                       V   |      ",
	"|-----|               g           |-----|", //Basic enemies, 2 puzzles
	"|c         V                        L   |", // Stage 2
	"|                            g          |",
	"|                                       |",
	"| L                                V    |",
	"|       V                               |",
	"|----------------|     |----------------|",
	"                 |  q  |                 ",
	"                 |     |                 ",
	"|----------------|*****|----------------|",
	"| g            L       q                |",
	"|                               V       |", //2 Puzzles, tutorial battle(?), ~Start of adventure~
	"|                                       |", // Stage 1
	"|-----|        V                  |-----|",
	"      |                           |      ", //SYMBOL LEGEND
	"      |                  g        |      ",  // D - Dragon, P - Princess, H - Hero
	"|-----|                           |-----|",  // V - Human Villagers, c - cat:D, g - Goblin Friends
	"|   V                                 L |",  // L - Gate Lock, q - Guide Goblins
	"|                                 V     |",
	"|c             g                        |",
	"|----------------|*****|----------------|",
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
			else cout << BOLDWHITE << worldMap.at(i).at(j);
		}
		cout << endl;
	}

}

int main() {
	movecursor(0, 0);
	clearscreen();


	int userhealth, userAtt;
	string userName;

	Bosses firstBoss;
	realBosses secondBoss;
	Villager villager;

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
	bool Bossbattle = false; //Battle mode
	bool realBossbattle = false;
	bool Villagerbattle = false;
	bool stageClear = false; //Whether or not the player has meet the requirements to move on
	bool puzzle1 = false;
	bool puzzle2 = false;
	bool puzzle3 = false;
	bool puzzle4 = false;
	bool puzzle5 = false;
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
			movecursor(12, COLUMNS + 5);
			cout.flush();
		}



		bool defeatH = false;
		while (Bossbattle == true) {
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
				if (firstBoss.curHealth <= 0) {
					defeatH = true;
					OnBossDeath(firstBoss);
					Bossbattle = false;
					break;
				}
				cout << firstBoss.getName() << " Attacked you!\n";
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << "Your HP: " << firstBoss + Mario << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				//This if statement is AI generated
				if (Mario.curHealth <= 0) {
					OnDeath();
				}
			}    else if (choice == 2) {
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << WHITE << "You chose to dodge!" << endl;
			}
		}

		while (Villagerbattle == true) {
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
				cout << "Boss HP: " << villager % Mario << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				if (villager.curHealth <= 0) {
					OnVillagerDeath(villager);
					Villagerbattle = false;
					break;
				}
				cout << villager.getName() << " Attacked you!\n";
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << "Your HP: " << Mario.getHealth() << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				//This if statement is AI generated
				if (Mario.curHealth <= 0) {
					OnDeath();
				}
			}    else if (choice == 2) {
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << WHITE << "You chose to dodge!" << endl;
			}
		}

		bool defeat = false;
		while (realBossbattle == true) {
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
				cout << "Boss HP: " << secondBoss * Mario << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				if (secondBoss.curHealth <= 0) {
					defeat = true;
					OnRealBossDeath(secondBoss);
					realBossbattle = false;
					break;
				}
				cout << secondBoss.getName() << " Attacked you!\n";
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << "Your HP: " << secondBoss / Mario << endl;
				movecursor(loc, COLUMNS + 5);
				loc++;
				//This if statement is AI generated
				if (Mario.curHealth <= 0) {
					OnDeath();
				}
			}    else if (choice == 2) {
				movecursor(loc, COLUMNS + 5);
				loc++;
				cout << WHITE << "You chose to dodge!" << endl;
			}
		}

		//WALL BARRIERS AND GATES
		if (getLocation(rows, columns) == '-') { //Bottoms and tops
			if (rows == 0 or rows == 12 or rows == 19 or rows == 25 or rows == 29 or rows == 38 or rows == 45) rows++;
			if (rows == 17 or rows == 23 or rows == 35 or rows == 42) rows --;
			else if (rows == 4 or rows == 8 or rows == 49) {
				if (barRow == rows - 1) rows--;
				else if (barRow == rows + 1) rows++;
			}
		}  else if (getLocation(rows, columns) == '|') { //Side walls
			if (columns == 17 or columns == 23) {
				if (barCol == columns - 1) columns--;
				else if (barCol == columns + 1) columns++;
				else if (rows == 49 or rows == 38 or rows == 35 or rows == 25 or rows == 23 or rows == 9 or rows == 12 or rows == 4 or rows == 3 or rows == 53) {
					if (barRow == rows - 1) rows--;
					else if (barRow == rows + 1) rows++;
				}
			} else if (columns == 0 or columns == 6 or columns == 18 or columns == 8 or columns == 19 or columns == 11 or columns == 14) columns++;
			else if (columns == 40 or columns == 34 or columns == 22 or columns == 21 or columns == 29 or columns == 26 or columns == 32) columns--;

		} else if (getLocation(rows, columns) == '*') { //Gates ( 53, 49, 38, 25, 11, 4)
			movecursor(2, COLUMNS + 5);
			if (completedTask == 1 && stage == 0 and rows == 53) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(53, i + 18, ' ');
			} else if (completedTask == 2 and stage == 0 and rows == 49) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(49, i + 18, ' ');
				stage = 1;
			} else if (puzzle1 == true and puzzle2 == true and stage == 1 and rows == 38) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(38, i + 18, ' ');
				stage = 2;
			} else if (puzzle3 == true and puzzle4 == true and stage == 2 and rows == 25) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(25, i + 18, ' ');
				stage = 3;
			} else if (defeatH == true and puzzle5 == true and stage == 3 and rows == 11) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(11, i + 18, ' ');
			} else if (defeat == true and rows == 4) {
				cout << "The gate has been unlocked.\n";
				for (int i = 0; i < 5; i++) setLocation(4, i + 18, ' ');
			} else {
				rows++;
				cout << "You cannot enter this area yet, the gate is locked.\n";
				usleep(1'000'000);
			}
		}

		//CHARACTERS AND OBJECTS
		if (getLocation(rows, columns) == 'D') { //End goal/Dragon is saved
			movecursor(2, COLUMNS + 5);
			cout << "Congratulations!!! You've saved the dragon from the evil princess!\n";
			movecursor(3, COLUMNS + 5);
			cout << "The dragon gives you a ride back to your small town village and you lived happily ever after!\n";
			movecursor(4, COLUMNS + 5);
			cout << WHITE << "Thank you for playing our game!\n";
			usleep(4'000'000);
			break;
		}

		if (getLocation(rows, columns) == 'V') { //Enemy encounter
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "You encountered a human villager! They want to fight!\n";
			Villagerbattle = true;
		}

		if (getLocation(rows, columns) == 'H') { //Hero encounter
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "HERO OF THE HUMAN KINGDOM:\n";
			movecursor(3, COLUMNS + 5);
			cout << WHITE << "I will not let you harm the princess. I will kill you before you even get the chance.\n";
			Bossbattle = true;
		}

		if (getLocation(rows, columns) == 'P') { //Princess encounter
			setLocation(rows, columns, ' ');
			movecursor(2, COLUMNS + 5);
			cout << BOLDRED << "PRINCESS OF THE HUMAN KINGDOM:\n";
			movecursor(2, COLUMNS + 5);
			cout << WHITE << "Oh, someone actually managed to reach this far. But that doesn't matter now, does it?";
			movecursor(4, COLUMNS + 5);
			cout << WHITE << "This is where you will breath your last breath.";
			realBossbattle = true;
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
				completedTask = 1;
			} else if (rows == 50 and columns == 22) {
				cout << BOLDGREEN << "SELFISH COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "What's a villager doing here?\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "We don't need a random villager to take the gold reward. Leave this instant and go back to the village!\n";
				completedTask = 2;
			} else if (rows == 39 and columns == 23) {
				cout << BOLDGREEN << "COMMANDER GOBLIN WITH POOR EYE-SIGHT:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "The gate closed on us right when we were storming the castle! The rest of the troops are on the other side.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "There's some locks somewhere, but I can't seem to find any. Maybe you can spot them for me?\n";
				//completedTask = 2;
			} else if (rows == 36 and columns == 20) {
				cout << BOLDGREEN << "RELIEVED COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Oh thank goodness! You finally got the gate open!\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "The dragon is further up ahead, but there's more locks in the way. We need to hurry to get the gold!\n";
				movecursor(5, COLUMNS + 5);
				cout << WHITE << "Have this potion to heal yourself up! The more hands on deck, the quicker we can get the gold.\n";
				//HP Heal
				//completedTask = 2;
			} else if (rows == 18 and columns == 20) {
				cout << BOLDGREEN << "LAZY COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "The hero is just past this way. I don't want to deal with him.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Here kid, here's a healing potion. Take it and defeat the human hero for me.\n";
				//HP Heal
				//completedTask = 2;
			} else if (rows == 9 and columns == 18) {
				cout << BOLDGREEN << "SCARED COMMANDER GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Look man, I have no idea how I got this far. I do NOT want to be the one to deal with the princess.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "I do NOT want to die, so take this potion and deal with her for me.\n";
				//HP Heal
			}
		}

		if (getLocation(rows, columns) == 'g') { //Goblins
			movecursor(2, COLUMNS + 5);
			if (rows == 55 and columns == 6) {
				cout << BOLDGREEN << "GOBLIN SOLDIER:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "I really don't hate doing my job. But at the same time I hate the human princess even more, so...\n";
			} else if (rows == 51 and columns == 3) {
				cout << BOLDGREEN << "TIRED GOBLIN SOLDIER:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Do you think we'll be done with this mission before 5 PM? I want to go home already.\n";
			} else if (rows == 54 and COLUMNS == 31) {
				cout << BOLDGREEN << "GOBLIN SOLDIER:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Knowing how the commanders are, they'll probably take all the reward gold for themselves.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "It's not really fair considering most of them are hiding instead of fighting.\n";
			} else if (rows == 51 and columns == 26) {
				cout << BOLDGREEN << "CONFUSED GOBLIN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "What the heck am I doing here? I'm not even a soldier, I shouldn't be here.\n";
			} else if (rows == 48 and columns == 15) {
				cout << BOLDGREEN << "GOBLIN SOLDIER:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "I've been trying to get farther into the castle, but the humans keep attacking me!\n";
			} else if (rows == 44  and columns == 25) {
				cout << BOLDGREEN << "GOBLIN SOLDIER WHO'S NOT INTO ARSON:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "WE NEED TO SAVE THE DRAGON!!! THEN WE CAN BURN THE PRINCESS'S CASTLE!!!\n";
				//AI GENERATED CODE FROM CO-PILOT
			} else if (rows == 39 and columns == 2) {
				cout << BOLDGREEN << "NERVOUS GOBLIN SCOUT:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "I saw something move in the shadows... I think the humans have a wizard!\n";
			} else if (rows == 31 and columns == 29) {
				cout << BOLDGREEN << "GOBLIN SOLDIER WITH A PLAN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "If we sneak through the kitchen, we might reach the throne room undetected!\n";
			} else if (rows == 27 and columns == 32) {
				cout << BOLDGREEN << "EXHAUSTED GOBLIN VETERAN:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "I've fought in three sieges and still haven't seen the dragon. Is it even real?\n";
				//NO LONGER AI GENERATED CODE
			} else if (rows == 26 and columns == 12) {
				cout << BOLDGREEN << "GOBLIN SOLDIER:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "So are we gonna defeat the princess? Or like, actually kill her?\n";
			} else if (rows == 29 and columns == 22) {
				cout << BOLDGREEN << "GOBLIN SOLDIER WHO MIGHT BE DYING:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Just because I have a sword stuck in my chest, DOES NOT MEAN that I'm dying.\n";
			}
		}

		if (getLocation(rows, columns) == 'c') { //cat
			movecursor(2, COLUMNS + 5);
			if (rows == 50 and columns == 39) { // Outside cat
				cout << BOLDRED << "SUSPICIOUS CAT:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "You should totally trust me when I say that there's a luck system.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, your luck has mysteriously gone down.\n";
			} else if (rows == 48 and columns == 1) {
				cout << BOLDRED << "SUSPICIOUS CAT #2:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Do you still believe that there's a luck system?\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, your luck has increased by 5%.\n";
			} else if (rows == 30 and columns == 1) {
				cout << BOLDRED << "SUSPICIOUS CAT #3:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "The luck system is real and you should believe in it. Aliens are real too.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, your luck did not change whatsoever.\n";
			} else if (rows == 21 and columns == 28) {
				cout << BOLDRED << "SUSPICIOUS CAT #4:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "There is no luck system. And there never was.\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, your luck has decreased by 10%.\n";
			} else if (rows == 16 and columns == 31) {
				cout << BOLDRED << "SUSPICIOUS CAT #5:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "You've made it so far! Even without using the luck system!\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, your luck has been multiplied by 0.\n";
			} else if (rows == 1 and columns == 15) {
				cout << BOLDRED << "SUSPICIOUS CAT #6:\n";
				movecursor(3, COLUMNS + 5);
				cout << WHITE << "Why did you go to the cat before the dragon?\n";
				movecursor(4, COLUMNS + 5);
				cout << WHITE << "Anyways, since you went to the cat, you don't get to save the dragon.\n";
				movecursor(5, COLUMNS + 5);
				cout << WHITE << "Thanks for playing!!! <3\n";
				usleep(4'000'000);
				break;
			}
		}


		if (getLocation(rows, columns) == 'L') { //Puzzle Locks
			if (rows == 39 and columns == 15) {
				//LOCK #1; //  puzzle 5:
				string ansRiddle;
				string ans;
				string ansActual = "an echo";
				movecursor(2, COLUMNS + 5);
				cout << "I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?" << endl;

				while (true) {
					getline(cin, ans);
					for (char &c : ans) c = tolower(c);

					if (ans == ansActual) {
						movecursor(3, COLUMNS + 5);
						cout << "you can pass" << endl;
						break;
					} else {
						movecursor(3, COLUMNS + 5);
						cout << "no" << endl;
					}
				}
				rows = 40;
				puzzle1 = true;

			} else if (rows == 46 and columns == 38) {
				//LOCK #2:
				int a = 3;
				string word1 = "cabbage";
				string w1;
				string word2 = "abbreviation";
				string w2;
				string word3 = "discombobulated";
				string w3;
				string word4 = "deinstitutionalisation";
				string w4;
				int mistakes = 0;
				movecursor(2, COLUMNS + 5);
				cout << "Four words to unscramble...Good luck" << endl;
				movecursor(a, COLUMNS + 5);
				cout << "Unscramble aeagbcb" << endl;

				while (true) {
					cin >> w1;
					for (char &c : w1) c = tolower(c);
					if (w1 == word1) {
						movecursor(a + 1, COLUMNS + 5);
						cout << "Good job, next word" << endl;
						break;
					} else {
						mistakes++;
					}
				}
				movecursor(a + 1, COLUMNS + 5);
				cout << "Unscramble nrvbeiiaobat" << endl;

				while (true) {
					cin >> w2;
					for (char &c : w2) c = tolower(c);

					if (w2 == word2) {
						movecursor(a + 1, COLUMNS + 5);
						cout << "Good job, next word" << endl;
						break;
					} else {
						mistakes++;
					}
				}
				movecursor(a + 1, COLUMNS + 5);
				cout << "Unscramble toaoddbibesmcul" << endl;

				while (true) {
					cin >> w3;
					for (char &c : w3) c = tolower(c);

					if (w3 == word3) {
						movecursor(a + 1, COLUMNS + 5);
						cout << "Good job, next word" << endl;
						break;
					} else {
						mistakes++;
					}
				}
				movecursor(a + 1, COLUMNS + 5);
				cout << "Unscramble ztonniiiotiseuditalant" << endl;

				while (true) {
					cin >> w4;
					for (char &c : w4) c = tolower(c);

					if (w4 == word4) {
						movecursor(a + 1, COLUMNS + 5);
						cout << "Good job, no more words" << endl;
						puzzle2 = true;
						rows = 47;
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
			} else if (rows == 30 and columns == 36) {
				//LOCK #3:
				int start = 1;
				int end = 30;
				int attempts = 0;
				int max_attempts = 5;
				int mistake = 0;
				int a = 0;

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
				movecursor(a + 1, COLUMNS + 5);
				cout << "FizzBuzz again...But with a really really really fun twist :D" << endl;
				movecursor(a + 1, COLUMNS + 5);
				cout << "New Ruels: " << endl;
				movecursor(a + 1, COLUMNS + 5);
				cout << "Numbers divisible by 11 are now uh-lehvuhntean" << endl;
				movecursor(a + 1, COLUMNS + 5);
				cout << "Numbers divisible by 13 are now deurtuahtiang" << endl;
				movecursor(a + 1, COLUMNS + 5);
				cout << "Numbers divisible by 14 are now 3x + 2 = 44" << endl;
				movecursor(a + 1, COLUMNS + 5);
				cout << "good luck :)" << endl;
				movecursor(a + 1, COLUMNS + 5);
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
						puzzle3 = true;
						rows = 29;
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
			} else if (rows == 33 and columns == 2) {
				//LOCK #4:
				string word;
				cout << "Enter a word:" << endl;
				cin >> word;
				int a = 2;

				string reversed;

				for (int i = word.size() - 1; i >= 0; i--) { // ai fixed for loop
					reversed += word.at(i);
				}

				if (word == reversed) {
					movecursor(a + 1, COLUMNS + 5);
					cout << "Congrats, you know a word that's reversed." << endl;
					puzzle4 = true;
					rows = 34;
				} else {
					movecursor(a + 1, COLUMNS + 5);
					cout << "you fail" << endl;
				}
			} else if (rows == 12 and columns == 20) {
				//LOCK #5:
				int lowerBound = 1;
				int upperBound = 6;
				int numRectangles = 5;
				int answer = 0;
				int a = 2;
				double result;

				result = leftriemannSum(lowerBound, upperBound, numRectangles); // Answer is 979 for future reference.

				// Puzzle #1:
				movecursor(a + 1, COLUMNS + 5);
				cout << "Using Left Riemann Sum, find the area under x^4 from 1 to 6 with 5 rectangles" << endl;

				int count = 0;

				while (count != 3) {
					movecursor(a + 1, COLUMNS + 5);
					cout << "Enter answer: ";
					cin >> answer;
					if (result == answer) {
						movecursor(a + 1, COLUMNS + 5);
						cout << "Yippee you did it :DD" << endl;
						puzzle5 = true;
						rows = 13;
						break;
					} else {
						movecursor(a + 1, COLUMNS + 5);
						cout << "womp womp :(, try again" << endl;
					}

					count++;
				}

				if (count == 3) {
					movecursor(a + 1, COLUMNS + 5);
					cout << "You failed, try again" << endl;
				}

			}
		}

	}
	set_raw_mode(false);
	show_cursor(true);
	movecursor(0, 0);
	clearscreen();

}

