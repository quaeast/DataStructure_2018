//bjfu244
//
#include <iostream>

using namespace std;

typedef struct {
    double *data;
    int top;
}Stack;

void initStack(Stack &st){
    st.data=new double[200];
    st.top=-1;
}

void push(Stack &st, double n){
    st.top++;
    st.data[st.top]=n;
}

double top(Stack &st){
    return st.data[st.top];
}

double pop(Stack &st){
    st.top--;
    return st.data[st.top+1];
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

double Operate(double a, char o, double b){
    if (o=='+'){
        return a+b;
    } else if(o=='-'){
        return a-b;
    } else if(o=='*'){
        return a*b;
    } else{
        return a/b;
    }
}

double cal(){
    char c;
    cin>>c;
    if (c=='='){
        return 1;
    }
    Stack opnd;
    initStack(opnd);
    while (c!='='){
        if(c>='0'&&c<='9'){
            push(opnd, c-'0');
        } else{
            double b=pop(opnd);
            double a=pop(opnd);
            double res=Operate(a, c, b);
            push(opnd, res);
        }
        cin>>c;
    }
    printf("%.2lf\n",pop(opnd));
    return 0;
}

int main() {
    while (1){
        if(cal()==1){
            break;
        }
    }
    return 0;
}