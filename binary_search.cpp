/*
Implementation of a binary search algorithm by Carson Hanel
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <math.h>

int count = 0;

using namespace std;

bool check_sorted(const vector<int>& vec){
	bool asc = (vec.at(0) < vec.at(1)); //true if ascending
	if(asc){
		for(int i = 0; i < vec.size() - 1; i++){
			if(!(vec.at(i + 1) > vec.at(i))){
				throw runtime_error("Vector is unsorted!"); //Auto-throws exception that propogates back to main
			}
		}
		return true; //Returns true, the vector is sorted ascending
	}else{
		for(int i = 0; i < vec.size() - 1; i++){
			if(!(vec.at(i + 1) < vec.at(i))){
				throw runtime_error("Vector is unsorted!"); //Auto-throws exception that propogates back to main
			}
		}
		return false; //Returns false, the vector is sorted descending
	}
}

int binary_search(const vector<int>& vec, const int val, int low, int high, bool asc){
	int mid, temp;
	
	if(asc){ //Only runs if the function check_asc returns TRUE, or rather ascending.
		if(/*count++,*/ low > high){ //I chose not to count non-ley comparisons. I can change this if necessary.
			cout << "It took " << count << " steps to NOT find " << val << endl;
			count = 0;
			throw runtime_error("The sought value doesn't exist.");
		}
		else{
			mid = (low + high) / 2;
			temp = vec.at(mid);
			if(count++, temp == val){
				cout << "It took " << count << " steps to find " << temp << endl;
				cout << "It should've taken " << abs(2 * floor(log2(val)) - 1)<< " iterations." << endl << endl;
				count =   0;
				return temp;
			}
			else if(count++, temp < val){
				return binary_search(vec, val, ++mid, high, asc);
			}
			else{
				return binary_search(vec, val, low, --mid, asc);
			}
		}
	}
	else{ //Only runs if the function check_asc returns FALSE, or rather descending.
		if(/*count++,*/ low > high){ //I chose not to count non-key comparisons. I can change this if necessary.
			cout << "It took " << count << " steps to NOT find " << val << endl;
			count = 0;
			throw runtime_error("The sought value doesn't exist.");
		}
		else{
			mid = (low + high) / 2;
			temp = vec.at(mid);
			if(count++, temp == val){
				cout << "It took " << count << " steps to find " << temp << endl;
				cout << "It should've taken " << abs(2 * floor(log2(val)) - 1)<< " iterations." << endl << endl;
				count =   0;
				return temp;
			}
			else if(count++, temp < val){
				return binary_search(vec, val, low, --mid, asc);
			}
			else{
				return binary_search(vec, val, ++mid, high, asc);
			}
		
		}
	}
}
int main(){
	vector<int> v;
	vector<int> v1;
	
	for(int i = 1; i < 2049; i++){
		v.push_back(i);
	}
	for(int i = 2048; i > 0; i--){
		v1.push_back(i);
	}

	try{
		bool asc = true;
		int loc;
		cout << "Ascending searches: " << endl << "(Note, using abs(2 * floor(log2(val)) - 1) to compute runtime)" << endl;
		
		for(int i = 1; i < 2049; i *= 2){
			loc = binary_search(v, v.at(i - 1) , 0, i, asc);
		}
		asc = false;
		cout << "Descending searches: " << endl << "(Note, using abs(2 * floor(log2(val)) - 1) to compute runtime)" << endl;
		for(int i = 1; i < 2049; i*=2){
			loc = binary_search(v1 , v1.at(v1.size() - i ), v1.size() - i, v1.size() - 1, asc);
		}
	}
	catch(const runtime_error &e){
		cout << e.what() << endl;
	}
	system("PAUSE");
}

