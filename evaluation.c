#include <stdio.h>
#include <string.h>

void evaluate_quiz(int score, int total, const char* username) {
    printf("You scored %d out of %d.\n", score, total);
    FILE *fp = fopen("results.csv", "a");
    if (fp) {
        fprintf(fp, "%s,%d,%d\n", username, score, total);
        fclose(fp);
    }
}