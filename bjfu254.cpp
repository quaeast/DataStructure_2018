//bjfu254
//
#include <sstream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct{
    int *data;
    int top;
}Stack;


void initStack(Stack &st){
    st.data=new int[300];
    st.top=-1;
}

void push(Stack &st, int a){
    st.top++;
    st.data[st.top]=a;
}

int pop(Stack &st){
    st.top--;
    return st.data[st.top+1];
}

int top(Stack &st){
    return st.data[st.top];
}

void clear(Stack &st){
    st.top=-1;
}

int trans(char op){
    if (op=='+'){
        return 0;
    } else if(op=='-'){
        return 1;
    } else if(op=='*'){
        return 2;
    } else if(op=='/'){
        return 3;
    } else if(op=='('){
        return 4;
    } else if(op==')'){
        return 5;
    } else{
        return 6;
    }
}

int cmpOp(char a, char b){ // = 2,X -1
    int cmp[7][7]={
            {1,1,0,0,0,1,1},
            {1,1,0,0,0,1,1},
            {1,1,1,1,0,1,1},
            {1,1,1,1,0,1,1},
            {0,0,0,0,0,2,-1},
            {1,1,1,1,-1,1,1},
            {0,0,0,0,0,-1,2}
    };
    return cmp[trans(a)][trans(b)];
}


double cal(){
    Stack optr;
    initStack(optr);
    push(optr, '=');
    char c;
    cin>>c;
    if(c=='='){
        return 1;
    }
    char res[100];
    int front=0;
    while (c!='='||optr.top!=-1){
        if(c>='0'&&c<='9'){
            res[front]=c;
            front++;
        }else if(cmpOp(top(optr),c)==2){
            pop(optr);
        } else if(cmpOp(top(optr),c)==0){
            push(optr, c);
        } else if(cmpOp(top(optr),c)==1){
            res[front]=pop(optr);
            front++;
            continue;
        }
        if(c!='='){
            cin>>c;
        }
    }
    res[front]=0;
    cout<<res<<endl;
    return 0;
}

int main() {
    while (1){
        double t=cal();
        if (t==1){
            break;
        }
    }
    return 0;
}