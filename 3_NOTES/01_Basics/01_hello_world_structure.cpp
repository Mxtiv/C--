// ======================================================================
// ADDED (gap-fill): structure of every C++ program
// Not from your original repo - written to fill a missing topic.
// Build & run:  g++ 01_hello_world_structure.cpp -o hello.exe   then   .\hello.exe
// ======================================================================

#include <iostream>   // 1) #include = "paste this library here". iostream gives cout / cin
#include <string>     //    string gives std::string

using namespace std;  // 2) lets you write cout instead of std::cout (fine for school/exam code)

// 3) Global constants / functions / classes go ABOVE main (or declare a prototype above main)
const string GREETING = "Hello, World!";

void sayHello()                 // a function that returns nothing (void)
{
    cout << GREETING << endl;   // endl = new line + flush ; "\n" = new line only (faster)
}

// 4) main() is where the program STARTS. It must return int.
int main()
{
    sayHello();

    // Statements end with ;   Blocks are in { }
    // Comments: // single line     /* multi
    //                                 line */

    cout << "Line 1\n";
    cout << "Value: " << 42 << ", text: " << "abc" << '\n';   // chain with <<

    return 0;   // 0 = "program ended OK". Any other number = error code.
}
