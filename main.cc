//Fill out this comment with your names and which bullet points you did
//Partners:
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include <string>
#include <iostream>


using namespace std;


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
void OnAttack(int attDamage, const int& other) {

	if (attDamage > 0) {
		curHealth = curHealth - attDamage;
	}

}

//For test purpose
int main() {
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
	}
}
