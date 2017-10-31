/* ayy lmao */
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

//using namespace std;

/* 
 * Bubble Sort: O(n^2)
 */
std::vector<int> bubble_sort(std::vector<int> toSort) {

  int holder = 0;

  for(int j = 0; j < toSort.size() - 1; j++) {  
    for(int i = 0; i < toSort.size() - j -1; i++) {
      if(toSort[i] > toSort[i+1]) {
        holder = toSort[i];
	toSort[i] = toSort[i+1];
	toSort[i+1] = holder;
      }
    }
  }
  
  return toSort;
}


/*
 * Merge Sort: O(nlogn)
 */
std::vector<int> merge_sort(std::vector<int> toSort) {




  return toSort;
}


int main(int argc, char * argv[]) {
  
  std::vector<int> toSort;
  //std::vector<int>::iterator sorter;
  int s;
  char choice;
  std::string algo, complexity;

  std::cout << "Please enter integers to sort" << std::endl; 

  while((std::cin >> s) && s <= 9) {
    toSort.push_back(s);
  }
  
  std::cout << "Sort with which algorithm? : bubble sort (b), selection sort (s), quick sort (q), merge sort (m), insertion sort (i)" << std::endl; 
  std::cin >> choice;
std::cout << choice << std::endl; 
  switch (choice) {
    case 'b':
      toSort = bubble_sort(toSort);
      break;
    
    case 's':
      break;
   
    case 'q':
      break;
   
    case 'm': 
      break;
   
    case 'i':
      break;
   
    default:
      toSort = bubble_sort(toSort);
  }
  
  //std::cout << "Sorting 

/*
  cout << "Enter integers " << endl;

  while(cin >> s) {   
    toSort.push_back(s);
  } 

cerr << "test" << endl;
cerr << toSort.size() << endl;
  
  toSort = bubble_sort(toSort);

cerr << "Sorted Array: " << endl;
  
  for(unsigned int i = 0; i < toSort.size(); i++) {
    cerr << toSort[i] << " "; 
  }
  
cerr << endl;
*/
  //char * word = "null"; 
//std::cerr << word[4] << "a";  
  return 0;
}
