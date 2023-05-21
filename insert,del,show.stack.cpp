#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void insertAtBeginning(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtEnd(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        return;
    }

    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = NULL;

    delete temp;
}

void display()
{
    if (head == NULL)
    {
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Delete from beginning" << endl;
        cout << "4. Delete from end" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data to insert at the beginning: ";
            cin >> data;
            insertAtBeginning(data);
            break;

        case 2:

            cout << "Enter the data to insert at the end: ";
            cin >> data;
            insertAtEnd(data);
            break;

        case 3:
            deleteAtBeginning();
            break;

        case 4:
            deleteAtEnd();
            break;

        case 5:
            display();
            break;

        case 6:
            return 0;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
