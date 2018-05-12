//for testing out the classes and object creation
#include "Player.h"
#include "Team.h"
#include "League.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Player p;
	Player steph("Stephen Curry", "PG", 70, 1400, 256, 201);

	cout << p;
	cout << "\n\n";
	p.addGamePlayed(28, 10, 4);
	cout << p;
	cout << "\n\n";

	cout << steph;
	cout << "\n\n";
	steph.setInjured(true);
	cout << steph;
	cout << "\n\n";

	cout << steph.getPointsPerGame();

	//TODO:test the team class
}