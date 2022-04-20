//  12S21015 - Sitogab Antonio Octavianus Girsang
//  12S21049 - Jesika Audina Purba


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

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
        input[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        }
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
