#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeginning()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << "Node inserted successfully.\n";
}

void insertEnd()
{
    int value;

    cout << "Enter value: ";
    cin >> value;

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted successfully.\n";
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        Node* temp = head;

        cout << "Deleted node: " << head->data << endl;

        head = head->next;
        delete temp;
    }
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
    }
    else if (head->next == NULL)
    {
        cout << "Deleted node: " << head->data << endl;

        delete head;
        head = NULL;
    }
    else
    {
        Node* temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Deleted node: " << temp->next->data << endl;

        delete temp->next;
        temp->next = NULL;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
    }
    else
    {
        Node* temp = head;

        cout << "Linked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n----- SINGLY LINKED LIST MENU -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}