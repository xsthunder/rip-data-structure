#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>


// defined in performance.cpp
void usage();


void priority_queue_test(const std::string* input_data, int input_count, const std::string &operation, std::string *output_data, int &output_count) {

  // HINT: declare your priority_queue like this:
  // DESENDING
  std::priority_queue<std::string,std::vector<std::string> > pq(input_data,input_data+input_count);
  
  if(pq.empty()){
      output_count = 0;
      return;
  }
  if (operation == "sort") {
      output_count = input_count;
      while(!pq.empty()){
          output_data[--input_count] = pq.top();
          pq.pop();
      }
  } else if (operation == "remove_dups") {
      std::cerr << "Error: DATA STRUCTURE IS NOT SENSITIVE FOR "<<operation<<" XXXXXXXXXXXX" << std::endl;
      exit(0);
  } else if (operation == "mode") {
    int current_count = 0;
    std::string mode;
    int mode_count = 0;
    // keep track of two pointers into the structure
    std::string previous, current;
    previous = pq.top();
    while(!pq.empty()){
        current = pq.top();
        if(previous == current){
            current_count ++;
        }else if(current_count >= mode_count){
            mode = previous;
            mode_count = current_count;
            current_count = 1;
        }
        pq.pop();
    }
    if(current_count >= mode_count){
        mode = previous;
        mode_count = current_count;
    }
    // save the mode to the output lsttor
    output_count = 1;
    output_data[0] = mode;
  } else {
    std::cerr << "Error: Unknown operation: " << operation << std::endl;
    usage();
  }
}
