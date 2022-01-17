#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct Node * next;
} Node;

int even(int number) {
    return number % 2 ? 0 : 1;
}

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(newNode == NULL) {
        perror("Error creating new node!");
        return;
    }

    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void addToList(Node** head, int data) {
    Node* temp = *head;
    Node* newNode = createNode(data);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

Node* evenLinkedList(Node* head) {
    Node* temp = head;
    Node* newList = NULL;
    while(temp != NULL) {
        if(even(temp -> data)) {
            addToList(&newList, temp -> data);
        }
        temp = temp -> next;
    }
    return newList;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
}

int countZeros(Node* head) {
    Node* temp = head;
    int counter = 0;
    while(temp != NULL) {
        if(temp->data == 0) {
            ++counter;
        }
        temp = temp->next;
    }
    return counter;
}

int checkIfLinkedListsAreIdentical(Node* first, Node* second) {
    Node* firstTemp = first;
    Node* secondTemp = second;
    while(firstTemp != NULL && secondTemp != NULL) {
        if(firstTemp->data != secondTemp->data) {
            return 0;
        }
        firstTemp = firstTemp->next;
        secondTemp = secondTemp->next;
    }
    return 1;
}

void appendListToAnother(Node** first, Node* second) {
    Node* firstTemp = *first;
    Node* secondTemp = second;
    // Traverse first list until last element
    while(firstTemp->next != NULL) {
        firstTemp = firstTemp->next;
    }

    //Now traverse through second list and append it to 
    while(secondTemp != NULL) {
        firstTemp->next = secondTemp;
        firstTemp = secondTemp;
        secondTemp = secondTemp->next;
    }
}

void changeMinAndMaxElement(Node** head) {

}

Node* min(Node* head) {
    Node* temp = head;
    int min = INT_MAX;
    Node* minNode = NULL;
    while(temp != NULL) {
        if(temp->data < min) {
            min = temp->data;
            minNode = temp;
        }
        temp = temp->next;
    }
    return minNode;
}

Node* max(Node* head) {
    Node* temp = head;
    int max = INT_MIN;
    Node* maxNode = NULL;
    while(temp != NULL) {
        if(temp->data > max) {
            max = temp->data;
            maxNode = temp;
        }
        temp = temp->next;
    }
    return maxNode;
}

void switchNodes(Node** head, Node* first, Node* second) {
    Node* secondNext = second->next;
    Node* beforeFirst = *head;
    Node* beforeSecond = *head;
    while(beforeFirst != NULL && beforeFirst->next != first) {
        beforeFirst = beforeFirst->next;
    }
    while(beforeSecond != NULL && beforeSecond->next != second) {
        beforeSecond = beforeSecond->next;
    }

    second->next = first->next;
    beforeFirst->next = second;
    first->next = secondNext;
    beforeSecond->next = first;
}

Node* loadListFromKeyboard() {
    Node* head = NULL;
    int data;
    while(1) {
        printf("Enter value for list (0 for last element): ");
        scanf("%d", &data);
        if(data == 0)
            return head;
        addToList(&head, data);
    }
}

int main(void) {
    Node* head = NULL;
    addToList(&head, 1);
    addToList(&head, 2);
    addToList(&head, 3);
    addToList(&head, 0);
    addToList(&head, 4);
    addToList(&head, 5);
    addToList(&head, 0);
    addToList(&head, 6);
    addToList(&head, 7);
    addToList(&head, 0);
    addToList(&head, 8);
    addToList(&head, 9);
    Node* newList = evenLinkedList(head);
    printf("Whole list: \n");
    printLinkedList(head);
    printf("\nEven list: \n");
    printLinkedList(newList);
    printf("\nCount of zeros: %d", countZeros(head));
    printf("\nCheck if two lists are identical: %s", checkIfLinkedListsAreIdentical(head, head) ? "Yes" : "No");
    printf("\nCheck if two lists are identical: %s", checkIfLinkedListsAreIdentical(head, newList) ? "Yes" : "No");

    // Appending lists
    // First list 
    Node* firstList = NULL;
    addToList(&firstList, 1);
    addToList(&firstList, 2);
    addToList(&firstList, 3);

    // second list 
    Node* secondList = NULL;
    addToList(&secondList, 4);
    addToList(&secondList, 5);
    addToList(&secondList, 6);
    printf("\nPrint first list\n");
    printLinkedList(firstList);
    printf("\nPrint second list\n");
    printLinkedList(secondList);
    appendListToAnother(&firstList, secondList);
    printf("\nAppended lists\n");
    printLinkedList(firstList);

    // List for switching min and max node
    Node* switchingList = NULL;
    addToList(&switchingList, 2);
    addToList(&switchingList, 1);
    addToList(&switchingList, 4);
    addToList(&switchingList, 3);
    addToList(&switchingList, 6);
    printf("\nOriginal list: \n");
    printLinkedList(switchingList);
    Node* first = min(switchingList);
    Node* second = max(switchingList);
    printf("\nMin value in list is: %d", first->data);
    printf("\nMax value in list is: %d\n", second->data);
    switchNodes(&switchingList, first, second);
    printLinkedList(switchingList); 
    printf("\n");  
    Node* listFromKeyboard = loadListFromKeyboard();
    printf("%d", listFromKeyboard->data);
    printf("\nList from keyboard: \n");
    printLinkedList(listFromKeyboard);
    return 0;
}