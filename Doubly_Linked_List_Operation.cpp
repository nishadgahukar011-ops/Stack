#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

void insertAtStart(Node*& head, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    cout << "Node inserted successfully.\n";
}

void deleteAtStart(Node*& head) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;

    cout << "Node deleted successfully.\n";
}

void traverseForward(Node* head) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "Forward Traversal: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void traverseBackward(Node* head) {

    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    cout << "Backward Traversal: ";

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;

        insertAtStart(head, value);
    }

    int choice;

    do {

        cout << "\n========== MENU ==========\n";
        cout << "1. Insert at Start\n";
        cout << "2. Delete from Start\n";
        cout << "3. Traverse Forward\n";
        cout << "4. Traverse Backward\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value to insert: ";
            cin >> value;

            insertAtStart(head, value);
            break;

        case 2:
            deleteAtStart(head);
            break;

        case 3:
            traverseForward(head);
            break;

        case 4:
            traverseBackward(head);
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

