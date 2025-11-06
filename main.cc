//Fill out this comment with your names and which bullet points you did
//Partners: 
//Bullet Points: 
//Extra Credit: 
//URL to cover art and music: 


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
	miniBoss() {
		health = 100;
		ATTDamage = 20;
		curHealth = maxHealth;
	}
};
//Class for main character
class mainCharacter {
	//basic stats for main character
	private: 
	int maxHealth;
	int curHealth; 
	int ATTDamage;
//	int damageTaken;
	//initialization
	public:
	mainCharacter() {
		maxHealth = 10;
		ATTDamage = 10;
		curHealth = maxHealth;


};

int OnAttack(int ATTDamage, int curHealth) {
	if(attack > 0)
	{
		if(curHealth == 0)
		{
			OnDeath();
		}
		return curHealth - ATTDamage;
	}
	else 
	{
		cout << ("You are doing nothing");
		return 0;
	}

}

void OnDeath {
	cout << "YOU DIED\n";
	exit();
}

