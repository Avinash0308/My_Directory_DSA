#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void linear(int number , int arr[] , int size){
    int flag = 1;
    for(int i = 0; i<size; i++){
        if(arr[i] == number){
            cout<<"Given number is present at index number : "<<i<<endl;
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"Given number is not present in given array"<<endl;
    }
}
void binary(int number , int arr[] , int size){
    int high = size-1;
    int low = 0;
    while(low<=high){
        int mid = (high + low + 1)/2;
        if(number > arr[high] || number<arr[low]){
            cout<<"Given number is not present in given array"<<endl;
            break;
        }
        if(number == arr[mid]){
            cout<<"Given number is present at index number : "<<mid<<endl;
            break; 
        }
        if(number>arr[mid]){
            low = mid+1;
        }
        if(number<arr[mid]){
            high = mid-1;
        }  
    }

}
int main(){
    int arr[10] = {12,14,23,34,45,56,78,89,90,100};
    int number;
    cout<<"Please input the number to be searched : ";
    cin>>number;
    linear(number,arr,10);
    binary(number,arr,10);
return 0;
}