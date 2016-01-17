// CppStudy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <algorithm>


using std::vector;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
    
	int x = 0;
	for_each(begin(v), end(v), [&x](int n) { printf("x:%d %d\n", x, n); x++; });

	printf("Hello World!  :%d\n", x);

    return 0;
}
