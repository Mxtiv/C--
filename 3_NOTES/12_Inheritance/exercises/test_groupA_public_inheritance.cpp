// ======================================================================
// test group A: public inheritance, protected field via derived getter/setter
// Original file: unsorted/various/heritageB.cpp
// FIXED: initializer list reordered to match the order the fields are declared in (removes -Wreorder)
// ======================================================================

#include <iostream>
using namespace std;

// Klasa bazowa dla Grupy A
class BaseA {
protected:
    int protectedProperty; // Właściwość chroniona

public:
    int publicProperty; // Właściwość publiczna

    // Konstruktor bezparametrowy
    BaseA() : protectedProperty(0), publicProperty(0) {}

    // Konstruktor parametryczny
    BaseA(int pubProp, int protProp) : protectedProperty(protProp), publicProperty(pubProp) {}
};

// Klasa pochodna dla Grupy A
class DerivedA : public BaseA {
public:
    // Konstruktor bezparametrowy
    DerivedA() : BaseA() {}

    // Konstruktor parametryczny
    DerivedA(int pubProp, int protProp) : BaseA(pubProp, protProp) {}

    // Getter dla chronionej właściwości
    int getProtectedFromDerived() const {
        return protectedProperty;
    }

    // Setter dla chronionej właściwości
    void setProtectedFromDerived(int value) {
        protectedProperty = value;
    }
};

int main() {
    // Obiekt utworzony za pomocą konstruktora parametrycznego
    DerivedA objA(10, 20);
    cout << "Public property: " << objA.publicProperty << "\n";
    cout << "Protected property (from derived): " << objA.getProtectedFromDerived() << "\n";

    objA.setProtectedFromDerived(30);
    cout << "Updated protected property (from derived): " << objA.getProtectedFromDerived() << "\n";

    // Obiekt utworzony za pomocą konstruktora bezparametrowego
    DerivedA objA2;
    cout << "Default public property: " << objA2.publicProperty << "\n";

    return 0;
}