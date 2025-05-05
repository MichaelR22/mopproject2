#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define length 10
#define width 10
#define NUM_TABLEAU_PILES 7
#define NUM_TABLEAU_ROWS 10
#define NUM_CARDS 52




int main(void) {
    //////////////////
    char input[3]; //needs to be 3 because terminating the input steam takes 1, otherwise the user input should always be 2.


    for (int i = 0; i < NUM_TABLEAU_PILES; i++) {
        printf("C%d   ", i + 1);
    }
    printf("\n");
    int j = 0;
    int line = 0;
    int lineline = 1;
    while (j < NUM_CARDS) {
        for (int k = 0; k < NUM_TABLEAU_PILES; k++) {
            printf("[]");
            printf("   ");
            j++;
            if (j == NUM_CARDS) {
                break;
            }

        }
        line++;
        if (line == 0 || line % 2) {
            printf("\t");
            printf("\t");
            printf("[]");
            printf("\t");
            printf("F%d",lineline);
            lineline++;
        }

        printf("\n");
    }
    printf("LAST Command:\n"); //remember to add link to last command
    printf("Message:\n");//remember to add link to message
    printf("INPUT >");

    fgets(input, sizeof(input), stdin); //input from user

    for (int i = 0; i < 2; ++i) { //converts user input so it is always uppercase
        input[i] = toupper(input[i]);
    }
    printf("you entered %s\n",input);
    if (strcmp(input,"LD") == 0) {
        printf("LD works"); //call to LD subroutine should replace this
    } else if (strcmp(input, "SW") == 0) {
        printf("SW works"); //call to SW subroutine should replace this
    } else if (strcmp(input, "SI") == 0) {
        printf("SW works"); //call to SI subroutine should replace this
    } else if (strcmp(input, "SR") == 0) {
        printf("SW works"); //call to SR subroutine should replace this
    } else if (strcmp(input, "SD") == 0) {
        printf("SW works"); //call to SD subroutine should replace this
    } else if (strcmp(input, "QQ") == 0) {
        return 0;
    } else {
        printf("Invalid command");
    }

    //////////////////
    typedef struct {
          char suit;
          int rank;
    } Card;

    typedef struct Node {
        Card* Card;              // Pointer to store the string (line of text)
        struct Node* next;       // Pointer to the next node
    } Node;



}
//SW delen
