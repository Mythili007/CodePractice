#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *getNewNode(int data)
{
    struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
    temp->data = data;
    temp->next = NULL;
    return temp;
};
int main()
{
    int n, num, data, pos;
    cin >> n;
    struct Node *head = NULL, *temp;
    temp = head;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (temp == NULL)
        {
            temp = getNewNode(num);
            temp = head;
        }
        else
        {
            temp->next = getNewNode(num);
            temp = temp->next;
        }
    }
    cin >> data >> pos;
    struct Node *newNode = (struct node *)(malloc(sizeof(struct Node)));
    newNode->data = data;
    if (head == NULL)
    {
        return newNode;
    }
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }
    struct Node *currentNode = head;
    while (pos - 1 > 0)
    {
        currentNode = currentNode->next;
        pos--;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    return 0;
}