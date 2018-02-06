#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	
	srand(time(NULL));

	char action = 'h';
	bool hit = true;

	int your1 = 0;
	int your2 = 0;
	int yourHit = 0;
	int yourTotal = 0;

	int dealer1 = 0;
	int dealerHit = 0;
	int dealerTotal = 0;

	char play_again = 'y';

	while (play_again == 'y')
	{
		// set all the variables inside the while loop so if the game is run again, they will be different
		your1 = rand() % 10 + 1;
		your2 = rand() % 10 + 1;
		yourTotal = your1 + your2;
		dealer1 = rand() % 10 + 1;
		dealerTotal = dealer1;

		cout << "Your first card is " << your1 << endl;
		cout << "Your second card is " << your2 << endl;
		cout << "The dealer's first card is " << dealer1 << endl << endl;

		// player part of the game
		hit = true;
		while (hit == true)
		{
			cout << "Total, you have " << yourTotal << endl;
			if (yourTotal > 21)
			{
				cout << "Bust! Since your total is greater than 21, You lose." << endl;
				hit = false;
			}
			else
			{
				cout << "Hit or Stay? (Type h or s): ";
				cin >> action;
				cout << endl;

				switch (action)
				{
				case 'h':
					yourHit = rand() % 10 + 1;
					cout << "Your next card is " << yourHit << endl;
					yourTotal = yourTotal + yourHit;
					break;

				case 's': hit = false;
					break;

				default:
					cout << "I didn't understand that, try again" << endl;
				}
			}
		}

		// dealer part of the game, only plays out if the player has not bust
		if (yourTotal < 22)
		{
			while (dealerTotal < 17)
			{
				cout << "The dealer has " << dealerTotal << " and must Hit." << endl;
				dealerHit = rand() % 10 + 1;
				dealerTotal = dealerTotal + dealerHit;
				cout << "The dealer's next card is " << dealerHit << endl;
				cout << "The dealer's new total is " << dealerTotal << endl << endl;
			}
			if (dealerTotal > 21)
			{
				cout << "The dealer's total is greater than 21, the dealer busts. You win!" << endl;
			}
			else
			{
				cout << "The dealer has " << dealerTotal << " and must Stay." << endl << endl;
				cout << "Your total is " << yourTotal << " and the dealer's total is " << dealerTotal << endl;
				if (yourTotal == dealerTotal)
				{
					cout << "Your totals are the same. Ties go to the dealer. You lose." << endl;
				}
				else
					if (yourTotal < dealerTotal)
					{
						cout << "The dealer's total is greater. You lose." << endl;
					}
					else
					{
						cout << "Your total is greater. You win!" << endl;
					}
			}
		}
		// ask to restart
		cout << "Play again? (Type y for yes.)";
		cin >> play_again;
		cout << "----------------------" << endl << endl;
	}
	return 0;
}
