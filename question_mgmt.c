#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void view_results();

typedef struct {
    char question[256];
    char options[4][100];
    char answer[100];
    int type; // 0 = MCQ, 1 = One-word
} Question;

void add_question() {
    FILE *fp = fopen("questions.csv", "a");
    if (!fp) {
        printf("Failed to open file.\n");
        return;
    }

    Question q;
    printf("Enter question type (0: MCQ, 1: One-word): ");
    scanf("%d", &q.type);
    getchar();
    printf("Enter question: ");
    fgets(q.question, sizeof(q.question), stdin);
    q.question[strcspn(q.question, "\n")] = 0;

    if (q.type == 0) {
        for (int i = 0; i < 4; i++) {
            printf("Option %d: ", i + 1);
            fgets(q.options[i], sizeof(q.options[i]), stdin);
            q.options[i][strcspn(q.options[i], "\n")] = 0;
        }
    }

    printf("Enter correct answer: ");
    fgets(q.answer, sizeof(q.answer), stdin);
    q.answer[strcspn(q.answer, "\n")] = 0;

    fprintf(fp, "%d,%s,%s,%s,%s,%s,%s\n", q.type, q.question,
        q.options[0], q.options[1], q.options[2], q.options[3], q.answer);

    fclose(fp);
    printf("\nQuestion added successfully.\n");
}void admin_dashboard() {
    int choice;
    while (1) {
        printf("\n--- Admin Dashboard ---\n");
        printf("1. Add Question\n");
        printf("2. View Results\n");
        printf("3. View QOTD\n");
        printf("4. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_question();
                break;
            case 2:
                view_results();
                break;
            case 3:
                question_of_the_day();
                break;
            case 4:
                printf("\nLogging out...\n");
                return;
            default:
                printf("\nInvalid choice.\n");
        }
    }
}