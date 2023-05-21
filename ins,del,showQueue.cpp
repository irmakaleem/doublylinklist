#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void enqueue(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void dequeue()
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head == NULL)
    {
        tail = NULL;
    }
    else
    {
        head->prev = NULL;
    }

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
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data to enqueue: ";
            cin >> data;
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
