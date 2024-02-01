//2 sum and three sum combined; the choice of array and the choice of target values can be given as per wish
#include <iostream>
#include <vector>
using namespace std;

class three_number_sum{
private:
    int i, j, k;
    int target, sum, count;
    vector<int> arr;

public:
    void input(){
        cout << "Target=" << endl;
        cin >> target;
        arr = {3, 7, 9, 8, 6, 5, 4}; // can be added manually as well
    }
    void Solution();
    void display(){
        cout << "Pairs "<< "(" << arr[i] << "," << arr[j] << ")" << endl;
    }
    void displayTriplet(){
        cout << "Pairs "<< "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
    }
};
void three_number_sum::Solution(){
    sum = 0;
    count = 0;
    for (int a = 0; a < arr.size() - 2; a++){
        for (int b = a + 1; b < arr.size() - 1; b++)
        {
            sum = arr[a] + arr[b];
            if (sum == target && arr[a] != arr[b]){
                i = a;
                j = b;
                count++;                
                display();
            }
            else{
                sum = 0;
                for (int c = b + 1; c < arr.size(); c++){
                    sum = arr[a] + arr[b] + arr[c];
                    if (sum == target && arr[a] != arr[b] && arr[b] != arr[c]){
                        i = a;
                        j = b;
                        k = c;
                        count++;                        
                        displayTriplet();
                    }
                }
            }
        }
    }
    if (count == 0){
        cout << "no pair" << endl;
    }
}
int main(){
    three_number_sum a;
    a.input();
    a.Solution();

    return 0;
}
