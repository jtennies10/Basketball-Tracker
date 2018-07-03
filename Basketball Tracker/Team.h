//Declaration of Team Class

#pragma once
#include <vector>
#include "Player.h"

class Team {
private:

	//vector containing all the players on a team, will hold a max of 15 players
	std::vector<Player> players; 

	//holds location and name
	std::string teamName; 
	
	//number of season wins
	int numWins;

	//number of season losses
	int numLosses;

public:

	/*Constructor providing default values for a team
	players will only take vectors of size 15 or less(the max roster size in the nba
	
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

	/*Adds a player to the team if there is space
	Sets the players team to the team name

	@param p The player to be added to the team
	*/
	void addPlayer(Player &p);

	/*Removes a player from the team if a match is found

	@param playerName The name of the player to be removed if found
	@return true if the player was found, false if not
	*/
	bool removePlayer(std::string playerName);
	
	
	
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

