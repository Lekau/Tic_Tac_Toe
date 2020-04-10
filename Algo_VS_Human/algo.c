#include <stdio.h>
#define TRUE 1
#define FALSE 0

int block_win(char grid[9])
{       
        if ((grid[8] != 'X' || grid[8] != 'O') && (grid[0] == 'X' || grid[0] == 'O') && (grid[2] == 'X' || grid[2] == 'O') && (grid[6] == 'X' || grid[6] == 'O'))
            return (8);
        else if ( (grid[6] != 'X' || grid[6] != 'O') && (grid[0] == 'X' || grid[0] == 'O') && (grid[2] == 'X' || grid[2] == 'O') && (grid[8] == 'X' || grid[8] == 'O'))
            return (6);
        else if ((grid[2] != 'X' || grid[2] != 'O') && (grid[0] == 'X' || grid[0] == 'O') && (grid[6] == 'X' || grid[6] == 'O') && (grid[8] == 'X' || grid[8] == 'O'))
            return (2);
        else if ((grid[0] != 'X' || grid[0] != 'O') && (grid[2] == 'X' || grid[2] == 'O') && (grid[6] == 'X' || grid[6] == 'O') && (grid[8] == 'X' || grid[8] == 'O'))
            return (0);
        else
            return (10);
}

int play(char grid[9], int first_move)
{
    int winning_comb[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int k = 0, i = 0;
    if (first_move == TRUE)
    {   
        printf("first move is true");
        return (4);
    }
    else 
    {
        int x_count = 0, o_count = 0;
        while(k++ <= 7)
        {
            x_count = 0;
            o_count = 0;
            while(i++ <= 2)
            {
                if(grid[winning_comb[k][i]] == 'O')
                    o_count++;
                else if (grid[winning_comb[k][i]] == 'X')
                    x_count++;
            }
            if (x_count == 2 || o_count == 2)
            {
                if ((grid[winning_comb[k][0]] == 'X' && grid[winning_comb[k][1]] == 'X') || (grid[winning_comb[k][0]] == 'O' && grid[winning_comb[k][1]] == 'O'))
                    return(winning_comb[k][2]);
                else if ((grid[winning_comb[k][1]] == 'X' && grid[winning_comb[k][2]] == 'X') || (grid[winning_comb[k][1]] == 'O' && grid[winning_comb[k][2]] == 'O'))
                    return(winning_comb[k][0]);
                else 
                    return(winning_comb[k][1]);
            }
            else
                k++;   
        }
        if(block_win(grid) != 10)
            return (block_win(grid)); 
        else if(grid[4] != 'O' || grid[4] != 'X')
            return (4);        
        else 
        {
            int h = 1;
            while(h <= 7)
            {
                if (grid[h] != 'O' || grid[h] != 'X')
                    return (h);
                h = h + 2;
            }
        }
    }
}

int call_strategy(char grid[9])
{
    int count_x = 0;
    int count_o = 0;
    int i = 0;
    int first_move = FALSE;

    while (grid[i] != '\0')
    {
        if(grid[i] == 'X')
            count_x++;
        if(grid[i] == 'O')
            count_o++;
        i++;
    }
        if (count_x == 0 && count_o == 0)
            first_move = TRUE;
            
        return (play(grid, first_move));
}