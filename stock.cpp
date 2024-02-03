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
