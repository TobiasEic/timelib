/*
 * timelib.h
 *
 *  Created on: 11.02.2020
 *      Author: tobiaseichhorn
 */

#ifndef TIMELIB_H_
#define TIMELIB_H_

int is_leapyear(int year);
struct date {
	int day;
	int month;
	int year;

};

int get_days_for_month(int month, int year);

int day_of_the_year(struct date inputDate);



int exists_date(struct date inputDate);

struct date input_date();




#endif /* TIMELIB_H_ */
