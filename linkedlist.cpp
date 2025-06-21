#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Linkedlist {
    public:
        Node* Head;
        int size;

    Linkedlist() {
        this->Head = NULL;
        this->size = 0;
    }

    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = this->Head;
        Head = newNode;
        this->size++;
    }

     void insert_at_index(int index, int data) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        if (index == 0) {
            insert_at_beginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* current = Head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
        cout << data << " inserted at index " << index << endl;
    }

    void insert_at_end(int data) {
        Node* newNode = new Node(data);
        if (this->Head == NULL) {
            this->Head = newNode;
        } else {
            Node* ptr = this->Head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        this->size++;
        cout << data << " inserted at end" << endl;
    }

    void update_node(int index, int newValue) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        Node* ptr = Head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        cout << "Value at index " << index << " updated from " << ptr->data << " to " << newValue << "." << endl;
        ptr->data = newValue;
    }

    void delete_node(int index) {
        if (this->Head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0) {
            this->Head = this->Head->next;
            cout << "Deleted successfully." << endl;
        } else {
            Node* current = this->Head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            current->next = current->next->next;
            cout << "Deleted successfully." << endl;
        }
        this->size--;
    }

    void display() {
        if (this->Head == NULL) {
            cout << "List is Empty!" << endl;
            return;
        }
        Node* ptr = this->Head;
        cout << "Linked List : ";
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Linkedlist list;
    int choice, element, index;

    do {
        cout << endl << "--------------------------------" << endl;
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at index" << endl;
        cout << "4. Update element at index" << endl;
        cout << "5. Display list" << endl;
        cout << "6. Delete node at index" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element: ";
                cin >> element;
                list.insert_at_beginning(element);
                break;
            case 2:
                cout << "Enter element: ";
                cin >> element;
                list.insert_at_end(element);
                break;
            case 3:
                cout << "Enter index to insert: ";
                cin >> index;
                cout << "Enter element: ";
                cin >> element;
                list.insert_at_index(index, element);
                break;
            case 4:
                cout << "Enter index to update: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> element;
                list.update_node(index, element);
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Enter index to delete: ";
                cin >> index;
                list.delete_node(index);
                list.display();
                break;
            case 0:
                cout << "Exiting.....!" << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}