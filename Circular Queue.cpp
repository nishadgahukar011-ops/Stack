#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow! Queue is full.\n";
    }
    else
    {
        cout << "Enter element to insert: ";
        cin >> value;

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        cout << "Element inserted successfully.\n";
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow! Queue is empty.\n";
    }
    else
    {
        cout << "Deleted element: " << queue[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        cout << "Circular Queue: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n----- CIRCULAR QUEUE MENU -----\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}