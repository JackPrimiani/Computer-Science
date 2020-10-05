/*
Copyright 2018
Author: Jack Primiani
October 2nd, 2018
*/

#ifndef HW3_MAX_HEAP_H_
#define HW3_MAX_HEAP_H_

void Add(int item, int heap[], int count);

int Remove(int heap[], int count);

void MaxHeapify(int array[], int size);

void HeapSortAsc(int array[], int size);

#endif  // HW3_MAX_HEAP_H_
