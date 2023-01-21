#include <iostream>
#include <conio.h>
#include <string>
#include "Test.cpp"
#include "Sort.cpp"
using namespace std;

int main()
{
	Sort s;
	Test t;
	int n = 10;
	int *a = new int[n]{58, 94, 25, 3, 7, 89, 0, 78, 63, 7};
	t.print_Array(a, 10);
	s.Merge_sort(a, 10);
	cout << "Print Mergesort : \n";
	t.print_Array(a, 10);
	return 0;
}