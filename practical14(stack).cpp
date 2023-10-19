#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:

    int size;
    int top;
    int *arr;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int a){
        if(size - top > 1){
            top ++;
            arr[top] = a;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }

    int Top(){
        if(top >= 0){
            return arr[top];
        }
        else{
            return -1;
        }
    }

    bool empty(){
        if(top >= 0){
            return false;
        }
        else return true;
    }

    
    ~Stack() {
        delete[] arr;
    }

};

int main(){

    Stack st(5);

    st.push(2);
    st.push(3);
    st.push(4);
    int x = st.Top();
    cout<<x<<endl;
    st.pop();
    st.push(5);
    st.push(5);
    int y = st.Top();
    cout<<y<<endl;
    st.push(5);
    st.push(5);

    return 0;
} 