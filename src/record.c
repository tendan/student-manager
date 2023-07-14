#include "record.h"

int update_record(char* raw_value, int field, student_record *record_ptr) {
    switch(field) {
        case 0: {
            __uint128_t new_id = (__uint128_t) atoi(raw_value);
            if (new_id <= 0) return -1;
            record_ptr->id = new_id;
            break;
        }
        case 1:
            strcpy(record_ptr->lastname, raw_value);
            break;
        case 2:
            strcpy(record_ptr->firstname, raw_value);
            break;
        case 3: {
            double new_grade = atof(raw_value);
            if (new_grade < 1. || new_grade > 6. || fmod(new_grade, .5) != 0.) return -1;
            record_ptr->grade = (float) new_grade;
            break;
        }
        default:
            return -1;
    }
    return 0;
}

void print_record(student_record *record) {
    printf("Id: %llx\n", (unsigned long long)record->id);
    printf("Name: %s %s\n", record->firstname, record->lastname);
    printf("Grade: %f\n", record->grade);
}