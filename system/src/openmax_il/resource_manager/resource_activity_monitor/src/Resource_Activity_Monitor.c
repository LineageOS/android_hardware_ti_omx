
/*
 * Copyright (C) Texas Instruments - http://www.ti.com/
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Resource_Activity_Monitor.h"


void omap_pm_set_constraint(int ID, int MHz)
{
#ifdef RAM_ENABLED
    char command[100];
    unsigned int operatingPoint;

    if (MHz < OPERATING_POINT_1_MHZ) {
        operatingPoint = OPERATING_POINT_1;
    }
    else if (MHz < OPERATING_POINT_2_MHZ) {
        operatingPoint = OPERATING_POINT_2;
    }
    else if (MHz < OPERATING_POINT_3_MHZ) {
        operatingPoint = OPERATING_POINT_3;
    }
    else if (MHz < OPERATING_POINT_4_MHZ) {
        operatingPoint = OPERATING_POINT_4;
    }
    else {
        operatingPoint = OPERATING_POINT_5;
    }
    
    printf("[setting operating point] MHz = %d operatingPoint = %d\n",MHz,operatingPoint);
    strcpy(command,"echo -n ");
    strcat(command,ram_itoa(operatingPoint));
    strcat(command," > /sys/power/vdd1_opp");
    system(command);
#endif    
}

int omap_pm_get_constraint(int ID)
{
    printf("[omap_pm_get_constraint] id = %d \n",ID);
    return 0;
}

char * ram_itoa(int a)
{
    static char str[50];
    int i = sizeof(str) - 1;
    if (i != 0) {
        do {
            str[--i] = '0' + a % 10;
        }
        while ((a = a / 10) && i >= 0);
    }
    return &str[i];
}

