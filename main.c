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


	struct date inputDate = input_date();

	int checkDate = day_of_the_year(inputDate);


	//check errors
	if (checkDate == -1) {
		printf("Fehlercode -1: Datum existiert nicht.");
	}
	printf("Tag des Jahres ist: %i", checkDate);

}

