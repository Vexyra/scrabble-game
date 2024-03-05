#include <iostream>
#include <string>
#include <algorithm>

struct Data {
    char chLetter;
    int nLetterScore;
};

int CalculateScore(std::string sPlayerInput) {
    Data ScrabbleGame[26] = {
            {'A', 1},
            {'B', 3},
            {'C', 3},
            {'D', 2},
            {'E', 1},
            {'F', 4},
            {'G', 2},
            {'H', 4},
            {'I', 1},
            {'J', 8},
            {'K', 5},
            {'L', 1},
            {'M', 3},
            {'N', 1},
            {'O', 1},
            {'P', 3},
            {'Q', 10},
            {'R', 1},
            {'S', 1},
            {'T', 1},
            {'U', 1},
            {'V', 4},
            {'W', 4},
            {'X', 8},
            {'Y', 4},
            {'Z', 10},
    };

    int nPlayerScore;

    for(int i = 0; i < sPlayerInput.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (sPlayerInput[i] == ScrabbleGame[j].chLetter) {
                std::cout << "Character: " << sPlayerInput[i] << ", " << "Score: " << ScrabbleGame[j].nLetterScore
                          << std::endl;
                nPlayerScore+= ScrabbleGame[j].nLetterScore;
            } else {
                nPlayerScore+= 0;
            }
        }
    }

    return nPlayerScore;
}

int main() {
    int nPlayer1Score;
    int nPlayer2Score;

    std::string sPlayer1Input;
    std::string sPlayer2Input;

    std::cout << "Player 1: ";
    std::cin >> sPlayer1Input;

    std::transform(sPlayer1Input.begin(), sPlayer1Input.end(), sPlayer1Input.begin(), ::toupper);
    nPlayer1Score = CalculateScore(sPlayer1Input);

    std::cout << "Player 2: ";
    std::cin >> sPlayer2Input;

    std::transform(sPlayer2Input.begin(), sPlayer2Input.end(), sPlayer2Input.begin(), ::toupper);
    nPlayer2Score = CalculateScore(sPlayer2Input);

    if(nPlayer1Score > nPlayer2Score) {
        std::cout << "Player 1 Wins!";
    } else if(nPlayer1Score == nPlayer2Score) {
        std::cout << "Tie!";
    } else {
        std::cout << "Player 2 Wins!";
    }

    return 0;
}
