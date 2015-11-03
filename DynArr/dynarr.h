#ifndef DYNARR_H
#define DYNARR_H
#include <iostream>
using namespace std;

class dynArr
{
    private:
        int *data;
        int size;

    public:
       dynArr();
       dynArr(int s);
       ~dynArr();
       void set(int index, int value);
       int get(int index);
};

#endif // DYNARR_H