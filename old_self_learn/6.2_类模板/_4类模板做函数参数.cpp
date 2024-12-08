#include <iostream>
#include <string>
#include <typeinfo>
// 类模板
template <class NameType = std::string, class AgeType = int>
class Person {
   public:
    Person(NameType name, AgeType age) {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson() {
        std::cout << "name: " << this->mName << " age: " << this->mAge
                  << std::endl;
    }

   public:
    NameType mName;
    AgeType mAge;
};

// 1 直接传入具体的类型
void printPerson1(Person<std::string, int>& p) {
    p.showPerson();
}

void test1() {
    Person<std::string, int> p1("xxx", 18);
    printPerson1(p1);
}

// 2 参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2>& p) {
    p.showPerson();
}

void test2() {
    Person<std::string, int> p2("xxxx", 19);
    printPerson2(p2);
}

// 3 整个类 模板化
template <class T>
void printPerson3(T& p) {
    std::cout << "its type is " << typeid(p).name() << std::endl;
    p.showPerson();
}

void test3() {
    Person<std::string, int> p3("xxxxx", 20);
    printPerson3(p3);
}
int main() {
    // test1();
    // test2();
    test3();
    return 0;
}