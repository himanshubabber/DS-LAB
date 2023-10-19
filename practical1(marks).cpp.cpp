#include <bits/stdc++.h>
using namespace std;
int main(){
    int student ;
    cin>> student;
    vector<vector<int>> arr(student,vector<int> (5));
    for(int i =0;i<student ;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    float avg1=0,avg2=0,avg3=0,avg4=0,avg5=0;
    for(int i =0;i<student ;i++){
        int total=0;
        for(int j=0;j<5;j++){

            total+=arr[i][j];
        }
        cout<<"Total for "<< i+1<<" student is : "<<total<<"\n";
    }
    for(int i =0;i<student;i++){
        avg1+=arr[i][0];
        avg2+=arr[i][1];
        avg3+=arr[i][2];
        avg4+=arr[i][3];
        avg5+=arr[i][4];
        
    }
    cout<<"The averages for the 5 subjects are : \n";
    cout<<avg1/student<<" "<<avg2/student<<" "<<avg3/student<<" "<<avg4/student<<" "<<avg5/student<<" ";


    return 0;
}