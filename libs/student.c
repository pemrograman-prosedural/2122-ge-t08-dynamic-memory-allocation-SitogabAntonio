#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t s;
    strcpy(s.id, _id);
    strcpy(s.name, _name);
    strcpy(s.year, _year);
    s.gender = _gender;
    s.dorm = NULL;
    return s;
}

void print_student(struct student_t *_student, int count){
    for (int i = 0; i < count; i++){
        if (_student[i].gender==GENDER_MALE){
            printf("%s|%s|%s|male\n", _student[i].id, _student[i].name, _student[i].year);
        } else if (_student[i].gender==GENDER_FEMALE){
            printf("%s|%s|%s|female\n", _student[i].id, _student[i].name, _student[i].year);
        }
    }
} 