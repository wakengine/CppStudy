// CppStudy.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;

int main()
{
    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
    }

    int x = 1, y = 1;
    auto print = [&](const char* description) { printf("%s:\t x=%d\ty=%d\n", description, x, y); };
    print("Before Lambda");
    for_each(begin(v), end(v), [&](int n) { x += n; y *= n; });
    print("After Lambda");

    return 0;
}
