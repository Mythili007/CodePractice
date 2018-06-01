#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *getNewNode(int data)
{
    struct Node *temp = (Node *)(malloc(sizeof(Node)));
    temp->data = data;
    temp->next = NULL;
    return temp;
};
int main()
{
    int n, num;
    cin >> n;
    struct Node *temp, *temp1, *temp2, *temp3, *temp4;
    struct Node *head = NULL;
    temp = head;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (temp == NULL)
        {
            temp = getNewNode(num);
            head = temp;
        }
        else
        {
            temp->next = getNewNode(num);
            temp = temp->next;
        }
    }
    // struct Node *temp1;
    // temp1 = head;
    // while (temp1 != NULL)
    // {
    //     cout << temp1->next << " " << endl;
    //     head = temp1->next;
    //     head->next = NULL;
    //     cout << head << " " << endl;
    // }

    temp1 = temp;
    temp2 = temp->next;
    while (temp1 != NULL)
    {
        cout << "temp1: temp" << temp1 << endl;
        cout << "temp2: temp->next" << temp2 << endl;
    }
    // struct Node *freeThis;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << temp1->data << " ";
    //     freeThis = temp1;
    //     temp1 = temp1->next;
    //     free(freeThis);
    // }
    return 0;
}
