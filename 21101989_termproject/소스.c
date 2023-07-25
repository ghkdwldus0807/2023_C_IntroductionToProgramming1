//21101989 황지연 termproject

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

#define MAX_NUMBERS 45
#define PICKS 6
#define MAX_PLAYS 1000000
#define PRICE 1000

int numPrizes[4] = { 0 };


void generateRandomPicks(int* picks) {
    for (int i = 0; i < PICKS; i++) {
        picks[i] = rand() % MAX_NUMBERS + 1;
    }
}


void readUserPicks(int* picks) {
    printf("Enter your picks (6 unique numbers from 1 to 45)\n or Enter A (random number): \n");
    for (int i = 0; i < PICKS; i++) {
        scanf("%d", &picks[i]);
    }
}


bool validateUserPicks(const int* picks) {
    bool valid = true;
    for (int i = 0; i < PICKS; i++) {
        if (picks[i] < 1 || picks[i] > MAX_NUMBERS) {
            valid = false;
            break;
        }
        for (int j = 0; j < i; j++) {
            if (picks[j] == picks[i]) {
                valid = false;
                break;
            }
        }
    }
    return valid;
}

void generateWinningNumbers(int* winningNumbers) {
    for (int i = 0; i < PICKS; i++) {
        int number = rand() % MAX_NUMBERS + 1;
        winningNumbers[i] = number;
    }
}


int countMatchingNumbers(const int* picks, const int* winningNumbers) {
    int count = 0;
    for (int i = 0; i < PICKS; i++) {
        for (int j = 0; j < PICKS; j++) {
            if (picks[i] == winningNumbers[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}

void displayResult(const int* picks, const int* winningNumbers, int prize) {
    printf("User's pick: ");
    for (int i = 0; i < PICKS; i++) {
        printf("%d ", picks[i]);
    }
    printf("\nWinning numbers: ");
    for (int i = 0; i < PICKS; i++) {
        printf("%d ", winningNumbers[i]);
    }
    printf("\nPrize: ");
    switch (prize) {
    case 1:
        printf("1st prize (2 billion won)\n");
        break;
    case 2:
        printf("2nd prize (2 million won)\n");
        break;
    case 3:
        printf("3rd prize (50 thousand won)\n");
        break;
    case 4:
        printf("4th prize (5 thousand won)\n");
        break;
    default:
        printf("No prize\n");
        break;
    }
}

void playSingleGameKeyboard() {
    char input[100];
    printf("Enter your picks (6 numbers from 1 to 45, separated by whitespace): or Enter A (random number): \n 종료를 원하시면 q를 입력하세요 \n ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    fgets(input, sizeof(input), stdin);

    if (input[0] == 'q' || input[0] == 'Q') {
        printf("프로그램이 종료됩니다. .\n");
        exit(0);
    }

    int userPicks[PICKS] = { 0 };
    if (input[0] == 'A') {
        generateRandomPicks(userPicks);
    }
    else {
        int count = sscanf(input, "%d %d %d %d %d %d", &userPicks[0], &userPicks[1], &userPicks[2], &userPicks[3], &userPicks[4], &userPicks[5]);
        if (count != PICKS) {
            printf("Invalid input! Please enter 6 unique numbers from 1 to 45.\n");
            return;
        }
        if (!validateUserPicks(userPicks)) {
            printf("Invalid input! Please enter 6 unique numbers from 1 to 45.\n");
            return;
        }
    }

    int winningNumbers[PICKS];
    generateWinningNumbers(winningNumbers);

    int matchingNumbers = countMatchingNumbers(userPicks, winningNumbers);
    int prize;
    switch (matchingNumbers) {
    case 6:
        prize = 1;
        break;
    case 5:
        prize = 2;
        break;
    case 4:
        prize = 3;
        break;
    case 3:
        prize = 4;
        break;
    default:
        prize = 0;
        break;
    }

    displayResult(userPicks, winningNumbers, prize);
}


void playSingleGameFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file!\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int userPicks[PICKS] = { 0 };
        bool validLine = true;
        for (int i = 0; i < PICKS; i++) {
            if (validLine && (line[0] == 'A' || validateUserPicks(userPicks))) {
                generateRandomPicks(userPicks);
                break;
            }
            else if (sscanf(&line[i * 3], "%d", &userPicks[i]) != 1) {
                validLine = false;
                break;
            }
        }

        if (validLine && validateUserPicks(userPicks)) {
            int winningNumbers[PICKS];
            generateWinningNumbers(winningNumbers);

            int matchingNumbers = countMatchingNumbers(userPicks, winningNumbers);
            int prize;
            switch (matchingNumbers) {
            case 6:
                prize = 1;
                break;
            case 5:
                prize = 2;
                break;
            case 4:
                prize = 3;
                break;
            case 3:
                prize = 4;
                break;
            default:
                prize = 0;
                break;
            }

            displayResult(userPicks, winningNumbers, prize);
        }
    }

    fclose(file);
}

void playMultiGameSimulation(const char* filename, int numPlays) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to create the output file!\n");
        return;
    }

    srand(time(NULL));

    
    int moneySpent = numPlays * PRICE;
    int moneyEarned = 0;

    for (int i = 0; i < numPlays; i++) {
        int userPicks[PICKS];
        generateRandomPicks(userPicks);

        int winningNumbers[PICKS];
        generateWinningNumbers(winningNumbers);

        int matchingNumbers = countMatchingNumbers(userPicks, winningNumbers);
        int prize;
        switch (matchingNumbers) {
        case 6:
            prize = 1;
            moneyEarned += 2000000000;
            break;
        case 5:
            prize = 2;
            moneyEarned += 2000000;
            break;
        case 4:
            prize = 3;
            moneyEarned += 50000;
            break;
        case 3:
            prize = 4;
            moneyEarned += 5000;
            break;
        default:
            prize = 0;
            break;
        }

        numPrizes[prize - 1]++;

        fprintf(file, "User's pick: ");
        for (int j = 0; j < PICKS; j++) {
            fprintf(file, "%d ", userPicks[j]);
        }
        fprintf(file, "\nWinning numbers: ");
        for (int j = 0; j < PICKS; j++) {
            fprintf(file, "%d ", winningNumbers[j]);
        }
        fprintf(file, "\nPrize: ");
        switch (prize) {
        case 1:
            fprintf(file, "1st prize (2 billion won)\n");
            break;
        case 2:
            fprintf(file, "2nd prize (2 million won)\n");
            break;
        case 3:
            fprintf(file, "3rd prize (50 thousand won)\n");
            break;
        case 4:
            fprintf(file, "4th prize (5 thousand won)\n");
            break;
        default:
            fprintf(file, "No prize\n");
            break;
        }
    }

    fprintf(file, "Number of 1st prizes: %d\n", numPrizes[0]);
    fprintf(file, "Number of 2nd prizes: %d\n", numPrizes[1]);
    fprintf(file, "Number of 3rd prizes: %d\n", numPrizes[2]);
    fprintf(file, "Number of 4th prizes: %d\n", numPrizes[3]);
    fprintf(file, "Money spent: %d won\n", moneySpent);
    fprintf(file, "Money earned: %d won\n", moneyEarned);

    fclose(file);
}

int main() {
    int mode;
    printf("21101989 황지연 termproject \n \n");
    printf("Lotto Simulator\n");
    printf("1. Single game mode (keyboard input)\n");
    printf("2. Single game mode (file input)\n");
    printf("3. Multi game simulation mode\n");
    printf("1,2,3 이외의 입력을 하시면 프로그램은 종료됩니다. \n");
    printf("Enter the game mode (1-3): ");
    scanf("%d", &mode);
    fflush(stdin); 

    switch (mode) {
    case 1:
        playSingleGameKeyboard();
        break;
    case 2:
    {
        char filename[100];
        printf("Enter the input file name: ");
        scanf("%s", filename);
        playSingleGameFile(filename);
    }
    break;  
    case 3:
    {
        char filename[100];
        int numPlays;
        printf("Enter the output file name: ");
        fflush(stdin);
        scanf("%s", filename);
        printf("Enter the number of plays (between 1,000 and 1,000,000): ");
        scanf("%d", &numPlays);
        if (numPlays < 1000 || numPlays > 1000000) {
            printf("Invalid number of plays!\n");
            break;
        }
        playMultiGameSimulation(filename, numPlays);
    }
    break;
    default:
        printf("Invalid game mode!\n");
        break;
    }

    return 0;
}
