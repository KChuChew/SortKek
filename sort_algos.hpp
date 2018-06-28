/*
 * Name: sort_algos.hpp
 *
 *
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <algorithm>

#ifndef SORT_ALGOS_HPP_INCLUDED 
#define SORT_ALGOS_HPP_INCLUDED
std::vector<int> bubble_sort(std::vector<int> to_sort);
std::vector<int> insertion_sort(std::vector<int> to_sort);
std::vector<int> selection_sort(std::vector<int> to_sort);
std::vector<int> merge_sort(std::vector<int> to_sort);
std::vector<int> quick_sort(std::vector<int> & to_sort, int low, int high);
#endif
