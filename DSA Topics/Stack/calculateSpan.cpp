// Problem statement
// Amit has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.

// The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.

// For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

// Explanation:
// On the sixth day when the price of the stock was 75, the span came out to be 4, because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

// Similarly, we can deduce the remaining results.
// Amit has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 0 <= N <= 10^7
// 1 <= X <= 10^9
// Where X denotes the stock's price for a day.

// Time Limit: 1 second
// Sample Input 1:
// 4
// 10 10 10 10
// Sample Output 1:
// 1 1 1 1 
// Sample Input 2:
// 8
// 60 70 80 100 90 75 80 120
// Sample Output 2:
// 1 2 3 4 1 1 2 8 






// void calculateSpan(int prices[], int n, int spans[]) {
//     //Write your code here
//     if(n==1)
//     {
//         spans[0] = 1;
//         return;
//     }

//     spans[0] = 1;

//     for(int i=1;i<n;i++)
//     {
//         int count = 0;
//        for(int j=0;j<i;j++)
//        {
//            if(prices[j]<prices[i])
//            {
//                count++;
//            }
//            else{
//                count = 0;
//            }
//        }
//        spans[i]= count+1;

//     }

// }

void calculateSpan(int prices[], int n, int spans[]) {
    stack<int> s;  // Stack to store indices of prices array

    // The span of the first day is always 1
    spans[0] = 1;
    s.push(0);

    for (int i = 1; i < n; i++) {
        // Pop elements from stack while stack is not empty and
        // the price at the top of stack is less than or equal to current price
        while (!s.empty() && prices[s.top()] < prices[i]) {
            s.pop();
        }

        // If stack becomes empty, then price[i] is greater than all elements on left of it
        // i.e., the span is i+1
        spans[i] = (s.empty()) ? (i + 1) : (i - s.top());

        // Push this element to stack
        s.push(i);
    }
}