/*
 * Info: Kevin Chu : 25 May 2018 : 牛肉 
 * Name: sort_algos.cpp
 *
 */
#include "sort_algos.hpp"

/* 
 * Bubble Sort: O(n^2)
 */
std::vector<int> bubble_sort(std::vector<int> to_sort) {
  for(int j = 0; j < to_sort.size() - 1; j++) {  
    for(int i = 0; i < to_sort.size() - j - 1; i++) {
      if(to_sort[i] > to_sort[i+1]) {
        int holder = to_sort[i];
	      to_sort[i] = to_sort[i+1];
	      to_sort[i+1] = holder;
      }
    }
  }
  
  return to_sort;
}

/*
 * Insertion Sort: O(n^2)
 */
std::vector<int> insertion_sort(std::vector<int> to_sort) {
  for(int i = 1; i < to_sort.size(); ++i) {
    int counter = i - 1;
    int ele = to_sort[i];
    while(counter >= 0 && ele < to_sort[counter]) {
      to_sort[counter + 1] = to_sort[counter];
      counter--; 
    }
    to_sort[counter + 1] = ele; 
  }

  return to_sort;
}

/*
 * Selection Sort: O(n^2)
 */
std::vector<int> selection_sort(std::vector<int> to_sort) {
  int min_index;  
  for(int i = 0; i < to_sort.size(); ++i) {
    min_index = i;
    for(int j = i + 1; j < to_sort.size(); ++j) {
      if(to_sort[j] < to_sort[min_index]) {
        min_index = j;
      }
    }
    std::swap(to_sort[min_index], to_sort[i]);
  }
  return to_sort;
}

/*
 * Name: partition
 * Description: Helper function for quick_sort. Function takes in pivot point 
 *              in to_sortay (last element) and partitions to_sortay such that all elements
 *              less than pivot val appear before pivot val and elements greater than 
 *              pivot val appear after pivot val.
 * Parameters: to_sort - to_sortay of values to parition
 *             low - first index to start partitioning
 *             high - last index to start paritioning
 * Return: index of partitioned element 
 */
int partition(std::vector<int> & to_sort, int low, int high) {
  int pivot = to_sort[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; ++j) {
    if(to_sort[j] <= pivot) {
      i++;
      std::swap(to_sort[i], to_sort[j]);
    }
  }
  std::swap(to_sort[i + 1], to_sort[high]);
  return (i + 1);
}
/*
 * Quick Sort: O(nlogn)
 */
std::vector<int> quick_sort(std::vector<int> & to_sort, int low, int high) {
  if(low < high) {
    int part = partition(to_sort, low, high);
    quick_sort(to_sort, low, part - 1);
    quick_sort(to_sort, part + 1, high);
  }
  return to_sort;
}

/*
 * Merge Sort: O(nlogn)
 */
std::vector<int> merge_sort(std::vector<int> to_sort) {

}
