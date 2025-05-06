#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define length 10
#define width 10
#define NUM_TABLEAU_PILES 7
#define NUM_TABLEAU_ROWS 10
#define NUM_CARDS 52


typedef struct{
    char suit;
    int rank;
}Card;

typedef struct Node {
    char* data;              // Pointer to store the string (line of text)
    struct Node* next;       // Pointer to the next node
} Node;


// Function to create a new node
Node* createNode(char* line) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for node!\n");
        exit(1);
    }

    // Allocate memory for the string and copy the line
    newNode->data = (char*)malloc(strlen(line) + 1);
    if (newNode->data == NULL) {
        printf("Memory allocation failed for data!\n");
        free(newNode);
        exit(1);
    }

    strcpy(newNode->data, line);
    newNode->next = NULL;

    return newNode;
}


// Function to insert a node at the end of the linked list
void insertEnd(Node** head, char* line) {
    // Create a new node
    Node* newNode = createNode(line);

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the end of the list and add the new node
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}




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
        Node* Deck = NULL;
        FILE* file;
        char line[1024];  // Buffer to store each line from the file
        char filename[100];

        // Get filename from user
        printf("Enter the name of the text file to read: ");
        scanf("%s", filename);

        // Open the file
        file = fopen("C:\\Users\\sokka\\CLionProjects\\mopproject2\\Projekt 2 - machineProg\\DeckDefault.txt", "r");
        if (file == NULL) {
            printf("Error opening file '%s'!\n", filename);
            return 1;
        }

        // Read file line by line and add to linked list
        while (fgets(line, sizeof(line), file)) {
            insertEnd(&Deck, line);
        }


        // Close the file
        fclose(file);


        return 0;

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


}
//SW delen
