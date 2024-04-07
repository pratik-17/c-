#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    char gender;
};

int main() {
    Person person1;

    person1.name = "PK";
    person1.age = 21;
    person1.gender = 'M';

    cout << "Name: " << person1.name << std::endl;
    cout << "Age: " << person1.age << std::endl;
    cout << "Gender: " << person1.gender << std::endl;

    return 0;
}
