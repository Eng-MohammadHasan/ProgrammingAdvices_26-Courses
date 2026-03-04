#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, NoWinner = 3 };

struct strGameInfo
{
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;

};

int RandomNumber(int From, int To)
{
	int randomNum = rand() % (To - From + 1) + From;
	return randomNum;
}

short ReadNumberOfRounds()
{
	short NumOfRounds = 0;

	do
	{
		cout << "How many Rounds 1 to 10 ?" << endl;
		cin >> NumOfRounds;

	} while (NumOfRounds < 0);

	return NumOfRounds;
}

enGameChoice ReadPlayerChoice()
{
	short PlayerChoice = 0;

	cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?\n";
	cin >> PlayerChoice;

	return (enGameChoice)PlayerChoice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

string PrintRoundChoice(enGameChoice Choice)
{
	switch (Choice)
	{
	case enGameChoice::Stone:
		return "Stone";

	case enGameChoice::Paper:
		return "Paper";

	case enGameChoice::Scissors:
		return "Scissors";
	}
}

enWinner GetRoundWinner(enGameChoice PlayerChoice, enGameChoice ComputerChoice, strGameInfo& GameInfo)
{
	if (PlayerChoice == ComputerChoice)
	{
		GameInfo.DrawTimes += 1;
		system("color 6F");
		return enWinner::NoWinner;
	}
	else if (PlayerChoice == enGameChoice::Stone && ComputerChoice == enGameChoice::Paper)
	{
		GameInfo.ComputerWonTimes += 1;
		system("color 4F");
		cout << "\a";
		return enWinner::Computer;
	}
	else if (PlayerChoice == enGameChoice::Stone && ComputerChoice == enGameChoice::Scissors)
	{
		GameInfo.Player1WonTimes += 1;
		system("color 2F");
		return enWinner::Player1;
	}
	else if (PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Stone)
	{
		GameInfo.Player1WonTimes += 1;
		system("color 2F");
		return enWinner::Player1;
	}
	else if (PlayerChoice == enGameChoice::Paper && ComputerChoice == enGameChoice::Scissors)
	{
		GameInfo.ComputerWonTimes += 1;
		system("color 4F");
		cout << "\a";
		return enWinner::Computer;
	}
	else if (PlayerChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Stone)
	{
		GameInfo.ComputerWonTimes += 1;
		system("color 4F");
		cout << "\a";
		return enWinner::Computer;
	}
	else if (PlayerChoice == enGameChoice::Scissors && ComputerChoice == enGameChoice::Paper)
	{
		GameInfo.Player1WonTimes += 1;
		system("color 2F");
		return enWinner::Player1;
	}
}

string PrintRoundWinner(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		return "Player1";

	case enWinner::Computer:
		return "Computer";

	case enWinner::NoWinner:
		return "No Winner";
	}
}

void StartRound(short CurrentRound, strGameInfo& GameInfo)
{
	enGameChoice PlayerChoice = ReadPlayerChoice();
	enGameChoice ComputerChoice = GetComputerChoice();
	enWinner RoundWinner = GetRoundWinner(PlayerChoice, ComputerChoice, GameInfo);

	cout << "______________Round [" << CurrentRound << "]" << "______________\n";
	cout << "\nPlayer1  Choice: " << PrintRoundChoice(PlayerChoice) << endl;
	cout << "\nComputer Choice: " << PrintRoundChoice(ComputerChoice) << endl;
	cout << "\nRound Winner   : " << "[ " << PrintRoundWinner(RoundWinner) << " ]" << endl;
	cout << "____________________________________";
	cout << endl << endl;
}

string GetFinalGameWinner(strGameInfo GameInfo)
{
	if (GameInfo.Player1WonTimes == GameInfo.ComputerWonTimes)
	{
		return "No Winner";
	}
	else if (GameInfo.Player1WonTimes > GameInfo.ComputerWonTimes)
	{
		return "Player1";
	}
	else
	{
		return "Computer";
	}

}

void ShowGameResults(strGameInfo GameInfo)
{
	cout << "\t\t_____________________________________________\n\n";
	cout << "\t\t            +++ Game Over +++                \n\n";
	cout << "\t\t_____________________________________________\n\n";
	cout << "\t\t________________[Game Results]_______________\n\n";
	cout << "\t\tGame Rounds        : " << GameInfo.GameRounds << endl;
	cout << "\t\tPlayer1 won times  : " << GameInfo.Player1WonTimes << endl;
	cout << "\t\tComputer won times : " << GameInfo.ComputerWonTimes << endl;
	cout << "\t\tDraw times         : " << GameInfo.DrawTimes << endl;
	cout << "\t\tFinal Winner       : " << GetFinalGameWinner(GameInfo) << endl << endl;
	cout << "\t\t_____________________________________________\n\n";

}

bool PlayAgain()
{
	char Answer;

	cout << "Do you want to play again? Y/N?";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{
		return true;
	}

	return false;

}

void StartGame()
{
	do {
		strGameInfo GameInfo;

		GameInfo.GameRounds = ReadNumberOfRounds();

		for (int Counter = 1; Counter <= GameInfo.GameRounds; Counter++)
		{
			StartRound(Counter, GameInfo);
		}

		ShowGameResults(GameInfo);
	} while (PlayAgain());
}


int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
