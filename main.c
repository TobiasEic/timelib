/*
 ============================================================================
 Name        : tagBerechnung.c
 Author      : Tobias E
 Version     :
 Copyright   :
 Description : Ein Programm, welches nach Eingabe des aktuellen Datums berechnet, der wievielte Tag in diesem Jahr ist.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main(void) {

	int day;
	int month;
	int year;

	input_date(&day, &month, &year);
	int checkDate = day_of_the_year(day, month, year);

	if (checkDate == -1) {
		printf("Fehlercode -1: Datum existiert nicht.");
	}
	printf("Tag des Jahres ist: %i", checkDate);

}

