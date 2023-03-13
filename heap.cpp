// heap.cpp
// Diba Mirza
// Oviya Seeniraj 3/10/23

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int index = vdata.size() - 1;
  Heap::percolateUp(index);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) // empty case
    return;
  vdata[0] = vdata.back(); // base for any length, 1 or more
  vdata.pop_back();
  if (!vdata.empty()) // > 1 node case
  {
    percolateDown(0);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty())
  {
    return -1;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.size() == 0;
}
    