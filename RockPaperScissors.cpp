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

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::NoWinner;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Rock:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoice::Rock)
		{
			return enWinner::Computer;
		}
		break;
	}
	
	return enWinner::Player1;

}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
	{
		return enWinner::Player1;
	}
	else if (Player1WinTimes < ComputerWinTimes)
	{
		return enWinner::Computer;
	}
	else
	{
		return enWinner::NoWinner;
	}
}

string WinnerName(enWinner Winner)
{
	string WinnerArray[3] = { "Player1", "Computer", "No Winner" };
	return WinnerArray[ Winner - 1 ];
}

string ChoiceName(enGameChoice Choice)
{
	string ChoiceArray[3] = { "Rock", "Paper", "Scissor" };
	return ChoiceArray[Choice - 1];
}

void SetScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("Color 2F");
		break;

	case enWinner::Computer:
		system("Color 4F");
		cout << "\a";
		break;

	case enWinner::NoWinner:
		system("Color 6F");
		break;
	}
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << "________________ Round [" << RoundInfo.GameRound << "] ______________________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	cout << "________________________________________________________\n\n";

	SetScreenColor(RoundInfo.Winner);
}








int main()
{
	srand((unsigned)time(NULL));
	return 0;
}