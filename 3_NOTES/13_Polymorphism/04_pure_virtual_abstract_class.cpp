// ======================================================================
// pure virtual = 0, abstract class Animal, Dog/Cat on the heap
// Original file: Classes/spr/sprawdzianpolimorfia/main.cpp
// FIXED: added virtual ~Animal() (objects are deleted through a base pointer)
// ======================================================================

#include <iostream>
using namespace std;


class Animal
{
    public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}   // always give a polymorphic base class a virtual destructor
};


class Dog : public Animal
{
    public:

    void makeSound()
    {
        cout << "Hau! - Dog\n";
    }
};


class Cat : public Animal
{
    public:

    void makeSound()
    {
        cout << "Miau! - Cat\n";
    }
};

int main()
{
    Animal *zwierze;

    zwierze = new Dog;
    zwierze -> makeSound();
    delete zwierze;

    zwierze = new Cat;
    zwierze -> makeSound();
    delete zwierze;
    return 1;
}