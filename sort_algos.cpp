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
  for(int i = 0; i < to_sort.size(); ++i) {
    std::cout << to_sort[i] << " ";
  }
  std::cout << "\n";
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
 * Merge Sort: O(nlogn)
 */
std::vector<int> merge_sort(std::vector<int> to_sort) {
  return to_sort;
}

/*
 * Selection Sort: O(n^2)
 */
std::vector<int> selection_sort(std::vector<int> to_sort) {
}
