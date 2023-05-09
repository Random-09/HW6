#include "../include/merge_sort.h"

bool compare_id(Student_t *left_array, Student_t *right_array) {
    return left_array->id <= right_array->id;
}

bool compare_name(Student_t *left_array, Student_t *right_array) {
    return left_array->name <= right_array->name;
}

bool compare_student_card(Student_t *left_array, Student_t *right_array) {
    return left_array->student_card_number <= right_array->student_card_number;
}

bool compare_average_grade(Student_t *left_array, Student_t *right_array) {
    return left_array->average_grade <= right_array->average_grade;
}

bool compare_login(Student_t *left_array, Student_t *right_array) {
    return left_array->login <= right_array->login;
}

bool (*sort_select())(Student_t *, Student_t *) {
    printf("Select a value by which database will be sorted:"
           "\n1) ID\n2) Name\n3) Student card number\n4) Average grade\n5) Login\n");
    char input;
    int sort_choice;
    scanf("%s", &input);
    sort_choice = strtol(&input, NULL, 10);
    switch (sort_choice) {
        case ID:
            return compare_id;
        case NAME:
            return compare_name;
        case STUDENT_CARD_NUMBER:
            return compare_student_card;
        case AVERAGE_GRADE:
            return compare_average_grade;
        case LOGIN:
            return compare_login;
        default:
            puts("Incorrect input!");
            break;
    }
    return NULL;
}

void merge(Student_t *array, int left, int middle, int right, bool (*compare)(Student_t *, Student_t *)) {
    int i, j, k;
    int left_len = middle - left + 1;
    int right_len = right - middle;
    Student_t left_array[left_len], right_array[right_len];
    for (i = 0; i < left_len; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < right_len; j++)
        right_array[j] = array[middle + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < left_len && j < right_len) {
        if (compare(&left_array[i], &right_array[j])) {
            array[k] = left_array[i];
            i++;
        } else {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }
    while (i < left_len) {
        array[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right_len) {
        array[k] = right_array[j];
        j++;
        k++;
    }
}

void merge_sort(Student_t *array, int left, int right, bool (*compare)(Student_t *, Student_t *)) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(array, left, middle, compare);
        merge_sort(array, middle + 1, right, compare);
        merge(array, left, middle, right, compare);
    }
}

void sort_database(Student_t *p_database, int number_of_students) {
    bool (*compare)(Student_t *, Student_t *) = sort_select();
    merge_sort(p_database, 0, number_of_students - 1, compare);
}