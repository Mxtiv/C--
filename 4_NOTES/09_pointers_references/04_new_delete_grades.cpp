// ======================================================================
// 4 dynamically allocated doubles, read grades, average
// Original file: Pointers/dynamicDemo.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    // One pointer per grade, each gets its own memory with new
    double *polski = new double;
    double *matematyka = new double;
    double *angielski = new double;
    double *informatyka = new double;

    cout << "Enter grade for Polish: ";
    cin >> *polski;                 // cin writes straight into the memory the pointer points to
    cout << "Enter grade for Math: ";
    cin >> *matematyka;
    cout << "Enter grade for English: ";
    cin >> *angielski;
    cout << "Enter grade for Computer Science: ";
    cin >> *informatyka;

    double srednia = (*polski + *matematyka + *angielski + *informatyka) / 4;
    cout << "The average grade is: " << srednia << endl;

    delete polski;
    delete matematyka;
    delete angielski;
    delete informatyka;

    return 0;
}
