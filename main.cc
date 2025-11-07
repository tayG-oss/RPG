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

//For test purpose
int main() {
	playerCharacter Mario;

	Mario.setName("Mario");
	Mario.setMaxHealth(0);
	Mario.setAttDamage(0);
}
