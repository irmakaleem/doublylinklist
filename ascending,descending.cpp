#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtStart(Node *head, int data)
{
    Node *newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);

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

    return head;
}

Node *insertAtPosition(Node *head, int data, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position." << endl;
        return head;
    }

    Node *newNode = createNode(data);

    if (head == NULL && position == 1)
    {
        head = newNode;
    }
    else if (head != NULL && position == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        Node *current = head;
        int count = 1;
        while (current != NULL && count < position - 1)
        {
            current = current->next;
            count++;
        }
        if (current == NULL)
        {
            cout << "Invalid position." << endl;
            return head;
        }
        newNode->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

Node *deleteFromStart(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return head;
    }

    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;

    return head;
}

Node *deleteFromEnd(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return head;
    }

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    delete current;

    return head;
}

Node *search(Node *head, int data)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void displayForward(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
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

void displayBackward(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

Node *bubbleSortAscending(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    bool swapped;
    Node *current;
    Node *last = NULL;

    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);

    return head;
}

Node *bubbleSortDescending(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    bool swapped;
    Node *current;
    Node *last = NULL;

    do
    {
        swapped = false;
        current = head;

        while (current->next != last)
        {
            if (current->data < current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }

        last = current;
    } while (swapped);

    return head;
}

int main()
{
    Node *head = NULL;
    int choice, data, position;

    do
    {
        cout << "---------------------- Doubly Linked List Implementation -----------------------" << endl;
        cout << "1. Insert an element at the start." << endl;
        cout << "2. Insert an element at the end." << endl;
        cout << "3. Insert an element at any position." << endl;
        cout << "4. Traverse the linked list in both directions (forward and backward)." << endl;
        cout << "5. Delete an element from the end." << endl;
        cout << "6. Delete an element from the start." << endl;
        cout << "7. Search an element." << endl;
        cout << "8. Display the list." << endl;
        cout << "9. Sort the list in ascending order using bubble sort." << endl;
        cout << "10. Sort the list in descending order using bubble sort." << endl;
        cout << "11. Exit." << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the data to insert at the start: ";
            cin >> data;
            head = insertAtStart(head, data);
            break;
        case 2:
            cout << "Enter the data to insert at the end: ";
            cin >> data;
            head = insertAtEnd(head, data);
            break;
        case 3:
            cout << "Enter the data to insert: ";
            cin >> data;
            cout << "Enter the position to insert at: ";
            cin >> position;
            head = insertAtPosition(head, data, position);
            break;
        case 4:
            cout << "List in forward direction: ";
            displayForward(head);
            cout << "List in backward direction: ";
            displayBackward(head);
            break;
        case 5:
            head = deleteFromEnd(head);
            cout << "Element deleted from the end." << endl;
            break;
        case 6:
            head = deleteFromStart(head);
            cout << "Element deleted from the start." << endl;
            break;
        case 7:
            cout << "Enter the data to search: ";
            cin >> data;
            if (search(head, data) != NULL)
            {
                cout << "Element found in the list." << endl;
            }
            else
            {
                cout << "Element not found in the list." << endl;
            }
            break;
        case 8:
            cout << "List: ";
            displayForward(head);
            break;
        case 9:
            head = bubbleSortAscending(head);
            cout << "List sorted in ascending order using bubble sort." << endl;
            break;
        case 10:
            head = bubbleSortDescending(head);
            cout << "List sorted in descending order using bubble sort." << endl;
            break;
        case 11:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 11);

    return 0;
}
