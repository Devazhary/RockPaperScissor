#include <iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice {Rock = 1, Paper = 2, Scissor = 3};

enum enWinner {Player1 = 1, Computer = 2, NoWinner = 3};

struct stRoundInfo
{
	short GameRound = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResult
{
	short GameRound = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	enWinner winner;
	string FinalWinner;
};

int RandomNumber(int From, int To)
{
	int RandomNum = rand() % (To - From + 1) + From;
	return RandomNum;
}

int HowManyRounds()
{
	int RoundsNumber;
	do
	{
		cout << "How many rounds do you want to play ? \n";
		
		cin >> RoundsNumber;

	} while (RoundsNumber < 0);

	return RoundsNumber;
}

enGameChoice Player1Choice()
{
	short Number;
	do
	{
		cout << "Enter your Choice [1]Rock ,[2]Paper ,[3]Scissor ? ";

		cin >> Number;

	} while (Number < 1 || Number > 3);

	return (enGameChoice)Number;
}

enGameChoice ComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

string Tabs(short Number)
{
	string t = "";

	for (int i = 1; i < Number; i++)
	{
		t = t + "\t";
		cout << t;
	}

	return t;
}




int main()
{
	srand((unsigned)time(NULL));
	return 0;
}