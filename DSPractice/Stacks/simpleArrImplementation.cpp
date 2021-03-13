#include <bits/stdc++.h>
using namespace std;

struct ArrayStack {
  int top;
  int capacity;
  int *array;
};

int isEmptyStack(struct ArrayStack *s) { return (s->top == -1); }

int isFullStack(struct ArrayStack *s) { return (s->top == s->capacity - 1); }

void push(struct ArrayStack *s, int data) {
  if (isFullStack(s))
    cout << "Stack Overflow" << endl;
  else
    /* increasing the top by 1 and storing the value at the top position*/
    s->array[++s->top] = data;
}

int pop(struct ArrayStack *s) {
  if (isEmptyStack(s))
    cout << "Stack is empty" << endl;
  else
    return s->array[s->top--];
}

void deleteStack(struct ArrayStack *s) {
  if (s) {
    if (s->array)
      free(s->array);
    free(s);
  }
}

struct ArrayStack *createStack() {
  struct ArrayStack *s = malloc(sizeof(struct ArrayStack));
  if (!s)
    return NULL;
  s->top = -1;
  s->capacity = 1;
  s->array = malloc(s->capacity * sizeof(int));
  if (!s->array)
    return NULL;
  return s;
}

int main() {
  push(createStack(), 20);
//   cout << "stack: " << push(createStack(), 30) << endl;
  return 0;
}