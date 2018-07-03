//Class declaration of Player

#pragma once
#include <string>
#include <ostream>
#include <iomanip>

class Player {
private:
	
	//the players team
	std::string team;

	//the players name
	std::string name;

	//the players basketball position(ex:PG)
	std::string position;

	//season totals for games played, points, assists, rebounds
	int gamesPlayed;
	int seasonPoints;
	int seasonAssists;
	int seasonRebounds;

	//whether or not the player is injured
	bool injured;

public:
	/*Constructor providing default values for all possible member variables 
	If the values provided do not list a number of gamesPlayed greater than 0 and less
	than or equal to 82, the player is given the default values of 0 for gamesPlayed, seasonPoints,
	seasonAssists, and seasonRebounds
	
	@param name The name of the player
	@param position The position of the player(ex:PG)
	@param gamesPlayed Amount of games played in the current season
	@param seasonPoints Player's total points on the season
	@param seasonAssists Player's total assists on the season
	@param seasonRebounds Player's total rebounds on the season
	@param injured Contains a value of true if the player is injured
	*/
	Player(std::string team = "Free Agent", std::string name = "Unknown", std::string position = "NA", int gamesPlayed = 0, int seasonPoints = 0,
		int seasonAssists = 0, int seasonRebounds = 0, bool injured = false);


	std::string getName();

	std::string getPosition();

	std::string getTeam();

	int getGamesPlayed();
	
	double getPointsPerGame();
	
	double getAssistsPerGame();
	
	double getReboundsPerGame();
	
	bool isInjured();

	void setTeam(std::string team);

	void setInjured(bool injured);

	/*Add a game played to the player along with the players stats in the game
	
	@param points Points scored in the game
	@param assists Assists recorded in the game
	@param rebounds Rebounds recorded in the game
	@return True if the game was added
	*/
	bool addGamePlayed(int points, int assists, int rebounds);

};

/*Overloads the output operator so that p can be printed out with <<

@param out The output stream to add the information to
@param p The player to be printed out
@return The output stream including the player information
*/
std::ostream& operator<<(std::ostream &out, Player p);
