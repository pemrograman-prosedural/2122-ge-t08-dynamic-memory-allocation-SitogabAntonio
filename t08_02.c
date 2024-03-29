//  12S21015 - Sitogab Antonio Octavianus Girsang
//  12S21049 - Jesika Audina Purba

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv){
    struct dorm_t *dorms = malloc(5 * sizeof(struct dorm_t));
    char input[100];
    char name[40];
    unsigned short capacity;
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
        } else if (strstr(input, "dorm-print-all")!=NULL) {
            print_dorm(dorms, i);
        } else if (strstr(input, "dorm-add")!=NULL){
            data = strtok(input, "#");
            data = strtok(NULL, "#");
            strcpy(name, data);
            data = strtok(NULL, "#");
            capacity = atoi(data);
            data = strtok(NULL, "#");
            if (strcmp(data, "male")==0){
                dorms[i] = create_dorm(name, capacity, GENDER_MALE);
            } else if (strcmp(data, "female")==0){
                dorms[i] = create_dorm(name, capacity, GENDER_FEMALE);
            }
            i++;
        }
    } while (1);
    return 0;
}
