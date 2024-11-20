#include "common_util.h"
#include "battery_parameters_check.h"

//battrey charge check
battery_status check_battery_chargerate_warning(float value,float range)
{

    if(value > range)
    {
        return warning;
    }
    return normal;
}

battery_status check_battery_chargerate_error(float value,float range)
{

    if(value > range)
    {
        return error;
    }
    return warning;
}

battery_status battery_charge_rate(float value,float range)
{
    float minimum_tolerance;
    int tolerance = 5;

    minimum_tolerance = range - calculate_tolerance(range,tolerance);

    if(check_battery_chargerate_warning(value,minimum_tolerance) == warning)
    {
          return check_battery_chargerate_error(value,range);
    }

    return normal;

}

battery_status battery_soc_check(float value,float min_range,float max_range)
{

    float range_arr[4] = {0};
    int tolerance = 5;

    range_arr[min_tolerance] = min_range + calculate_tolerance(min_range,tolerance) ;
    range_arr[min] = min_range;
    range_arr[max_tolerance] = max_range - calculate_tolerance(max_range,tolerance);
    range_arr[max] = max_range;

     if(check_battery_warning(value,range_arr)== warning)
     {
         return check_battery_error(value,range_arr);
     }

     return normal;
}

battery_status battery_temperature_check(float value,float min_range,float max_range)
{

    float range_arr[4] = {0};
    int tolerance = 5;

    range_arr[min_tolerance] = min_range + calculate_tolerance(min_range,tolerance) ;
    range_arr[min] = min_range;
    range_arr[max_tolerance] = max_range - calculate_tolerance(max_range,tolerance);
    range_arr[max] = max_range;

     if(check_battery_warning(value,range_arr)== warning)
     {
         return check_battery_error(value,range_arr);
     }

     return normal;
}
