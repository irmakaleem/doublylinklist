#include <iostream>

using namespace std;

// Structure of a node
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to print the list in forward direction
void printListForward(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort the list in ascending order using insertion sort algorithm
void sortAscending(Node **head)
{
    Node *current = *head;
    Node *next;
    Node *sortedHead = NULL;

    while (current != NULL)
    {
        next = current->next;
        while (next != NULL && current->data > next->data)
        {
            // Remove the current node from the list
            if (current->prev != NULL)
            {
                current->prev->next = next;
                next->prev = current->prev;
            }
            else
            {
                *head = next;
                next->prev = NULL;
            }

            // Insert the current node at the beginning of the sorted list
            current->next = sortedHead;
            if (sortedHead != NULL)
            {
                sortedHead->prev = current;
            }
            sortedHead = current;

            // Move on to the next node
            current = next;
            if (next != NULL)
            {
                next = current->next;
            }
        }
    }

    // Set the head of the list to the sorted list
    *head = sortedHead;
}

int main()
{
    // Create a doubly linked list
    Node *head = NULL;

    insertAtEnd(&head, 15);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 18);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 11);

    cout << "List in forward direction: ";
    printListForward(head);

    // Sort the list in ascending order
    sortAscending(&head);

    cout << "List in ascending order: ";
    printListForward(head);

    return 0;
}
