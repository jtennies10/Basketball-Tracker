//Declaration of Team Class

#pragma once
#include <vector>
#include "Player.h"

class Team {
private:
	std::vector<Player> players;

	std::string teamName; //holds location and name
	
	int numWins;
	int numLosses;

public:
	Team(std::vector<Player> players, std::string teamName="Expansion Team", 
		int numWins=0, int numLosses=0);

	std::string getTeamName();

	int getNumWins();
	int getNumLosses();
	int getNumPlayers();

	double getWinPercentage(); //calculates and returns team win percentage
	double getTeamPPG(); //returns team points per game
	double getTeamAPG(); //returns team assists per game
	double getTeamRPG(); //returns team rebounds per game
	
	Player getLeadingScorer(); //returns leading scorer on the team
	Player getLeadingRebounder(); //returns leading rebounder on the team
	Player getLeadingAssister(); //returns leading assister on the team

	std::vector<Player> getRoster();
	
};

/*
Overloads << operator
Prints out team name, record, and win percentage followed by
each players name and position
*/
std::ostream& operator<<(std::ostream &out, Team t);

