#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a,b,c;
	cout << a << " " << b << " ";
	for(int i = 3; i <= n; i ++){
		c = a + b;
		cout << c << " "; 
		a = b;
		b = c;
	}
	
	return 0;
}

