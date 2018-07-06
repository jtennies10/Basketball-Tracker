//for testing out the classes and object creation
#include "Player.h"
#include "Team.h"
#include "League.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Player p;
	Player steph("Golden State Warriors", "Stephen Curry", "PG", 70, 1400, 256, 201);

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

	std::vector<Player> roster = { p, steph };

	//Test the Team class with the created players
	Team warriors(roster, "Golden State Warriors", 73, 9);
	cout << warriors;
	cout << "Total number of players: " << warriors.getNumPlayers();
	cout << "\nLeading Scorer: " << warriors.getLeadingScorer().getPointsPerGame();
	cout << "\nLeading Assister: " << warriors.getLeadingAssister().getAssistsPerGame();
	cout << "\nLeading Assister: " << warriors.getLeadingRebounder().getReboundsPerGame();
	cout << "\n\nTeam PPG: " << warriors.getTeamPPG();
	cout << "\nTeam APG: " << warriors.getTeamAPG();
	cout << "\nTeam RPG: " << warriors.getTeamRPG() << std::endl;
}