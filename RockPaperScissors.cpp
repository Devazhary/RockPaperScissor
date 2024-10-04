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
	int RoundsNumber = 1;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		
		cin >> RoundsNumber;

	} while (RoundsNumber < 1 || RoundsNumber >10);

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

stGameResult FillGameResult(int GameRound,short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
	stGameResult GameResult;

	GameResult.GameRound = GameRound;
	GameResult.Player1WonTimes = Player1WonTimes;
	GameResult.ComputerWonTimes = ComputerWonTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.winner = WhoWonTheGame(Player1WonTimes, ComputerWonTimes);
	GameResult.FinalWinner = WinnerName(GameResult.winner);

	return GameResult;

}

void ShowGameOver()
{
	cout << Tabs(2) << "__________________________________________________________\n\n";
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
	cout << Tabs(2) << "__________________________________________________________\n\n";
}

void ShowFinalResult(stGameResult GameResult)
{
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n";
	cout << Tabs(2) << "Game Rounds        :" << GameResult.GameRound << endl;
	cout << Tabs(2) << "Player1 Won Times  :" << GameResult.Player1WonTimes << endl;
	cout << Tabs(2) << "Computer Won Times :" << GameResult.ComputerWonTimes << endl;
	cout << Tabs(2) << "Draw Times         :" << GameResult.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner       :" << GameResult.FinalWinner << endl;
	cout << Tabs(2) << "___________________________________________________________\n";

	SetScreenColor(GameResult.winner);
}

stGameResult PlayGame(short HowManyRound)
{
	stRoundInfo RoundInfo;
	short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRound; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.GameRound = GameRound;
		RoundInfo.Player1Choice = Player1Choice();
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
		{
			Player1WonTimes++;
		}
		else if (RoundInfo.Winner == enWinner::Computer)
		{
			ComputerWonTimes++;
		}
		else
		{
			DrawTimes++;
		}

		PrintRoundResult(RoundInfo);
	}

	return FillGameResult(HowManyRound, Player1WonTimes, ComputerWonTimes, DrawTimes);
}

void ResetScreen()
{
	system("cls");
	system("Color 0F");
}

void StartGame()
{
	char Continue = 'Y';

	do
	{

		ResetScreen();
		stGameResult GameResult = PlayGame(HowManyRounds());
		ShowGameOver();
		ShowFinalResult(GameResult);

		cout << Tabs(3) << "Do you want to play again? Y/N? ";

		cin >> Continue;

	} while (Continue == 'Y' || Continue == 'y');

}


int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}