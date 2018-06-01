#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *nextAddress;
};
int main()
{

    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node)); //malloc gives void pointer - casting
    head->data = 0;
    head->nextAddress = NULL;

    head->data = 10;

    struct Node *head1;
    head1 = (struct Node *)malloc(sizeof(struct Node)); //malloc gives void pointer - casting
    head1->data = 0;//why did we initialize with 0?
    head1->nextAddress = NULL;

    head1->data = 20;

    struct Node *head2;
    head2 = (struct Node *)malloc(sizeof(struct Node)); //malloc gives void pointer - casting
    head2->data = 0;
    head2->nextAddress = NULL;

    head2->data = 30;

    head->nextAddress = head1;
    head1->nextAddress = head2;

    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " was at location " << temp << endl;
        temp = temp->nextAddress;
    }

    free(head);
    free(head1);
    free(head2);
    return 0;
}