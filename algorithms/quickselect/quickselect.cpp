#include <iostream>
using namespace std;

int p(int* a, int l, int h){
  int t = 0;
	int v = a[h];
  int i = l;
	for(int j = l; j < h; j++){
		if(a[j] <= v){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
      i++;
		}
	}
	t = a[i];
	a[i] = a[h];
	a[h] = t;
	return i;
}

void q(int* a, int k, int l, int h){
  int v = p(a, l, h);
  if(k < v){
    q(a, k, l, v-1);
  }
  else if(k == v){
    cout << a[v] << endl;
  }
  else{
    q(a, k, v+1, h);
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
	q(a, k-1, 0, n-1);
}
