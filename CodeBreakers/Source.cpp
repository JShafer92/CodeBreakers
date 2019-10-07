// 05 Assignment: Keywords - Building Code Breaker Training Simulation Program for CIA Recruits


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// Declare and intitalize the integer <correctAnswers> to 0
int correctAnswers = 0; 
// Declare and intitalize the integer <wrongAnswers> to 0
int wrongAnswers = 0; 
// Declare and intitalize the integer <totalAnswers> to 0
int totalAnswers = 0; 
string wordArray[3];


int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 10;
	//keywords , hints
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"carnival", "a traveling amusement show or circus."},
		{"luxury", "the state of great comfort and extravagant living."},
		{"ripe", "ready to harvest"},
		{"appear", "become visible or noticeable"},
		{"guild", "a medieval association of craftsmen or merchants"},
		{"crypt", "an underground room or vault beneath a church"},
		{"emperor", "a sovereign ruler"},
		{"lizard", "a reptile"},
		{"gasmask", "defense against poisonous gas"},
		{"obsession", "an idea or thought that continually preoccupies or intrudes on a person's mind."},
	};

	cout << "\t\tInstructions\n\n";
	cout << "Greetings. As recruits you will need to pass this test to continue.\n";
	cout << "To pass you will need to unscramble 3 keywords" << endl;
	cout << "If you need a hint enter 'hint'.\n";
	cout << "You may skip a word by entering 'pass'\n\n";

	for (int i = 0; i < 3; ++i)
	{
		srand(time(0));
		int words = (rand() % NUM_WORDS);
		for (int c = 0; c < 3; ++c)
		{
			while (WORDS[words][WORD] == wordArray[c])
			{
				words = (rand() % NUM_WORDS);
			}
		}
		wordArray[i] = WORDS[words][WORD];

		// word to guess
		string theWord = WORDS[words][WORD];  
		// hint for word
		string theHint = WORDS[words][HINT]; 
		// jumbled version of word
		string jumble = theWord;  
		int length = jumble.size();
		for (int j = 0; j < length; ++j)
		{
			int index1 = (rand() % length);
			int index2 = (rand() % length);
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}
		//output a jumbled random word
		cout << "The keyword is: " << jumble;

		string guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;

		while ((guess != theWord) && (guess != "pass"))
		{
			if (guess == "hint")
			{
				cout << theHint;
			}
			else
			{
				cout << "Sorry, that's not it.";
				wrongAnswers++;
				totalAnswers++;
			}

			cout << "\n\nEnter your guess: ";
			cin >> guess;
		}

		if (guess == theWord)
		{
			totalAnswers++;
			correctAnswers++;
			cout << "\n You solved the code!\n" << endl;
		}
	}

	cout << "\n\t\tStats" << endl;
	cout << "-------------------------------" << endl;
	cout << "You guessed " << correctAnswers << " words correctly this simulation." << endl;
	cout << "You guessed " << wrongAnswers << " words incorrectly this simulation." << endl;
	cout << "You guessed a total of " << totalAnswers << " words this simulation." << endl;
	string playAgain;
	cout << "Would you like to play again? Y/N" << endl;
	cin >> playAgain;

	while (true) {
		if (playAgain == "Y") {
			system("cls");
			main();
		}
		else if (playAgain == "N") {
			cout << "Thanks for playing!" << endl;
			Sleep(2000);
			exit(0);
		}
		else {
			cout << "Please enter Y or N..." << endl;
			cin >> playAgain;
		}
	}
}