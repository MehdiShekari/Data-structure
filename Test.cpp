//github.com/MehdiShekari
#include <iostream>
using namespace std;
class Test{
public :
	Test() {
	//	cout << "array Test class.\n";
	}
	int input() {
		int temp;
		cin >> temp;
		return temp;
	}
	void get_Array_Print(){
		cout << "Enter n : \n";
		int n = input();
		int* a = new int[n];
		for (int i = 0; i < n; i++) {
			cout << "Enter " << i << "\n";
			int t = input();
			a[i] = t;
		}
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = " << a[i] << "\n";
		}
	}
	void print_Array(int a[],int n) {
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = " << a[i] << "\n";
		}
	}
};

	
/*

*/
