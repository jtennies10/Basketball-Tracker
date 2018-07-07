#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPlayer
{		
	TEST_CLASS(PlayerClass)
	{
	public:
		//a default player to test
		Player default = Player(); 

		//A player with specified args to test
		Player steph = Player("Golden State Warriors", "Stephen Curry", "PG", 70, 1400, 256, 201);
		
		TEST_METHOD(getName)
		{
			Assert::AreEqual(static_cast<std::string>("Stephen Curry"), steph.getName());
		}

		//TODO::test getPosition
		//TODO::getTeam
		//TODO::getGamesPlayed
		//TODO::getPointsPerGame
		//TODO::getAssistsPerGame
		//TODO::getReboundsPerGame
		//TODO::isInjured
		//TODO::setTeam
		//TODO::setInjured
		//TODO::addGamePlayed
		//TODO::operator<<
		//TODO::


	};
}