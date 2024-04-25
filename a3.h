// a3.h

/////////////////////////////////////////////////////////////////////////
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////


#include "cmpt_error.h" // These are the only
#include <iostream>     // files you can #include. 
#include <fstream>      // Don't remove or change
#include <string>       // any of them, and don't 
#include <algorithm>    // #include any others.
#include <cassert>      

using namespace std;

class int_vec {
private:

    int cap; // length of underlying array
    int* arr;     // pointer to the underlying array
    int sz;     // # of elements in this int_vec from user's perspective

public:
//quest1
// default constructor
	int_vec()
	: cap(10), arr(new int[cap]), sz(0)
	{}
//quest2
	~int_vec(){
		delete []arr;
	}
//quest3
	int_vec(int n, int s)
	: cap(10), arr(new int[cap]), sz(n)
	{
		//error message is n is negative
		if(n < 0){
			cmpt::error("can't construct int_vec of negative sz");
		}  
		//sets new arr[i] to int s
		arr = new int[cap];
		for(int i = 0; i < sz; i++){
			arr[i] = s;
		}
	}
//quest4
// copy constructor
	int_vec(const int_vec &other)
	: cap(other.cap), arr(new int[cap]), sz(other.sz)
	{
		//copies all elements from arr[i] to other.arr[i]
		for(int i = 0; i < sz; i++){
			arr[i] = other.arr[i];
		}
	}
//quest5 
	int size() const{
		return sz;
	}

	int capacity() const{
		return cap;
	}

	double pct_used() const{ 
		return double(sz) / double(cap);
	}
//quest6
//using to_string: https://en.cppreference.com/w/cpp/string/basic_string/to_string
	string to_str() const{
		string bracket = "[";
		if(sz > 0){
			//start with [
			bracket.append(to_string(arr[0]));
		}
		// elements added to array follow ', ' till end of array
		for(int i = 1; i < sz; i++){
			bracket.append(", " + to_string(arr[i]));
		}
		//prints ] at the end of array
		bracket.append("]");
		return bracket;
	}
	void print() const{
		//prints all values in array
		cout << "[";
			for(int i = 1; i < sz; i++){
				cout << ", " << arr[i];
			}
		cout << "]";
	}
	void println() const{
		print();
		cout << "\n";
	}
//quest7
	int get(int i) const{
		return arr[i];
	}
	int set(int i, int s){
		arr[i] = s;
		return arr[i];
	}
//quest8
	void append(int s){
		if(sz >= cap){
			//double capacity
			cap = 2*cap;
			int* new_arr = new int[cap];
			//copy elemnts from arr[] to new_arr
			for(int i = 0; i < sz; i++){
			new_arr[i] = arr[i];
			}
			//delete old and assign new_arr
			delete[] arr;
			arr = new_arr;
		}
		//testing 
		assert(sz < cap);
		arr[sz] = s;
		sz++;
	}
	void prepend(int s){
		//if capacity is bigger than size
		if(sz < cap){
			//right shifts array to insert at 0th position 
			for(int i = sz; i > 0;i--){
			arr[i] = arr[i-1];
			}
			sz++;
			arr[0]= s;
			
		}else{
			//creates new underlying array wiht double capacity
			int* new_arr = new int[cap*2];
			for(int i = sz; i > 0;i--){
			arr[i] = arr[i-1];	
		}
		sz++;
		new_arr[0] = s;
		//deletes old and assigns new_arr 
		delete[] arr;
		arr = new_arr;
		}
	}
	//ques9
	void append(int_vec other){
		int* arr = new int[other.cap];
		int n = other.sz;
		for(int i = 0; i < n; i++){
			this-> append(arr[i]);
			
		}delete[]arr;
	}
	//ques10
	//got help understanding from this website
	//https://www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
	void reverse(){
		int temp;
		//reverses the array 
		for(int i = 0; i < sz/2; i++){
			temp = arr[i];
			arr[i] = arr[sz - i - 1];
			arr[sz - i - 1] = temp;
		}
	}
	void sort(){
		//sorts array to assending order 
		//https://www.geeksforgeeks.org/sort-c-stl/
		int n = sz;
		std::sort(arr, arr+n);
	}
	//ques11
	void clear(){
		sz = 0;
	}
	void compact(){
		if(sz > cap || cap > sz){
			//re-sizes array so that size and capacity are same
			int* arr_new = new int[cap];
			for(int i = 0; i < sz; i++){
				arr_new[i] = arr[i];
			}
			cap = sz;
			delete[] arr;
			arr = arr_new;
		}
	}
	//ques13
	void remove_all(int n){
		//search for n
		int* new_arr = new int[sz];
		int index = 0; 
		//loops through elements
		for(int i = 0; i < sz; i++){
			//if n is found continue to find all 'n' 
				if(arr[i] == n){
					continue;
				}
				else{
					new_arr[index++] = arr[i];
				}
		}
		delete[] arr;
		arr = new int[index];
			for(int j = 0; j < sz-1; j++){
					arr[j] = new_arr[j];
			}
			sz = index;
			delete[] new_arr;
	}
	//quest 14
int_vec(string fname): cap(100), arr(new int[cap]), sz(0) {
		int x;
		int index = 0;
		ifstream inFile;
		inFile.open(fname);
		//if file not found
		if(!inFile){
			cmpt::error("file not found");
		}
		while (inFile >> x){
			//if capacity is greater or equal to size x becomes arr[size] 
			if( sz <= cap){
				arr[sz] = x;
			}
			else if(sz < cap){
				//if capacity is greater creates a new underlying array with double capacity
				int* new_arr = new int[cap*2];
				for(int i = 0; i < sz; i++){
					new_arr[i] = arr[i];
				}
				delete[] arr;
				arr = new_arr;
			}
			//increments elements
			 sz++;
			 index++;
		}
		inFile.close();
}
	
}; // class int_vec


//ques12
bool operator==(const int_vec& a, const int_vec& b){
	if(a.size() != b.size()){
			return false;
		}else {
			for(int i = 0; i < a.size(); i++){
				if(a.get(i) != b.get(i)){
					return false;
				}
			}
			return true;
		}
	}
bool operator!=(const int_vec& a, const int_vec& b){
	if(a.size() != b.size()){
		return true;
	    }else {
			for(int i = 0; i < a.size(); i++){
				if(a.get(i) != b.get(i)){
					return true;
				}
			}
			return false;
		}
	}

// ...
