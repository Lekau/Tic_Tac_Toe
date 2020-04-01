#include <unistd.h>

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
    if((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]))
    {
        return (2);
    }
    else if ((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]) || (str[2] == str[4] && str[6]))
    {
        return (2);
    } 
    else if ((str[0] == str[4] && str[8]) || (str[2] == str[4] && str[6]) || (str[2] == str[4] && str[6]))
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
    if (str[pos] == 'O' || str[pos] == 'X')
        return (1);
    else
        return (0); 
}

void print_grid(char str[9])
{
    int i = 0, k = 0, h_div = 0, v_div = 0;

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
}

int main(int count, char **players)
{
    int turns = 0;

    while(turns < 9)
    {
        
        turns++;
    }


    print_grid(players[1]);
    return (0);
}