// ex7-2.cpp
#include <iostream>
#include "my_string.h"

using std::cout;
using std::endl;

int main() {
    string t1("New");
    cout << "t1=" << t1 << endl;
    string t2 = "York";
    cout << "t2=" << t2 << endl;
    string t3 = t1 + " " + t2;
    cout << "t3=" << t3 << endl;

    if (t1 <= t3)
        cout << t1 << " is smaller than "  << t3 << endl;
    else
        cout << t1 << " is bigger than " << t3 << endl;

    return 0;
}
