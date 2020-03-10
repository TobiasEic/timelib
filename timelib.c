/*
 * timelib.c
 *
 *  Created on: 11.02.2020
 *      Author: tobiaseichhorn
 */
#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

//Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
//Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
int get_days_for_month(int month, int year) {

	int tage[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (is_leapyear(year) == 1) {
		tage[1] = 29;
	}

	if (is_leapyear(year) == -1 || month > 12 || month < 1) {
		return -1;
	}
	return tage[month - 1];

}

//Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
//und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
//Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
int day_of_the_year(struct date inputDate) {
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 0;
	int result = 0;

	if (exists_date(inputDate) == 0) {
		return -1;
	}

	for (i = 0; i < inputDate.month - 1; i++) {
		result += days[i];
	}

	result += inputDate.day;

	return result;

}

// schaltJahrBerechnung
// return 1 bei Schaltjahr
// return 0 bei keinem Schaltjahr
//Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
//ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
int is_leapyear(int year) {

	if (year < 1582 || year > 2400) {
		return -1;
	} else {
		// Jahr ohne Rest durch 4 teilbar -> nein kein Schaltjahr
		if (year % 4 == 0) {
			// Jahr ohne Rest durch 100 teilbar -> nein ein Schaltjahr
			if (year % 100 == 0) {
				// Jahr ohne Rest durch 400 teilbar -> ja ein Schaltjahr
				if (year % 400 == 0) {
					return 1;
				}
				// Jahr ohne Rest durch 400 teilbar -> nein kein Schaltjahr
				else {
					return 0;
				}
			} else {
				return 0;
			}
		} else {
			return 1;
		}
	}

}

//Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
//wie alle Daten nach dem 31.12.2400.
int exists_date(struct date inputDate) {

	if (inputDate.day < 1 || inputDate.month < 1 || inputDate.month > 12 || inputDate.year < 1582 || inputDate.year > 2399
			|| get_days_for_month(inputDate.month, inputDate.year) < inputDate.day) {
		return 0;

	}

	return 1;

}

//Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
//ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.

struct date input_date() {

	struct date inputDate;
	do {

		printf("\nBitte geben Sie einen korrekten Tag an: \n");
		scanf("%d", &inputDate.day);
		fflush(stdin);

		printf("\nBitte geben Sie einn korrekten Monat an: \n");
		scanf("%d", &inputDate.month);
		fflush(stdin);

		printf("\nBitte geben Sie ein korrektes Jahr an (zwischen 1582 und 2400): \n");
		scanf("%d", &inputDate.year);
		fflush(stdin);

	} while (exists_date(inputDate) != 1);

	return inputDate;


}
