#include <unistd.h>
#include <stdio.h>

int call_strategy(char grid[9]);

void our_putchar(char k)
{
    write(1, &k, 1);
}

void our_putstr(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        our_putchar(str[i++]);
}

void draw_X_or_O(char str[9], int pos, int player)
{
    int xo = 0;
    if (player%2 != 1)
    {
        while(xo != pos)
            xo++;
        str[xo] = 'X';
    }
    else 
    {
        while(xo != pos)
            xo++;
        str[xo] = 'O';
    }
}

int game_over(char str[9], int turns)
{
    if((str[0] == str[4] && str[8] == str[4]) || (str[2] == str[4] && str[6] == str[4]))
    {
        return (2);
    }
    else if ((str[0] == str[3] && str[3] == str[6]) || (str[1] == str[4] && str[4] == str[7]) || (str[2] == str[5] && str[5] == str[8]))
    {
        return (2);
    } 
    else if ((str[0] == str[1] && str[1] == str[2]) || (str[3] == str[4] && str[4] == str[5]) || (str[6] == str[7] && str[7] == str[8]))
    {
        return (2);
    }
    else if (turns == 9)
    {
        return (1);
    } 
    else
    {
        return (0);
    }
}

int disqualifier(char str[9], int pos)
{
    if (str[pos] == 'O' || str[pos] == 'X' || pos < 0 || pos > 8)
        return (1);
    else
        return (0); 
}

void print_grid(char str[9])
{
    int i = 0, k = 0, h_div = 0, v_div = 0;
    our_putchar('\n');
    while(i < 9)
    {
        k = 0;
        h_div = 0;
        while(k++ < 3)
        {
            if (h_div++ < 2)
            {
                our_putchar(str[i++]);
                our_putstr(" | ");
            }
            else
            {
                our_putchar(str[i++]);
                our_putstr(" \n");
            }
        }
        if (v_div++ < 2)
            our_putstr("----------\n"); 
    }
    our_putchar('\n');
}

int main(void)
{
    int human = 0;
    int computer = 0;
    int turns = 1;
    char cur_player = '1';
    char winner[14] = "Player 1 Wins\n";
    char draw_check = 'Y';
    char playing_grid[9] = "Z12345678";

    while(turns <= 9)
    {
        if(turns%2 != 0)
        {
            cur_player = '1';
            our_putstr("\nComputer made a move ");
            computer = call_strategy(playing_grid);
            if (disqualifier(playing_grid, computer) == 1)
            {
                our_putstr("\nComputer, You are disqualified!!!\n");
                print_grid(playing_grid);
                return (0);
            }

            draw_X_or_O(playing_grid, computer, turns);
            print_grid(playing_grid);
            if (game_over(playing_grid, turns) == 1)
            {
                draw_check = 'Y';
                break;
            }
            else if (game_over(playing_grid, turns) == 2)
            {
                draw_check = 'N';
                break;
            }
        }
        else
        {
            cur_player = '2';
            our_putstr("\nEnter position Human: ");
            scanf("%d", &human);
            if (disqualifier(playing_grid, human) == 1)
            {
                our_putstr("\nHuman, You are disqualified!!!\n");
                print_grid(playing_grid);
                return (0);
            }
        
            draw_X_or_O(playing_grid, human, turns);
            print_grid(playing_grid);
            if (game_over(playing_grid, turns) == 1)
            {
                draw_check = 'Y';
                break;
            }
            else if (game_over(playing_grid, turns) == 2)
            {
                draw_check = 'N';
                break;
            }
        }
        turns++;
    }

    print_grid(playing_grid);

    if (draw_check == 'Y')
    {
        our_putstr("its a Draw Kids \n");
    } 
    else if (draw_check == 'N')
    {
        winner[7] = cur_player;
        our_putstr(winner);
    }
    return (0);
}