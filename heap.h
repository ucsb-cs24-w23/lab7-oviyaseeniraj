// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element 
    int top();
    bool empty();
    
 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
    void percolateDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int min = index;
        if (left < vdata.size() && vdata[left] < vdata[min]) {
            min = left;
        }
        if (right < vdata.size() && vdata[right] < vdata[min]) {
            min = right;
        }
        if (min != index) {
            int temp = vdata[index];
            vdata[index] = vdata[min];
            vdata[min] = temp;
            percolateDown(min);
        }
    }
    void percolateUp(int index)
    {
      while (index > 0) {
            int parent = (index - 1) / 2;
            if (vdata[index] < vdata[parent]) {
                int temp = vdata[index];
                vdata[index] = vdata[parent];
                vdata[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }
};

#endif