#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <cstdlib>    // library with the exit function
using namespace std;

// Returns true if the candidate root is indeed a root of the polynomial a*x*x + b*x + c = 0 
bool check_root(int a, int b, int c, float root) {  
  // plug the value into the formula
  float check = a * root * root + b * root + c;
  // see if the absolute value is zero (within a small tolerance)
  if (fabs(check) > 0.0001) {
    std::cerr << "ERROR:  " << root << " is not a root of this formula." << std::endl;
    return false;
  } else {
    return true;
  }
}

/* Use the quadratic formula to find the two real roots of polynomial.   Returns 
true if the roots are real, returns false if the roots are imaginary.  If the roots 
are real, they are returned through the reference parameters root_pos and root_neg. */ 
bool find_roots(int a, int b, int c, float &root_pos, float &root_neg) {
  // compute the quantity under the radical of the quadratic formula
  int radical = b*b - 4*a*c;
  // if the radical is negative, the roots are imaginary
  if (radical < 0) {
    std::cerr << "ERROR:  Imaginary roots" << std::endl;
    return false;
  }
  float sqrt_radical = sqrt(radical);  
  // compute the two roots
  root_pos = (-b + sqrt_radical) / 2*a;
  root_neg = (-b - sqrt_radical) / 2*a;
  return true;
}

int main() {
  // We will loop until we are given a polynomial with real roots
  const int LOOP_CNT=5;
  int b_array[LOOP_CNT];
  int c_array[LOOP_CNT];
  float smaller_root[LOOP_CNT];
  std::cout << "Enter "<<LOOP_CNT<<" integer b coefficients to a quadratic function: x*x + b*x + c = 0" << std::endl;
  for(int i = 0;i<LOOP_CNT;i++){
    cin>>b_array[i];
  }
  std::cout << "Enter "<<LOOP_CNT<<" integer c coefficients to a quadratic function: x*x + b*x + c = 0" << std::endl;
  for(int i = 0;i<LOOP_CNT;i++){
    cin>>c_array[i];
  }
  // create a place to store the roots
  
  for(int i = 0;i<LOOP_CNT;i++){
    float root_pos, root_neg;
    int my_a = 1, my_b = b_array[i], my_c = c_array[i];
    bool success = find_roots(my_a,my_b,my_c, root_pos,root_neg);
    if (!success) {
      cerr << "fucntion #" << i+1 << " has no root" << endl;
      continue;
    }
    if (check_root(my_a,my_b,my_c, root_pos) && check_root(my_a,my_b,my_c, root_neg) ){
      smaller_root[i]=root_neg;
    }
    else {
      std::cerr << "ERROR:  Unable to verify one or both roots. for function #"<< i+1 << std::endl;
    }
  }
  for(int i = 0;i<LOOP_CNT;i++){
      cerr << "fucntion #" << i+1 << "'s smaller root is "<<smaller_root[i] << endl;
  }
  return 0; 
}
