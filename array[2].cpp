#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> freqPairs;
    vector <int> nums;
    int k;
    
public:
    void input(){
        nums = {13,13, 12,12,5,5,5,12,13,13, 11, 9, 8, 7, 5, 5, 4, 3, 2, 1};
        cout<<"The array is: "<<"{13,13, 12,12,5,5,5,12,13,13, 11, 9, 8, 7, 5, 5, 4, 3, 2, 1}"<<endl;
        cout<<"K: ";
        cin >>k;
    }
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high) {
        int leftLength = mid - low + 1;
        int rightLength = high - mid;

        vector<pair<int, int>> left(leftLength);
        vector<pair<int, int>> right(rightLength);

        for (int i = 0; i < leftLength; ++i) {
            left[i] = arr[low + i];
        }
        for (int j = 0; j < rightLength; ++j) {
            right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = low;
        while (i < leftLength && j < rightLength) {
            if (left[i].second > right[j].second || (left[i].second == right[j].second && left[i].first > right[j].first)) {
                arr[k] = left[i];
                ++i;
            } else {
                arr[k] = right[j];
                ++j;
            }
            ++k;
        }

        while (i < leftLength) {
            arr[k] = left[i];
            ++i;
            ++k;
        }

        while (j < rightLength) {
            arr[k] = right[j];
            ++j;
            ++k;
        }
    }

    void mergeSort(vector<pair<int, int>>& arr, int low, int high) {
        if (low < high) {
            int mid = low + (high - low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    void countFrequency(const vector<int>& nums) {
    for (int num : nums) {
        int index = -1;
        for (int i = 0; i < freqPairs.size(); ++i) {
            if (freqPairs[i].first == num) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            freqPairs[index].second++;
        } else {
            freqPairs.push_back({num, 1});
        }
    }
}


    void topKFrequentNumbers(int K) {
        mergeSort(freqPairs, 0, freqPairs.size() - 1);

        cout << "Top " << K << " numbers with most occurrences:\n";
        for (int i = 0; i < K; ++i) {
            cout << freqPairs[i].first <<" ";
            // " (Frequency: " << freqPairs[i].second << ")\n";
        }
    }
    void solution(){
    input();
    countFrequency(nums);
    topKFrequentNumbers(k);
    }
};

int main() {
    Solution s;
    s.solution();

    return 0;
}
