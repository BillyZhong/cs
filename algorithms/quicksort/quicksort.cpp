#include <iostream>
using namespace std;

int p(int* a, int l, int h){
  int t = 0;
	int v = a[h];
	int i = l - 1;
	int j = l;
	for(j = l; j < h; j++){
		if(a[j] <= v){
			i = i + 1;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	i = i + 1;
	t = a[i];
	a[i] = a[h];
	a[h] = t;
	return i;
}

void q(int* a, int l, int h){
	if(l < h){
		int v = p(a, l, h);
		q(a, l, v - 1);
		q(a, v + 1, h);
	}
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
	q(a, 0, n-1);
	for(int i = 0; i < n; i++){
		cout << a[i] << ", ";
	}
	cout << endl;
}
