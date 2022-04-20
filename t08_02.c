// NIM - Name
// NIM - Name

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv){
    struct dorm_t *dorms = malloc(4 * sizeof(struct dorm_t));
    char input[100];
    char name[40];
    unsigned short capacity;
    char *data;
    int i=0;
    do
    {
        fflush(stdin);
        gets (input);
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
