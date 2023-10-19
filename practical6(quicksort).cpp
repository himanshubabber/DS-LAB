#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int low, int high){
    int pivot = v[0];

    int i = low, j = high;

    while(i < j){
        while(v[i] <= pivot && i <= high -1){
            i++;
        }

        while(v[j] > pivot && j >= low + 1){
            j--;
        }

        if(i < j) swap(v[i], v[j]);
    }
    
    swap(v[low], v[j]);

    return j;
}

void quicksort(vector<int>& v, int low, int high){
    if(low < high){
        int partitionIdx = partition(v, low, high);

        quicksort(v, low, partitionIdx - 1);
        quicksort(v, partitionIdx + 1, high);
    }
}

void print(vector<int>& v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> v = {5,4,2,1,1};

    quicksort(v, 0, 4);

    print(v);

    return 0;
}