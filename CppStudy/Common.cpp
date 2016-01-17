#include "Common.h"

using std::vector;

namespace test {

void testLambda() {
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }

    int x = 0, y = 0;
    auto reset = [&]() {x = 0; y = 0; };
    auto print = [&](const char* description) { printf("x=%d\ty=%d\t(%s)\n", x, y, description); };

    reset();
    for_each(begin(v), end(v), [&](int n) { x += n; y += n; });
    print("All captured by reference");

    reset();
    for_each(begin(v), end(v), [=](int n) mutable { x += n; y += n; });
    print("All captured by value");

    reset();
    for_each(begin(v), end(v), [=, &x](int n) mutable { x += n; y += n; });
    print("All except x captured by value");

    reset();
    for_each(begin(v), end(v), [&, x](int n) mutable { x += n; y += n; });
    print("All except x captured by reference");
}

}