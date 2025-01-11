/*
Write a function that takes in an n x m 2D array that can be square
shaped when n == m and returns a one dimentional array of all the
array's elements in spiral order.

Spiral order starts at the top left corner of the 2D array, goes to
the right, and proceeds in a spiral pattern all the way until every
element has been visited.

Sample input:

array = [
 [1,   2,  3, 4],
 [12, 13, 15, 5],
 [11, 16, 15, 6],
 [10,  9,  8, 7],
]

Sample output:

[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]


*/

using namespace std;


vector<int> spiralTraverse(vector<vector<int>> a) {
  // Write your code here.
    vector<int> b;
    int row_s = 0, col_s = 0;
    int row_e = a.size() - 1;
    int col_e = a[0].size() - 1;
    
    while(row_s <= row_e && col_s <= col_e) {
        for (int c = col_s; c <= col_e && row_s <= row_e; c++)
            b.push_back(a[row_s][c]);
        row_s++;
        
        for (int r = row_s; r <= row_e && col_s <= col_e; r++)
            b.push_back(a[r][col_e]);
        col_e--;
        
        for (int c = col_e; c >= col_s && row_s <= row_e; c--)
            b.push_back(a[row_e][c]);
        row_e--;
        
        for (int r = row_e; r >= row_s && col_s <= col_e; r--)
            b.push_back(a[r][col_s]);
        col_s++;
    }
  return b;
}


