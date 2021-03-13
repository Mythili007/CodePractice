#include"linkedListUtil.h"

int main() {
  int n;
  cin >> n;

  struct Node *temp, *head;

  head = inputList(n);
  printList(head);
  return 0;
}