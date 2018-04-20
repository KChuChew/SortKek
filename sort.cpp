/*
 * Name: sort.cpp
 *
 *
 */
#include "sort_algos.hpp"

/*
 * Name: is_integer
 * Description: This function checks if a specific string is an integer.
 *
 */
inline bool is_integer(const std::string & s) {
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   std::strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

/*
 * Name: get_rand_int
 * Description: Produces a random integer between vals 0 to passed in limit. 
 *
 */
inline int get_rand_int(unsigned int limit) {
  return (std::rand() % limit);
}

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
 
  std::cout << quantity + 5 << "\n";
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
  //std::cout << to_sort.size() << "\n";
  for(unsigned int i = 0; i < quantity; ++i) {
    int r = std::rand() % limit;
    to_sort.push_back(r);
  }
  /*for(unsigned int i = 0; i < to_sort.size(); ++i) {
std::cout << to_sort[i] << " ";
  }*/
//std::cout << "\n";
	while(true) {
  	std::cout << "Sort with which algorithm? :\n" 
                 "bubble sort (b),\n" 
                 "selection sort (s),\n"
                 "quick sort (q),\n" 
                 "merge sort (m),\n" 
                 "insertion sort (i),\n" 
                 "OR type exit when done testing.\n"; 
  	//std::cin >> choice;
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
std::cerr << "CHOICE NOT JUDGED " << c << "\n";
      if(c != 'b' && c != 's' && c != 'q' && c != 'm' && c != 'i') {
        std::cout << "Please enter valid option\n";
        continue;
      }
    }
    char c = choice[0];
std::cerr << "CORRECT CHOICE " << c << "\n";
    //choice = std::stoi(choice);	
	
  	switch (c) {
    	case 'b': {
      	//to_sort = bubble_sort(to_sort);
        std::cout << "Begin Bubble Sorting\n";
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> output = bubble_sort(to_sort);
        auto stop = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by Bubble Sort: " << dur.count() << " milliseconds.\n";
        std::cout << "Output Vector \n";
        /*for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";*/
        break;
      }
    	case 's':
      	std::cout << "Begin Selection Sorting\n";
        break;
   
    	case 'q':
        std::cout << "Begin Quick Sorting\n";	
        break;
   
    	case 'm': 
      	std::cout << "Begin Merge Sorting\n";
        break;
   
    	case 'i':
      	std::cout << "Begin Insertion Sorting\n";
        break;
   
    	default:
				std::cout << "Please choose a sorting algorithm from above\n";  
		}
	}
  
  return 0;
}
