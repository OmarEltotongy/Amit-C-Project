/*
 ============================================================================
 Name        : SDB.h
 Author      : Omar Eltoutongy
 Description : A Simple Db with function declaration
 Date        : 17/7/2024
 ============================================================================
 */

#ifndef SDB_H_
#define SDB_H_
#include "STD.h"

#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

typedef struct SimpleDb
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
} student;

bool SDB_IsFull ();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry (uint32 id);
bool SDB_ReadEntry (uint32 id);
void SDB_GetList (uint8 * count, uint32 * list);
bool SDB_IsIdExist (uint32 id);
#endif /* SDB_H_ */
