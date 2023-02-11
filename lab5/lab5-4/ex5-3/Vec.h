// Vec.h
#ifndef VEC_H
#define VEC_H

class Vec
{
private:
    int* array;
    int dim;

public:
    Vec();
    Vec(int*, int);
    Vec(const Vec&);
    Vec(Vec&&);
    ~Vec();
    Vec& operator=(const Vec&);
    Vec& operator=(Vec&&);
    void assign(int*, int);
    void sort();
    void printVec();
    bool isEqual(Vec&);
    void unionSet(Vec&, Vec&);
    int min();
    int max();
    bool find(int);
    Vec independentSet();
};

#endif
