//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1SECONDTRY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

class Question {
	public:
	String Text;
	String Answer1;
	String Answer2;
	String Answer3;
	String Answer4;
	int CorrectAnswer;

	Question (){}
	Question(String text, String ans1, String ans2, String ans3, String ans4, int correctAns){
		Text = text;
		Answer1 = ans1;
		Answer1 = ans2;
		Answer1 = ans3;
		Answer1 = ans4;
		CorrectAnswer = correctAns;
	}

};

	std::queue<Question> LoadQuestions () {
		Question q1 = Question("1. What is 1+1?", "1", "2", "3", "4", 2);
		Question q2 = Question("2. The mango tree branch has 13 leaves on one side and 29 on the other side. How many leaves are on the branch?", "42", "32", "36", "50", 1);
		Question q3 = Question("3. John sold twice as many apples in the afternoon than in the morning. If he sold 360 kilograms of apples that day, how many kilograms did he sell in the morning and how many in the afternoon?", "130", "131", "132", "134", 1);
		Question q4 = Question("4. Daisy has twice as many friends as Lilly. Rose has 5 friends, which is 9 fewer than Daisy has. How many friends does Lilly have?", "14", "21", "7", "8", 3);
		Question q5 = Question("5. Who created the painting Mona Lisa?", "Jerome Cabral", "Trixie Malinao", "Ryan Bernales", "Airhon Villiafuerte", "Leonardo da Vinci", 4);

	std::queue<Question> questions;
		questions.push(q1);
		questions.push(q2);
		questions.push(q3);
		questions.push(q4);
		questions.push(q5);

		return questions;

	}

	std::queue<Question> qustions;
	Questions currectQuestion;
	int selectedAnswer;
	int points = 0;


TFrame1 *Frame1;
//---------------------------------------------------------------------------
__fastcall TFrame1::TFrame1(TComponent* Owner)
	: TFrame(Owner)
{
    questions = LoadQuestions();
	curentQuestion = question.front();

	QuestionLabel->Text = currentQuestion.Text;
	AnswerRadioButton1->Text = currentQuestion.Answer1;
	AnswerRadioButton1->Text = currentQuestion.Answer2;
	AnswerRadioButton1->Text = currentQuestion.Answer3;
	AnswerRadioButton1->Text = currentQuestion.Answer4;

	question.pop();
	PointsLabel->Text = IntToStr(points);
}


//---------------------------------------------------------------------------

void __fastcall TFrame1::AnswerRadioButton1Change(TObject *Sender)
{
     selectedAnswer = 1;
}
//---------------------------------------------------------------------------

void __fastcall TFrame1::AnswerRadioButton2Change(TObject *Sender)
{
     selectedAnswer = 2;
}
//---------------------------------------------------------------------------

void __fastcall TFrame1::AnswerRadioButton3Change(TObject *Sender)
{
     selectedAnswer = 3;
}
//---------------------------------------------------------------------------

void __fastcall TFrame1::AnswerRadioButton4Change(TObject *Sender)
{
     selectedAnswer = 4;
}
//---------------------------------------------------------------------------

void __fastcall TFrame1::ConfirmClick(TObject *Sender)
{
    if (selectedAnswer == currentQuestion.CorrectAnswer) {
		points ++;
		PointsLabel->Text = IntToStr(points);
	} else {
		String correctAnswer;
		switch (currentQuestion.CorrectAnswer) {
		   case 1:
					correctAnswer = currentQuestion.Answer1;
					break:
		   case 2:
					correctAnswer = currentQuestion.Answer2;
					break:
		   case 3:
					correctAnswer = currentQuestion.Answer3;
					break:
		   case 4:
					correctAnswer = currentQuestion.Answer4;
					break:
		default:
			;
		}
		ShowMessage("Mali ka boi!" + correctAnswer "ang tamaang sagot");
	}

	if (!questions.empty()) {
		currentQuestion = question.front();

		QustionLabel->Text = currentQuestion.Text;

		AnswerRadioButton1->Text = currentQuestion.Answer1;
		AnswerRadioButton1->Text = currentQuestion.Answer2;
		AnswerRadioButton1->Text = currentQuestion.Answer3;
		AnswerRadioButton1->Text = currentQuestion.Answer4;

		question.pop();

			AnswerRadioButton1->IsChecked = false;
			AnswerRadioButton2->IsChecked = false;
			AnswerRadioButton3->IsChecked = false;
			AnswerRadioButton4->IsChecked = false;
	} else {
		Confirm->Enabled = false;
    }
}
//---------------------------------------------------------------------------

