#include <iostream>
#include <ctime>
#include <cstdlib>
#include<string>

using namespace std;

enum enQuestionLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Subtract = 2, Multiplication = 3, Division = 4, MixOP = 5 };

enum enPassOrFail { Pass = 1, Fail = 2 };

struct stQuizz
{
	short NumberOfQuestions = 0;
	enQuestionLevel QuestionsLevel;
	string QuestionsLevelText;
	enOperationType OperationType;
	string OpTypeText;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	enPassOrFail PassOrFail;
	string QuizPassOrFail = "";
};

struct stQuestion
{
	short Answer = 0;
	short Number1 = 0;
	short Number2 = 0;
	char OpTypeText;
	enPassOrFail AnswerStatus;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short HowManyQuestions()
{
	short NumberOfQuestions = 0;

	do
	{
		cout << "How many Questions do you want to answer ?\n";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions <= 0);

	return NumberOfQuestions;
}

enQuestionLevel ReadQuestionLevel()
{
	short QuestionLevel = 0;

	cout << "Enter Questions level [1] Easy, [2] Med , [3] Hard , [4] Mix ? \n";
	cin >> QuestionLevel;

	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType()
{
	short OpType = 0;

	cout << "Enter Operation Type [1] Add , [2] Sub , [3] Mul , [4] Div , [5] Mix ?\n";
	cin >> OpType;

	return (enOperationType)OpType;
}

string QuestionsLevelText(enQuestionLevel QuestionLevel)
{
	string  arrQuestionLevels[4] = { "Easy" , "Med" , "Hard" , "Mix" };
	return arrQuestionLevels[QuestionLevel - 1];
}

string QuizOperationTypeText(enOperationType OpType)
{
	string arrOpType[5] = { "+" , "-" , "*" , "/" , "Mix" };
	return arrOpType[OpType - 1];
}

char ConvertQuestionOpTypeToText(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return '+';

	case enOperationType::Subtract:
		return '-';

	case enOperationType::Multiplication:
		return '*';

	case enOperationType::Division:
		return '/';

	case enOperationType::MixOP:
		char arrOpType[4] = { '+' , '-' , '*' , '/' };
		return arrOpType[RandomNumber(0, 3)];
	}
}

void SetScreenColor(enPassOrFail PassOrFail)
{
	switch (PassOrFail)
	{
	case enPassOrFail::Pass:
		system("color 2F");
		break;

	case enPassOrFail::Fail:
		system("color 4F");
		break;
	}
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

short GetNumberBasedOnQuestionsLevel(enQuestionLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		return RandomNumber(1, 10);

	case enQuestionLevel::Medium:
		return RandomNumber(11, 30);

	case enQuestionLevel::Hard:
		return RandomNumber(31, 100);

	case enQuestionLevel::Mix:
		return RandomNumber(1, 100);
	}
}

short CalculateRightAnswer(stQuestion Question)
{
	short Num1 = Question.Number1;
	short Num2 = Question.Number2;
	char OpType = Question.OpTypeText;

	switch (OpType)
	{
	case '+':
		return Num1 + Num2;

	case '-':
		return Num1 - Num2;

	case '*':
		return Num1 * Num2;

	case '/':
		return Num1 / Num2;
	}
}

enPassOrFail IsRightAnswer(short Answer, short RightAnswer)
{
	if (Answer == RightAnswer)
	{
		return enPassOrFail::Pass;
	}
	else
	{
		return enPassOrFail::Fail;
	}
}

void ShowFinalQuestionResults(enPassOrFail IsRightAnswer, short RightAnswer)
{
	switch (IsRightAnswer)
	{
	case enPassOrFail::Pass:
		cout << "Right Answer :-)\n\n";
		break;

	case enPassOrFail::Fail:
		cout << "Wrong Answer :-(\n";
		cout << "The right answer is : " << RightAnswer << endl << endl;
		break;
	}

	SetScreenColor(IsRightAnswer);
}

enPassOrFail PassOrFailTheWholeQuizz(short NumOfRightAnswers, short NumOfWrongAnswers)
{
	if (NumOfRightAnswers >= NumOfWrongAnswers)
	{
		return enPassOrFail::Pass;
	}
	else
	{
		return enPassOrFail::Fail;
	}
}

string ConvertPassOrFailResultToText(enPassOrFail PassOrFail)
{
	switch (PassOrFail)
	{
	case enPassOrFail::Pass:
		return "Pass :-)";

	case enPassOrFail::Fail:
		return "Fail :-(";
	}
}

void PlayQuiz(short HowManyQuestions, stQuizz& Quiz)
{
	stQuestion Question;

	Quiz.NumberOfQuestions = HowManyQuestions;
	Quiz.QuestionsLevel = ReadQuestionLevel();
	Quiz.QuestionsLevelText = QuestionsLevelText(Quiz.QuestionsLevel);
	Quiz.OperationType = ReadOperationType();
	Quiz.OpTypeText = QuizOperationTypeText(Quiz.OperationType);

	for (short QuestionNumber = 1; QuestionNumber <= HowManyQuestions; QuestionNumber++)
	{
		Question.Number1 = GetNumberBasedOnQuestionsLevel(Quiz.QuestionsLevel);
		Question.Number2 = GetNumberBasedOnQuestionsLevel(Quiz.QuestionsLevel);
		Question.OpTypeText = ConvertQuestionOpTypeToText(Quiz.OperationType);

		cout << "\nQuestion [" << QuestionNumber << "/" << HowManyQuestions << "]\n\n";
		cout << Question.Number1 << endl;
		cout << Question.Number2 << Question.OpTypeText << endl;
		cout << "________________\n";
		cin >> Question.Answer;

		short RightAnswer = CalculateRightAnswer(Question);

		Question.AnswerStatus = IsRightAnswer(Question.Answer, RightAnswer);
		ShowFinalQuestionResults(Question.AnswerStatus, RightAnswer);

		//Count right/wrong answers...
		if (Question.AnswerStatus == enPassOrFail::Pass)
		{
			Quiz.NumberOfRightAnswers++;
		}
		else
		{
			Quiz.NumberOfWrongAnswers++;
		}
	}

	Quiz.PassOrFail = PassOrFailTheWholeQuizz(Quiz.NumberOfRightAnswers, Quiz.NumberOfWrongAnswers);
	Quiz.QuizPassOrFail = ConvertPassOrFailResultToText(Quiz.PassOrFail);

}

void ShowFinalQuizResults(stQuizz Quiz)
{
	SetScreenColor(Quiz.PassOrFail);

	cout << "________________________________\n\n";
	cout << "Final Results is " << Quiz.QuizPassOrFail << endl;
	cout << "________________________________\n\n";
	cout << "Number of Questions : " << Quiz.NumberOfQuestions << endl;
	cout << "Questions Level     : " << Quiz.QuestionsLevelText << endl;
	cout << "OpType              : " << Quiz.OpTypeText << endl;
	cout << "Number of Right Answers : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number of Wrong Answers : " << Quiz.NumberOfWrongAnswers << endl;
	cout << "________________________________\n\n";

}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		stQuizz Quiz;

		ResetScreen();
		PlayQuiz(HowManyQuestions(), Quiz);
		ShowFinalQuizResults(Quiz);

		cout << "Do you want to play again? Y/N? \n";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
