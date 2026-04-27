/*
Problem: Best Time to Buy and Sell Stock II
- Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Approach:
- Use a greedy strategy by summing all positive differences between consecutive days.
- This captures every upward price movement without explicitly tracking buy/sell points.

Time Complexity: O(n)
- Traverse the vector once

Space Complexity: O(1)
- Memory usage stays constant

Key Concepts:
- Greedy algorithm (capture all profitable upward movements)
- Array traversal with local comparisons

Edge Cases Considered:
- Empty or single-element array (no transactions possible)
- Strictly decreasing prices (profit = 0)
- Constant prices (no gain opportunities)

Real-World Relevance:
- Models decision-making in financial systems where multiple trades are allowed
- Similar patterns appear in:
     - Signal processing (capturing positive deltas in time-series data)
     - Resource optimization (accumulating incremental gains)
     - Event-driven systems where small profitable actions are aggregated over time
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size() <= 1)
            return 0;
            
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }

        return profit;
    }
};
