#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int num);
void printList(struct Node *head);
void append(struct Node **head, int num);
void prepend(struct Node **head, int num);
void deleteByKey(struct Node **head, int key);
void deleteByValue(struct Node **head, int value);
void insertAfterKey(struct Node **head, int key, int value);
void insertAfterValue(struct Node **head, int searchValue, int newValue);

//function to call the implementations
int main()
{
    struct Node *head = NULL;
    int choice, data, key, value;  //these are different items we shall use in the implementation

    while (1)
    {
      //on every call  to this menu function, the program will display a menu of options and wait for user input
        printf("\n\nyou shall enter the number for you choice by pressing enter key:\n");
        printf("\nLinked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. Prepend\n");
        printf("4. Delete by Key\n");
        printf("5. Delete by Value\n");
        printf("6. Insert After Key\n");
        printf("7. Insert After Value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

//for different choices, 'switch' allows us to call each of the choices independently
        switch (choice)
        {
        case 1:
            printf("The list is: ");
            printList(head);
            break;
        case 2:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 3:
            printf("Enter data to prepend: ");
            scanf("%d", &data);
            prepend(&head, data);
            break;
        case 4:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteByKey(&head, key);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;
        case 6:
            printf("Enter key after which to insert: ");
            scanf("%d", &key);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAfterKey(&head, key, value);
            break;
        case 7:
            printf("Enter value after which to insert: ");
            scanf("%d", &value);
            printf("Enter value to insert: ");
            scanf("%d", &data);
            insertAfterValue(&head, value, data);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function definitions
//function to create a new node
struct Node *createNode(int num)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error: Unable to allocate memory for a new node\n");
        exit(1);
    }
    newNode->number = num;
    newNode->next = NULL;
    return newNode;
}
//function to print the list of the available values
void printList(struct Node *head)
{
    struct Node *current = head;
    printf("[");
    while (current != NULL)
    {
        printf("%d", current->number);
        current = current->next;
        if (current != NULL)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
//function to append a new element to the list
void append(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);//a new node is created if the condition below is met
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

//function to prepend a value to the list items
void prepend(struct Node **head, int num)
{
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

//function to implement deletion by key
void deleteByKey(struct Node **head, int key) 
{
    struct Node *temp = *head, *prev = NULL; //the function deletes a value of the list according to the key associated to the value

    if (temp != NULL && temp->number == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->number != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}


//function to implement deletion by value
void deleteByValue(struct Node **head, int value) {
    struct Node *temp = *head, *prev = NULL;  //the function deletes a value input ted by the user from the linked list.
//     struct Node* curr = *head;

    if (temp != NULL && temp->number == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->number != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}


//function to implement insertion after key
void insertAfterKey(struct Node **head, int key, int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp = *head;

    while (temp != NULL && temp->number != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the list.\n"); //the function returns an error message if key entered is out of range
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//function to implement insertion after value
void insertAfterValue(struct Node **head, int searchValue, int newValue) {
    struct Node *newNode = createNode(newValue);
    struct Node *temp = *head;

    while (temp != NULL && temp->number != searchValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list.\n");  //the function returns an error message if the value entered by the user is not among the values within the list
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
