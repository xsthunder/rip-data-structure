#include <iostream>
#include <string>


// Note: It's ok that all the member variables are public for this
// tiny class.  We'll build up to a more robust and complete linked
// list implementation in lecture 11.
template <class T>
class Node {
public:
  T value;
  Node<T> *ptr;
};



template <class T>
void print(Node<T> *data, const std::string &label) {
  std::cout << label;
  Node<T> *tmp = data;
  while (tmp != NULL) {
    std::cout << " " << tmp->value;
    tmp = tmp->ptr;
  }
  std::cout << std::endl;
}



template <class T>
void reverse(Node<T>* &input) {
  // FILL IN THIS FUNCTION
    typedef Node<T>* NodePtr;
    if(input == NULL)return; // empty list
    NodePtr p = input, nxt = input->ptr;
    NodePtr prev = NULL;
    while(p!=NULL){
        nxt = p->ptr;
        p->ptr = prev;
        prev = p;
        p = nxt;
    }
    input = prev;
}




int main() {

  // manually create a linked list of notes with 4 elements
  Node<int>* my_list = new Node<int>; 
  my_list->value = 1; 
  my_list->ptr = new Node<int>;
  my_list->ptr->value = 2;
  my_list->ptr->ptr = new Node<int>;
  my_list->ptr->ptr->value = 3;
  my_list->ptr->ptr->ptr = new Node<int>;
  my_list->ptr->ptr->ptr->value = 4;
  my_list->ptr->ptr->ptr->ptr = NULL;

  
  print(my_list,"my_list before");
  reverse(my_list);
  print(my_list,"my_list after ");

  // test 0
  Node<int>* list_0 = NULL;
  print(list_0,"list_0 before");
  reverse(list_0 );
  print(list_0,"list_0 after ");

  // test 1 
  Node<int>* list_1 = new Node<int>; 
  list_1->value = 1; 
  list_1->ptr = NULL;
  print(list_1,"list_1 before");
  reverse(list_1);
  print(list_1,"list_1 after ");


  // test 2
  Node<int>* list_2 = new Node<int>; 
  list_2->value = 1; 
  list_2->ptr = new Node<int>;
  list_2->ptr->value = 2;
  list_2->ptr->ptr = NULL;
  print(list_2,"list_2 before");
  reverse(list_2);
  print(list_2,"list_2 after ");

  // Note: We are not deleting any of the Nodes we created...  so this
  // program has memory leaks!  More on this in lecture 11.

}

// ===========================================================================
