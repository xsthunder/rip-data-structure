#include <iostream>
#include <string>
#include <list>


template <class T>
void print(std::list<T> &data, const std::string &label) {
  std::cout << label << " ";
  for(const T& x:data){
      std::cout<<" "<<x;
  }
  std::cout << std::endl;
}

template <class T>
void swap(T &a, T &b) {
    T c = b;
    b = a;
    a = c;
}

template <class T>
void reverse(std::list<T> &data) {
  // FILL IN THIS FUNCTION
   typedef typename std::list<T>::iterator IT;
   typedef typename std::list<T>::reverse_iterator RIT;
   int cnt=0;
   const int n = data.size();
   IT it = data.begin();
   RIT rit = data.rbegin();
   while(cnt < n){
       swap(*it, *rit);
       cnt += 2;
       it++;
       rit++;
   }
}


int main() {
  std::list<int> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);
  data.push_back(4);
  data.push_back(5);
  data.push_back(6);
  data.push_back(7);

  print(data,"before:");
  reverse(data);
  print(data,"after: ");

  std::list<std::string> data2;
  data2.push_back("apple");
  data2.push_back("banana");
  data2.push_back("carrot");
  data2.push_back("date");

  print(data2,"before:");
  reverse(data2);
  print(data2,"after: ");
}
