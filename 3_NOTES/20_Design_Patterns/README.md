# 20_Design_Patterns - Design patterns - Singleton

[⬅ notes index](../README.md) · [main index](../../README.md)

Singleton = a class that can have only ONE object: a private constructor, a `static` pointer to the single instance, and a `static getInstance()` that creates it on the first call and returns the same object every time after that.

```cpp
class Singleton
{
private:
    static Singleton *instancja;
    Singleton()                         // prywatny - "Singleton s;" sie nie skompiluje
    {
    }
public:
    static Singleton *getInstance()
    {
        if (instancja == NULL)
        {
            instancja = new Singleton();
        }
        return instancja;
    }
};
Singleton *Singleton::instancja = NULL;   // definicja pola static poza klasa
```

## Files

| File | What it shows | |
|---|---|---|
| [01_singleton_minimal.cpp](01_singleton_minimal.cpp) | minimal singleton: private ctor, static instance pointer, getInstance() | ⭐ |
| [02_singleton_with_value.cpp](02_singleton_with_value.cpp) | singleton that stores a value; the second getInstance("Drugi") still returns the first object |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
