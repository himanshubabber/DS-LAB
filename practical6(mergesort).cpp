#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int low, int mid, int high){

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){
        if(v[left] <= v[right]){
            temp.push_back(v[left++]);
        }
        else{
            temp.push_back(v[right++]);
        }
    }

    while(left <= mid) temp.push_back(v[left++]);

    while(right <= high) temp.push_back(v[right++]);

    for(int i = low; i <= high; i++){
        v[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& v, int l, int r){
    if(l == r){
        return;
    }

    int mid = l + (r - l)/2;

    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, mid, r);
}

void print(vector<int>& v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> v = {5,4,2,1,1};

    mergeSort(v, 0, 4);

    print(v);
}