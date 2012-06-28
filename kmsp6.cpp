/* Kristi Short
   COP1000.C01
   Project 6 */


#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;


// Function Prototypes
void hello();
void openKey(ifstream& inKey);
void loadKey(ifstream& inKey,const int SCANDIUM, char key[]);
void openStudent(ifstream& inStudent);
void loadStudent(ifstream& inStudent, const int SCANDIUM, char student[]);
void compare(const int SCANDIUM, char key[], char student[], int& correct);
void display(const int SCANDIUM, int correct);


int incorrect = 0;
double percent = 0; 
double here = 0;


// Main Function
int main()
{


	// Variables               // Scandium has an atomic number of 21.
	const int SCANDIUM = 21;   // Array size 21; holds 20 char elements and a null terminator.
	char key[SCANDIUM];        // Array to hold the contents of "CorrectAnswers.txt".
	char student[SCANDIUM];    // Array to hold the contents of "StudentAnswers.txt".

	int correct = 0;           // Counter for number answered correct.
	int incorrect = 0;
	double percent = 0;

	ifstream inKey;            // input correct answers file (key).
	ifstream inStudent;        // input student answer file (student).

	// Program Purpose (Resisting urge to write Porpoise, corny I know.) 
	hello();

	// Open "CorrectAnswers.txt" file. 
	openKey(inKey);

	// Load the key array (CorrectAnswers contents)
	loadKey(inKey, SCANDIUM, key);

	// Open "StudentAnswers.txt" file. 
	openStudent(inStudent);

	// Load the student array (StudentAnswers contents)
	loadStudent(inStudent, SCANDIUM, student);

	// Compare Arrays 
	compare(SCANDIUM, key, student, correct);

	// Display Stats! 
	display(SCANDIUM, correct);

	cout << "\n\n";

	 return 0;

} // CLOSE MAIN CURLY BRACKET!!!


/**********************************************************************
*** Hello Function! Now Replaced by Program Purpose. Pretty much 
*** served same function anyway.
*********************************************************************/
void hello()
{
	
	cout << "\t*********************** !GRADE A TEST! ***********************\n";
	cout << "\t**************************************************************\n";
	cout << "\t****   !This Program grades a 20 multiple choice test!    ****\n";
	cout << "\t****        !Possible Choices were: A, B, C, and D!       ****\n";
	cout << "\t**    Answer key is read from file: \"CorrectAnswers.txt\"  **\n";
	cout << "\t* Student Answers are read from file: \"StudentAnswers.txt\" *\n";
	cout << "\t**    Program then displays, number of questions missed,    **\n";
	cout << "\t***     The correct answer for every incorrect answer,     ***\n";
	cout << "\t****          The percentage answered correctly,          ****\n";
	cout << "\t*** Finally, whether or not student has failed misserably! ***\n";
	cout << "\t**************************************************************\n";
	
}


/**********************************************************************
*** openFile opens the input file key! (ominous music)
**********************************************************************/
void openKey(ifstream& inKey)
{
	inKey.open("CorrectAnswers.txt");

}


/**********************************************************************
*** loadKey will read the file ("CorrectAnswers.txt") contents into
*** the key array!
***********************************************************************/
void loadKey(ifstream& inKey, const int SCANDIUM, char key[])
{
	for (int k = 0; k < SCANDIUM; k++)
		inKey >> key[k];
}


/**********************************************************************
*** openFile opens the input file student! (even more ominous music)
**********************************************************************/
void openStudent(ifstream& inStudent)
{
	inStudent.open("StudentAnswers.txt");

}


/**********************************************************************
*** loadStudent will read the file ("StudentAnswers.txt") contents
*** into the student array!
**********************************************************************/
void loadStudent(ifstream& inStudent, const int SCANDIUM, char student[])
{
	for (int s = 0; s < SCANDIUM; s++)
		inStudent >> student[s];
}


/**********************************************************************
*** This compare function compares the contents of student to the 
*** contents of key and increments correct if the elements match key,
*** then it displays the correct answer for every answer missed, 
*** and the student's answer!
**********************************************************************/
void compare(const int SCANDIUM, char key[], char student[], int& correct)
{
	for (int c = 0; c < SCANDIUM; c++)
	{
		if (key[c] == student[c])
			correct++;
		else
			cout << "\n\n\t\t\tQuestion Number: " << c + 1 << " is incorrect!\n\t\t You answered: " << student[c] << " The correct answer is: " << key[c] << "! \n";
	}
}

/***********************************************************************
*** Here is my Display Function! Displays percentage correct, 
*** pass or fail status of student, and number of incorrect points.
***********************************************************************/
void display(const int SCANDIUM, int correct)
{
	if (correct == SCANDIUM)
		cout << "\n\n\t\t\t***!!! Perfect Score! 100% !!!***" << endl << endl;
	else 
	{
		incorrect = (20 - correct);
		here = static_cast<double>(correct) - 1;
		percent = (here / 20) * 100;
		cout << "\n\n\t\t\tYou missed a total of: " << incorrect + 1 << " points.\n";
		cout << fixed << showpoint << setprecision(1) << "\n\t\t      Your percentage correct is: " << percent << "% !" << endl;

		// Pass or Fail Statements
		if( percent >= 70 )
			cout << "\n\t\t\t!You have passed your test!";
		else if( percent < 70 )
		{
			cout << "\n\t\t\t!I am sorry but you failed.";
		}

	}
	
}
 












