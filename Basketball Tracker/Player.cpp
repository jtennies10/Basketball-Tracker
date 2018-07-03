//Definiton of Player class

#include "Player.h"


const int MAX_GAMES = 82;

/*
Makes sure the games played is less than or equal to
the max number of games possible before setting member values,
If games played is greater than the max, then create the player as though they
have no season stats
*/
Player::Player(std::string name, std::string position, int gamesPlayed, int seasonPoints,
	int seasonAssists, int seasonRebounds, bool injured)
{
	this->name = name;
	if (position == "PG" || position == "SG" || position == "SF"
		|| position == "PF" || position == "C") {
		this->position = position;
	}
	else {
		this->position = "NA";
	}
	if (gamesPlayed <= MAX_GAMES) {
		this->gamesPlayed = gamesPlayed;
		this->seasonPoints = seasonPoints;
		this->seasonAssists = seasonAssists;
		this->seasonRebounds = seasonRebounds;

	}
	else { //create the player as having no season stats
		this->gamesPlayed = 0;
		this->seasonPoints = 0;
		this->seasonAssists = 0;
		this->seasonRebounds = 0;
	}
	this->injured = injured;
}

std::string Player::getName()
{
	return name;
}

std::string Player::getPosition()
{
	return position;
}

int Player::getGamesPlayed()
{
	return gamesPlayed;
}

double Player::getPointsPerGame()
{
	if (gamesPlayed != 0) {
		return seasonPoints * 1.0 / gamesPlayed;
	}
	else {
		return 0;
	}
}

double Player::getAssistsPerGame()
{
	if (gamesPlayed != 0) {
		return seasonAssists * 1.0 / gamesPlayed;
	}
	else {
		return 0;
	}
}

double Player::getReboundsPerGame()
{
	if (gamesPlayed != 0) {
		return seasonRebounds * 1.0 / gamesPlayed;
	}
	else {
		return 0;
	}
}

bool Player::isInjured()
{
	return injured;
}

bool Player::addGamePlayed(int points, int assists, int rebounds)
{
	if (gamesPlayed + 1 <= 82 && points >= 0 && assists >= 0 && rebounds >= 0) {
		gamesPlayed++;
		seasonPoints += points;
		seasonAssists += assists;
		seasonRebounds += rebounds;
		return true;
	}
	else {
		return false;
	}
}

void Player::setInjured(bool injured)
{
	this->injured = injured;
}

std::ostream& operator<<(std::ostream &out, Player p)
{
	out << std::fixed << std::setprecision(1); //show only one decimal place
	out << "Player: " << p.getName() << std::endl;
	out << "Position: " << p.getPosition() << std::endl;
	out << "Games Played: " << p.getGamesPlayed() << std::endl;
	out << "PPG: " << p.getPointsPerGame() << std::endl;
	out << "APG: " << p.getAssistsPerGame() << std::endl;
	out << "RPG: " << p.getReboundsPerGame() << std::endl;
	if (p.isInjured()) {
		out << "Player is Injured\n";
	}
	return out;
}


