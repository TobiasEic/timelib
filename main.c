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

	// Erstellt ein neuen Struct der mit Daten der Funktion input_Date() gefüllt wird
	struct date inputDate = input_date();

	// Berechnet den Tag des Jahres
	int checkDate = day_of_the_year(inputDate);

	//check errors
	if (checkDate == -1) {
		printf("Fehlercode -1: Datum existiert nicht.");
	}
	printf("Tag des Jahres ist: %i", checkDate);

}

