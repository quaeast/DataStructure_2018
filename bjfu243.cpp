//bjfu243
//
#include <iostream>
using namespace std;

const int MaxSize=200;

typedef struct Stack{
    int *data;
    int top;
};

void initStack(Stack &st, int n){
    st.data = new int[n];
    st.top=-1;
}

bool isEmpty(Stack &st){
    if(st.top==-1){
        return 1;
    }
    return 0;
}

void push(Stack &st,int n){
    ++st.top;
    st.data[st.top]=n;
}

int top(Stack &st){
    return st.data[st.top];
}

int pop(Stack &st){
    --st.top;
    return st.data[st.top+1];
}

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        int t[100];
        for (int i = 0; i < n; ++i) {
            cin>>t[i];
        }
        Stack st;
        initStack(st, MaxSize);
        for (int i = 0; i < n; ++i) {
            if(t[i]==-1){
                if(isEmpty(st)){
                    cout<<"POP ERROR"<<endl;
                    break;
                } else{
                    cout<<pop(st)<<endl;
                }
            } else{
                push(st, t[i]);
            }
        }
    }
    return 0;
}