#include <iostream>
using namespace std;

void ms(int* a, int* b, int l, int m, int h, int n){
  copy(b, b+n, a);
  int i = l;
  int j = m+1;
  for(int k = l; k < h+1; k++){
    if(i > m){
      b[k] = a[j];
      j++;
    }
    else if(j > h){
      b[k] = a[i];
      i++;
    }
    else if(a[i] <= a[j]){
      b[k] = a[i];
      i++;
    }
    else if(a[j] < a[i]){
      b[k] = a[j];
      j++;
    }
  }
}

void s(int* a, int* b, int l, int h, int n){
  if(l < h){
    int m = (l+h)/2;
    s(a, b, l, m, n);
    s(a, b, m+1, h, n);
    ms(a, b, l, m, h, n);
  }
}

int main(){
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  copy(a, a+n, b);
	s(a, b, 0, n-1, n);
	for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	cout << endl;
}
