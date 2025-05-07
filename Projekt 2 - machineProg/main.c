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
    Card card;              // variable of the struct Card
    struct Node* next;       // Pointer to the next node
}Node;

void saveDeck(struct Node* head) {  // Removed the extra semicolon
    char filename[1024];
    printf("Enter the name of the text file to save to: ");
    scanf("%s", filename);

    FILE *fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL) {
        printf("Deck not found, creating new deck\n");
    }

    struct Node* current = head;  // Use a temporary pointer to avoid modifying the original head

    // A loop that runs till current is NULL
    while (current != NULL) {
        // Printing data of current node
        fprintf(fptr, "%c%d\n", current->card.suit, current->card.rank);  // Added file pointer and newline

        // Moving to the next node
        current = current->next;
    }

    // Close the file AFTER the loop (not inside it)
    fclose(fptr);
    printf("Deck saved successfully to %s\n", filename);
}

// Function to create a new node
Node* createNode(char suit, int rank) {
    // Allocate memory for the new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed for node!\n");
        exit(1);
    }
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

//SI
void shuffleInterleaving(Node** deck, int split) {
    if (*deck == NULL || (*deck)->next == NULL) return;

    int size = NUM_CARDS;
    if (split < 1 || split >= size) {
        srand((unsigned int)time(NULL));
        split = rand() % (size - 1) + 1;
    }

    // Split the list
    Node* first = *deck;
    Node* second = NULL;
    Node* prev = NULL;

    Node* current = *deck;
    for (int i = 0; i < split; i++) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = NULL; // Break the list into two parts
        second = current;
    }

    // Shuffle
    Node* interleaved = NULL;
    Node** tail = &interleaved;

    while (first && second) {
        *tail = first;
        first = first->next;
        tail = &((*tail)->next);

        *tail = second;
        second = second->next;
        tail = &((*tail)->next);
    }

    *tail = (first != NULL) ? first : second;
    *deck = interleaved;
}

// Helper function to parse cards
int parseCard(const char* str, char* suit, int* rank) {
    if (strlen(str) < 2)
        return 0;
    *suit = str[0];
    *rank = atoi(&str[1]);
    return 1;
}

void printDeck(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%c %d\n", current->card.suit, current->card.rank);
        current = current->next;
    }
}

void startPhase() {
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
}

int main(void) {
    //////////////////
    char input[5]; //user can enter 4 characters, number 5 is used to terminate the input steam
    Node* head = NULL;

    startPhase();

    fgets(input, sizeof(input), stdin); //input from user

    for (int i = 0; i < 2; ++i) { //converts user input so it is always uppercase
        input[i] = toupper(input[i]);
    }
    printf("you entered %s\n",input);

    if (strncmp(input,"LD",2) == 0) {

        head = NULL;
        char line[1024];  // Buffer to store each line from the file
        char filename[100];

        // Get filename from user
        printf("Enter the name of the text file to read: ");
        scanf("%s", filename);

        //char nameAppend[100] = "Projekt 2 - machineProg/"; //can uncomment if the code doesnt want to accept just the file name
        //strcat(nameAppend,filename);
        // Open the file
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file '%s'!\n", filename);
            return 1;
        }

        // Read file line by line and add to linked list
        while (fgets(line, sizeof(line), file)) {
            char suit;
            int rank;
            if (parseCard(line, &suit, &rank)) {
                insertEnd(&head, suit, rank);
            }
        }
        printDeck(head);



        // Close the file
        fclose(file);


    } else if (strncmp(input, "SW",2) == 0) {
       /* void SW(Card* deck) {
            if (deck == NULL) { //her tjekkes om der er kort i decket
                printf("Error: No deck loaded.\n");
                return;
            }

            Card* current = deck;
            while (current != NULL) {//hvis der er kort, så printer vi suit før rank, for hele decket
                printf("%c %d ", current->suit, current->rank);
                current = current->next;
            }
            printf("\n");

         printf("LAST Command: SW\nMessage: OK\n");//alt har kørt ok
        }*/
    } else if (strncmp(input, "SI", 2) == 0) { //checks if the first two characters of user input is SI
        int split = 0;
        if (strlen(input) > 2) { //Now checks if input is longer than 2 characters
            split = atoi(&input[2]); //converts the input after SI to an integer
        }
        shuffleInterleaving(&head, split);
    } else if (strncmp(input, "SR",2) == 0) {
        shuffleRandom(head);
    } else if (strncmp(input, "SD",2) == 0) {
        saveDeck(head);
    } else if (strncmp(input, "QQ",2) == 0) {
        return 0;
    } else {
        printf("Invalid command");
    }


}


