#ifndef TASK3_MERGE_SORT_H
#define TASK3_MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "database.h"

enum sort_choice {
    ID = 1,
    NAME,
    STUDENT_CARD_NUMBER,
    AVERAGE_GRADE,
    LOGIN
};

bool compare_id(Student_t *left_array, Student_t *right_array);

bool compare_name(Student_t *left_array, Student_t *right_array);

bool compare_student_card(Student_t *left_array, Student_t *right_array);

bool compare_average_grade(Student_t *left_array, Student_t *right_array);

bool compare_login(Student_t *left_array, Student_t *right_array);

bool (*sort_select())(Student_t *, Student_t *);

void merge(Student_t *array, int left, int middle, int right, bool (*compare)(Student_t *, Student_t *));

void merge_sort(Student_t *array, int left, int right, bool (*compare)(Student_t *, Student_t *));

void sort_database(Student_t *p_database, int number_of_students);

#endif