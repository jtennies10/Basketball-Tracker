//Definition of team class


#include "Team.h"
#include <iomanip>


std::string Team::getTeamName()
{
	return teamName;
}

int Team::getNumWins()
{
	return numWins;
}

int Team::getNumLosses()
{
	return numLosses;
}

int Team::getNumPlayers()
{
	return players.size();
}

//calculates and returns team win percentage
double Team::getWinPercentage()
{
	return numWins / (numWins + numLosses);
}

double Team::getTeamPPG()
{
	double ppg = 0;

	//iterate through the players vector, collecting each players points per game
	for (Player p : players) {
		ppg += p.getPointsPerGame();
	}

	return ppg;
}

double Team::getTeamAPG()
{
	double apg = 0;

	//iterate through the players vector, collecting each players assists per game
	for (Player p : players) {
		apg += p.getAssistsPerGame();
	}

	return apg;
}

double Team::getTeamRPG()
{
	double rpg = 0;

	//iterate through the players vector, collecting each players assists per game
	for (Player p : players) {
		rpg += p.getReboundsPerGame();
	}

	return rpg;
}

Player Team::getLeadingScorer()
{
	int leadingScorerIndex = 0;

	for (int i = 0; i < players.size(); i++) {

		//if the current player's points per game is greater than the leading scorer's
		//set the leading scorer index to the current player
		if(players[i].getPointsPerGame() > players[leadingScorerIndex].getPointsPerGame()) {
			leadingScorerIndex = i;
		}
	}

	return players[leadingScorerIndex];
}

Player Team::getLeadingRebounder()
{
	int leadingRebounderIndex = 0;

	for (int i = 0; i < players.size(); i++) {

		//if the current player's rebounds per game is greater than the leading rebounder's
		//set the leading rebounder index to the current player
		if (players[i].getReboundsPerGame() > players[leadingRebounderIndex].getReboundsPerGame()) {
			leadingRebounderIndex = i;
		}
	}

	return players[leadingRebounderIndex];
}

Player Team::getLeadingAssister()
{
	int leadingAssisterIndex = 0;

	for (int i = 0; i < players.size(); i++) {

		//if the current player's assists per game is greater than the leading assister's
		//set the leading assister index to the current player
		if (players[i].getAssistsPerGame() > players[leadingAssisterIndex].getAssistsPerGame()) {
			leadingAssisterIndex = i;
		}
	}

	return players[leadingAssisterIndex];
}

/*
Overloads << operator
Prints out team name, record, and win percentage followed by
each players name and position
*/
std::ostream & operator<<(std::ostream & out, Team t)
{
	out << t.getTeamName() << ", " << t.getNumWins() << "-" << t.getNumLosses()
		<< ", " << std::fixed << std::setprecision(3) << t.getWinPercentage() << "\n";
	out << "Roster:\n";
	for (Player p : t.players) {
		out << p.getName() << ", " << p.getPosition() << "\n";
	}
}
