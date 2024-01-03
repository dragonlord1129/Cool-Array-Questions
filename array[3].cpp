// queries for the array stuff... this ain't much of cool work I just found this question laying of in the internet somewhere!!
/*
Input: Q[] = {4, 5} 
Output: 
288 
34560 
Query 1: 1! * 2! * 3! * 4! = 1 * 2 * 6 * 24 = 288 
Query 2: 1! * 2! * 3! * 4! * 5! = 1 * 2 * 6 * 24 * 120 = 34560
Input: Q[] = {500, 1000, 7890} 
Output: 
976141892 
560688561 
793351288 
*/
#include <iostream>
#include<vector>
using namespace std;

long factorial(int &n){
    int fact = 1;
    if (n<=1) return fact;
    else{
        for(int i=2; i<=n; i++){
            fact *=i;
        }
        return fact;        
    }
}


class factorial_array{
    private:
        vector<int> array_main;
        vector<long> array_required;
        long  result;
    public:
        void input();
        void calculation_of_factorial();
        void display();
};
void factorial_array::input(){
     char ch = 'y';
     int element;
        while (ch == 'y' || ch == 'Y') {
            cout << "Enter the element: ";
            cin>>element;        
            array_main.push_back(element);
            cout << "Add another element (y/n): ";
            cin >> ch;
    }
}

void factorial_array::calculation_of_factorial(){
    for(int num : array_main){
        result =1;
        for (int i = 1; i <= num; ++i) {
            result *= factorial(i);
        }
        array_required.push_back(result);
    }
}


void factorial_array::display(){
    for(long nums : array_required){
        cout<<nums<<" "<<endl;
    }
}

int main(){
    factorial_array array;
    array.input();
    array.calculation_of_factorial();
    array.display();
}
