//It shifts last k nodes to start

#include "LL.h"
using namespace std;
void AppendAtEnd(node* &head, int k)
{
    node* temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count ++;
    }
    node* end = temp;
    temp = head;
    for (int i = 0; i < count - k; i ++)
    {
        temp = temp->next;
    }
    node* store = temp->next;
    temp->next = NULL;
    end->next = head;
    head = store;
    return;
}   
int main()
{
    node * head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    AppendAtEnd(head,2);
    display(head);
}