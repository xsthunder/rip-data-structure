#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
using namespace std;


// defined in performance.cpp
void usage();


void bst_test(const std::string* input_data, int input_count, const std::string &operation, std::string *output_data, int &output_count) {

  std::map<std::string,int> mp;


  for (int i = 0; i < input_count; i++) 
    mp[input_data[i]]++;

  if (operation == "sort") {
      for(auto p:mp){
          for(int i = 0;i<p.second;i++){
              output_data[output_count++] = p.first;
          }
      }
  } else if (operation == "remove_dups") {
      for(int i = 0;i<input_count;i++){
          if(mp[input_data[i]]){
              output_data[output_count++] = input_data[i];
              mp[input_data[i]] = 0;
          }
      }
  } else if (operation == "mode") {
      int mx = 0;
      for(auto p:mp){
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
