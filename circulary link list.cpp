#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class CircularLinkList {
    node* head;
    int size;
public:
    CircularLinkList() {
        size = 0;
        head = nullptr;
    }

    void InsertAtBegine(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (head == nullptr) {
            newnode->next = newnode;
            head = newnode;
        }
        else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
        size++;
    }

    void InsertAtEnd(int value) {
        node* newnode = new node();
        newnode->data = value;
        if (head == nullptr) {
            newnode->next = newnode;
            head = newnode;
        }
        else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
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
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        node* toDelete = head;
        int x = head->data;
        if (head->next == head) {
            head = nullptr;
        }
        else {
            temp->next = head->next;
            head = head->next;
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
        while (temp->next->next != head) {
            temp = temp->next;
        }
        int x = temp->next->data;
        delete temp->next;
        temp->next = head;
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
        int x = toDelete->data;
        delete toDelete;
        size--;
        return x;
    }

    int SizeOflist() {
        return size;
    }

    void Concatenate(CircularLinkList& other) {
        if (other.head == nullptr) {
            return;
        }
        if (head == nullptr) {
            head = other.head;
        }
        else {
            node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = other.head;
            node* othertemp = other.head;
            while (othertemp->next != other.head) {
                othertemp = othertemp->next;
            }
            othertemp->next = head;
        }
        size += other.size;
    }

    void Invert() {
        if (head == nullptr || head->next == head) {
            return;
        }
        node* prev = nullptr;
        node* current = head;
        node* next = nullptr;
        node* last = head;
        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        head = prev;
    }

    void Printlist() {
        if (head == nullptr) {
            cout << "list is empty!" << endl;
            return;
        }
        node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkList list1, list2;
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
    cout<<"delete data : "<<list1.RemoveNodeAtIndex(2)<<endl;
    list1.Printlist();
    cout << "delete data : " << list1.RemoveNodeAtBegin()<<endl;
    list1.Printlist();
    cout << "delete data : " << list1.RemoveNodeAtEnd()<<endl;
    list1.Printlist();
    list2.InsertAtBegine(3);
    list1.Concatenate(list2);
    list1.Printlist();
    cout<<"size list 1 : " << list1.SizeOflist() << endl;
    cout<<"size list 2 : " << list2.SizeOflist() << endl;
    list1.Invert();
    list1.Printlist();
}