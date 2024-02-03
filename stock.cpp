/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0. */
#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;


class Solution {
private:
    int least_present_value;
    int profit_if_sold_today;
    int overall_profit;
    vector<int> prices;

public:
    Solution() {
        prices = {7, 1, 5, 3, 6, 4}; // can be initialized to literally anything else as per choice
        least_present_value = INT_MAX;
        profit_if_sold_today = 0;
        overall_profit = 0;
    }
    void calculation();
    void display();
};

void Solution::calculation() {
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < least_present_value) {
            least_present_value = prices[i];
        }
        profit_if_sold_today = prices[i] - least_present_value;
        if (profit_if_sold_today > overall_profit) {
            overall_profit = profit_if_sold_today;
        }
    }
    cout << "The maximum profit made is: " << overall_profit << endl;
}

int main() {
    Solution s1;
    s1.calculation();
    return 0;
}
