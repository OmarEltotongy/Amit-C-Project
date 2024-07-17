/*
 ============================================================================
 Name        : amit_c_project.c
 Author      : Omar Eltoutongy
 Description : AMIT-C Programming Project Struct Database (SDB)
 Date        : 17/7/2024
 ============================================================================
 */

#include "SDB.h"
#include <stdio.h>
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("Welcome To AMIT C program project\n");

	while(SDB_GetUsedSize() < MIN_STUDENTS)
	{
		printf("We should have 3 student at minimum at DB\n");
		SDB_AddEntry();
	}
	SDB_APP();
	return 0;
}
