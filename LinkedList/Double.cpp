#include <iostream>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;
    node(int val, node *previous = NULL, node *nex = NULL)
    {
        data = val;
        next = nex;
        prev = previous;
    }
};
void insert(node *&head, int val, int pos = -1)
{
    if (head == NULL)
    {
        head = new node(val);
        head->prev = head;
        return;
    }
    if (pos == 0)
    {
        head = new node(val,NULL,head);
        return;
    }
    if (pos == -1)
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node(val, temp);
        return;
    }
    int posi = 0;
    node *temp = head;
    while (temp->next != NULL && posi != (pos - 1))
    {
        temp = temp->next;
        posi++;
    }
    temp->next = new node(val, temp, temp->next);
    return;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " - ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void remove(node *&head, int pos = -1)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 0)
    {
        node* deleter = head;
        head->next->prev = NULL;
        head = head->next;
        delete deleter;
        return;
    }
    if (pos == -1)
    {
        node * temp = head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        node* deleter = temp;
        temp->prev->next = NULL;
        delete deleter;
        return;
    }
    node* temp = head;
    int posi = 0;
    while (temp != NULL && posi < pos-1)
    {
        temp=temp->next;
        posi++;
    }
    node *deleter = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev = temp;
    delete deleter;
    return;
}
int main()
{
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    remove(head,2);
    display(head);
}