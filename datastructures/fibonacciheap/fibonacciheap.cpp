#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int key;
  int rank;
  Node *parent;
  Node *left;
  Node *right;
  vector <Node> children;
};
