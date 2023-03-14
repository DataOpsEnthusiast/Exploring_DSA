#include <iostream>
#include "DNodeClass.h"
using namespace std;

class DLinkList
{
private:
    DNode *head;
    DNode *tail;

public:
    DLinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void addToHead(double data)
    {

        if (head == NULL)
        {
            DNode *temp = new DNode();
            temp->setData(data);
            head = temp;
        }
        else
        {
            DNode *temp = new DNode();
            temp->setData(data);
            temp->setNext(head);
            temp->setPrev(NULL);
            head->setPrev(temp);
            head = temp;
        }
    }
    void addToTail(double data)
    {

        if (head == NULL)
        {
            DNode *temp = new DNode();
            temp->setData(data);
            head = temp;
            tail = head;
        }
        else
        {
            DNode *temp = new DNode();
            temp->setData(data);
            tail->setNext(temp);
            temp->setPrev(tail);
            tail = temp;
        }
    }
    void addAfter(double existing, double newData)
    {
        DNode *temp = head;
        while (temp != NULL)
        {
            if (existing == temp->getData())
            {
                DNode *next = temp->getNext();
                DNode *newNode = new DNode();
                newNode->setData(newData);
                temp->setNext(newNode);
                newNode->setPrev(temp);
                newNode->setNext(next);
                next->setPrev(newNode);
            }

            temp = temp->getNext();
        }
    }
    void addBefore(double existing, double newData)
    {

        DNode *temp = head;
        while (temp != NULL)
        {
            if (existing == temp->getData())
            {
                DNode *prev = temp->getPrev();
                DNode *newNode = new DNode();
                newNode->setData(newData);
                prev->setNext(newNode);
                newNode->setPrev(prev);
                newNode->setNext(temp);
                temp->setPrev(newNode);
            }

            temp = temp->getNext();
        }
    }
    void deleteFromHead()
    {
        if (head != NULL)
        {
            DNode *temp = head;
            head = temp->getNext();
            delete temp;
            head->setPrev(NULL);
        }
    }
    void deleteFromTail()
    {
        if (head != NULL)
        {
            DNode *temp = tail;
            tail = temp->getPrev();
            delete temp;
            tail->setNext(NULL);
        }
    }
    void deleteSpecificNode(double data)
    {
        DNode *temp = head;
        while (temp != NULL)
        {
            if (data == temp->getData())
            {
                DNode *prev = temp->getPrev();
                DNode *next = temp->getNext();
                prev->setNext(next);
                next->setPrev(prev);
                delete temp;
            }

            temp = temp->getNext();
        }
    }
    void forwardtraversing()
    {
        DNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";

            temp = temp->getNext();
        }
    }
    void reversetraversing()
    {
        DNode *temp = tail;
        while (temp != NULL)
        {
            cout << temp->getData() << "	";

            temp = temp->getPrev();
        }
    }
};

int main()
{

    cout << "**Doubly Linked List**" << endl;
    DLinkList list;
    int choice;
    do
    {
        cout << "\n\t.....Menu......" << endl;
        cout << "\nPress 1: Add to Head" << endl;
        cout << "Press 2: Add to Tail" << endl;
        cout << "Press 3: Add After" << endl;
        cout << "Press 4: Add Before" << endl;
        cout << "Press 5: Delete from Head" << endl;
        cout << "Press 6: Delete from Tail" << endl;
        cout << "Press 7: Delete Specific" << endl;
        cout << "Press 8: Forward Traverse the List" << endl;
        cout << "Press 9: Reverse Traverse the List" << endl;
        cout << "Press 0: Exit" << endl;
        cout << "\nEnter choice of user: ";
        cin >> choice;
        if (choice == 1)
        {
            int element;
            cout << "Enter element_";
            cin >> element;
            list.addToHead(element);
            list.forwardtraversing();
        }
        else if (choice == 2)
        {
            int element;
            cout << "Enter element_";
            cin >> element;
            list.addToTail(element);
            list.forwardtraversing();
        }
        else if (choice == 3)
        {
            int existing, newData;
            cout << "Enter Old Item_";
            cin >> existing;
            cout << "Enter new Item_";
            cin >> newData;
            list.addAfter(existing, newData);
            list.forwardtraversing();
        }
        else if (choice == 4)
        {
            int existing, newData;
            cout << "Enter Old Item_";
            cin >> existing;
            cout << "Enter new Item_";
            cin >> newData;
            list.addBefore(existing, newData);
            list.forwardtraversing();
        }
        else if (choice == 5)
        {
            list.deleteFromHead();
            list.forwardtraversing();
        }
        else if (choice == 6)
        {
            list.deleteFromTail();
            list.forwardtraversing();
        }
        else if (choice == 7)
        {
            int data;
            cin >> data;
            list.deleteSpecificNode(data);
            list.forwardtraversing();
        }

        else if (choice == 8)
        {
            list.forwardtraversing();
        }
        else if (choice == 9)
        {
            list.reversetraversing();
        }

        else if (choice == 0)
        {
            cout<<"Thankyou For Using The Program";
            break;
        }

    } while (choice != 0);
    return 0;
}