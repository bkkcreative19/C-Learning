#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void take_string_input(char banner[], char buffer[], int size) {
    printf(banner);
    fgets(buffer, size, stdin);
}

void take_int_input(char banner[], int* buffer) {
    printf(banner);
    scanf("%d", buffer);
}

void create_account() {
    srand(time(NULL));
    int min = 10;
    int max = 100;
    int randomNumber = rand() % (max - min + 1) + min;
    
    char fullName[40];;
    int account_number = randomNumber;
    int deposit;

    take_string_input("Type your full name: \n", fullName, sizeof(fullName));
    take_int_input("Enter your intial deposit: \n", &deposit);
    
    printf("Name is %s", fullName);
    printf("Account number is %d", account_number);
    printf("Deposit is %d", deposit);

    FILE *fptr;

    char location[30] = "Accounts//";
    strcat(location, fullName);

    fptr = fopen("database", "a");

    fprintf(fptr, "\nAccount Name: %s", fullName);
    fprintf(fptr, "Account Number: %d\n", randomNumber);
    fprintf(fptr, "Account Balance: %d\n", deposit);


    fclose(fptr);

}

void view_accounts() {
    // Open a file in read mode
    FILE *file = fopen("database", "r");

    char line[100];

    if(file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        // Example: Print the line
        // printf("Line: %s\n", line);

        char temp[256];
        strcpy(temp, line);

        char *token = strtok(temp, ",");

        char name[50] = "";
        char balance[50] = "";

        while (token != NULL) {
            if (strstr(token, "Account Name:")) {
                sscanf(token, "Account Name: %s", name);
            } else if (strstr(token, "Account Balance:")) {
                sscanf(token, "Account Balance: %s", balance);
            }
            token = strtok(NULL, ",");
        }
        
        printf("The account with the name %s has a balance of $%s\n", name, balance);
        // printf("Balance: %s\n", balance);
        
        
    }

    // Close the file
    fclose(file);
}


void search_for_account(char account_number[]) {
    FILE *file = fopen("database", "r");
    // printf("%s", account_number);
    char line[100];

    if(file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';

        // Example: Print the line
        char string[] = "Account Number: ";
        strcat(string, account_number);

        
        if (strstr(line, string)) {
            char temp[256];
            strcpy(temp, line);

            char *token = strtok(temp, ",");

            char name[50] = "";
            char balance[50] = "";

            while (token != NULL) {
                if (strstr(token, "Account Name:")) {
                    sscanf(token, "Account Name: %s", name);
                } else if (strstr(token, "Account Balance:")) {
                    sscanf(token, "Account Balance: %s", balance);
                }
                token = strtok(NULL, ",");
            }

            printf("The account with the name %s has a balance of $%s\n", name, balance);
            return;
            
        }
        
    }

    printf("The account with the account number of %s does not exits", account_number);
}

int main() {
    
    char input[2];
    take_string_input("Type Input: \n", input, sizeof(input));
    search_for_account(input);
    // printf("%s", input);
    return 0;
}