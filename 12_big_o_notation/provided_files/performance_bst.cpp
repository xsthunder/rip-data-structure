#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>


// defined in performance.cpp
void usage();


void bst_test(const std::string* input_data, int input_count, const std::string &operation, std::string *output_data, int &output_count) {

  // HINT: declare your binary search tree (BST) like this:
  // std::set<std::string> st;
  // OR 
  // std::map<std::string,int> mp;

  std::cerr << "Error: DATA STRUCTURE NOT IMPLEMENTED" << std::endl;
  exit(0);

  if (operation == "sort") {
  } else if (operation == "remove_dups") {
  } else if (operation == "mode") {
  } else {
    std::cerr << "Error: Unknown operation: " << operation << std::endl;
    usage();
  }
}
