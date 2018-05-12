//Class declaration of Player

#pragma once
#include <string>
#include <ostream>
#include <iomanip>

class Player {
private:
	std::string name;
	std::string position;

	//season totals for games played, points, assists, rebounds
	int gamesPlayed;
	int seasonPoints;
	int seasonAssists;
	int seasonRebounds;

	bool injured;

public:
	//constructor with default parameters
	Player(std::string name = "Unknown", std::string position = "NA", int gamesPlayed = 0, int seasonPoints = 0,
		int seasonAssists = 0, int seasonRebounds = 0, bool injured = false);

	std::string getName();
	std::string getPosition();

	int getGamesPlayed();
	double getPointsPerGame();
	double getAssistsPerGame();
	double getReboundsPerGame();
	bool isInjured();

	//adds a game played and the stats from that game
	void addGamePlayed(int points, int assists, int rebounds);
	void setInjured(bool injured);
};

/*
Overloads the output operator so that p can be printed out with <<
*/
std::ostream& operator<<(std::ostream &out, Player p);
