// NIM - Name
// NIM - Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv){
    struct student_t *students = malloc(12 * sizeof(struct student_t));
    char input[100];
    char id[12];
    char name[40];
    char year[5];
    char *data;
    int i=0;
    do
    {
        fflush(stdin);
        gets(input);
        if(strcmp(input, "---")==0){
            break;
        } else if (strstr(input, "student-print-all")!=NULL) {
            print_student(students, i);
        } else if (strstr(input, "student-add")!=NULL){
            data = strtok(input, "#");
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(name, data);
            data = strtok(NULL, "#");
            strcpy(year, data);
            data = strtok(NULL, "#");
            if (strcmp(data, "male")==0){
                students[i] = create_student(id, name, year, GENDER_MALE);
            } else if (strcmp(data, "female")==0){
                students[i] = create_student(id, name, year, GENDER_FEMALE);
            }
            i++;
        }
        
    } while (1);
    return 0;
}
