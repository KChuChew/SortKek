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

#ifndef SORT_ALGOS_HPP_INCLUDED 
#define SORT_ALGOS_HPP_INCLUDED
std::vector<int> bubble_sort(std::vector<int> to_sort);
std::vector<int> insertion_sort(std::vector<int> to_sort);
std::vector<int> selection_sort(std::vector<int> to_sort);
std::vector<int> merge_sort(std::vector<int> to_sort);
#endif
