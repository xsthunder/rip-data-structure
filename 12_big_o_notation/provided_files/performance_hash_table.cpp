#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>


// defined in performance.cpp
void usage();


void hash_table_test(const std::string* input_data, int input_count, const std::string &operation, std::string *output_data, int &output_count) {

  std::unordered_map<std::string,int> ht(input_count);
  for (int i = 0; i < input_count; i++) 
    ht[input_data[i]]++;
  if (operation == "sort") {
      std::cerr << "Error: DATA STRUCTURE IS NOT SENSITIVE FOR "<<operation<<" XXXXXXXXXXXX" << std::endl;
      exit(0);
  } else if (operation == "remove_dups") {
      for(int i = 0;i<input_count;i++){
          if(ht[input_data[i]]){
              output_data[output_count++] = input_data[i];
              ht[input_data[i]] = 0;
          }
      }
  } else if (operation == "mode") {
      int mx = 0;
      for(auto p:ht){
          if(p.second>=mx){
              output_data[0] = p.first;
              output_count = 1;
          }
      }
  } else {
    std::cerr << "Error: Unknown operation: " << operation << std::endl;
    usage();
  }
}
