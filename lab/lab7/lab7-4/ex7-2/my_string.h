// my_string.h
#include <iostream>
#include <cstring>

class string
{
private:
    char *p;

public:
    string(const char *s);
    string(const string &s);
    ~string() { if(p) {delete [] p; p = NULL;} }
    friend std::ostream& operator << (std::ostream&, const string &s);
    friend string operator + (const string &s, const string &t);
    bool operator <= (const string &s);
};

/*
    definition of class string.
*/

string::string(const char *s) {
    p = new char[strlen(s) + 1];
    strcpy(p, s);
}

string::string(const string &s) {
    p = new char[strlen(s.p) + 1];
    strcpy(p, s.p);
}

std::ostream& operator << (std::ostream& out, const string &s) {
    out << s.p; 
    return out;
}

string operator + (const string &s, const string &t) {
    char *p = new char[strlen(s.p) + strlen(t.p) + 1];
    strcpy(p, s.p);
    strcpy(p + strlen(s.p), t.p);
    return string(p);
}

bool string::operator <= (const string &s) {
    return strlen(p) <= strlen(s.p) ? true : false;
}
