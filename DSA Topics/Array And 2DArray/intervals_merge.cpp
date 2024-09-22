// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104


class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    stack<pair<int, int>> s;
    vector<vector<int>> result;

    s.push({intervals[0][0], intervals[0][1]});

    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        int start_top = s.top().first;
        int end_top = s.top().second;

        if (start <= end_top) {
            s.pop();
            s.push({min(start, start_top), max(end, end_top)});
        } else {
            
            s.push({start, end});
        }
    }

    while (!s.empty()) {
        result.push_back({s.top().first, s.top().second});
        s.pop();
    }

    return result;
}
};