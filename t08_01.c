//  12S21015 - Sitogab Antonio Octavianus Girsang
//  12S21049 - Jesika Audina Purba


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv){
    struct student_t *students = malloc(13 * sizeof(struct student_t)); 
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
        } else if (strstr(input, "student-print-all")!=NULL) { // strstr untuk menemukan string student-print-all dalam input.
            print_student(students, i);
        } else if (strstr(input, "student-add")!=NULL){ // untuk menemukan string student-add dalam input.
            data = strtok(input, "#"); // untuk membuat separasi # (hash)
            data = strtok(NULL, "#");
            strcpy(id, data); // mengcopy string dari id ke data
            data = strtok(NULL, "#");
            strcpy(name, data); // copy dari name ke data
            data = strtok(NULL, "#");
            strcpy(year, data); // copy dari year ke data
            data = strtok(NULL, "#");
            if (strcmp(data, "male")==0){ // untuk melihat apakah data itu = male
                students[i] = create_student(id, name, year, GENDER_MALE);
            } else if (strcmp(data, "female")==0){ // melihat apakah data itu = female
                students[i] = create_student(id, name, year, GENDER_FEMALE);
            }
            i++;
        }
        
    } while (1);
    return 0;
}
