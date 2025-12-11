#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int user, comp;
    int userWins = 0, compWins = 0, draws = 0;

    FILE *fp;
    fp = fopen("game_results.txt", "w"); // Save output to file
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    srand(time(0));

    for (int i = 1; i <= 10; i++)
    {
        printf("\nRound %d\n", i);
        printf("Choose an option:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\nYour choice: ");
        scanf("%d", &user);

        if (user < 1 || user > 3)
        {
            printf("Invalid choice! Enter 1, 2, or 3.\n");
            i--;
            continue;
        }

        comp = (rand() % 3) + 1;

        char *names[] = {"", "Rock", "Paper", "Scissors"};

        printf("You chose: %s\n", names[user]);
        printf("Computer chose: %s\n", names[comp]);

        fprintf(fp, "Round %d: You = %s, Computer = %s -> ",
                i, names[user], names[comp]);

        if (user == comp)
        {
            printf("Result: Draw!\n");
            fprintf(fp, "Draw\n");
            draws++;
        }
        else if ((user == 1 && comp == 3) ||
                 (user == 2 && comp == 1) ||
                 (user == 3 && comp == 2))
        {

            printf("Result: You Win!\n");
            fprintf(fp, "You Win\n");
            userWins++;
        }
        else
        {
            printf("Result: Computer Wins!\n");
            fprintf(fp, "Computer Wins\n");
            compWins++;
        }

        // 🔥 Scoreboard after every round
        printf("\n----- Scoreboard After Round %d -----\n", i);
        printf("User Wins: %d\n", userWins);
        printf("Computer Wins: %d\n", compWins);
        printf("Draws: %d\n", draws);
        printf("-------------------------------------\n");
    }

    // Final results summary
    printf("\n===============================\n");
    printf("       FINAL RESULTS\n");
    printf("===============================\n");
    printf("User Wins: %d times\n", userWins);
    printf("Computer Wins: %d times\n", compWins);
    printf("Draws: %d times\n", draws);

    fprintf(fp, "\nFINAL RESULTS:\nUser Wins: %d\nComputer Wins: %d\nDraws: %d\n",
            userWins, compWins, draws);

    if (userWins > compWins)
    {
        printf("\n🎉 Overall Winner: YOU!\n");
        fprintf(fp, "Overall Winner: YOU\n");
    }
    else if (compWins > userWins)
    {
        printf("\n💻 Overall Winner: COMPUTER!\n");
        fprintf(fp, "Overall Winner: COMPUTER\n");
    }
    else
    {
        printf("\n🤝 It's an OVERALL DRAW!\n");
        fprintf(fp, "Overall Result: DRAW\n");
    }

    fclose(fp);
    printf("\nResults saved to file: game_results.txt\n");

    return 0;
}