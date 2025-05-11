#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char username[50];
    char password[50];
} User;

int admin_login() {
    char username[50], password[50];
    printf("Admin Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    FILE *fp = fopen("admins.csv", "r");
    if (!fp) {
        printf("No admin data.\n");
        return 0;
    }
    char line[100], user[50], pass[50];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%s", user, pass);
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            printf("\nAdmin login successful.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    printf("\nInvalid admin credentials.\n");
    return 0;
}

void register_user() {
    FILE *fp = fopen("users.csv", "a");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    char username[50], password[50];
    printf("Choose a Username: ");
    scanf("%s", username);
    printf("Choose a Password: ");
    scanf("%s", password);
    fprintf(fp, "%s,%s\n", username, password);
    fclose(fp);
    printf("\nUser registered successfully.\n");
}

void register_admin() {
    FILE *fp = fopen("admins.csv", "a");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    char username[50], password[50];
    printf("Choose Admin Username: ");
    scanf("%s", username);
    printf("Choose Admin Password: ");
    scanf("%s", password);
    fprintf(fp, "%s,%s\n", username, password);
    fclose(fp);
    printf("\nAdmin registered successfully.\n");
}

int user_login(char* username_out) {
    char username[50], password[50];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    FILE *fp = fopen("users.csv", "r");
    if (!fp) {
        printf("Error opening users file.\n");
        return 0;
    }
    char line[100], user[50], pass[50];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^,],%s", user, pass);
        if (strcmp(username, user) == 0 && strcmp(password, pass) == 0) {
            strcpy(username_out, username);
            fclose(fp);
            printf("\nLogin successful.\n");
            return 1;
        }
    }
    fclose(fp);
    printf("\nInvalid credentials.\n");
    return 0;
}