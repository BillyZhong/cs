#include <iostream>
using namespace std;

struct Node{
  int val;
  int height;
  Node *left;
  Node *right;
}

void updateheight(Node * node){
  int leftheight = -1;
  int rightheight = -1;
  if((*node).left != NULL){
    leftheight = (*(*node).left).height;
  }
  if((*node).right != NULL){
    rightheight = (*(*node).right).height;
  }
  (*node).height = max(leftheight, rightheight) + 1;
}

void rotateleft(Node * parent, Node * child){
  int tempval = (*parent).val;
  (*parent).val = (*child).val;
  (*child).val = tempval;
  (*parent).right = (*child).right;
  (*child).right = (*child).left;
  (*child).left = (*parent).left;
  (*parent).left = child;
  updateheight(child);
  updateheight(parent);
}

void rotateright(Node * parent, Node * child){
  int tempval = (*parent).val;
  (*parent).val = (*child).val;
  (*child).val = tempval;
  (*parent).left = (*child).left;
  (*child).left = (*child).right;
  (*child).right = (*parent).right;
  (*parent).right = child;
  updateheight(child);
  updateheight(parent);
}

void insert(Node * newnode, Node * currentnode){
  if((*newnode).val < (*currentnode).val){
    if((*currentnode).left == NULL){
      (*currentnode).left = newnode;
    }
    else{
      insert(newnode, (*currentnode).left);
    }
  }
  else{
    if((*currentnode).right == NULL){
      (*currentnode).right = newnode;
    }
    else{
      insert(newnode, (*currentnode).right);
    }
  }
  int leftheight = -1;
  int rightheight = -1;
  int leftleftheight = -1;
  int leftrightheight = -1;
  int rightleftheight = -1;
  int rightrightheight = -1;
  if((*currentnode).left != NULL){
    leftheight = (*(*currentnode).left).height;
    if((*(*currentnode).left).left != NULL){
      leftleftheight = (*(*(*currentnode).left).left).height;
    }
    if((*(*currentnode).left).right != NULL){
      leftrightheight = (*(*(*currentnode).left).right).height;
    }
  }
  if((*currentnode).right != NULL){
    rightheight = (*(*currentnode).right).height;
    if((*(*currentnode).right).left != NULL){
      rightleftheight = (*(*(*currentnode).right).left).height;
    }
    if((*(*currentnode).right).right != NULL){
      rightrightheight = (*(*(*currentnode).right).right).height;
    }
  }
  if(abs(leftheight - rightheight) > 1){
    if(leftheight > rightheight){
      if(leftleftheight > leftrightheight){
        rotateright(currentnode, (*currentnode).left);
      }
      else{
        rotateleft((*currentnode).left, (*(*currentnode).left).right);
        rotateright(currentnode, (*(*currentnode).left).right);
      }
    }
    else{
      if(rightrightheight > rightleftheight){
        rotateleft(currentnode, (*currentnode).right);
      }
      else{
        rotateright((*currentnode).right, (*(*currentnode).right).left);
        rotateleft(currentnode, (*(*currentnode).right).left);
      }
    }
  }
  else{
    updateheight(currentnode);
  }
}

int main(){
  Node * root = new Node{0, 0, NULL, NULL};
}
