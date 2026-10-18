#include <iostream>
#include <time.h>
#include <cctype>
using namespace std;

char getLetter(int position) {
	char letter[27] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	return letter[position];
}

int getPosition() {
	int position = 1 + (rand() % 26); 

	return position;
}

void runGame() {
	char guess, select = getLetter(getPosition());

	select = tolower(select);

	cout << "I am thinking of a letter. what is your guess? ";
	cin >> guess;

	guess = tolower(guess);

	while (guess != select) {
		if (guess < select) {
			cout << "Your guess is too low" << endl;
			cin >> guess;

			guess = tolower(guess);
		}
		else {
			cout << "Your guess is too high" << endl;
			cin >> guess;

			guess = tolower(guess);
		}
	}
	
	cout << "Congratulations you guessed my letter." << endl;

	return;
}

int main(void) {
	char answer;

	srand(time(0));

	do {
		runGame();

		cout << "Do you want to play again?" << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');

	cout << "Goodbye !" << endl;

	return 0;
}