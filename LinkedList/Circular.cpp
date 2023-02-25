#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int val)
    {
        data = val;
        next = NULL;
    }
    node(int val, node *nex)
    {
        data = val;
        next = nex;
    }
};
void insert(node *&head, int val, int pos = -1)
{
    if (head == NULL)
    {
        head = new node(val);
        head->next = head;
        return;
    }
    if (pos == 0)
    {
        node *temp = head;
        head = new node(val, head);
        node *tem = head->next;
        while (tem->next != temp)
        {
            tem = tem->next;
        }
        tem->next = head;
        return;
    }
    if (pos == -1)
    {
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new node(val, temp->next);
        return;
    }
    int posi = 0;
    node *temp = head;
    while (posi != (pos - 1) && temp->next != head)
    {
        temp = temp->next;
        posi++;
    }
    temp->next = new node(val, temp->next);
    return;
}
void deleteAtPos(node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 0)
    {
        node *temp = head;
        node *tem = head;
        head = head->next;
        while (temp->next != tem)
        {
            temp = temp->next;
        }
        temp->next = head;
        return;
    }
    int posi = 0;
    node *temp = head;
    while (temp->next != head && posi != pos - 1)
    {
        temp = temp->next;
        posi++;
    }
    if (temp->next == head)
    {
        return;
    }
    node *deleter = temp->next;
    temp->next = temp->next->next;
    delete (deleter);
}
void deleteVal(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->data == val)
    {
        node *tem = head;
        node *temp = head->next;
        head = head->next;
        while(temp->next != tem)
        {
            temp = temp->next;
        }
        temp->next = head;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        if (temp->next->data == val)
        {
            node *deleter = temp->next;
            temp->next = temp->next->next;
            delete(deleter);
            return;
        }
        temp = temp->next;
    }
}
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << head->data << "->";
        head = head->next;
    } while (head != temp);
    cout << "LOOP\n";
}
int main()
{
    node *head = NULL;
    insert(head, 4, 5);
    insert(head, 6, 0);
    insert(head, 3);
    insert(head, 2, 8);
    display(head);
    deleteVal(head, 9);
    display(head);
}