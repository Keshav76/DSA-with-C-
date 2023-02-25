#include "LL.h"
using namespace std;
void connect(node *&head1, node *&head2, int pos) //It connects : head2 is connected to pos node of head1
{
    node *temp1 = head1;
    while (pos-- != 1 && temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    if (pos != 0)
    {
        return;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    return;
}
int checkConnection(node *h1, node *h2)
{
    int l1 = length(h1);
    int l2 = length(h2);
    node *tl, *ts;
    int d;
    if (l1 > l2)
    {
        tl = h1;
        ts = h2;
        d = l1 - l2;
    }
    else
    {
        tl = h2;
        ts = h1;
        d = l2 - l1;
    }
    while (d-- != 0)
    {
        tl = tl->next;
    }
    while (tl != NULL && ts != NULL)
    {
        if (tl == ts)
        {
            return tl->data;
        }
        tl = tl->next;
        ts = ts->next;
    }
    return -1;
}
void removeConnection(node *&h1, node *&h2)
{
    int con = checkConnection(h1, h2);
    node *t = h2;
    while (t != NULL)
    {
        if (t->next->data == con)
        {
            t->next = NULL;
            return;
        }
        else
        {
            t = t->next;
        }
    }
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 4);
    insert(head1, 5);
    insert(head1, 6);
    insert(head2, 9);
    insert(head2, 8);
    connect(head1, head2, 2);
    display(head1);
    display(head2);
    cout << checkConnection(head1, head2) << endl;
    removeConnection(head1, head2);
    display(head1);
    display(head2);
    cout << checkConnection(head1, head2) << endl;
}