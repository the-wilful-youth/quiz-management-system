#include <stdio.h>
#include <string.h>

void question_of_the_day() {
    FILE *fp = fopen("qotd.csv", "r");
    if (!fp) {
        printf("\nNo QOTD available.\n");
        return;
    }

    char line[512], question[256], answer[100], user_ans[100];
    if (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%s", question, answer);
        printf("Question of the Day: %s\n", question);
        printf("Your Answer: ");
        scanf("%s", user_ans);
        if (strcmpi(user_ans, answer) == 0) {
            printf("\nCorrect!\n");
        } else {
            printf("\nIncorrect. Correct Answer: %s\n", answer);
        }
    }
    fclose(fp);
}