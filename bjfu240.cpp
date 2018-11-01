#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct{
    double *data;
    int top;
}Stack;


void initStack(Stack &st){
    st.data=new double[300];
    st.top=-1;
}

void push(Stack &st, double a){
    st.top++;
    st.data[st.top]=a;
}

double pop(Stack &st){
    st.top--;
    return st.data[st.top+1];
}

double top(Stack &st){
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

double AToD(char *c){
    double res=0;
    int len=strlen(c);
    int g=0;
    int point;
    for (point = 0; point < len; ++point) {
        if(c[point]=='.'){
            break;
        }
    }
    for (int i = point-1; i >=0 ; --i) {
        res+=(c[i]-'0')*pow(10, point-i-1);
    }
    for (int i = point+1; i < len; ++i) {
        res+=(c[i]-'0')*pow(10, point-i);
    }
    return res;
}

double cal(){
    Stack optr,opnd;
    initStack(optr);
    initStack(opnd);
    push(optr, '=');
    char c;
    cin>>c;
    if(c=='='){
        return 1;
    }
    char num[100];
    int numPos=0;
    while (c!='='||optr.top!=-1){
        if((c>='0'&&c<='9')||c=='.'){
            num[numPos]=c;
            numPos++;
            num[numPos]=0;
        } else {
            if(numPos>0){
                numPos=0;
                float dn=AToD(num);
                num[0]=0;
                push(opnd, dn);
            }
            if(cmpOp(top(optr),c)==0){
                push(optr, c);
            } else if(cmpOp(top(optr), c)==2){
                pop(optr);
            } else if(cmpOp(top(optr), c)==1){
                double t=pop(opnd);
                double res=Operate(pop(opnd), pop(optr), t);
                push(opnd, res);
                if(cmpOp(top(optr), c)==2){
                    pop(optr);
                } else if(c!='='){
                    push(optr, c);
                }
            }
        }
        if(c!='='){
            cin>>c;
        }
    }
    double end=pop(opnd);
    printf("%.2lf\n",end);
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