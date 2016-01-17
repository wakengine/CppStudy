#pragma once

#include <stdio.h>

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

namespace test {
    void testLambda();
    void testSmartPointer();
}

class Person {
public:
    Person(const char* name, int age) : mName(name), mAge(age) {
        printf("Construct Person name:%s age:%d\n", mName.c_str(), mAge);
    }

    Person(const Person& p) {
        mName = p.mName;
        mAge = p.mAge;
        printf("Copy construct Person name:%s age:%d\n", mName.c_str(), mAge);
    }

    Person& operator = (const Person& p) {
        mName = p.mName;
        mAge = p.mAge;
        printf("Assignment Person name:%s age:%d\n", mName.c_str(), mAge);
        return *this;
    }

    ~Person() {
        printf("Destroy Person name:%s\n", mName.c_str());
    }
private:
    string mName;
    int mAge;
};