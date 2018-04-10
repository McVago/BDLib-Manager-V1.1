#ifndef INDEX_H
#define INDEX_H
#include "index.h"
#include <vector>
#include "list.h"

template<class T>
class Index
{
public:
    vector<T> array;
    int size;
    Index(){size = 0;}
    void Insert(T x);
    T get(int i);
    void empty(){if(size == 0)return true;else return false;}
};
template<class T>
void Index<T>::Insert(T x){
    size++;
    array.resize(size);
    array[size] = x;
    }
template<class T>
T Index<T>::get(int i){
    if(empty){throw "Empty Array";}
    else{return array[i];}
}
#endif // INDEX_H
