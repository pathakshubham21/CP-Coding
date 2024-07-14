// Problem statement
// You are given a positive integer ‘N’. Your task is to find and return its square root. If ‘N’ is not a perfect square, then return the floor value of sqrt(N).



// Note:
// In case, if you are facing the test case failure, take the variables inside the function in 'unsigned int' data type.
// Example:
// Input: ‘N’ = 6

// Output: 2

// Explanation: The square root of the number 6 lies between 2 and 3, so the floor value is 2.


long long int floorSqrt(long long int N)
{
    // Write your code here.

    if (N == 0 || N == 1) return N;

    unsigned long long start = 1, end = N, result = 0;

    while (start <= end) {
        unsigned long long mid = (start + end) / 2;

        // Check if mid*mid == N
        if (mid * mid == N)
            return mid;
        
        // If mid*mid < N, discard the left search space
        if (mid * mid < N) {
            start = mid + 1;
            result = mid;
        } else {
            // If mid*mid > N, discard the right search space
            end = mid - 1;
        }
    }

    return result;
}