// queries for the range stuff
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
    if (n==0) return fact;
    else{
        while(n!=0){
            fact *=n;
            n--;
        }
        return fact;
    }
}

class factorial_array{
    private:
        vector<int> array_main;
        vector<int> array_required;
    public:
        void input();
        void calculation_of_factorial();
        void display();
};
void factorial_array::input(){
    array_main =  {9, 8, 7, 5, 5, 4, 3, 2, 1};
}

void factorial_array::calculation_of_factorial(){
    for(int num : array_main){
        array_required.push_back(factorial(num));
    }
}
void factorial_array::display(){
    for(int i=0; i<array_main.size(); ++i){
        cout<<array_required[i]<<" "<<endl;
    }
}
int main(){
    factorial_array array;
    array.input();array.calculation_of_factorial();
    array.display();
}
