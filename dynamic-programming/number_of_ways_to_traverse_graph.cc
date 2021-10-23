
/*

You are given two positive integers representing the width and height of a grid-shaped
rectangular graph. Write a function that returns the number of ways to reach the bottom
right corder of the graph when starting at the top left corner. Each move you must either
go down or right. You can never move up or left or diagnonally.

*/

using namespace std;

/// Recursive solution
// O(2^(n + m)) time, O(n + m) space
// (n, m) : width and height of graph
int numberOfWaysToTraverseGraphRecursive(int width, int height) {
  if (width == 1 || height == 1)
        return 1;
    int n1 = numberOfWaysToTraverseGraphRecursive(width - 1, height);
    int n2 = numberOfWaysToTraverseGraphRecursive(width, height  -1);
  return n1 + n2;
}

// Dynamic programming
// O(n * m) time, O(n * m) space
int numberOfWaysToTraverseGraphDP(int width, int height) {
    int num_ways[height + 1][width + 1];
    
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j <= width; j++) {
            num_ways[i][j] = 0;
        }
    }
    // Traverse through the graph and calculate distances
    for (int w = 1; w <= width; w++) {
        for (int h = 1; h <= height; h++) {
            if (w == 1 || h == 1) {
              num_ways[h][w] = 1;
            } else {
                int ways_left = num_ways[h][w - 1]; // ways to reach item on the left
                int ways_right = num_ways[h - 1][w]; // ways to reach item above
                num_ways[h][w] = ways_left + ways_right;
            }
        }
    }
  return num_ways[height][width];
}

int factorial(int num) {
    int fact = 1;
    for (int n = 2; n <= num; n++) {
        fact *= n;
    }
    return fact;
}

// Permutation formula
// O(n + m) time, O(1) space
int numberOfWaysToTraverseGraph(int width, int height) {
    int xDist = width - 1; // x Distance to the bottom right corner of graph
    int yDist = height - 1; // y Distance to the bottom right corner of graph
    
    /*
     * Total number ways to reach from top left to bottom right:
     * Permutations (with with non-distinct items) of Set S = {R, R, R, D, D}
     * n: Number of items in the set 'S' = 5
     * R: Move right, number of non-distinct R's = 3
     * D: Move down, number of non-distinct D's = 2
     * ways to arrange set 'S': n! / ((num_R)! x (num_D)!)
     */
    int numerator = factorial(xDist + yDist);
    int denominator = factorial(xDist) * factorial(yDist);
  return numerator / denominator;
}




