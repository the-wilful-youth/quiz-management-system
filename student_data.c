#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    int total_attempts;
    int total_score;
} Student;

void update_student_profile(char *username, int score) {
    FILE *fp = fopen("students.csv", "a");
    if (!fp) {
        printf("Unable to update student data.\n");
        return;
    }
    fprintf(fp, "%s,%d\n", username, score);
    fclose(fp);
}