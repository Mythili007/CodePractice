#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *nextAddress;
};
struct Node *getNewNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->nextAddress = NULL;
    return temp;
}

struct Node *insertingValues(int num, int size)
{
    struct Node head = NULL, *temp;
    temp = head;
    for (int i = 0; i < size; i++)
    {
        // num = rand();
        cin >> num;
        if (temp == NULL)
        {
            // cout << "getNewNode(num)1 : " << getNewNode(num) << endl;
            temp = getNewNode(num); //stored the addr of the first variable in the list
            // cout << "temp: " << temp << endl;
            head = temp;
            // cout << "head: " << head << endl;
        }
        else
        {
            // cout << "getNewNode(num) : " << getNewNode(num) << endl;
            temp->nextAddress = getNewNode(num);
            // cout << "temp->nextAddress: " << temp->nextAddress << endl;
            temp = temp->nextAddress;
            // cout << "temp: " << temp << endl;
        }
    }
}

void printList(struct Node *head)
{
    struct Node *freeThis, *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " was at location " << temp << endl;
        // freeThis = temp;
        temp = temp->nextAddress;
        // free(freeThis);
    }
}
int main()
{
    int n, num;
    cin >> n;
    struct Node *head = NULL;
    insertingValues(num, n);
    printList(head);

    return 0;
}