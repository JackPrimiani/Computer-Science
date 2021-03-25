/*
Copyright 2018
Author: Jack Primiani
October 2nd, 2018
*/
#include "max_heap.h"  //NOLINT
#include <iostream>
using std::cout;
using std::endl;

void Add(int item, int heap[], int count) {
  bool loop = true;
  int parent = 0, index = count, temp;
  heap[index] = item;
  while (loop && index > 0) {
    if (index%2 == 0) {
      parent = (index-2)/2;
    } else if (index%2 == 1) {
      parent = (index-1)/2;
    }

    if (heap[parent] < heap[index]) {
      temp = heap[parent];
      heap[parent] = heap[index];
      heap[index] = temp;
      index = parent;
    } else {
      loop = false;
    }
  }
}

int Remove(int heap[], int count) {
  bool loop = true;
  int n = 0, temp, ret = heap[0];
  heap[0] = heap[count-1];
  heap[count] = -1;
  while (loop) {
    if (heap[n] < (heap[(2*n)+1]) && heap[(2*n)+1] > heap[(2*n)+2]) {
      temp = heap[(2*n)+1];
      heap[(2*n)+1] = heap[n];
      heap[n] = temp;
      n = (2*n)+1;
    } else if (heap[n] < (heap[(2*n)+2]) && heap[(2*n)+1] < heap[(2*n)+2]) {
      temp = heap[(2*n)+2];
      heap[(2*n)+2] = heap[n];
      heap[n] = temp;
      n = (2*n)+2;
    } else {
      loop = false;
    }
  }
  return ret;
}

void MaxHeapify(int array[], int size) {
  int temp;
  for (int j = 0; j < size+1; j++) {
    for (int i = 0; i < size+1; i++) {
      if (((i*2)+1) < size && ((i*2)+2) < size && i != 0) {
        if ((array[(i*2)+1] < array[(i*2)+2]) && (array[i] < array[(i*2)+2])) {
          temp = array[i];
          array[i] = array[(i*2)+2];
          array[(i*2)+2] = temp;
        } else if (array[(i*2)+2] < array[(i*2)+1]
                   && (array[i] < array[(i*2)+1])) {
          temp = array[i];
          array[i] = array[(i*2)+1];
          array[(i*2)+1] = temp;
        }
      } else if (i == 0) {
        if (array[1] < array[2] && array[0] < array[2]) {
          temp = array[0];
          array[0] = array[2];
          array[2] = temp;
        } else if (array[2] < array[1] && array[0] < array[1]) {
          temp = array[0];
          array[0] = array[1];
          array[1] = temp;
        }
      } else if (((i*2)+2) <= size && ((i*2)+1) > size) {
        if (array[i] < array[(i*2)+1]) {
          temp = array[i];
          array[i] = array[(i*2)+1];
          array[(i*2)+1] = temp;
        }
      }
    }
  }
}

void HeapSortAsc(int array[], int size) {
  bool loop = true;
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = size-1; j >= 0; j--) {
      if (array[i] > array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
