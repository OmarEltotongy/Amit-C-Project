/*
 ============================================================================
 Name        : SDB.c
 Author      : Omar Eltoutongy
 Description : Struct Database (SDB) Functions
 Date        : 17/7/2024
 ============================================================================
 */
#include "STD.h"
#include "SDB.h"
#include <stdio.h>

static uint8 currentStudentCount = 0;
static student studentDB[MAX_STUDENTS];

bool SDB_IsFull ()
{
	if(currentStudentCount >= MAX_STUDENTS)
	{
		printf("YES, It is Full\n");
		return 1;
	}
	else
	{
		printf("NO, It is not Full\n");
		return 0;
	}
}

uint8 SDB_GetUsedSize()
{
	return currentStudentCount;
}
bool SDB_AddEntry()
{
	printf("Now we Have %u student in our database\n", currentStudentCount);
	if (SDB_IsFull())
	{
		printf("Sorry, The DB is Full\n");
		return 0;
	}
	student new_student;
	printf("Please enter the following requirement to add new entry\n"
			"Student_ID, Student_year,\nCourse1_ID, Course1_grade,\nCourse2_ID, "
			"Course2_grade,\nCourse3_ID, Course3_grade\n");
	scanf(" %u %u %u %u %u %u %u %u", &new_student.Student_ID,&new_student.Student_year
			,&new_student.Course1_ID, &new_student.Course1_grade,&new_student.Course2_ID,
			&new_student.Course2_grade, &new_student.Course3_ID, &new_student.Course3_grade);

	while(new_student.Student_ID == 0)
	{
		printf("Please Don't enter ID with Value =0\n");
		printf("Please Enter the ID again: ");
		scanf(" %u",&new_student.Student_ID);
		printf("\n");
	}

	/* responsible for adding the new student record to the database */
	studentDB[currentStudentCount]= new_student;
	currentStudentCount++;

	printf("New Student is added.\n");
	return 1;
}
void SDB_DeletEntry (uint32 id)
{
	for(uint8 i=0; i<currentStudentCount; i++)
	{
		if(studentDB[i].Student_ID == id)
		{
			printf("The id is found and will be deleted\n");
			for(uint8 j=i; j<currentStudentCount; j++)
			{
				/* overwriting on the deleted element*/
				studentDB[j]=studentDB[j+1];
			}
			currentStudentCount--;
			printf("Student with ID %u is deleted.\n", id);
		}
	}
	if (!SDB_IsIdExist(id))
	{
		printf("Didn't found the id\n");
	}

}
bool SDB_ReadEntry (uint32 id)
{
	for(uint8 i=0; i<currentStudentCount; i++)
	{
		if(SDB_IsIdExist(id))
		{


			if(studentDB[i].Student_ID == id)
			{
				printf("The id is found and we will display its data\n");
				printf("student_ID is: %u\nStudent_year: %u\nCourse1_ID: %u\nCourse1_grade: %u\nCourse2_ID: %u\n"
						"Course2_grade: %u\nCourse3_ID: %u\nCourse3_grade: %u\n", studentDB[i].Student_ID,
						studentDB[i].Student_year,studentDB[i].Course1_ID,studentDB[i].Course1_grade,
						studentDB[i].Course2_ID,studentDB[i].Course2_grade,
						studentDB[i].Course3_ID,studentDB[i].Course3_grade);
				return 1;

			}
		}


	}
	return 0;


}
void SDB_GetList (uint8 * count, uint32 * list)
{
	*count = currentStudentCount;
	for(uint8 i=0; i<currentStudentCount; i++)
	{
		list[i]=studentDB[i].Student_ID;
	}
}
bool SDB_IsIdExist (uint32 id)
{
	for(uint8 i=0; i<currentStudentCount; i++)
	{
		if(studentDB[i].Student_ID == id)
		{
			printf("The id is found in DB\n");
			return 1;
		}
	}
	return 0;


}














