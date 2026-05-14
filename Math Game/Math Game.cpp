#include<iostream>
#include<cstdlib>
using namespace std;
enum enQuestionLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOP = 5 };

struct stQuestioin
{
    int number1 = 0;
    int number2 = 0;
    enOperationType OperatioinType;
    enQuestionLevel QuestionLevel;
    int CorrectAnswer;
    int playerAnswer;
    bool AnswerResult = false;
};
struct stQuizz
{
    stQuestioin QuestionList[100];
    short NumberOfQuestioin;
    enQuestionLevel QuestionLevel;
    enOperationType OPType;
    short NumberOfWronAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool IsPass = false;

};
short ReadNumberOfQuestion()
{
    short NumberOfQuestion;
    do
    {
        cout << "How many question do you want to answer? ";
        cin >> NumberOfQuestion;

    } while (NumberOfQuestion < 1 || NumberOfQuestion > 10);
    return NumberOfQuestion;

}
int Random(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
enOperationType GetRandomOperationType()
{
    int Op = Random(1, 4);
    return (enOperationType)Op;
}

int SimpleCalculator(int number1, int number2, enOperationType OPtype)
{
    switch (OPtype)
    {
    case enOperationType::Add:
        return number1 + number2;
    case enOperationType::Sub:
        return number1 - number2;
    case enOperationType::Mult:
        return number1 * number2;
    case enOperationType::Div:
        return number1 / number2;
    default:
        return number1 + number2;
    }
}

stQuestioin GenerateQuestion(enQuestionLevel QuestionLevel, enOperationType OPType)
{
    stQuestioin Question;
    if (QuestionLevel == enQuestionLevel::Mix)
    {
        QuestionLevel = (enQuestionLevel)Random(1, 3);
    }
    if (OPType == enOperationType::MixOP)
    {
        OPType = GetRandomOperationType();
    }

    Question.OperatioinType = OPType;
    switch (QuestionLevel)
    {
    case enQuestionLevel::EasyLevel:
        Question.number1 = Random(1, 10);
        Question.number2 = Random(1, 10);

        Question.CorrectAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperatioinType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::MedLevel:
        Question.number1 = Random(10, 50);
        Question.number2 = Random(10, 50);

        Question.CorrectAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperatioinType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionLevel::HardLevel:
        Question.number1 = Random(50, 100);
        Question.number2 = Random(50, 100);

        Question.CorrectAnswer = SimpleCalculator(Question.number1, Question.number2, Question.OperatioinType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
    }
}
enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel;
    do
    {
        cout << " Enter Question Level [1]: Easy, [2]: Med, [3]: Hard, [4]: Mix ";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel >4);

    return (enQuestionLevel)QuestionLevel;
}
enOperationType ReadOperationType()
{
    short OperationType;
    do
    {
        cout << "Enter Operation Type [1]: Add, [2]: Sub, [3]: Mult, [4]: Div, [5]: Mix? ";
        cin >> OperationType;

    } while (OperationType < 1 || OperationType>5);
    return (enOperationType)OperationType;
}

void GenerateQuizzQuestion(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestioin; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OPType);
    }
}
string GetOPtypeSymboll(enOperationType OPtype)
{
    switch (OPtype)
    {
    case enOperationType::Add:
        return "+";

    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "*";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }


}
int ReadQuestionAnswer()
{
    int Answer;
    cin >> Answer;
    return Answer;
}
void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestioin << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].number2 << " "<< GetOPtypeSymboll(Quizz.QuestionList[QuestionNumber].OperatioinType);
    cout << "____________" << endl;
}
void setScreenColor(bool AnswerResult)
{
    if (AnswerResult)
    {
        system("color 2F");

    }
    else
        system("color 4F");
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short NumberOfQuestion)
{
    if (Quizz.QuestionList[NumberOfQuestion].playerAnswer != Quizz.QuestionList[NumberOfQuestion].CorrectAnswer)
    {
        Quizz.QuestionList[NumberOfQuestion].AnswerResult = false;
        Quizz.NumberOfWronAnswers++;
        cout << "Wrong Answer :-( \n";
        cout << "The Right Answer is :";
        cout << Quizz.QuestionList[NumberOfQuestion].CorrectAnswer;
        cout << "\n";
    }

    else
    {

        Quizz.QuestionList[NumberOfQuestion].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;
        cout << "Right Answer :-) \n";
        cout << "\n";
    }
    cout << endl;
    setScreenColor(Quizz.QuestionList[NumberOfQuestion].AnswerResult);
}
void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestioin; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);//number of question in the list
        Quizz.QuestionList[QuestionNumber].playerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWronAnswers);
}
string GetFinalResulText(bool Pass)
{
    if (Pass)
    {
        return "Pass :-)";
      
        
    }
    else
        return "Fail :-(";
  

}
string GetQuestionLevel(enQuestionLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy","Med","Hard","Mix" };
    return arrQuestionLevelText[QuestionLevel - 1];
}
void printQuizzResults(stQuizz& Quizz)
{
    cout << "\n";
    cout << "-------------------------";
    cout << "Final Results is: " << GetFinalResulText(Quizz.IsPass) << endl;
    cout << "\n__________________________\n\n";
    cout << "Number of Questions    :" << Quizz.NumberOfQuestioin << endl;
    cout << "Question Level         :" << GetQuestionLevel(Quizz.QuestionLevel) << endl;
    cout << "OpType                 :" << GetOPtypeSymboll(Quizz.OPType) << endl;
    cout << "Number of Right Answers:" << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers:" << Quizz.NumberOfWronAnswers << endl;
        setScreenColor(Quizz.IsPass);
    cout << "__________________________\n";


}


void playMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestioin = ReadNumberOfQuestion();
    Quizz.QuestionLevel = ReadQuestionLevel();
    Quizz.OPType = ReadOperationType();

    GenerateQuizzQuestion(Quizz);

    AskAndCorrectQuestionListAnswers(Quizz);

   printQuizzResults( Quizz);
    

    
}

void RecetScreen()
{
    system("cls");
    system("color 0F");
}
void startGame()
{
    char PlayAgain = 'Y';
    do
    {
        RecetScreen();
        playMathGame();
        cout << endl << "Do you want to play again (Y/N)?";
        cin >> PlayAgain;


    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}

int main()
{
    srand((unsigned)time(NULL));
    startGame();

}