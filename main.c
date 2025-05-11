#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auth.c"
#include "evaluation.c"
#include "excel_utils.c"
#include "qotd.c"
#include "question_mgmt.c"
#include "quiz_conduct.c"
#include "result_mgmt.c"
#include "student_data.c"

int main() {
    int choice;
    char username[50];
    while (1) {
        printf("\n==== Quiz Management System ====\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Register User\n");
        printf("4. Register Admin\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (admin_login())
                    admin_dashboard();
                break;
            case 2:
                if (user_login(username))
                    user_dashboard(username);
                break;
            case 3:
                register_user();
                break;
            case 4:
                register_admin();
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}