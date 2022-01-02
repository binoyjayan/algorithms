
#include <vector>
using namespace std;

void permutationsHelper(int i, vector<int> &a, vector<vector<int>> &perms) {
    // base case - when i reaches end of list, add snapshot of current array to the output
    if (i == a.size() - 1) {
        perms.push_back(a);
        return;
    }
    
    for (int j = i; j < a.size(); j++) {
        swap(a[i], a[j]);
        permutationsHelper(i + 1, a, perms);
        swap(a[i], a[j]);
    }
}

// O(n * n!) time | O(n * n!) space
vector<vector<int>> getPermutations(vector<int> array) {
    vector<vector<int>> perms;
  permutationsHelper(0, array, perms);
  return perms;
}

