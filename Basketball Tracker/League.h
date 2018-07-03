#pragma once
#include <vector>
#include <string>
#include "Team.h"

class League {
private:
	std::vector<Team> Teams;

public:
	//TODO:Document each function, then implemment

	League();
	
	League(std::vector<Team> Teams);

	bool addTeam(Team t);
	
	bool removeTeam(std::string teamName);
	
	void sortByName();
	
	void sortByWinPercentage();
	
	void sortByTeamPPG();
	
	void sortByTeamAPG();
	
	void sortByTeamRPG();

};
