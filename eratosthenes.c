#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SEARCH_SIZE 10

int main(int argc, char ** argv)
{
    bool * nums = NULL;
    int NO_OF_NUMBERS = DEFAULT_SEARCH_SIZE;
    FILE * dummy = fopen("/dev/null", "w");

    if (dummy == NULL)
    {
        puts("fopen: Oh no!");
        exit(1);
    }
    srand(time(NULL)); // Seed random number generator
    while (1)
    {
        NO_OF_NUMBERS = rand() % 100 + 1;
        if (NO_OF_NUMBERS == 1)
        {
            fprintf(dummy, "There are no prime numbers.\n");
            continue;
        }
        nums = (bool *)malloc(sizeof(bool)*(NO_OF_NUMBERS - 1));
        for (int k = 0; k < NO_OF_NUMBERS - 1; k++)
        {
            nums[k] = true;
        }
        for (int k = 0; k < NO_OF_NUMBERS - 1; k++)
        {
            if (nums[k] == true)
            {
                for (int n = 2; n*(k+2) <= NO_OF_NUMBERS; n++)
                {
                    nums[n*(k+2)-2] = false;
                }
            }
        }
        fprintf(dummy, "The prime numbers will appear below this line.\n");
        for (int k = 0; k < NO_OF_NUMBERS - 1; k++)
        {
            if (nums[k] == true)
            {
                fprintf(dummy, "%d ", k+2);
            }
        }
        free(nums);
        fprintf(dummy, "\n");
    }
    exit(0);
}
