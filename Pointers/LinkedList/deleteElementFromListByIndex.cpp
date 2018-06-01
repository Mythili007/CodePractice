#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *nextAddr;
};

struct Node *getNewNodeElement(int data)
{
    struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->data = data;
    temp->nextAddr = NULL;
    return temp;
}
int main()
{
    int size, input, numToDel;
    cin >> size;
    struct Node *head = NULL;
    struct Node *temp;
    temp = head;
    //user input array of elements
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        cout << "temp before: " << temp << endl;
        if (temp == NULL)
        {
            temp = getNewNodeElement(input);
            head = temp;
        }
        else
        {
            temp->nextAddr = getNewNodeElement(input);
            temp = temp->nextAddr;
        }
    }
    struct Node *freeThis;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        freeThis = temp;
        temp = temp->nextAddr;
        free(freeThis);
    }

    // cin >> numToDel;
    //delete head element

    //delete tail element
    //delete middle element
    return 0;
}