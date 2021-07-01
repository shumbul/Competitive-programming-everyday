// Link - https://www.javatpoint.com/cpp-this-pointer
// Author - Shumbul Arifa

#include <iostream>
using namespace std;
class Employee {
public:
    int id; //data member (also instance variable)
    string name; //data member(also instance variable)
    float salary;
    Employee(int i, string n, float s)
    {
        // this->id = i;
        // this->name = n;
        // this->salary = s;
        // // OR
        id = i;
        name = n;
        salary = s;
    }
    void display()
    {
        cout << id << "  " << name << "  " << salary << endl;
    }
};
int main(void) {
    Employee e1 = Employee(101, "Sonoo", 890000); //creating an object of Employee
    Employee e2 = Employee(102, "Nakul", 59000); //creating an object of Employee
    e1.display();
    e2.display();
    e1.display();
    e2.display();
    return 0;
}