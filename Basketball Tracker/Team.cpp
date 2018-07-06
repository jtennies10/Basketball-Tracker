//Definition of team class


#include "Team.h"
#include <iomanip>

Team::Team(std::vector<Player> players, std::string teamName, int numWins, int numLosses)
{
	if (players.size() <= 15) {
		this->players = players;
	}
	else {
		this->players = std::vector<Player>();
	}
	this->teamName = teamName;
	this->numWins = numWins;
	this->numLosses = numLosses;

}

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
	return numWins * 1.0 / (numWins + numLosses);
}

double Team::getTeamPPG()
{
	double totalPoints = 0;

	//iterate through the players vector, collecting each players season points
	//since season points is a private variable, calculate it by multiplying a players
	//points per game by their games played
	for (Player p : players) {
		totalPoints += (p.getPointsPerGame() * p.getGamesPlayed());
	}

	//divide total points by total games played to get points per game
	return totalPoints / (numWins + numLosses);
}

double Team::getTeamAPG()
{
	double totalAssists = 0;

	//iterate through the players vector, collecting each players season Assists
	//since season Assists is a private variable, calculate it by multiplying a players
	//Assists per game by their games played
	for (Player p : players) {
		totalAssists += (p.getAssistsPerGame() * p.getGamesPlayed());
	}

	//divide total points by total games played to get points per game
	return totalAssists / (numWins + numLosses);
}

double Team::getTeamRPG()
{
	double totalRebounds = 0;

	//iterate through the players vector, collecting each players season Rebounds
	//since season Rebounds is a private variable, calculate it by multiplying a players
	//Rebounds per game by their games played
	for (Player p : players) {
		totalRebounds += (p.getReboundsPerGame() * p.getGamesPlayed());
	}

	//divide total points by total games played to get points per game
	return totalRebounds / (numWins + numLosses);
}

Player Team::getLeadingScorer()
{
	int leadingScorerIndex = 0;

	for (int i = 0; i < players.size(); i++) {

		//if the current player's points per game is greater than the leading scorer's
		//set the leading scorer index to the current player
		if (players[i].getPointsPerGame() > players[leadingScorerIndex].getPointsPerGame()) {
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

std::vector<Player> Team::getRoster()
{
	return players;
}

void Team::addPlayer(Player & p)
{
	if (players.size() < 15) {
		players.push_back(p);
	}
}

bool Team::removePlayer(std::string playerName)
{
	for (int i = 0; i < players.size(); i++) {
		if (players[i].getName() == playerName) {
			players.erase(players.begin()+i);
			return true;
		}
	}

	return false;
}

/*
Overloads << operator
Prints out team name, record, and win percentage followed by
each players name and position
*/
std::ostream& operator<<(std::ostream & out, Team t)
{
	out << t.getTeamName() << ", " << t.getNumWins() << "-" << t.getNumLosses()
		<< ", " << std::fixed << std::setprecision(3) << t.getWinPercentage() << "\n";
	out << "Roster:\n";
	out << std::fixed << std::setprecision(1);
	for (Player p : t.getRoster()) {
		out << "\t" << p.getName() << ", " << p.getPosition() << "\n";
	}

	out << std::endl;

	return out;
}
