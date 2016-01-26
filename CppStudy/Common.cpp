/**
 * Implmentation of some testing functions
 */

#include "Common.h"
#include "Log.h"

namespace test {

void testStringstream() {
    FuncTrace();
    const int LENGTH_PER_LINE = 8;
    ostringstream os;
    os << "Data start:" << endl;
    os.precision(5);
    os.setf(std::ios::fixed);

    for (int i = 0; i < LENGTH_PER_LINE * 20; i++) {
        os << std::setw(10) << 1.1 * i << "  ";
        if (i % LENGTH_PER_LINE == LENGTH_PER_LINE - 1) {
            os << endl;
        }
    }
    cout << os.str() << endl;
    const string& tmp = os.str();
    std::ofstream outfile("result.txt", std::ofstream::binary);
    outfile << tmp;
    outfile.flush();
    outfile.close();
}

void testConstructor() {
    FuncTrace();
    ConstructorTest first("First");
    ConstructorTest second(first);
    second = first;
    second = ConstructorTest("Tmp1");
    cout << "Now test move constructor" << endl;
    ConstructorTest third(ConstructorTest("Tmp2"));
    third.setName("Third");
    third.printName();
}

void testSmartPointer() {
    FuncTrace();

    Person solid = Person("Solid", 20);
    shared_ptr<Person> sp = make_shared<Person>("Bob", 10);
    {
        shared_ptr<Person> sp_inside(new Person("Eric", 30));
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

} // end of namespace test
