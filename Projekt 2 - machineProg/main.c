#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define length 10
#define width 10
#define NUM_TABLEAU_PILES 7
#define NUM_TABLEAU_ROWS 10
#define NUM_CARDS 52


typedef struct{
    char suit; // C, D, H, S
    int rank; // 1-13
}Card;

typedef struct Node {
    Card card;              // Pointer to store the string (line of text)
    struct Node* next;       // Pointer to the next node
} Node;


// Function to create a new node
Node* createNode(char suit, int rank) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for node!\n");
        exit(1);
    }

    // Kristian med mindre at LD eller SD behøver dette kan det slettes da Card ikke længere er en pointer variabel
    // Allocate memory for the string and copy the card
    /*newNode->card = (char*)malloc(strlen(card) + 1);
    if (newNode->card == NULL) {
        printf("Memory allocation failed for data!\n");
        free(newNode);
        exit(1);
    }*/

    newNode->card.suit = suit;
    newNode->card.rank = rank;
    newNode->next = NULL;
    return newNode;
}

// Function to get the node at a specific index
Node* getNodeAt(Node* head, int index) {
    int count = 0;
    Node* current = head;
    while (current && count < index) {
        current = current->next;
        count++;
    }
    return current;
}


// Function to insert a node at the end of the linked list
void insertEnd(Node** head, char suit, int rank) {
    // Create a new node
    Node* newNode = createNode(suit, rank);

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


//Swap two nodes card data
 void swapCards(Node* a, Node* b) {
    Card temp = a->card;
    a->card = b->card;
    b->card = temp;
 }

//SR
void shuffleRandom(Node* head) {
    srand((unsigned int)time(NULL)); //Sets seed based on current time ;D
    for (int i = NUM_CARDS - 1; i > 0; i--) { //As we use a single linked list we have to start from the last element
        int j = rand() % (i + 1);
        Node* nodeI = getNodeAt(head, i);
        Node *nodeJ = getNodeAt(head, j);
        swapCards(nodeI,nodeJ);
    }
}

// Helper function to parse cards
int parseCard(const char* str, char* suit, int* rank) {
    if (strlen(str) < 2)
        return 0;
    *suit = str[0];
    *rank = atoi(&str[1]);
    return 1;
}


int main(void) {
    //////////////////
    char input[3]; //needs to be 3 because terminating the input steam takes 1, otherwise the user input should always be 2.
    Node* head = NULL;


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
        char line[1024];  // Buffer to store each line from the file
        char filename[100];

        // Get filename from user
        printf("Enter the name of the text file to read: ");
        scanf("%s", filename);

        // Open the file
        FILE* file = fopen("DeckDefault.txt", "r");
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
        shuffleRandom(head);
    } else if (strcmp(input, "SD") == 0) {
        printf("SW works"); //call to SD subroutine should replace this
    } else if (strcmp(input, "QQ") == 0) {
        return 0;
    } else {
        printf("Invalid command");
    }


}


