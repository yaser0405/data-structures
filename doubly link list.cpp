// doubly link list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
class linkedlist
{
public:
    linkedlist()
    {
        head = nullptr;
        size = 0;
    };
    void InsertAtBegine(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (head == nullptr) {
            newnode->next = nullptr;
            newnode->prev = nullptr;
            head = newnode;
        }
        else {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
            newnode->prev = nullptr;
        }
        size++;
    }

    void InsertAtEnd(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (head == nullptr) {
            newnode->next = nullptr;
            newnode->prev = nullptr;
            head = newnode;
        }
        else {
            node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = nullptr;
        }
        size++;
    }

    void InsertAtIndex(int value, int index) {
        if (index < 0 || index > size) {
            cout << "index is out of range";
            return;
        }
        if (index == 0) {
            InsertAtBegine(value);
            return;
        }
        if (index == size) {
            InsertAtEnd(value);
            return;
        }
        node* newnode = new node();
        newnode->data = value;
        node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        size++;
    }

    void UpdatNode(int value, int index) {
        if (index < 0 || index >= size) {
            cout << "index is out of range";
            return;
        }
        node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = value;
    }
    int RemoveNodeAtBegin() {
        if (size == 0) {
            cout << "list is empty!" << endl;
            return -1;
        }
        node* toDelete = head;
        int x = head->data;
        if (head->next == nullptr) {
            head = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete toDelete;
        size--;
        return x;
    }

    int RemoveNodeAtEnd() {
        if (size == 0) {
            cout << "list is empty!" << endl;
            return -1;
        }
        if (size == 1) {
            int x = head->data;
            delete head;
            head = nullptr;
            size--;
            return x;
        }
        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        node* todelete = temp->next;
        int x = temp->next->data;
        delete todelete;
        temp->next = nullptr;
        size--;
        return x;
    }

    int RemoveNodeAtIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "index is out of range!" << endl;
            return -1;
        }
        if (index == 0) {
            return RemoveNodeAtBegin();
        }
        if (index == size - 1) {
            return RemoveNodeAtEnd();
        }
        node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        node* toDelete = temp->next;
        temp->next = toDelete->next;
        (temp->next)->prev = temp;
        int x = toDelete->data;
        delete toDelete;
        size--;
        return x;
    }

    int SizeOflist() {
        return size;
    }

    void Concatenate(linkedlist& other) {
        if (other.head == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = other.head;
        }
        else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = other.head;
            other.head->prev = temp;
        }
        size += other.size;
    }

    void Invert() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        node* prevnode = nullptr;
        node* current = head;
        while (current != nullptr)
        {
            node* temp = current->next;
            current->next = prevnode;
            current->prev = temp;
            prevnode = current;
            current = temp;
        }
        head = prevnode;
    }
    void Printlist() {
        if (head == nullptr) {
            cout << "list is empty!" << endl;
            return;


        }
        node* temp = head;
        do {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != nullptr);
        cout << "null" << endl;
    }
	

private:
    node* head;
    int size;

};
int main()
{
    linkedlist list1, list2;
    list1.InsertAtEnd(10);
    list1.Printlist();
    list1.InsertAtEnd(30);
    list1.Printlist();
    list1.InsertAtBegine(5);
    list1.Printlist();
    list1.InsertAtIndex(25, 1);
    list1.Printlist();
    list1.Invert();
    list1.Printlist();
    cout << "delete data : " << list1.RemoveNodeAtIndex(2) << endl;
    list1.Printlist();
    cout << "delete data : " << list1.RemoveNodeAtBegin() << endl;
    list1.Printlist();
    cout << "delete data : " << list1.RemoveNodeAtEnd() << endl;
    list1.Printlist();
    list2.InsertAtBegine(3);
    list1.Concatenate(list2);
    list1.Printlist();
    cout << "size list 1 : " << list1.SizeOflist() << endl;
    cout << "size list 2 : " << list2.SizeOflist() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
