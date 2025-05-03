#include <stdio.h>

#define length 10
#define width 10
#define NUM_TABLEAU_PILES 7
#define NUM_TABLEAU_ROWS 10
#define NUM_CARDS 52




int main(void) {
    //////////////////

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


