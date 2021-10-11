#include <vector>
#include <iostream>
using namespace std;

/*
Given is a non-empty array of positive integers representing the amount
of time that specific queries take to execute. Only one query can be
executed at a time, but the queries can be executed in any order.

A query's waiting time is defined as the amount of time that it must
wait before its execution.

Write a function that returns the minimum amount of total waiting time
for all of the queries.
*/

int minimumWaitingTime(vector<int> queries) {
    int sum = 0;
    int n = queries.size();
    for (int i = 0; i < queries.size() -1 ; i++) {
        sum += (n - i - 1) * queries[i];
    }
  return sum;
}

int main() {
  vector<int> v = {3, 2, 1, 2, 6};
  int s = minimumWaitingTime(v);
  cout << "sum = " << s << endl;
}
