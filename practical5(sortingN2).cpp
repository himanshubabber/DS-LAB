#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> v, int n){

    for(int i = 1; i < n -1 ; i++){
        for(int j = 0; j < n - i  - 1; j++){
            if(v[i] < v[j]){
                swap(v[i], v[j]);
            }
        }
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

void selectionSort(vector<int> v, int n){

    for(int i = 0; i < n - 1; i++){
        int mini = i;

        for(int j = i + 1; j < n; j++){
            if(v[j] < v[mini]){
                mini = j;
            }
        }
        swap(v[mini], v[i]);
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

void insertionSort(vector<int>& v, int n){

    for(int i = 0; i < n; i++){
        int ele = v[i];
        int j = i -1;
        
        while(j >= 0 && v[j] > ele){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ele;
    }

    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;    
}

int main(){
    vector<int> v = {5,4,3,2,1};

    //bubbleSort(v, 5);

    selectionSort(v, 5);

    //insertionSort(v, 5);

}