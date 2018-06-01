#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

struct Node *pushIntoList(int data) {
  struct Node *temp = (struct Node *)(malloc(sizeof(struct Node)));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

struct Node *inputList(int n) {
  struct Node *head = NULL, *temp1;
  int num;
  temp1 = head;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (temp1 == NULL) {
      temp1 = pushIntoList(num); // pushing num into list
      head = temp1;
    } else {
      temp1->next = pushIntoList(num);
      temp1 = temp1->next;
    }
  }
  return head;
}

void printList(struct Node *head) {
  while (head != NULL) {
    cout << head->data;
    if (head->next != NULL) {
      cout << "->";
    }
    head = head->next;
  }
  cout << endl;
}