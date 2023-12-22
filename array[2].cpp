#include <iostream>
#include<vector>
using namespace std;

/* question 2:
Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
        query[] = [0, 4], [1, 3] [2, 4]
        Output: Sum of arr[] elements in range [0, 4] is 8
        Sum of arr[] elements in range [1, 3] is 4
        Sum of arr[] elements in range [2, 4] is 6
*/
class Solution
{
private:
    vector<int> array;
    vector<pair<int, int>> query_range;
    vector<int> result;

public:
    Solution()
    {
        cout << "your array is: {13,13, 12,12,5,5,5,12,13,13, 11, 9, 8, 7, 5, 5, 4, 3, 2, 1}" << endl; // you can input the array of your choice!!!
        array = {13, 13, 12, 12, 5, 5, 5, 12, 13, 13, 11, 9, 8, 7, 5, 5, 4, 3, 2, 1};
    }
    void input();
    void add_range();
    void display();
};
void Solution::input() {
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        cout << "Enter the range [start end]: ";
        int start, end;
        cin >> start >> end;
        query_range.emplace_back(start, end);
        cout << "Add another range (y/n): ";
        cin >> ch;
    }
}
void Solution::add_range() {
    for (pair<int, int> &range : query_range) {
        int temp = 0;
        for (int j = range.first; j <= range.second; j++) {
            temp += array[j];
        }
        result.push_back(temp);
    }
}

void Solution::display() {
    int i = 0;
    for (int &res : result) {
        cout << "The output of [" << query_range[i].first << ", " << query_range[i].second << "]: " << res << endl;
        i++;
    }
}

int main(){
    Solution s1;
    s1.input();
    s1.add_range();
    s1.display();

    return 0;
}