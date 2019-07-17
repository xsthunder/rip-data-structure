#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <list>


// defined in performance.cpp
void usage();


void list_test(const std::string* input_data, int input_count, const std::string &operation, std::string *output_data, int &output_count) {

  // for all cases, simply put the data into a vector
  std::list<std::string> lst;
  for (int i = 0; i < input_count; i++) 
    lst.push_back(input_data[i]);
  
  if (operation == "sort") {
    // use the list sort algorithm
    lst.sort();
    for (auto x : lst){
      output_data[output_count++] = x;
    }

  } else if (operation == "remove_dups") {
    // don't reorder the elements, just do all pairwise comparisons
    output_count = 0;
    for (auto x : lst) {
      bool dup = false;
      for (int j = 0; j < output_count; j++) {
	if (x == output_data[j]) {
	  dup = true;
	  break;
	}
      }
      // if it has not already been added to the output list
      if (!dup) {
	output_data[output_count] = x;
	output_count++;
      }
    }

  } else if (operation == "mode") {
    // use the lsttor sort algorithm
    lst.sort();
    int current_count = 1;
    std::string mode;
    int mode_count = 0;
    // keep track of two pointers into the structure
    std::list<std::string>::iterator current = lst.begin();
    ++current;
    std::list<std::string>::iterator previous = lst.begin();
    for (; current != lst.end(); ++current, ++previous) {
      if (*current == *previous) {
	// if they are the same increment the count
        current_count++;
      } else if (current_count >= mode_count) {
        // found a new mode!
        mode = *previous;
        mode_count = current_count;
        current_count = 1;
      } else {
        current_count = 1;
      }
    }
    if (current_count >= mode_count) {
      // last entry is a new mode!
      mode = *previous;
      mode_count = current_count;
    }
    // save the mode to the output lsttor
    output_count = 1;
    output_data[0] = mode;
  } else {
    std::cerr << "Error: Unknown operation: " << operation << std::endl;
    usage();
    exit(0);
  }
}
