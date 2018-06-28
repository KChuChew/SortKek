/*
 * Info: Kevin Chu : 25 May 2018 : 牛樓 
 * FileName: sort.cpp
 * Description: File contains controls for user input and
 *              calling various sorting functions.
 *
 */
#include "sort_algos.hpp"

/*
 * Name: is_integer
 * Description: This function checks if a specific string is an integer.
 * Parameters: s - string to be determined if integer
 * Return: bool - true if s is integer false if s not integer
 */
inline bool is_integer(const std::string & s) {
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   std::strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

/*
 * Name: get_rand_int
 * Description: Generates a random integer between vals 0 to passed in limit. 
 * Parameters: limit - integer value for upper limit of integer to generate
 *                     value limited from 0 <= x <= limit.
 * Return: randomly generated integer
 */
inline int get_rand_int(unsigned int limit) {
  return (std::rand() % limit);
}

/*
 * Name: main
 * Description: Main control function for calling sort algos.
 * Parameters: argc - # of command line args (not used)
 *             argv - vector of command line inputs (not used)
 * Return: 0 (on user exit)
 */
int main(int argc, char * argv[]) {
  
  std::string s, choice;
  std::string algo, complexity;
 
  unsigned int quantity = 0; // var to store number of rand ints to generate 
  /* loop runs until user inputs valid number of integers to sort (# >= 1) 
   * while(true) for error checking and invalid input
   */
  while(true) {
    std::cout << "How many integers to sort?\n";
    std::cin >> s;
    if(is_integer(s)) {
	    if(std::stoi(s.c_str()) <= 0) {
        std::cout << "Please sort more than 0 integers\n\n";
        continue;
      }
      else {
        quantity = std::stoi(s.c_str());	
        break;
      }
    }
		else {
	    std::cout << "Please sort a valid number of integers (more than 0 integers)\n\n";	
    }
  }
 
  s.clear();

  unsigned int limit = 0; // var to store upper bound on integer values
  /* loop runs until user inputs valid upper bound for values (# >= 1) 
   * while(true) for error checking and invalid input
   */
  while(true) {
    std::cout << "What is the highest valued integer to sort?\n";
    std::cin >> s;
    if(is_integer(s)) {
	    if(std::stoi(s.c_str()) <= 0) {
        std::cout << "Please input valid upper bound for values (# >= 1)\n\n";
        continue;
      }
      else {
        limit = std::stoi(s.c_str());	
        break;
      }
    }
		else {
	    std::cout << "Please set valid upper bound for values (# >= 1)\n\n";	
    }
  }
 
  std::cout << "just nyolo me\n";
  std::vector<int> to_sort; // empty initialized vector to input rand vals to sort
  for(unsigned int i = 0; i < quantity; ++i) {
    int r = std::rand() % limit;
    to_sort.push_back(r);
  }
  while(1) {
    std::cout << "Sort with which algorithm? :\n" 
                 "bubble sort (b),\n" 
                 "selection sort (s),\n"
                 "quick sort (q),\n" 
                 "merge sort (m),\n" 
                 "insertion sort (i),\n" 
                 "OR type exit when done testing.\n"; 
 	  std::cin >> choice;
	  std::cout << choice << "\n"; 
 	  if(choice == "exit") {
      break;
    }
    if(choice.length() > 1) {
      std::cout << "Please enter valid option\n";
      continue;
    }
    if(choice.length() == 1) {
      char c = choice[0];
      if(c != 'b' && c != 's' && c != 'q' && c != 'm' && c != 'i') {
        std::cout << "Please enter valid option\n";
        continue;
      }
    }
    char c = choice[0];
//std::cerr << "CORRECT CHOICE " << c << "\n";

	  switch (c) {
   	  case 'b': {
        std::cout << "Begin Bubble Sorting\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> output = bubble_sort(to_sort);
        auto stop = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by Bubble Sort: " << dur.count() << " microseconds.\n";
        std::cout << "Output Vector \n";
        for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";
        break;
      }
  	  case 's': {
    	  std::cout << "Begin Selection Sorting\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> output = selection_sort(to_sort);
        auto stop = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by Selection Sort: " << dur.count() << " microseconds.\n";
        std::cout << "Output Vector \n";
        for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";
        break;
      } 
      case 'q': {
        std::cout << "Begin Quick Sorting\n";	
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> t = to_sort;
        std::vector<int> output = quick_sort(t, 0, t.size() - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by Quick Sort: " << dur.count() << " microseconds.\n";
        std::cout << "Output Vector \n";
        for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";
        break;
      } 
      case 'm': 
    	  std::cout << "Begin Merge Sorting\n";
        break;
   
      case 'i': {
        std::cout << "Begin Insertion Sorting\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> output = insertion_sort(to_sort);
        auto stop = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by Insertion Sort: " << dur.count() << " microseconds.\n";
        std::cout << "Output Vector \n";
        for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";
        break;
      } 
      default:
			  std::cout << "Please choose a sorting algorithm from above\n";  
	  }
  }  
  return 0;
}
