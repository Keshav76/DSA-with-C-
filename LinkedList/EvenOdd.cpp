#include "LL.h"
using namespace std;
node *oddEvenList(node *head)
{
    node *temp = head;         //For iteration
    node *end = NULL;          //For Storing End
    while (temp->next != NULL) //Finding end of LL
    {
        temp = temp->next;
    }
    end = temp;
    node *fin = end;
    temp = head;
    while (temp != fin)
    {
        node *a = temp->next;

        temp->next = temp->next->next;
        end->next = a;
        end = end->next;
        if (a == fin)
            break;
        temp = temp->next;
    }
    end->next = NULL;
    return head;
}
int main()
{
    node *head = new node(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    display(head);
    head = oddEvenList(head);
    display(head);
}