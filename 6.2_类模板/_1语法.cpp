#include <iostream>
#include <string>

template <class NameType, class AgeType>
class Person {
   public:
    Person(NameType name, AgeType age) {
        this->age = age;
        this->name = name;
    }
    void showPerson() {
        std::cout << this->name << " " << this->age << std::endl;
    }

   private:
    int age;
    std::string name;
};

void test() {
    // 模板的好处在于 类型参数化  <> 内初始化参数的类型， （）初始化参数的内容
    Person<std::string, int> p("nihao", 16);
    p.showPerson();
}
int main() {
    std::cout << "Nihao" << std::endl;
    test();
    return 0;
}