#include <iostream>
using namespace std;

int p(int* a, int l, int h){
  for(int i = l; i < h; i++){
    
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
	p(a, k, 0, n);
	for(int i = 0; i < n; i++){
		cout << a[i] << ", ";
	}
	cout << endl;
}
