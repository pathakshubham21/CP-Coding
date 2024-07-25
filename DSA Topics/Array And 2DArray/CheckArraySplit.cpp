#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int>& vec, int csum, int sum, int size) {
    if (size == 0) {
        return false;
    }

    if ((csum * 2) == sum) {
        return true;
    }

    bool includeCurrent = check(vec, csum + vec[size - 1], sum, size - 1);
    bool excludeCurrent = check(vec, csum, sum, size - 1);
    
    return includeCurrent || excludeCurrent;
}

int main() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    // vec.push_back(4);
    // Initialize the vector with elements
    int totalSum = 0;

    // Calculate the total sum of elements in the vector
    for (int val : vec) {
        totalSum += val;
    }

    // Call the check function
    cout << check(vec, 0, totalSum, vec.size());
    return 0;
}
