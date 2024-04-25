// a3.cpp

/////////////////////////////////////////////////////////////////////////
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough detail
// so that someone can see the exact source and extent of the borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have not
// seen solutions from other students, tutors, websites, books, etc.
//
/////////////////////////////////////////////////////////////////////////

//
// You can add other #includes of standard C++ libraries if you need them for
// testing.
//
#include "a3.h"

using namespace std;

// ... put testing functions here ...
void q1_test(){
  cout << "Running default_constructor_test() ... ";
  int_vec arr0;
  assert(arr0.capacity() == 10);
  assert(arr0.size() == 0);

  int_vec arr1;
  assert(arr1.capacity() > 0);
  assert(arr1.size() == 0);

  int_vec arr2;
  assert(arr2.capacity() != arr2.size());
   cout << "\n default_constructor_test() passed \n ";
}

void copy_constructor_test(){
  cout << "Running copy_constructor_test() ... ";
  int_vec arr1;
  int_vec arr2 = int_vec(arr1);
  assert(arr1.size() == arr2.size());
  assert(arr1 == arr2);
  arr1.append(1);
  arr2.append(arr1);
  assert(arr1.size() == arr2.size());
  assert(arr1.capacity() == arr2.capacity());
    cout << "\n copy_constructor_test() passed \n";
}

void size_test(){
  cout << "Running size_test() ... ";
  int_vec arr1;
  for(int i = 0; i < 100; i++){
    arr1.append(i); 
  }
  assert(arr1.size() == 100);

  int_vec arr2;
  arr2.append(1);
  assert(arr2.size() == 1);

  int_vec arr3;
  assert(arr3.size() == 0);
  cout << "\n size_test() passed \n";
}

void capacity_test(){
  cout << "Running capacity_test() ... ";
  int_vec arr1;
  for(int i = 0; i < 10; i++){
    arr1.append(i);
    }
    assert(arr1.capacity() == 10);
    arr1.append(1);
    assert(arr1.capacity() == 20);

  cout << "\n capacity_test() passed \n";
}

void pct_used_test(){
  cout << "Running pct_used_test() ... ";
  int_vec arr1;
  assert(arr1.size()== 0);
  assert(arr1.capacity() == 10);
  assert(arr1.pct_used() == 0.0);

  int_vec arr2;
  arr2.append(2);
  assert(arr2.size() == 1);
  assert(arr2.capacity() == 10);
  assert(arr2.pct_used() == 0.1);

  cout << "\n pct_used_test() passed \n";
}

void to_str_test(){
  cout << "Running to_str_test() ... ";
  int_vec arr;
  assert(arr.to_str() == "[]");
  
  int_vec arr1;
  arr1.append(0);
  arr1.append(3);
  assert(arr1.to_str() == "[0, 3]");

  int_vec arr2;
  arr2.append(5);
  arr2.append(8);
  arr2.append(10);
  arr2.append(0);
  assert(arr2.to_str() == "[5, 8, 10, 0]");

  cout << "\n to_str_test() passed \n";
}
  void get_test(){
    cout << "Running get_test() ... ";
    int_vec arr1;
    for(int i = 0; i < 100; i++){
      arr1.append(i);
      assert(arr1.get(i) == i);
    }
    assert(arr1.get(2) == 2);
    assert(arr1.get(10) == 10);

    cout << "\n get_test() passed \n";
  }
  void set_test(){
    cout << "Running set_test() ... ";
    int_vec arr1;
    for( int i = 0; i < 100; i++){
      arr1.append(0);
    }
    arr1.set(0,5);
    assert(arr1.get(0) == 5);
    arr1.set(0,10);
    assert(arr1.get(0) == 10);
    arr1.set(arr1.size() - 1, 50);
    assert(arr1.get(arr1.size() - 1) == 50);

    cout << "\n set_test() passed \n";
  }

  void append_test(){
    cout << "Running append_test() ... ";
    int_vec arr1;
    assert(arr1.size() == 0);
    arr1.append(2);
    assert(arr1.size() == 1);
    assert(arr1.get(0) == 2);
    arr1.append(3);
    assert(arr1.size() == 2);
    assert(arr1.get(0) == 2);
    assert(arr1.get(1) == 3);

    cout << "\n append_test() passed \n";
  }
  void prepend_test(){
    cout << "Running prepend_test() ... ";
    int_vec arr1;
    assert(arr1.size() == 0);
    arr1.prepend(2);
    assert(arr1.size() == 1);
    assert(arr1.get(0) == 2);
    arr1.prepend(3);
    assert(arr1.size() == 2);
    assert(arr1.get(0) == 3);
    assert(arr1.get(1) == 2);

    cout << "\n prepend_test() passed \n";
  }
  void reverse_test(){
    cout << "Running reverse_test() ... ";
    int_vec arr1;
    arr1.append(2);
    arr1.append(3);
    arr1.append(4);
    arr1.append(5);
    assert(arr1.size() == 4);
    arr1.reverse();
    assert(arr1.get(0) == 5);
    assert(arr1.get(1) == 4);
    assert(arr1.get(2) == 3);
    assert(arr1.get(3) == 2);

    cout << "\n reverse_test() passed \n";
  }
  void sort_test(){
    cout << "Running sort_test() ... ";
    int_vec arr1;
    arr1.append(5);
    arr1.append(6);
    arr1.append(3);
    arr1.append(1);
    assert(arr1.size() == 4);
    arr1.sort();
    assert(arr1.get(0) == 1);
    assert(arr1.get(1) == 3);
    assert(arr1.get(2) == 5);
    assert(arr1.get(3) == 6);

    cout << "\n sort_test() passed \n";
  }
  void clear_test(){
    cout << "Running clear_test() ... ";
    int_vec arr1;
    arr1.append(12);
    assert(arr1.size() == 1);
    assert(arr1.capacity() == 10);
    arr1.clear();
    assert(arr1.size() == 0);
    assert(arr1.capacity() == 10);

    arr1.append(1);
    arr1.append(3);
    arr1.append(5);
    assert(arr1.size() == 3);
    assert(arr1.capacity() == 10);
    arr1.clear();
    assert(arr1.size() == 0);
    assert(arr1.capacity() == 10);

    cout << "\n clear_test() passed \n";
  }
  void compact_test(){
    cout << "Running compact_test() ... ";
    int_vec arr1;
    arr1.append(12);
    assert(arr1.size() == 1);
    assert(arr1.capacity() == 10);
    arr1.compact();
    assert(arr1.size() == 1);
    assert(arr1.capacity() == 1);
    arr1.clear();

    int_vec arr2;
    arr2.append(1);
    arr2.append(3);
    arr2.append(5);
    assert(arr2.size() == 3);
    assert(arr2.capacity() == 10);
    arr2.compact();
    assert(arr2.size() == 3);
    assert(arr2.capacity() == 3);

    cout << "\n compact_test() passed \n";
  } 
  void remove_all_test(){
    cout << "remove_all_test() ... ";
    int_vec arr1;
    assert(arr1.size() == 0);
    arr1.append(2);
    arr1.append(2);
    arr1.append(5);

    arr1.remove_all(2);
    //assert(arr1.to_str() == "[5]");
    
    // int_vec arr2;
    // arr2.append(2);
    // arr2.append(2);
    // arr2.append(2);
    // arr2.append(2);
    // assert(arr2.size() == 4);
    // arr2.remove_all(2);
    // assert(arr2.size() == 0);

    cout << "\n remove_all_test() passed \n";
  }
  void file_test(){
    cout << "file_test() ... ";
    int_vec arr1("data11.txt");
      assert(arr1.size() == 11);
      assert(arr1.get(0) == 180);
      assert(arr1.get(2) == 170);
      assert(arr1.get(8) == 200);

    int_vec arr2("data22.txt");
      assert(arr2.size() == 22);
      assert(arr2.get(7) == 150);
      assert(arr2.get(21) == 130);
      assert(arr2.get(17) == 160);

    int_vec arr3("data100.txt");
      assert(arr3.size() == 100);
      assert(arr3.get(0) == 2);
      assert(arr3.get(49) == 102);

  cout << "\n file_test() passed \n";
  }
   
int main() {
  cout << "Assignment 3 Testing ... \n\n";
  q1_test();
  copy_constructor_test();
  size_test();
  capacity_test();
  pct_used_test();
  to_str_test();
  get_test();
  set_test();
  append_test();
  prepend_test();
  reverse_test();
  sort_test();
  clear_test();
  compact_test();
 // remove_all_test(); 
  file_test();

} // main
