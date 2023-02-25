#include "LL.h"
using namespace std;
node *merge(node *a, node *b)
{
    node head(1);
    node *temp = &head;
    while (b != NULL && a != NULL)
    {
        if (a->data > b->data)
        {
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
        else
        {
            temp->next = a;
            temp = temp->next;
            a = a->next;
        }
    }
    while (a != NULL)
    {
        temp->next = a;
        temp = temp->next;
        a = a->next;
    }
    while (b != NULL)
    {
        temp->next = b;
        temp = temp->next;
        b = b->next;
    }
    return head.next;
}
node *recursiveMerge(node *a, node *b)
{
    node *result = NULL;
    if (a == NULL && b == NULL)
    {
        return NULL;
    }
    else if (a == NULL)
    {
        result = b;
    }
    else if (b == NULL)
    {
        result = a;
    }
    else if (a->data > b->data)
    {
        result = b;
        result->next = recursiveMerge(a, b->next);
    }
    else
    {
        result = a;
        result->next = recursiveMerge(a->next, b);
    }
    return result;
}
int main()
{
    node *h1 = NULL;
    node *h2 = NULL;
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        insert(h1, a);
    }
    for (int i = 0; i < 3; i++)
    {
        int a;
        cin >> a;
        insert(h2, a);
    }
    // display(h1);
    // display(h2);
    node *newHead = recursiveMerge(h1, h2);
    display(newHead);
}