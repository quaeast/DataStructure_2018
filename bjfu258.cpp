//bjfu258
//
#include <iostream>
#include <cstring>
using namespace std;

void reverse(char *str, int m, int n){
    if(m+1>=n){
        return;
    }
    char t;
    t = str[m];
    str[m]=str[n-1];
    str[n-1]=t;
    reverse(str, m+1, n-1);
}

int main() {
    while (1){
        char str[300];
        cin>>str;
        if (str[0]=='0'&&strlen(str)==1){
            break;
        }
        reverse(str, 0, strlen(str));
        cout<<str<<endl;
    }
    return 0;
}