#include <iostream>
#include<cmath>
#include<bits/stdc++>
using namespace std;

int max(int a, int b){
        return (a>b)?a:b;
    }
int maxprof(int arr[], int start, int end)
    {   int profit=0;
        if(start >= end) return 0;
        for(int i=start; i<end; i++){
            for(int j=i+1; j<=end; j++){
                if(arr[j] > arr[i]){
                    int c_profit=(arr[j]-arr[i]
                                 + maxprof(arr, start, i-1)
                                 + maxprof(arr, j+1, end));
                    profit = max(profit, c_profit);
                }
                
            }
        }
        return profit;
    }
int main()
{
    int arr[] = {7,1,5,3,6,4};
    int p = maxprof(arr, 0, 5);
    cout<<"profit: "<<p;

    return 0;
}