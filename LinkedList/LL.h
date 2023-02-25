#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int v)
    {
        data = v;
        next = NULL;
    }
};
int length(node* head)
{   
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
void insertAtHead(node *&head, int val)
{
    node *newN = new node(val);
    newN->next = head;
    head = newN;
}
void insertAtTail(node *&head, int val)
{
    node *newN = new node(val);
    if (head == NULL)
    {
        head = newN;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newN;
}
void insert(node *&head, int val, int pos = -1)
{
    if (pos == -1)
    {
        insertAtTail(head, val);
        return;
    }
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;
    int posi = 0;
    while ((posi + 1) != pos)
    {
        temp = temp->next;
        posi++;
    }
    node *a = temp->next;
    temp->next = new node(val);
    temp->next->next = a;
}
int search(node *head, int val) //Search for a value in linked list; Returns -1 if not found
{
    int count = 0;
    while (head != NULL)
    {
        if (head->data == val)
        {
            return count;
        }
        count++;
        head = head->next;
    }
    return -1;
}
void deleteVal(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == val)
    {
        head = head->next;
        return;
    }
    node *temp = head;
    while (temp->next->data != val && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    node *deleter = temp->next;
    temp->next = temp->next->next;
    delete deleter;
}
void deletePos(node *&head, int pos)
{

    if (pos == 0)
    {
        head = head->next;
        return;
    }
    int posi = 0;
    node *temp = head;
    while (posi != pos - 1 && temp != NULL)
    {
        posi++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    node *deleter = temp->next;
    temp->next = temp->next->next;
    delete deleter;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}