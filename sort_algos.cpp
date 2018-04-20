/*
 * Name: sort_algos.cpp
 *
 */
#include "sort_algos.hpp"

/* 
 * Bubble Sort: O(n^2)
 */
std::vector<int> bubble_sort(std::vector<int> to_sort) {

  int holder = 0;

  for(int j = 0; j < to_sort.size() - 1; j++) {  
    for(int i = 0; i < to_sort.size() - j -1; i++) {
      if(to_sort[i] > to_sort[i+1]) {
        holder = to_sort[i];
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

}

/*
 * Selection Sort: O(n^2)
 */
std::vector<int> selection_sort(std::vector<int> to_sort) {
}


/*
 * Merge Sort: O(nlogn)
 */
std::vector<int> merge_sort(std::vector<int> to_sort) {




  return to_sort;
}
