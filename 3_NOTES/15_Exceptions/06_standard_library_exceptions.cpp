// ======================================================================
// ADDED (gap-fill): exceptions thrown BY THE STANDARD LIBRARY and how to catch them -
// stoi (invalid_argument, out_of_range), vector::at / string::at (out_of_range),
// new (bad_alloc), catch order, rethrow, function that validates and throws
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <stdexcept>   // invalid_argument, out_of_range, runtime_error, logic_error
#include <string>
#include <vector>
#include <new>         // bad_alloc
using namespace std;

double safeDivide(double a, double b)
{
    if (b == 0) throw runtime_error("division by zero");
    return a / b;
}

int parseAge(const string &text)
{
    int age = stoi(text);                         // may throw invalid_argument / out_of_range
    if (age < 0 || age > 130) throw out_of_range("age must be 0-130");
    return age;
}

int main()
{
    // ---------------- stoi ----------------
    string inputs[] = {"25", "abc", "99999999999", "-4"};
    for (const string &s : inputs)
    {
        try
        {
            int age = parseAge(s);                       // if this throws, the next line is skipped
            cout << "parseAge(\"" << s << "\") = " << age << endl;
        }
        catch (const invalid_argument &e) { cout << s << ": not a number (" << e.what() << ")" << endl; }
        catch (const out_of_range &e)     { cout << s << ": out of range (" << e.what() << ")" << endl; }
    }

    // ---------------- .at() checks bounds, [] does NOT ----------------
    vector<int> v = {1, 2, 3};
    try
    {
        cout << v.at(10) << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "vector.at(10): " << e.what() << endl;
    }

    // ---------------- catch ORDER: specific first, general last ----------------
    try
    {
        safeDivide(1, 0);
    }
    catch (const runtime_error &e) { cout << "runtime_error: " << e.what() << endl; }
    catch (const exception &e)     { cout << "any std exception: " << e.what() << endl; }
    catch (...)                    { cout << "anything else" << endl; }

    // ---------------- bad_alloc: not enough memory for new ----------------
    try
    {
        long long huge = 1LL << 62;
        int *p = new int[huge];
        delete[] p;
    }
    catch (const bad_alloc &e)
    {
        cout << "bad_alloc: " << e.what() << endl;
    }
    catch (const exception &e)        // some compilers throw bad_array_new_length (also an exception)
    {
        cout << "allocation failed: " << e.what() << endl;
    }

    // ---------------- rethrow: handle partly, pass it up ----------------
    try
    {
        try
        {
            throw logic_error("inner problem");
        }
        catch (const exception &e)
        {
            cout << "inner catch logs: " << e.what() << endl;
            throw;                     // rethrow the SAME exception
        }
    }
    catch (const logic_error &e)
    {
        cout << "outer catch got: " << e.what() << endl;
    }

    return 0;
}
