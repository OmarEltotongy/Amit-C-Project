/*
 ============================================================================
 Name        : SDB_APP.c
 Author      : Omar Eltoutongy
 Description : SDB_APP To make the user chose what he want
 Date        : 17/7/2024
 ============================================================================
 */
#include <stdio.h>
#include "STD.h"
#include "SDB.h"

uint8 choice;
/*
 This allows the compiler to understand that such
 a function will be defined later in the code
 */
void SDB_action (uint8 choice);
uint8 Flag =1;
void SDB_APP()
{
	printf("Welcome to Our Program\n\n");
	while(Flag)
	{
		printf("Please Enter a number:\n"
				"Enter 1:To add entry\n"
				"Enter 2:To get used size in database\n" //check
				"Enter 3:To read student data\n"
				"Enter 4:To get the list of all student IDs\n"
				"Enter 5:To check is ID is existed\n"
				"Enter 6:To delete student data\n"
				"Enter 7:To check is database is full\n"
				"Enter 0:To exit\n"
				"Please choose an option: ");
		scanf(" %u", &choice);
		printf("\n\n");
		SDB_action(choice);


	}

}

void SDB_action (uint8 choice)
{
	if(choice == 1)
	{
		uint8 state =0;
		state = SDB_AddEntry();
		printf("The State of AddEntry is: %u\n\n", state);
	}
	else if (choice == 2)
	{
		uint8 Number_of_student=0;
		Number_of_student= SDB_GetUsedSize();
		printf("The number of Students are: %u\n\n", Number_of_student);

	}
	else if (choice == 3)
	{
		uint8 state=0;
		uint32 id=0;
		printf("Please Enter the ID: ");
		scanf(" %u",&id);
		printf("\n");
		state= SDB_ReadEntry(id);
		printf("Note: States are 0 for data is NOT Existed and 1 is for data IS"
				" Existed\nThe State of SDB_ReadEntry is: %u\n\n", state);

	}
	else if (choice == 4)
	{
		uint8 idCount;
		uint32 idList[MAX_STUDENTS]={0};
		SDB_GetList(&idCount,idList);
		printf("Number of IDs: %u\n\n", idCount);

		// Print the list of IDs
		for (uint8 i = 0; i < idCount; i++) {
			if(idList[i] == 0)
			{
				continue;
			}
			printf("ID[%u]: %u\n\n", i, idList[i]);
		}
	}
	else if (choice == 5)
	{
		uint8 state=0;
		uint32 id=0;
		printf("Please Enter the ID: ");
		scanf(" %u",&id);
		printf("\n");
		state= SDB_IsIdExist(id);
		printf("Note: States are 0 for id is NOT Existed and 1 is for id IS"
				" Existed\nThe State of SDB_ReadEntry is: %u\n\n", state);

	}
	else if (choice == 6)
	{
		uint32 id=0;
		printf("Please Enter the ID: ");
		scanf(" %u",&id);
		printf("\n\n");
		SDB_DeletEntry(id);

	}
	else if (choice == 7)
	{
		bool full=0;
		full= SDB_IsFull();
		printf("Note: State are 0 for DB is NOT full and 1 is for DB IS"
				" full\nThe FULL state is: %u\n\n", full);

	}
	else if (choice == 0)
	{
        printf("Exiting...\n\n");
		Flag =0;
	}
	else
	{
		printf("Please Enter A Valid Number Only\n\n");
	}

}
