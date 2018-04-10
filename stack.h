#ifndef STACK_H
#define STACK_H

template <class T, int N>
class STACK{
private:
  const int MaxStack = N;
  int top;
  T values[N];
public:
  STACK();
  bool empty();
  bool full();
  void push(T x);
  T pop();
  T getTop();
};

template<class T, int N>
STACK<T,N>::STACK(){top = -1;}

template<class T, int N>
bool STACK<T,N>::empty(){return top == -1;}

template<class T, int N>
bool STACK<T,N>::full(){return top == (MaxStack - 1);}

template<class T, int N>
void STACK<T,N>::push(T x){
  if (full()){
    throw "Stack Full";
  }
  else{
    top++;
    values[top] = x;
  }
}
template<class T, int N>
T STACK<T,N>::pop(){
  if(empty())throw "Empty Stack";
  else{
    T p = values[top];
    top--;
    return p;
  }
}
template<class T, int N>
T STACK<T,N>::getTop(){
  if(empty())throw "Empty Stack";
  else return values[top];
}

#endif // STACK_H
