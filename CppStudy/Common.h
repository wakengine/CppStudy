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
    void testConstructor();
}

class ConstructorTest {
public:
    ConstructorTest(string name) : mName(name) {
        cout << "Constructor is called: " << mName << endl;
    }

    ~ConstructorTest() {
        cout << "Destructor is called: " << mName << endl;
    }

    ConstructorTest(const ConstructorTest& rhs) {
        mName = rhs.mName;
        cout << "Copy constructor is called: " << mName << endl;
    }

    ConstructorTest& operator = (const ConstructorTest & rhs) {
        mName = rhs.mName;
        cout << "Copy assignment operator is called: " << mName << endl;
        return *this;
    }

    ConstructorTest(ConstructorTest&& rhs) {
        mName = rhs.mName;
        cout << "Move constructor is called: " << mName << endl;
    }

    ConstructorTest& operator = (ConstructorTest && rhs) {
        mName = rhs.mName;
        cout << "Move assignment operator is called: " << mName << endl;
        return *this;
    }

    void setName(string name) {
        mName = name;
    }

    void printName() {
        cout << "Now my name is: " << mName << endl;
    }
private:
    string mName = "Unset";
};

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