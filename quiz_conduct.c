#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void evaluate_quiz(int score, int total, const char* username);
extern void view_user_history(const char* username);
extern void show_leaderboard();

void take_quiz(const char* username) {
    FILE *fp = fopen("questions.csv", "r");
    if (!fp) {
        printf("Unable to open question file.\n");
        return;
    }

    char line[512];
    int score = 0, total = 0;
    while (fgets(line, sizeof(line), fp)) {
        int type;
        char question[256], opt1[100], opt2[100], opt3[100], opt4[100], answer[100], user_ans[100];
        sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", &type, question, opt1, opt2, opt3, opt4, answer);
        printf("\nQ: %s\n", question);
        if (type == 0) {
            printf("1. %s\n2. %s\n3. %s\n4. %s\n", opt1, opt2, opt3, opt4);
        }
        printf("Your Answer: ");
        scanf("%s", user_ans);
        if (strcmpi(user_ans, answer) == 0) {
            score++;
        }
        total++;
    }
    fclose(fp);
    evaluate_quiz(score, total, username);
}
void user_dashboard(const char* username) {
    int choice;
    while (1) {
        printf("\n--- User Dashboard ---\n");
        printf("1. Take Quiz\n");
        printf("2. View QOTD\n");
        printf("3. View My Quiz History\n");
        printf("4. View Leaderboard\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                take_quiz(username);
                break;
            case 2:
                question_of_the_day();
                break;
            case 3:
                view_user_history(username);
                break;
            case 4:
                show_leaderboard();
                break;
            case 5:
                printf("\nLogging out...\n");
                return;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}