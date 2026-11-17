// ======================================================================
// include guard #ifndef / #define / #endif (this is the header 01_ includes)
// Original file: Preprocessing/compilationConditions.cpp
// FIXED: renamed from compilationConditions.cpp to myheader.h and added #include <iostream>
// ======================================================================

#ifndef MYHEADER_H
#define MYHEADER_H  // Prevent multiple inclusions of this header file

#include <iostream>  // a header must include what IT uses (std::cout)

void sayHello() {
    std::cout << "Hello!" << std::endl;
}

#endif  // End of MYHEADER_H
