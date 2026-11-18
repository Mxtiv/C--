// ======================================================================
// task text + abstract Animal with 3 subclasses on the heap
// Original file: unsorted/sprawdzian/virtuals.cpp
// ======================================================================

// Zadanie 1: Zwierzeta
// Napisz program, w ktorym:
// - istnieje abstrakcyjna klasa Animal z czysto wirtualna metoda makeSound(),
// - klasy pochodne, takie jak Dog i Cat, implementuja te metode,
// - utworz dynamicznie obiekty zwierzat,
// - wywolaj metode makeSound() dla kazdego zwierzecia.
// Przykladowy wynik:
// Hau!
// Miau!
// (nazwy klas po angielsku, bo tak podaje tresc zadania)

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void makeSound() = 0;   // czysto wirtualna -> Animal jest abstrakcyjna

    // potrzebny, bo usuwamy obiekty przez Animal* (wiecej w ../05_)
    virtual ~Animal()
    {
    }
};

class Dog : public Animal
{
private:
    string glos;

public:
    Dog(string nowyGlos)
    {
        glos = nowyGlos;
    }

    void makeSound()
    {
        cout << glos << endl;
    }
};

class Cat : public Animal
{
private:
    string glos;

public:
    Cat(string nowyGlos)
    {
        glos = nowyGlos;
    }

    void makeSound()
    {
        cout << glos << endl;
    }
};

class Parrot : public Animal
{
private:
    string glos;

public:
    Parrot(string nowyGlos)
    {
        glos = nowyGlos;
    }

    void makeSound()
    {
        cout << glos << endl;
    }
};

int main()
{
    Animal *zwierze;

    // "dynamicznie" = przez new (obiekt na stercie)
    zwierze = new Dog("Hau!");
    zwierze->makeSound();
    delete zwierze;

    zwierze = new Cat("Miau!");
    zwierze->makeSound();
    delete zwierze;

    zwierze = new Parrot("Daj ciastko!");
    zwierze->makeSound();
    delete zwierze;
    return 0;
}
