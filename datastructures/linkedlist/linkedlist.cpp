#include <iostream>
using namespace std;

/**
struct DoublyLinkedNode{
  DoublyLinkedNode *next;
  DoublyLinkedNode *prev;
  int val;
}
**/

struct Node {
  Node *next;
  int val;
};

Node * accessbyindex(int index, Node * head){
  Node * temp = head;
  for(int i = 1; i < index; i++){
    temp = (*temp).next;
  }
  return temp;
}

Node * searchbyvalue(int query, Node * head){
  Node * temp = head;
  while((*temp).val != query){
    temp = (*temp).next;
  }
  return temp;
}

void insertnode(Node * prev, Node * n){
  (*n).next = (*prev).next;
  (*prev).next = n;
}

void deletenode(Node * prev, Node * n){
  (*prev).next = (*n).next;
  delete n;
}

int main(){
  Node * head = new Node{NULL, 0};
}
