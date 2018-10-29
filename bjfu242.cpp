//bjfu242
//
#include <iostream>
#include <cstring>
using namespace std;

const int maxSize=300;

typedef struct Stack{
    int *data;
    int top;
}Stack;

void initStack(Stack &st, int n){
    st.data=new int[n];
    st.top=-1;
}

void push(Stack &st, int n){
    st.top++;
    st.data[st.top]=n;
}

int top(Stack &st){
    return st.data[st.top];
}

int pop(Stack &st){
    --st.top;
    return st.data[st.top+1];
}

bool isReverse(char *c){
    Stack st;
    initStack(st ,maxSize);
    int len=strlen(c);
    for (int i = 0; i < len/2; ++i) {
        push(st, c[i]);
    }
    int flag=1;
    for (int i = len/2+len%2; i < len; ++i) {
        if(c[i]!=pop(st)){
            flag=0;
            break;
        }
    }
    return flag;
}

int main() {
    char c[300];
    while (1){
        cin>>c;
        if(c[0]=='0'&&c[1]==0){
            break;
        }
        if(isReverse(c)){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}