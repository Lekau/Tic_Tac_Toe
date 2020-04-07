#define TRUE 1
#define FALSE 0

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
    if((count_x == 0 && count_o == 0) || (count_x == count_o))
    {
        if (count_x == 0 && count_o == 0)
            first_move = TRUE;
        return (play_offence(grid, first_move));
    }
    else
    {
        if (count_x == 0 || count_o == 0)
            first_move = TRUE;
        return (play_defence(grid, first_move));
    }
}
int play_defence(char grid[9], int first_move)
{
    int winning_comb[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int k = 0, i = 0;
    if (first_move == TRUE)
    {
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
                i = 0;
                //block that shit
            }
            else
                k++;   
        }
    }
}
int play_offence(char grid[9], int first_move)
{
    if (first_move == TRUE)
    {
        return (4);
    }

    //still finding the best way to win this game. 
}



int computer_algo(char current_grid[9])
{
    return (call_strategy(current_grid));
}