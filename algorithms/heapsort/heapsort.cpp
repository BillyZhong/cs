#include <iostream>
using namespace std;

void h(int* a, int i, int n){
    if(i < n/2){
        if(2*i+2 == n){
          if(a[2*i+1] > a[i]){
            int s = a[i];
            a[i] = a[2*i+1];
            a[2*i+1] = s;
            h(a, 2*i+1, n);
          }
        }
        else{
          if(a[2*i+1] > a[i] || a[2*i+2] > a[i]){
            int t = 0;
            if(a[2*i+1] >= a[2*i+2]){
                t = 2*i+1;
            }
            else{
                t = 2*i + 2;
            }
            int s = a[i];
            a[i] = a[t];
            a[t] = s;
            h(a, t, n);
        }
      }
  }
}

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
      cin >> a[i];
  }
	for(int i = n/2-1; i >= 0; i--){
	    h(a, i, n);
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
