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
int main(int count, char **players)
{
    // take in name of players so we can print the winner

    char grid_array[3][5];
    char gridline_array[2][3];
    int i = 0, k = 0, j = 0;


    while (k < 2)
    {
        while (j < 3)
        {
            grid_array[k][j] = "_";
            j++;
        }
        k++;
    }
    //print 
    while (i <= 2)
    {
        our_putstr(grid_array[i]);
        i++;
    }
    

    
    return (0);
}