/****************************************************************************
* Program Name: linkList													*
* Author: Tristan Santiago													*
* Date: February 18, 2018													*
* Description: This program creates a simple doubly-linked list data		*
* structures consisting of Node objects.									*
****************************************************************************/
#include <iostream>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
// #include "inputValidation.cpp"

using namespace std;

/*******************
* Node Declaration *
*******************/
struct Node
{
    Node* next;
    Node* prev;
    int val;
};
//https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
   /* deref head_ref to get the real head */
   struct Node* current = *head_ref;
   struct Node* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

/*************************************************************
**						PUSH
** Given a reference (pointer to pointer) to the head
** of a list and an int, push a new node on the front
** of the list.
**************************************************************/
void push(struct Node** head_ref, int new_val)
{
    /* allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->val = new_val;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/********************
* Class Declaration *
********************/
class DoublyLinkedList
{
private:
    Node *head, *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

/**********************
*	  Add to Head     *
**********************/
    void addFirst(int val)
    {
        Node* n = new Node();
        n->val = val;
        if (tail == NULL) {
            head = tail = n;
        }
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        this->traverseFront();
    }
/**********************
*	  Add to Tail     *
**********************/
    void addLast(int val)
    {
        Node* n = new Node();
        n->val = val;
        if (head == NULL) {
            head = tail = n;
        }
        else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        this->traverseFront();
    }

/**********************
*  Delete from Head   *
**********************/
    int deleteFirst()
    {
        if (head == NULL)
            return -1;
        Node* tmp = head;
        if (head->next != NULL)
            head->next->prev = NULL;
        head = head->next;
        int val = tmp->val;
        delete tmp;
        return val;
    }
/**********************
*	Delete from Tail  *
**********************/
    int deleteLast()
    {
        if (tail == NULL)
            return -1;
        Node* tmp = tail;
        if (tail->prev != NULL)
            tail->prev->next = NULL;
        tail = tail->prev;
        int val = tmp->val;
        delete tmp;
        return val;
    }
/**********************
*  Delete Everything  *
**********************/
    int deleteAll()
    {
	    deleteList(&head);
	    deleteList(&tail);
    }
    int getAtHead()
    {
        if (head == NULL)
            return -1;
        return head->val;
    }
    int getAtTail()
    {
        if (tail == NULL)
            return -1;
        return tail->val;
    }

/***************************************
* Display elements of Doubly Link List *
***************************************/
    void traverseFront()
    {
        Node* tmp = head;
        if (tmp == NULL) {
            cout << "List is empty. Please add a value.";
            return;
        }
        while (tmp != NULL) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

/***************************************
*    Display elements in Reverse       *
***************************************/
    void traverseReverse()
    {
        Node* tmp = tail;
        if (tmp == NULL) {
            cout << "List is empty. Please add a value.";
            return;
        }
        while (tmp != NULL) {
            cout << tmp->val << " ";
            tmp = tmp->prev;
        }
        cout << endl;
    }
};

/**********************
* Main: Conatins Menu *
**********************/
int main()
{
    char ch = 0;
    DoublyLinkedList list;
    while (ch != '9') {
        cout << "\n1.Add a new node to the head.";
        cout << "\n2.Add a new node to the tail.";
        cout << "\n3.Delete the first node in the list.";
        cout << "\n4.Delete the last node in the list.";
        cout << "\n5.Traverse the list reversely.";
        cout << "\n6.Traverse the list.";
        cout << "\n7.Value pointed by head.";
        cout << "\n8.Value pointed by tail.";
        cout << "\n9.Exit";
        cout << "\n\nEnter Choice: ";
        cin >> ch;
        if (ch == '1' || ch == '2') {
            std::string str;
            int val;
            cout << endl
                 << "Please enter the value: ";
            cin >> str;
            try {
                val = std::stoi(str);
                if (ch == '1')
                    list.addFirst(val);
                else
                    list.addLast(val);
            }
            catch (...) {
                cout << "Please provide integer value. Operation aborted." << endl;
            }
        }
        else if (ch == '3' || ch == '4') {
            int v;
            if (ch == '3')
                v = list.deleteFirst();
            else
                v = list.deleteLast();
            if (v == -1)
                cout << "List is empty.";
            else
                cout << "Value with " << v << " deleted";
        }
        else if (ch == '5')
            list.traverseReverse();
        else if (ch == '6')
            list.traverseFront();
        else if (ch == '7') {
            int valueAtFront = list.getAtHead();
            if (valueAtFront == -1)
                cout << "List is empty.";
            else
                cout << "Value of node head pointing to is " << valueAtFront << endl;
        }
        else if (ch == '8') {
            int valueAtTail = list.getAtTail();
            if (valueAtTail == -1)
                cout << "List is empty.";
            else
                cout << "Value of node tail pointing to is " << valueAtTail << endl;
        }
    }
	list.deleteAll();	// Delete anything left over.
    return 0;
}
