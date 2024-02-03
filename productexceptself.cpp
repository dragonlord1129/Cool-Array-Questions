/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0] */
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
        vector<int> array;
    public:
        Solution(){
            array = {1,2,3,5,4,6}; // can be anything try another dataset from examples for test as well
        }
        void product();
        void display();
};
int product_of_elements(vector<int> &array){ 
    int product =1;
    for(int i : array){
        product = product*i;
    }
    return product;
}
int product_of_elements1(vector<int> &array){
    int product =1;
    for(int i : array){
        if(i != 0) product = product*i;
        else i++;
    }
    return product;
}
void Solution::product(){
    int product_value = product_of_elements(array);
    int product_value_without_zero = product_of_elements1(array);
    for(int i =0; i<array.size(); i++){
        if (array[i] != 0){
            array[i] = product_value/array[i];
        }
        else {
            array[i] = product_value_without_zero;
        }
    }
}
void Solution::display(){
    for(int i=0; i<array.size(); i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    Solution s1;
    s1.display(); //prints the current array
    s1.product();
    s1.display(); // prints the array of product of elements except self
}
