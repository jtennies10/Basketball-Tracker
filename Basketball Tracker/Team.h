//Declaration of Team Class

#pragma once
#include <vector>
#include "Player.h"

class Team {
private:

	//vector containing all the players on a team
	std::vector<Player> players; 

	//holds location and name
	std::string teamName; 
	
	//number of season wins
	int numWins;

	//number of season losses
	int numLosses;

public:

	/*Constructor providing default values for a team
	
	@param players A vector containing the players for a team
	@param teamName The name of the team
	@param numWins The team's number of wins this season
	@param numLosses The team's number of losses this season
	*/
	Team(std::vector<Player> players = std::vector<Player>(), std::string teamName="Expansion Team", 
		int numWins=0, int numLosses=0);

	std::string getTeamName();

	int getNumWins();
	
	int getNumLosses();
	
	int getNumPlayers();

	double getWinPercentage(); 
	
	double getTeamPPG();
	
	double getTeamAPG();
	
	double getTeamRPG();
	
	Player getLeadingScorer();
	
	Player getLeadingRebounder();
	
	Player getLeadingAssister();

	std::vector<Player> getRoster();

	//TODO:create addPlayer function
	//TODO:create removePlayer function
	//TODO:add sortByPlayerName function
	//TODO:add sortByPlayerPosition function
	//TODO:add sortByPlayerPPG function
	//TODO:add sortByPlayerRPG function
	//TODO:add sortByPlayerAPG function


	
};

/*
Overloads << operator
Prints out team name, record, and win percentage followed by
each players name and position
*/
std::ostream& operator<<(std::ostream &out, Team t);

