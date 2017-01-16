#include <iostream>
#include <limits>
using namespace std;

const int inf = std::numeric_limits<int>::max();

void relax(int weight, int * dist, int src, int dest){
  if(weight + dist[src] < dist[dest]){
    dist[dest] = weight + dist[src];
  }
}

void dijk(int ** adj, int * dist, int src, int dest, int n){
  for(int i = 0; i < n; i++){
    dist[i] = inf;
    if(i == src){
      dist[i] = 0;
    }
  }
  for(int i = 0; i < n; i++){
    int min = inf;
    int current;
    for(int j = 0; j < n; j++){
      if(min > dist[j] && dist[j] > -1){
        min = dist[j];
        current = j;
      }
    }
    for(int j = 0; j < n; j++){
      if(adj[current][j] > -1 && dist[j] > -1){
        relax(adj[current][j], dist, current, j);
      }
    }
    cout << current << " " << dist[current] << endl;
    dist[current] = -1;
  }
}

int main(){
  int n;
  cin >> n;
  int ** adj;
  adj = new int *[n];
  for(int i = 0; i < n; i++){
    adj[i] = new int[n];
    for(int j = 0; j < n; j++){
      cin >> adj[i][j];
    }
  }
  int dist[n];
  int src;
  int dest;
  cin >> src >> dest;
  dijk(adj, dist, src, dest, n);
}
