#include <cassert>
#include <queue>
#include <string>
#include <vector>


unsigned int kittens(const std::string& cards, unsigned int players) {
	assert(players > 0);

	std::queue<char> nextCards;
	for (char card : cards) {
		nextCards.push(card);
	}

	std::queue<unsigned> nextPlayers;
	for (unsigned player = 0; player < players; ++player) {
		nextPlayers.push(player);
	}

	std::vector<unsigned> defuses(players, 0);

	while (nextPlayers.size() > 1) {
		unsigned currentPlayer = nextPlayers.front();
		nextPlayers.pop();

		char currentCard = nextCards.front();
		nextCards.pop();

		switch (currentCard) {
		case 'S':
			++defuses[currentPlayer];
			nextPlayers.push(currentPlayer);
			break;
		case 'B':
			if (defuses[currentPlayer] > 0) {
				--defuses[currentPlayer];
				nextPlayers.push(currentPlayer);
				nextCards.push(currentCard);
			}
			// else don't push currentPlayer => they're out of the game
			break;
		case 'O':
			nextPlayers.push(currentPlayer);
			break;
		default:
			assert(false);
		}
	}

	return nextPlayers.front() + 1;
}

int main() {
	assert(kittens("BB", 3) == 3);
	assert(kittens("SSBB", 3) == 2);
	assert(kittens("SSBBOOOOOOOSBOOOOOOOOOSB", 5) == 1);
	assert(kittens("SOOSBBOOOOSOOOSBOSOOBOSOSOOBOSOSOOB", 7) == 3);

	return 0;
}
