#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Result{
    int tsize;
    int usize;
    int * ptr;
    public:
    Result(int a , int b , int * ptr){
        tsize = a;
        usize = b;
        this->ptr = ptr;
        search();
    }
    void search(){
        // cin>>tsize>>usize;
        for(int i = 0 ; i<usize ; i++){
            cin>>(*(ptr+i));
        }
        show();
    }
    void show(){
        cout<<"The array is : ";
        for(int i = 0 ; i<usize ; i++){
            cout<<(*(ptr+i))<<" ";
        }
        cout<<endl;
        minimum();
    }
    void minimum(){
        cout<<"The minimum element in the array is : " <<(*min_element(ptr , ptr+usize))<<endl;
        maximum();
    }
    void maximum(){
        cout<<"And the maximum element in the array is : "<<*max_element(ptr , ptr+usize)<<endl;
    }
};

int main(){
    int arr[100];
    Result a(100 , 5  , arr);
    return 0;
}