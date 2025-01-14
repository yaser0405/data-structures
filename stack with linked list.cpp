// stack with linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
class linklist
{
    node* head;
public:
    int size;
    linklist()
    {
        size = 0;
        head = nullptr;
    }
    void InsertAtBegine(int value)
    {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = head;
        head = newnode;
        size++;
    }
    void InsertAtIndex(int value, int index)
    {
        if (index<0 || index>size)
        {
            cout << "index is out of range";
            return;
        }
        if (index == 0)
        {
            InsertAtBegine(value);
            return;
        }
        node* newnode = new node();
        newnode->data = value;
        node* temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        size++;
    }
    void InsertAtEnd(int value)
    {
        node* newnode = new node();
        newnode->data = value;
        newnode->next = nullptr;
        if (size == 0)
        {
            head = newnode;
            size++;
            return;
        }
        else
        {
            node* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        size++;
    }
    void UpdatNode(int value, int index)
    {
        if (index<0 || index>size)
        {
            cout << "index is out of range";
            return;
        }
        node* temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;

        }
        temp->data = value;
    }
    int RemoveNodeAtBegin()
    {
        if (size == 0)
        {
            cout << "list is empty!" << endl;

        }
        else
        {
            node* temp = head;
            head = head->next;
            int x = temp->data;
            delete temp;
            size--;
            return x;
        }
    }
    int RemoveNodeAtEnd()
    {
        if (size == 0)
        {
            cout << "list is empty!" << endl;

        }
        else if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            node* temp = head;
            while (temp->next->next)
            {
                temp = temp->next;
            }
            int x = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            size--;
            return x;
        }
    }
    int RemoveNodeAtIndex(int index)
    {
        if (index<0 || index>size)
        {
            cout << "index is out of range!" << endl;
        }
        else if (size == 0)
        {
            cout << "list is empty!" << endl;
        }
        else if (index == 0)
        {
            return (RemoveNodeAtBegin());
        }
        else
        {
            node* temp = head;
            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }
            node* nodefordelete = temp->next;
            temp->next = temp->next->next;
            size--;
            int x = nodefordelete->data;
            delete nodefordelete;
            return x;
        }
    }
    int SizeOflist()
    {
        return(size);
    }
    void Concatenate(linklist& other)
    {
        if (other.head == nullptr)
        {
            return;
        }
        if (head == nullptr)
        {
            head = other.head;
        }
        else
        {
            node* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        size += other.size;
    }
    void Invert()
    {
        node* perv = nullptr;
        node* temp = head;
        node* next;
        while (temp != nullptr)
        {
            next = temp->next;
            temp->next = perv;
            perv = temp;
            temp = next;
        }
        head = perv;
    }
    void Printlist()
    {
        node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
class Stack
{
public:
    linklist stack;
    void push(int value)
    {
        stack.InsertAtEnd(value);
    }
    int pop()
    {
        return (stack.RemoveNodeAtEnd());
    }
    int peek()
    {
        if (stack.size==0)
        {
            cout << "stack is empty";
        }
        else
        {
            int x = stack.RemoveNodeAtEnd();
            stack.InsertAtEnd(x);
            return x;
        }
    }
    bool IsEmpty()
    {
        if (stack.size==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
