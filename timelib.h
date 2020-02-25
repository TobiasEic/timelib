/*
 * timelib.h
 *
 *  Created on: 11.02.2020
 *      Author: tobiaseichhorn
 */

#ifndef TIMELIB_H_
#define TIMELIB_H_

int get_days_for_month(int month, int year);

int day_of_the_year(int day, int month, int year);

int is_leapyear(int year);

int exists_date(int day, int month, int year);

void input_date(int *day, int *month, int *year);

#endif /* TIMELIB_H_ */
