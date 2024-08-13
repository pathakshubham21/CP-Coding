// Problem statement
// Given k no. of different size arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

// Hint : Use Heaps.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 0 <= k <= 1000
// 0 <= n1, n2 <= 10000
// Time Limit: 1 second
// Sample Input 1:
// 4
// 3
// 1 5 9
// 2
// 45 90
// 5
// 2 6 78 100 234
// 1
// 0
// Sample Output 1:
// 0 1 2 5 6 9 45 78 90 100 234

#include <vector>
#include <queue>
#include <tuple> // For using std::tuple
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int> result;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
    
    // Insert the first element of each array into the min heap
    for (int i = 0; i < input.size(); i++) {
        if (!input[i]->empty()) {
            minHeap.push(make_tuple((*input[i])[0], i, 0));
        }
    }

    while (!minHeap.empty()) {
        // Extract the smallest element from the heap
        auto current = minHeap.top();
        minHeap.pop();

        int value = get<0>(current);
        int arrayIndex = get<1>(current);
        int elementIndex = get<2>(current);

        // Add the smallest element to the result array
        result.push_back(value);

        // If there's another element in the same array, add it to the heap
        if (elementIndex + 1 < input[arrayIndex]->size()) {
            minHeap.push(make_tuple((*input[arrayIndex])[elementIndex + 1], arrayIndex, elementIndex + 1));
        }
    }

    return result;
}
