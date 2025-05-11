#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_results() {
    FILE *fp = fopen("results.csv", "r");
    if (!fp) {
        printf("No results to show.\n");
        return;
    }
    char line[100];
    printf("\n--- All Quiz Results ---\n");
    while (fgets(line, sizeof(line), fp)) {
        char user[50];
        int score, total;
        sscanf(line, "%[^,],%d,%d", user, &score, &total);
        printf("User: %s | Score: %d/%d\n", user, score, total);
    }
    fclose(fp);
}

void view_user_history(const char* username) {
    FILE *fp = fopen("results.csv", "r");
    if (!fp) {
        printf("No results available.\n");
        return;
    }
    char line[100];
    printf("\n--- Quiz History for %s ---\n", username);
    while (fgets(line, sizeof(line), fp)) {
        char user[50];
        int score, total;
        sscanf(line, "%[^,],%d,%d", user, &score, &total);
        if (strcmp(user, username) == 0)
            printf("Score: %d/%d\n", score, total);
    }
    fclose(fp);
}

void show_leaderboard() {
    FILE *fp = fopen("results.csv", "r");
    if (!fp) {
        printf("No results found.\n");
        return;
    }

    typedef struct {
        char username[50];
        int total_score;
        int total_quizzes;
    } Leader;

    Leader leaders[100];
    int count = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char user[50];
        int score, total;
        sscanf(line, "%[^,],%d,%d", user, &score, &total);

        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(leaders[i].username, user) == 0) {
                leaders[i].total_score += score;
                leaders[i].total_quizzes += 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(leaders[count].username, user);
            leaders[count].total_score = score;
            leaders[count].total_quizzes = 1;
            count++;
        }
    }
    fclose(fp);

    printf("\n--- Leaderboard (Avg Scores) ---\n");
    for (int i = 0; i < count; i++) {
        float avg = (float)leaders[i].total_score / leaders[i].total_quizzes;
        printf("%s: Avg Score = %.2f (%d attempts)\n", leaders[i].username, avg, leaders[i].total_quizzes);
    }
}