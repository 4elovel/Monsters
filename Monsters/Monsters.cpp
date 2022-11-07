#include <iostream>
#include <deque>
#include <string>
#include <windows.h>

using namespace std;

class Monsters
{
public:

	virtual void printMonster() = 0;
	void getDamage() {
		int choice;
		cout << "1 - punch(10 damage)\n";
		cout << "2 - kick(15 damage)\n";
		cout << "3 - cast fireball(60 damage)\n";
		cin >> choice;
		switch (choice)
		{
		case(1):
			c_health -= 10;
			l_hit = 10;
			break;
		case(2):
			c_health -= 15;
			l_hit = 15;
			break;
		case(3):
			c_health -= 60;
			l_hit = 60;
			break;
		default:
			break;
		}
		printMonster();
	}

	int c_health;

protected:
	string name;
	int max_health;
	int l_hit;
};

class Orc : public Monsters
{
public:
	Orc(string name) {
		this->name = name;
		max_health = 120;
		c_health = 120;
		l_hit = 0;
	}

	void printMonster() override {
		cout << "Huge orc " << name << " with big muscles is attacking you!\n";
		cout << "He have " << c_health << " health now\n";
		cout << "last your hit dealed " << l_hit << " damage to him\n";
	}
};


class Troll : public Monsters
{
public:
	Troll(string name) {
		this->name = name;
		max_health = 100;
		c_health = 100;
		l_hit = 0;
	}

	void printMonster() override {
		cout << "Ugly troll " << name << " with cudgel is attacking you!\n";
		cout << "He have " << c_health << " health now\n";
		cout << "last your hit dealed " << l_hit << " damage to him\n";
	}
};


class Zombie : public Monsters
{
public:
	Zombie(string name) {
		this->name = name;
		max_health = 70;
		c_health = 70;
		l_hit = 0;
	}

	void printMonster() override {
		cout << "Slow zombie " << name << " with sharp nails is attacking you!\n";
		cout << "He have " << c_health << " health now\n";
		cout << "last your hit dealed " << l_hit << " damage to him\n";
	}
};


class Goblin : public Monsters
{
public:
	Goblin(string name) {
		this->name = name;
		max_health = 40;
		c_health = 40;
		l_hit = 0;
	}

	void printMonster() override {
		cout << "Fast goblin " << name << " with little knife is attacking you!\n";
		cout << "He have " << c_health << " health now\n";
		cout << "last your hit dealed " << l_hit << " damage to him\n";
	}
};



int main()
{
	cout << "----------Start game----------\n\n";
	Sleep(1000);
	deque <Monsters*> mon;
	Orc orc("Jake");
	mon.push_back(&orc);
	Troll troll("Vasya");
	mon.push_back(&troll);
	Zombie zombie("Vanya");
	mon.push_back(&zombie);
	Goblin goblin("Oleg");
	mon.push_back(&goblin);

	for (size_t i = 0; i < mon.size(); i++)
	{
		mon[i]->printMonster();
		while (mon[i]->c_health>0)
		{
			int choice;
			cout << "1 - to info!\n";
			cout << "2 - to fight!\n";
			cin >> choice;
			switch (choice)
			{
			case(1):	mon[i]->printMonster();
				break;
			case(2):	mon[i]->getDamage();
				break;
			default:
				break;
			}
		}
		cout << "YOU WON FIGHT!\n";
	}
	system("CLS");
	cout << "\nYOU HAVE KILLED ALL ENEMIES!!\n";
	cout << "CONGRATULATIONS!!!!!!!!\n";
}
