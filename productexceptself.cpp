#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
        vector<int> array;
    public:
        Solution(){
            array = {1,2,3,5,4,6}; // can be anything
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
void Solution::product(){
    int product_value = product_of_elements(array);
    for(int i =0; i<array.size(); i++){
        array[i] = product_value/array[i];
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
    s1.display();
    s1.product();
    s1.display();
}