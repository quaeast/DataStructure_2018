//bjfu241
//
#include <iostream>
using namespace std;

const int MaxSize=200;

typedef struct {
    int top[2],bot[2];
    int *v;
    int m;
}DblStack;

void initDS(DblStack &st, int n){
    st.v=new int[n];
    st.bot[0]=-1;
    st.bot[1]=n;
    st.top[0]=-1;
    st.top[1]=n;
}

void push(DblStack &st, int select,int n) {
    st.top[select]++;
    st.v[st.top[select]]=n;
}

int pop(DblStack &st,int select){
    st.top[select]--;
    return st.v[st.top[select]+1];
}

int notEmpty(DblStack &st, int select){
    return st.bot[select]!=st.top[select];
}

int main() {
    while (1){
        DblStack st;
        initDS(st, MaxSize);
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        int s0,s1,o0,o1;
        cin>>s0>>s1>>o0>>o1;
        if(s0+s1==n){
            cout<<1<<endl;
        } else{
            cout<<0<<endl;
        }
        for (int i = 0; i < s0; ++i) {
            int temp;
            cin>>temp;
            push(st, 0, temp);
        }
        for (int i = 0; i < s1; ++i) {
            int temp;
            cin>>temp;
            push(st, 1, temp);
        }
        for (int i = 0; i < o0; ++i) {
            cout<<pop(st, 0)<<' ';
        }
        cout<<notEmpty(st, 0)<<endl;
        for (int i = 0; i < o1; ++i) {
            cout<<pop(st, 1)<<' ';
        }
        cout<<notEmpty(st, 1)<<endl;
    }
    return 0;
}