/* ayy lmao */
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <climits>

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

inline bool isInteger(const std::string & s) {
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   std::strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}

int main(int argc, char * argv[]) {
  
  std::vector<int> to_sort;
  //std::vector<int>::iterator sorter;
  //int s;
  //char choice;
  std::string s, choice;
  std::string algo, complexity;

  std::cout << "Enter integer to sort OR type exit to finalize list.\n"; 

  
  /*while(!std::cin.fail()) {
    std::cin >> s;
    to_sort.push_back(s);
  }*/
  while(true) {
    std::cin >> s;
    if(isInteger(s)) {
			to_sort.push_back(std::stoi(s.c_str()));	
		}
		else {
			break;
		}
		//std::getline(std::cin, s);
    /*if(!std::cin.fail()) {
      to_sort.push_back(std::stoi(s));
    }
    else {
      break;
    }*/

  }
  //std::cin.ignore(INT_MAX);
  for(unsigned int i = 0; i < to_sort.size(); ++i) {
std::cout << to_sort[i] << " ";
  }
std::cout << "\n";
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
        for(unsigned int i = 0; i < output.size(); ++i) {
          std::cout << output[i] << " "; 
        }
        std::cout << "\n";
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
