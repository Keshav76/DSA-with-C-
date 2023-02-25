#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next = NULL;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(node *&h, int val, int pos = -1)
{
    if (h == NULL)
    {
        h = new node(val);
        return;
    }
    if (pos == 0)
    {
        node *newN = new node(val);
        newN->next = h;
        h = newN;
        return;
    }
    if (pos == -1)
    {
        node *temp = h;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node(val);
        return;
    }
    int posi = 0;
    node *temp = h;
    while (posi < pos - 1 and temp->next != NULL)
    {
        posi++;
        temp = temp->next;
    }
    node *newN = new node(val);
    newN->next = temp->next;
    temp->next = newN;
}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
}
bool detect(node *head)
{
    node *turtle = head, *hare = head;
    while (hare->next != NULL and hare->next->next != NULL)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        if (hare == turtle)
        {
            return true;
        }
    }
    return false;
}
void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startOfCycle = NULL;
    int posi = 0;
    while (temp->next != NULL)
    {
        if (posi == pos - 1)
        {
            startOfCycle = temp;
        }
        temp = temp->next;
        posi++;
    }
    temp->next = startOfCycle;
}
void removeCycle(node *&head)
{
    if (detect(head) == false)
    {
        return;
    }
    node *slow = head, *fast = head, *past = NULL;
    do
    {
        past = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != fast);
    if(fast == head)
    {
        past->next = NULL;
        return;
    }
    fast = head;
    while(true)
    {
        if(slow->next == fast->next || slow->next == fast)
        {
            slow->next = NULL;
            return;
        }
        slow = slow->next;
        fast = fast->next;
    }
}
int main()
{
    node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    display(head);
    makeCycle(head, 1);
    cout << detect(head) << endl;
    removeCycle(head);
    cout << detect(head) << endl;
    display(head);
}