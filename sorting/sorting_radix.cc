#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

int mypow(int base, int exponent) {
    int result = 1;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
   return result;
}

// Count sort the array at digit 'digit'
void countingSort(vector<int> &array, int digit) {
    vector<int> sortedArray(array.size(), 0);
    // Has number of elements equal to the base (here it is 10)
    vector<int> countArray(10, 0);
	// value to divide the number by, to get the digit
	int digitColumn = mypow(10, digit);
	
	for (auto num : array) {
		// extract digit at digitColumn
		int countIndex = num / digitColumn % 10;
		countArray[countIndex]++;
	}
	
	// loop through count array and modify values
	for (int i = 1; i < countArray.size(); i++) {
		countArray[i] += countArray[i  - 1];
	}
	
	// insert values to sorted array from the end to maintain stable property
	for (int i = sortedArray.size() - 1; i >= 0 ; i--) {
		int countIndex = array[i] / digitColumn % 10;
		countArray[countIndex]--;
		int sortedIndex = countArray[countIndex];
		sortedArray[sortedIndex] = array[i];
	}
	// copy result back to original array
	for(int i = 0; i < array.size(); i++) {
		array[i] = sortedArray[i];
	}
	
}


// O(d * (n + b) time | O(n + b) space
// b: base (10)
void radixSort(vector<int>& array) {
    if (array.size() <= 1)
        return;
    int maxNumber = *max_element(array.begin(), array.end());

    int digit = 0; // least significant
    while (maxNumber / mypow(10, digit) > 0) {
        countingSort(array, digit);
	digit++;
    }
    return;
}

int main()
{
    // This algorith work only with +ve numbers
    vector<int> array = {8762, 654, 3008, 345, 87, 65, 234, 12, 2};
    print(array);
    radixSort(array);
    print(array);
    return 0;
}
