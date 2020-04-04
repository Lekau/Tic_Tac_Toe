#include <stdio.h>

int main()
{ 
    char *player1; 
    char *player2;
    printf("please enter player 1's name: ");
    scanf("%s", player1);
    printf("please enter player 2's name: ");
    scanf("%s", player2);
    printf("%s is the name of player one \n", player1);
    printf("%s is the name of player two \n", player2);
    return (0);
}