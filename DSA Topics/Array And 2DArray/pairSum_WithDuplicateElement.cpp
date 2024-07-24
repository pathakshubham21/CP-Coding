// Problem statement
// You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

// Note:
// Given array/list can contain duplicate elements. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^4
// 0 <= num <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 9
// 1 3 6 2 5 4 3 2 4
// 7
// Sample Output 1:
// 7
// Sample Input 2:
// 2
// 9
// 1 3 6 2 5 4 3 2 4
// 12
// 6
// 2 8 10 5 -2 5
// 10
// Sample Output 2:
// 0
// 2


//  Explanation for Input 2:
// Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

// For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).



#include <algorithm>
int pairSum(int *A, int size, int K)
{
    // Sort the array
    sort(A, A + size);

    int i = 0;
    int j = size - 1;
    int count = 0;

    while (i < j)
    {
        int sum = A[i] + A[j];

        if (sum < K)
        {
            i++;
        }
        else if (sum > K)
        {
            j--;
        }
        else
        {
            // When sum == K
            if (A[i] == A[j])
            {
                // If elements are the same, we count the number of pairs (i, j) within the range
                int num_elements = j - i + 1;
                count += (num_elements * (num_elements - 1)) / 2;
                return count;
            }
            else
            {
                int left_count = 1;
                int right_count = 1;

                // Count duplicates of A[i]
                while (i + 1 < j && A[i] == A[i + 1])
                {
                    i++;
                    left_count++;
                }

                // Count duplicates of A[j]
                while (j - 1 > i && A[j] == A[j - 1])
                {
                    j--;
                    right_count++;
                }

                count += left_count * right_count;
                i++;
                j--;
            }
        }
    }

    return count;
}
