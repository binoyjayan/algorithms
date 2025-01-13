
/*

Write a function that takes in a non-empty array of arbitrary intervals,
merges any overlapping intervals, and returns the new intervals in no
particular order.

Each interval is an array of two integers, with interval[0] as the start
of the interval and interval[1] as the end of the interval.

Sample input:

[[1, 2], [3,5], [4, 7], 6, 8], [9, 10]]

Sample output:

[[1,2,], [3, 8], [9, 10]]

*/

#include <vector>
#include <iomanip>
#include <iostream>

void print_intervals(const std::string& s, const std::vector<std::vector<int>>& vec_of_vecs) {
    std::cout << s << " [";
    for (size_t i = 0; i < vec_of_vecs.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < vec_of_vecs[i].size(); ++j) {
            std::cout << std::setw(2) << vec_of_vecs[i][j];
            if (j < vec_of_vecs[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < vec_of_vecs.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

std::vector<std::vector<int>> mergeOverlappingIntervals(std::vector<std::vector<int>> intervals) {
    std::vector<std::vector<int>> merged;
    std::vector<std::vector<int>> sorted = intervals;
    std::sort(sorted.begin(), sorted.end(), [](std::vector<int> a, std::vector<int> b) {
            return a[0] < b[0];
    });
    
    int n = 0;
    merged.push_back(sorted[0]);
    for (int i = 1; i < sorted.size(); i++) {
        std::vector<int> interval = sorted[i];
        if (merged[n][1] >= interval[0]) {
            merged[n][1] = std::max(merged[n][1], interval[1]);
        } else {
            merged.push_back(interval);
            n++;
        }
    }
    return merged;
}

int main() {
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    print_intervals("Overlapping Intervals", intervals);
    auto merged = mergeOverlappingIntervals(intervals);
    print_intervals("Merged Intervals     ", merged);
    return 0;
}
