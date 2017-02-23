#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
  Node * parent;
  vector <Node*> children;
  int key;
  int rank;
};

struct Root {
  Root * left;
  Root * right;
  Node * current;
};

struct BinomialHeap {
  Root * min;
  int maxrank;
};

int findMin(BinomialHeap * heap){
  return (*(*(*heap).min).current).key;
}

void linkTrees(BinomialHeap * heap){
  Root * rankList[(*heap).maxrank+1];
  for(int i = 0; i < (*heap).maxrank+1; i++){
    rankList[i] = NULL;
  }
  Root * currentRoot = (*heap).min;
  while(rankList[(*(*currentRoot).current).rank] != currentRoot){
    if(rankList[(*(*currentRoot).current).rank] == NULL){
      rankList[(*(*currentRoot).current).rank] = currentRoot;
    }
    else{
      //Root * currentListRoot = rankList[(*(*currentRoot).current).rank];
      if((*(*rankList[(*(*currentRoot).current).rank]).current).key <= (*(*currentRoot).current).key){
        (*(*rankList[(*(*currentRoot).current).rank]).current).children.push_back((*currentRoot).current);
        (*(*currentRoot).current).parent = (*rankList[(*(*currentRoot).current).rank]).current;
        (*(*currentRoot).left).right = (*currentRoot).right;
        (*(*currentRoot).right).left = (*currentRoot).left;
        //remove root
        (*(*rankList[(*(*currentRoot).current).rank]).current).rank++;
        (*heap).maxrank = max((*heap).maxrank,(*(*rankList[(*(*currentRoot).current).rank]).current).rank);
        rankList[(*(*rankList[(*(*currentRoot).current).rank]).current).rank] = rankList[(*(*currentRoot).current).rank];
        rankList[(*(*rankList[(*(*currentRoot).current).rank]).current).rank-1] = NULL;
      }
      else{
        (*(*currentRoot).current).children.push_back((*rankList[(*(*currentRoot).current).rank]).current);
        (*(*rankList[(*(*currentRoot).current).rank]).current).parent = (*currentRoot).current;
        (*(*rankList[(*(*currentRoot).current).rank]).left).right = (*rankList[(*(*currentRoot).current).rank]).right;
        (*(*rankList[(*(*currentRoot).current).rank]).right).left = (*rankList[(*(*currentRoot).current).rank]).left;
        //remove root
        (*(*currentRoot).current).rank++;
        (*heap).maxrank = max((*heap).maxrank, (*(*currentRoot).current).rank);
        rankList[(*(*currentRoot).current).rank] = currentRoot;
        rankList[(*(*currentRoot).current).rank-1] = NULL;
      }
      currentRoot = (*currentRoot).right;
    }
  }
}

int deleteMin(){

}

void insertKey(){

}

void decreaseKey(){

}

BinomialHeap merge(){

}

void deleteKey(){

}

int main()
{

}
