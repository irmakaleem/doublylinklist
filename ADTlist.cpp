#include <iostream>

using namespace std;

// Node structure
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Doubly linked list
void insertAtStart(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *currentNode = *head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }

        currentNode->next = newNode;
        newNode->prev = currentNode;
    }
}
int getLength(Node *head)
{
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}
void insertAtPosition(Node **head, int data, int position)
{
    if (position == 0)
    {
        insertAtStart(head, data);
    }
    else if (position > 0 && position <= getLength(*head))
    {
        Node *currentNode = *head;
        for (int i = 1; i < position; i++)
        {
            currentNode = currentNode->next;
        }

        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = currentNode;
        newNode->next = currentNode->next;

        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
    else
    {
        cout << "Invalid position" << endl;
    }
}

void traverse(Node *head)
{
    cout << "Traversing the linked list in forward direction..." << endl;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void traverseReverse(Node *head)
{
    cout << "Traversing the linked list in backward direction..." << endl;

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->prev;
    }

    cout << endl;
}

void deleteFromEnd(Node **head)
{
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node *currentNode = *head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }

        *head = currentNode->prev;
        currentNode->prev->next = NULL;

        delete currentNode;
    }
}

void deleteFromStart(Node **head)
{
    if (*head == NULL)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node *currentNode = *head;
        *head = currentNode->next;
        currentNode->next->prev = NULL;

        delete currentNode;
    }
}

void search(Node *head, int data)
{
    bool found = false;

    while (head != NULL)
    {
        if (head->data == data)
        {
            found = true;
            break;
        }

        head = head->next;
    }

    if (found)
    {
        cout << "The element " << data << " is found in the list" << endl;
    }
    else
    {
        cout << "The element " << data << " is not found in the list" << endl;
    }
}

int main()
{
    // Create a linked list
    Node *head = NULL;

    // Insert some elements
    insertAtStart(&head, 1);
    insertAtEnd(&head, 2);
    insertAtPosition(&head, 3, 1);

    // Traverse the linked list
    traverse(head);

    // Delete an element
    deleteFromEnd(&head);

    // Traverse the linked list again
    traverse(head);

    // Search for an element
    search(head, 3);

    // Get the length of the linked list
    int length = getLength(head);
    cout << "The length of the linked list is " << length << endl;

    return 0;
}
