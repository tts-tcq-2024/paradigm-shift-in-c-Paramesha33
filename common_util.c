#include "common_util.h"

float calculate_tolerance(float range,int tolerance)
{
    return ((range/100)*tolerance);
}

bool check_min_range(float value, float range)
{
   if(value < range)
   {
       return true;
   }
   return false;
}

bool check_max_range(float value,float range)
{
    if(value > range)
    {
        return true;
    }
    return false;
}

battery_status check_battery_warning(float value,float *range_arr)
{
    /*Warning levels are checked*/
    if(check_min_range(value,range_arr[min_tolerance]))
    {
        return warning;
    }

    if(check_max_range(value,range_arr[max_tolerance]))
    {
        return warning;
    }
    return normal;
}

battery_status check_battery_error(float value, float *range_arr)
{
    /*Error thresholds are checked*/
    if(check_min_range(value,range_arr[min]))
    {
        return error;
    }

    if(check_max_range(value,range_arr[max]))
    {
        return error;
    }
    return warning;

}

void message_logger(char *str,float value, battery_status state)
{
    if(state == warning)
    {
        printf("warning: %s %f is breaching \n",str,value);
    }
    else if(state == error)
    {
        printf("Error: %s %f is out of range\n",str,value);
    }
    else
    {
        printf("No Error: %s %f is Normal\n",str,value);
    }
}
