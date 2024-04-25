# An Object-oriented Dynamic Array
Simon Fraser Univirsity CMPT125

In this assignment your task is using *object-oriented programming* (*OOP*). The resulting `int_vec`
class manages its memory, and so is safer and easier to use than `int_list`

When you've finished this assignment, you'll be able to write code like this:

// a3_example.cpp

#include "a3_sol.h"
#include <string>

using namespace std;

double average(int_vec v) {
    int total = 0;
    for (int i = 0; i < v.size(); i++) {
        total += v.get(i);
    }
    return double(total) / v.size();
}

int main() {
    int_vec a;    // { }
    a.append(2);  // {2}
    a.append(5);  // {2, 5}
    a.prepend(2); // {2, 2, 5}
    a.prepend(3); // {3, 2, 2, 5}
    a.println();

    int_vec b(5, 0); // {0, 0, 0, 0, 0}
    b.println();

    if (a == b) {
        cout << "a and b are the same!\n";
    } else {
        cout << "a and b are different!\n";
    }
    
    cout << "average of a: " << average(a) << "\n";
    cout << "average of b: " << average(b) << "\n";

    a.sort();
    a.reverse();
    a.remove_all(2);
    a.println();
}
```

This has no memory leaks, and the compiler won't let you do anything
nonsensical like setting `a.cap = -1`.


## Getting Started

- [a3.h](a3.h) is where you write your solutions for questions 1 to 14. It is
  set up to get you started. Make sure to fill in the info in the header at
  the top.

  - **Do not** `#include` any other C++ header files.

  - You **can** add any helper methods/functions you think might be useful (as
    long as you write them yourself). Only include code you wrote yourself.

  - *Careful*: some of the questions below ask you write *functions* instead
    of methods. Functions should be defined outside the `int_vec` class.

- [a3_test.cpp](a3_test.cpp) is where you write *automated* testing code for
  each method/function. It should have a `main()` function that calls all the
  test functions.

  - **You can** `#include` any other standard C++ header files or helper code
    you need to do you testing. Only include code you wrote yourself.

  - Write enough test cases to show that the method/function you're testing is
    correct. This may be 3-5 test cases on average, and maybe more for
    important/tricky code.

  - **Hint**: Test as you go. *Don't* leave all the testing until the end.

- [a3_graph.cpp](a3_graph.cpp) is where you write the code for question 15. It
  should have a `main()` function that uses SFML to draw the requested chart.

- [makefile](makefile) is the makefile for this assignment:

  - `make a3_test` will compile `a3_test.cpp` and create the executable file
    `a3_test`

  - `make a3_graph` will compile `a3_graph.cpp` and create the executable file
    `a3_graph`

  - `make submit` will create the .zip file to submit for this assignment (see
    "What to Submit" below)

  - `make clean` will remove all executable and .o files created by the above
    `make` commands

- [cmpt_error.h](cmpt_error.h) contains the `cmpt::error` function.


## Questions

Implement each of the following methods and functions. Use `const`, `public`,
and `private` whenever it makes sense.

1. (1 mark) Implement a **default constructor** for `int_vec()` that creates a
   new `int_vec` of size 0 and capacity 10.

   Example:

   ```cpp
   int_vec arr;
   // arr is an empty int_vec of size 0 and capacity 10
   ```

2. (1 mark) Implement a **destructor** `~int_vec()` that deletes all the
   dynamic memory used by this `int_vec`.

   Be sure to test your program with `valgrind`!


3. (1 mark) Implement a **constructor** `int_vec(n, s)` that creates a new
   `int_vec` of size `n` where each element contains a copy of the int `s`.
   The capacity should be at least `n`. If `n` is less than 0, use
   `cmpt::error` to throw a helpful error message. If `n` is equal to 0, then
   vector should have a small capacity so that new numbers can be efficiently
   added.

   Example:

   ```cpp
   int_vec arr(5, 0);
   // arr is int_vec of size 5, each entry containing 0
   ```

4. (1 mark) Implement a **copy constructor** `int_vec(other)` that creates a
   new `int_vec` that is a copy of the `int_vec` named `other`.

   Example:

   ```cpp
   int_vec a(5, 100);
   int_vec b(a);
   // b is an int_vec of size 5 with each entry equal to 100
   ```

   The *capacity* of `b` should be at least the *size* of `a`.

5. (3 marks) Implement these **getters**:

   - `size()`: returns the number of ints in the `int_vec`.

   - `capacity()`: returns the capacity of the `int_vec`, i.e. the size of the
     underlying array.

   - `pct_used()`: returns the percentage (as a `double` from 0.0 to 1.0) of
     the underlying array that is in use, i.e. the size divided by the
     capacity.

   Make sure that these are all `const` methods!

   Example:

   ```cpp
   int_vec empty;

   cout << empty.size()     << ' '    // 0
        << empty.capacity() << ' '    // 10
        << empty.pct_used() << '\n';  // 0
   ```

6. (3 marks) Implement these non-mutating methods:

   - `to_str()`: returns a `string` representation of the `int_vec`; please
     use the `[]`-brackets style as shown in the example below.

   - `print()`: is a `void` method that prints the string representation of
     the `int_vec` to `cout`

   - `println()`: is a `void` method that does the same thing as `print()`,
     but also prints a `\n` at the end

   Make sure these are all `const`!

   Example:

   ```cpp
   int_vec arr(3, 5);

   string s = arr.to_str(); // s is the string "[5, 5, 5]"
   cout << s << "\n";       // print "[5, 5, 5]"

   arr.print();    // prints [5, 5, 5] on cout (no \n at end)
   arr.println();  // prints [5, 5, 5] on cout (\n at end)
   ```

7. (2 marks) Implement these methods:

   - `get(i)` is a **getter** that returns the int at index location of `i` of
     the `int_vec`. Just as with arrays, the first index location is 0. Make
     sure this is `const`!

   - `set(i, s)` is a **setter** that sets index location `i` to be a copy of
     the int `s`.

   Both methods should do *bounds checking*: use `cmpt::error` to throw a
   helpful error message if the passed-in index `i` is less than 0, or greater
   than `size()-1`.

   Example:

   ```cpp
   int_vec arr(3, 2);

   arr.set(1, -5);        // arr is now [2, -5, 2]

   int s1 = arr.get(1);  // s1 is -5
   int s2 = arr.get(2);  // s2 is 2
   cout << s1 << " " << s2;
   ```

8. (2 marks) Implement these mutating methods:

   - `append(s)` is a `void` method that adds `int` `s` to the right end (the
     back) of the `int_vec`, increasing the size by 1

   - `prepend(s)` is a `void` method that adds the `int` `s` to the left end
     (the front) of the `int_vec`, increasing the size by 1

   For both methods, the underlying capacity should only be increased if
   necessary. When the capacity is increased, it should be *doubled*.

   Example:

   ```cpp
   int_vec arr; // empty, size 0

   arr.append(5);   // [5]
   arr.append(2);   // [5, 2]
   arr.prepend(4);  // [4, 5, 2]
   arr.prepend(1);  // [1, 4, 5, 2]
   ```

9. (1 mark) Implement the `void` method `append(other)`, where `other` is an
   `int_vec`. All the ints in `other` are appended (in the order they occur)
   to the end of this `int_vec`.

   The underlying capacity should only be increased if necessary.

   ```cpp
   int_vec arr1;       // empty, size 0

   arr1.append(7);     // [7]
   arr1.append(9);     // [7, 9]
   
   int_vec arr2;
   arr2.append(arr1);  // [7, 9]
   arr2.append(arr2);  // [7, 9, 7, 9]
   ```

   Notice that the statement `arr2.append(arr2)` appends the vector to itself,
   i.e. it is an instance of **self-appending**. You may want to handle
   self-appending as a special case in `append`.

10. (2 marks) Implement these mutating methods:

    - `reverse()` is a `void` method that reverses the order of the elements
      in the `int_vec`; please implement this yourself using basic C++, i.e.
      don't use `std::reverse`

    - `sort()` is a `void` method that re-arranges all the elements in this
      `int_vec` into increasing sorted order; use `std::sort()` to help do
      this

    Example:

    ```cpp
    int_vec arr;

    arr.append(4);  // [4]
    arr.append(3);  // [4, 3]
    arr.append(1);  // [4, 3, 1]
    arr.append(2);  // [4, 3, 1, 2]
    arr.sort();     // [1, 2, 3, 4]
    arr.reverse();  // [4, 3, 2, 1]
    ```

11. (2 marks) Implement these mutating methods:

    - `clear()` is a `void` method that removes all elements from the
      `int_vec` so its size is 0; the capacity can stay the same;

    - `compact()` is a `void` method that will, if necessary, re-size the
      underlying array so that the size and capacity are the same; the
      elements in the array are not changed in any way.

    Example:

    ```cpp
    int_vec arr;     // [], size 0, capacity 10
    arr.append(12);  // [12], size 1, capacity 10
    arr.append(80);  // [12, 80], size 2, capacity 10
       
    arr.compact();     // [12, 80], size 2, capacity 2

    arr.clear();      // [], size 0, capacity 2
    ```

12. (2 marks) Implement these functions (not methods!):

    - `operator==(a, b)` is a `bool` function that returns `true` if the
      `int_vec` `a` and the `int_vec` `b` have the same elements in the same
      order, and `false` otherwise

    - `operator!=(a, b)` is a `bool` function that returns `true` if the
      `int_vec` `a` and the `int_vec` `b` are different sizes, or *don't* have
      the same elements in the same order. Otherwise, `false` is returned.

   Example:

   ```cpp
   int_vec a(3, -1); 
   int_vec b(3, -1);

   if (a == b) cout << "same\n";       // prints "same"
   if (a != b) cout << "different\n";  // prints nothing

   a.set(0, 25);

   if (a == b) cout << "same\n";       // prints nothing
   if (a != b) cout << "different\n";  // prints "different"
   ```

13. (2 marks) Implement the `void` method `remove_all(n)` that removes all
    occurrences of `n` from the `int_vec`. All other elements are moved down
    to fill in the gaps made by the removed values. If `n` doesn't appear in
    the `int_vec`, then the `int_vec` doesn't change. The size of the
    `int_vec` should be decreased by the number of numbers removed.

    For example, if `v` is an `int_vec`, then:

    - if `v` is `[14, 1, 6, 14, 14]`, then after calling `v.remove_all(14)`
      `v` is `[1, 6]`;

    - if `v` is `[14, 1, 6, 14, 14]`, then after calling `v.remove_all(6)` `v`
      is `[14, 1, 14, 14]`;

    - if `v` is `[14, 1, 6, 14, 14]`, then after calling `v.remove_all(3)` `v`
      is `[14, 1, 6, 14, 14]`;

    - if `v` is `[2, 2, 2, 2]`, then after calling `v.remove_all(2)` `v` is
      `[]`.

14. (1 mark) Implement a **constructor** `int_vec(fname)` that creates a new
    `int_vec` by reading `int`s from the text file `fname` (where `fname` is
    type `string`). You can assume `fname` contains valid `int`s separated by
    whitespace characters.

    For example, this prints the numbers in [data11.txt](data11.txt):

    ```cpp
    int_vec a("data11.txt");
    for(int i = 0; i < a.size(); i++) {
       cout << a.get(i) << "\n";
    }
    ```

   The *capacity* of `a` should be at least the *size* of `a`.



## Basic Requirements

Before we give your program any marks, it must meet the following basic
requirements:

- It must compile on Ubuntu Linux using the standard course
  [makefile](makefile):
  
  ```
  $ make a3_test
  g++  -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g   a3_test.cpp   -o a3_test
  ```
  
  If your program fails to compile, your mark for this assignment will be 0.

  A copy of [cmpt_error.h](cmpt_error.h) will be in the same folder as your
  code when it's compiled, so your program can use `cmpt::error` if necessary.

- It must have no memory leaks or memory errors, according to `valgrind`,
  e.g.:

  ```
  $ valgrind ./a3_test
    
  // ... lots of output ... 
  ```

  A program is considered to have no memory error if:

  - In the `LEAK SUMMARY`, `definitely lost`, `indirectly lost`, and `possibly
    lost` must all be 0.

  - The `ERROR SUMMARY` reports 0 errors.

  - It is usually okay if **still reachable** reports a non- zero number of
    bytes.

  If you think your program has memory leak or other memory error due to code
  that you didn't write, then please point that out in a source code comment.


### Source Code Readability (6 marks)

- All names of variables, functions, structs, classes, etc. are sensible,
  self-descriptive, and consistent.

- Indentation and spacing is perfectly consistent and matches the structure of
  the program. All blank lines and indents should have a reason.

- All lines are 100 characters in length, or less.

- Comments are used when appropriate: to describe code that is tricky or very
  important. There are no unnecessary comments, and no commented-out code.

- Appropriate features of C++ are used in an appropriate way. For example, do
  **not** use a feature of C (like C-style strings) when there is a better
  feature of C++ (e.g. the standard `string` class). Don't use any features
  you don't understand.

- Overall, the source code is easy to read and understand.


### Questions 

Each question is worth the number of marks indicated on the question.
