#include <iostream>
#include <string>
#include <utility>
#include <cassert>
#include "ds_set.h"
using namespace std;
void print_set(ds_set<int> &set){
    cout<<"begin -> end\n";
    for(auto it = set.begin();it!=set.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"end -> begin \n";
    for(auto it = --set.end();;--it){
        cout<<*it<<" ";
        if(it == set.begin()){
            break;
        }
    }
    cout<<endl;
}
int main() {
    ds_set<int> set_balanced;
    int array_balanced[] = {
        8, 
        4, 12, 
        2, 6, 10 ,14, 
        1, 3, 5, 7, 10 ,11 ,13, 15 };// bfs
    for(int i = 0;i<sizeof(array_balanced)/sizeof(int);i++){
        set_balanced.insert(array_balanced[i]);
    }
    set_balanced.print_as_sideways_tree(cout);
    print_set(set_balanced);
    
    ds_set<int>set_unbalanced_1;
    for(int i = 1;i<=15;i++){
        set_unbalanced_1.insert(i);
    }
    set_unbalanced_1.print_as_sideways_tree(cout);
    print_set(set_unbalanced_1);

    ds_set<int>set_unbalanced_2;
    for(int i = 1;i<=15;i++){
        set_unbalanced_2.insert(16-i);
    }
    set_unbalanced_2.print_as_sideways_tree(cout);
    print_set(set_unbalanced_2);
    return 0;
}
