#include <bits/stdc++.h>

using namespace std;

class Animal{
    public:
    int age;
    int weight;
    string type;
    char* name;
    char* myName;

    // Default constructor
    Animal() {
        name = new char[100];
        myName = new char[100];  // Allocate memory for myName
    }

    // Copy constructor for deep copy
    Animal(const Animal &temp) {
        this->name = new char[100];     // Allocate memory and deep copy name
        strcpy(this->name, temp.name);

        this->myName = new char[100];   // Allocate memory and deep copy myName
        strcpy(this->myName, temp.myName);

        this->age = temp.age;           // Copy basic types
        this->weight = temp.weight;
        this->type = temp.type;
    }

    // Destructor to free dynamically allocated memory
    // ~Animal() {
    //     delete[] name;
    //     delete[] myName;
    // }

    void setName(char name[]) {
        strcpy(this->name, name);
    }

    void setMyName(char myName[]) {
        strcpy(this->myName, myName);
    }

    void print() {
        cout << "Animal name is " << this->myName << endl;
    }
};

int main() {
    Animal Dog;
    Dog.age = 10;
    Dog.weight = 20;
    Dog.type = "mammal";

    char name[6] = "Tiger";  // Set name for Dog
    Dog.setName(name);

    char myName[5] = "Hero";  // Set myName for Dog
    Dog.setMyName(myName);

    // Use copy constructor for deep copy
    Animal Cat(Dog);
    Cat.type = "nocturnal";  // Modify Cat's type

    Cat.name[0] = 'L';       // Modify Cat's name (this should not affect Dog)
    Cat.myName[0] = 'Z';     // Modify Cat's myName (this should not affect Dog)

    Cat.print();  // Cat's name should be "Zero"
    Dog.print();  // Dog's name should still be "Hero"

    return 0;
}
