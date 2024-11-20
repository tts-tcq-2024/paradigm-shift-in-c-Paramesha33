#ifndef BATTERY_PARAMETERS_CHECK_H
#define BATTERY_PARAMETERS_CHECK_H
#include "common_util.h"

battery_status battery_temperature_check(float value,float min_range,float max_range);
battery_status battery_soc_check(float value,float min_range,float max_range);
battery_status battery_charge_rate(float value,float range);

#endif
