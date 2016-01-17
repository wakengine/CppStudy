#include "Common.h"
#include "Log.h"

namespace test {

void testSmartPointer() {
    FuncTrace();

    Person solid = Person("Solid", 20);
    shared_ptr<Person> sp = make_shared<Person>("Bob", 10);
    {
        shared_ptr<Person> sp(new Person("Eric", 30));
    }
    sp.reset(new Person("New and managed by sp", 40));

    Person* p = new Person("New and reset", 40);
    sp.reset(p);
    sp = nullptr;

    unique_ptr<Person> up;
    up.reset(new Person("Unique Pointer", 40));
}

void testLambda() {
    FuncTrace();

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