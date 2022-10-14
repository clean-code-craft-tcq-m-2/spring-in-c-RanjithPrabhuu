#include <math.h>
#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats stat;
    stat.average = 0;
    stat.min = 0;
    stat.max = 0;
    
    int counter = 0;
    float sum = 0, min, max;
    if((numberset != (void *)0) || (setlength > 0))
    {
        min = numberset[0];
        max = numberset[0];
        
        while(counter < setlength)
        {
            sum =sum + numberset[counter];
            if(min > numberset[counter])
            {
                min = numberset[counter];
            }
            if(max < numberset[counter])
            {
                max = numberset[counter];
            }
            
            counter++;
        }
        stat.average = sum / setlength;
        stat.min = min;
        stat.max = max;
    }
    else
    {
        stat.average = NAN;
        stat.min = NAN;
        stat.max = NAN;
    }
    
    return stat;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], int alerterCount, struct Stats computedStats)
{
    int counter = 0;

    if(computedStats.max > maxThreshold)
    {
        while(counter < alerterCount)
        {
            if(alerters[counter] != (void *)0)
            {
                alerters[counter]();
            }
            counter++;
        }
    }
}

