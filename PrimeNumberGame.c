#include <stdio.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Welcome to Prime Pursuit! Dive into the world of prime numbers!\n");

    int level;
    int score;
    int attempts_left;
    int levels_limit = 3;
    int hints_used;

    int play_again = 1;

    while (play_again) {
        printf("\n==== Prime Pursuit ====\n");

        level = 1;
        score = 0;
        hints_used = 0;

        while (level <= levels_limit) {
            printf("\n==== Level %d ====\n", level);

            int start, end;
            if (level == 1) {
                start = 2;
                end = 9;
            } else if (level == 2) {
                start = 10;
                end = 99;
            } else {
                start = 2;
                end = 999;
            }

            attempts_left = 2;

            while (attempts_left > 0) {
                printf("Enter a prime number between %d and %d: ", start, end);
                int num;
                scanf("%d", &num);

                int is_prime = isPrime(num);

                if (num < start || num > end || !is_prime) {
                    printf(RED "Incorrect! Try again.\n" RESET);
                    attempts_left--;
                    continue;
                }

                printf(GREEN "Correct!\n" RESET);
                score++;
                break;
            }

            if (attempts_left == 0) {
                printf(RED "Out of attempts. You failed this level.\n" RESET);
                break;
            }

            level++;
        }

        printf("\n==== Game Over ====\n");
        printf("Your final score: %d\n", score);

        char choice;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            play_again = 0;
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}
