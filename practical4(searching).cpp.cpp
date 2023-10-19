#include<bits/stdc++.h>
using namespace std;

int linearSearch(int num, vector<int>& v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        if(v[i] == num){
            return i;
        }
    }
    return -1;
}

int binarySearch(int num, vector<int>& v){
    sort(begin(v), end(v));

    int l = 0, r = v.size() - 1;
    
    while(l <= r){
        int mid = l + (r - l)/2;
        if(v[mid] == num){
            return mid;
        }
        else if(v[mid] > num){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    } 
    return -1;
}

int main(){
    vector<int> v = {4,31,3,1,2};

    int num;
    cin>>num;

    int a = linearSearch(num, v);

    if(a != -1){
        cout<<"Element found at index : "<<a<<endl;
    }

    cout<<"Element absent";

    int b = binarySearch(num, v);

    if(b != -1){
        cout<<"Element found at index : "<<a<<endl;
    }

    cout<<"Element absent";

    return 0;
}