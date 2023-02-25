#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(node *&head, int val, int pos = -1)
{
    node *newN = new node(val);
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = newN;
            return;
        }
        newN->next = head;
        head = newN;
        return;
    }
    if (pos == -1)
    {
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
        return;
    }
    node *temp = head;
    int posi = 0;
    while (posi != (pos - 1))
    {
        temp = temp->next;
        posi++;
    }
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
    cout << "NULL" << endl;
}
void reverse(node *&head)
{
    node *prev = NULL, *cur = head, *nex = head->next;
    while (cur != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = nex;
        nex = nex != NULL ? nex->next : NULL;
    }
    head = prev;
}
node *reverseRecursive(node *&head)
{
    if (head->next == NULL or head == NULL)
         return head;
    node *nexthead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return nexthead;
}
node *reverseKNodes(node *&head, int k)
{
    node *prev = NULL, *cur = head, *nex;
    int count = 0;
    while (count < k and cur != NULL)
    {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
        count++;
    }
    if (cur != NULL)
    {
        head->next = reverseKNodes(cur, k);
    }
    return prev;
}
int main()
{
    node *head = NULL;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);

    display(head);
    // reverse(head);
    // display(head);
    // head = reverseRecursive(head);
    // display(head);
    head = reverseKNodes(head, 2);
    display(head);
}