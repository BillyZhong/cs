#include <iostream>
using namespace std;

void bs(int* a, int k, int l, int h){
  int m = (l+h)/2;
  if(a[m] == k){
    cout << m << endl;
  }
  else if(a[m] < k){
    bs(a, k, m+1, h);
  }
  else if(a[m] > k){
    bs(a, k, l, m-1);
  }
}

int main(){
  int n;
  int k;
  cin >> n >> k;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
	bs(a, k, 0, n-1);
}
