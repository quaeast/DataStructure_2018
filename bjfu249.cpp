//bjfu249
//
#include <iostream>
using namespace std;

int Ack(int m, int n){
    if(m==0){
        return n+1;
    } else if(m>0&&n==0){
        return Ack(m-1, 1);
    } else {
        return Ack(m-1, Ack(m, n-1));
    }
}


int main() {
    int a,b;
    while (cin>>a>>b){
        if (a==0&&b==0){
            break;
        }
        cout<<Ack(a, b)<<endl;
    }
    return 0;
}