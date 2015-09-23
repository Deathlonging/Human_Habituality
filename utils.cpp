#include "utils.h"

#include <time.h>
#include <stdlib.h>
int getRandomValue(int min, int max)
{
    static bool isInitialized = false;
    if(!isInitialized)
    {
        srand(time(NULL));
        isInitialized=true;
    }
    return min + (rand() % (max-min+1));
}

