//bjfu260
//
#include <iostream>
using namespace std;

int main() {
    while (1){
        int a,b;
        cin>>a>>b;
        if (a==0&&b==0){
            break;
        }
        int array[a][b];
        int *p=array[0];
        for (int i = 0; i < a*b; ++i) {
            cin>>*p;
            p++;
        }
        p=array[0];
        int flag=0;
        for (int i = 0; i < a*b; ++i) {
            if (flag==1){
                break;
            }
            int *q=p+1;
            for (int j = 0; j < a*b-i-1; ++j) {
                if(*p==*q){
                    flag=1;
                    break;
                }
                q++;
            }
        }
        if (flag){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
}