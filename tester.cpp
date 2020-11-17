#include<iostream>
struct Node {
int id;
Node *next;
};

int main() {
Node *current = NULL;

for (int i = 0; i < 5; i++) {
Node *_newNode = new Node;
_newNode->id = i;
_newNode->next = NULL;
current->next = _newNode;
}
return 0;
}