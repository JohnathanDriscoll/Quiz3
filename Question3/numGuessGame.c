#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int maxNum = 10;

int main(void){
    int menuOpt = 1;
    char input[3];
    time_t t;
    srand((unsigned) time(&t));
    int secretNum;

    while (menuOpt < 4 && menuOpt){
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%d", &menuOpt);

        //Menu Option 1 - Play game
        if(menuOpt == 1){
            printf("Try to guess the secret number by entering a value between 1 and %d, or enter q to go back to the main menu.\n", maxNum);
            scanf("%s", &input);

            secretNum = rand() % (maxNum +1);
            while(atoi(input) != secretNum){
                if(strcmp(input,"q") == 0){
                    printf("You have selected return to main menu.\n");
                    goto skip;
                }
                if(atoi(input) < secretNum){
                    printf("Your guess is too low, pick another number between 1 and %d.\n", maxNum);
                    scanf("%s", &input);
                }
                if(atoi(input) > secretNum){
                    printf("Your guess is too high, pick another number between 1 and %d.\n", maxNum);
                    scanf("%s", &input);
                }
            }
            printf("Yes! that was the secret number! What do you want to do now?\n");
            goto skip;
        }
        //Menu option 2 - Change max number
        if(menuOpt == 2){
            printf("To change the max number, enter a value between 1 and 101, or enter q to return to main menu.\n");
            scanf("%s", &input);
            if(strcmp(input,"q") == 0){
                printf("You have selected return to main menu.\n");
                goto skip;
            }
            while (atoi(input) < 2 || atoi(input) > 100){
                printf("Please enter a number that is at least 2 but no more than 100.\n");
                scanf("%s", &input);
                if(strcmp(input,"q") == 0){
                    printf("You have selected return to main menu.\n");
                    goto skip;
                }
            }
            maxNum = atoi(input);
            printf("You have changed the max number to %d.\n", maxNum);
            goto skip;            
        }
        // Menu option 3 - quit
        if(menuOpt == 3){
            printf("You have selected to quit.  Thanks for playing!");
            break;
        }

        
        skip:
        menuOpt = 1;
    }
    return EXIT_SUCCESS;

}