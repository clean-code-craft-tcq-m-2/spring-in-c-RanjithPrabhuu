#include <math.h>
#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    int counter = 0;
    float sum = 0, min, max;
    if((numberset != (void *)0) || (setlength > 0))
    {
        min = numberset[0];
        max = numberset[0];
        
        while(counter < setlength)
        {
            sum += numberset[counter];
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
        s.average = sum / setlength;
        s.min = min;
        s.max = max;
    }
    else
    {
        s.average = NAN;
        s.min = NAN;
        s.max = NAN;
    }
    
    return s;
}
