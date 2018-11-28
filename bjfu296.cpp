//bjfu296
//
#include <iostream>
using namespace std;

void stone_sort(char *stone, int len){
    int r=0,w=0,b=0;
    for (int i = 0; i < len; ++i) {
        if(stone[i]=='R'){
            r++;
        } else if(stone[i]=='W'){
            w++;
        } else{
            b++;
        }
    }
    char s[100];
    int i=0;
    for (; i < r; ++i) {
        s[i]='R';
    }
    for (; i < r+w; ++i) {
        s[i]='W';
    }
    for (; i < r+w+b; ++i) {
        s[i]='B';
    }
    for (int i = 0; i < len-1; ++i) {
        cout<<s[i]<<' ';
    }
    cout<<s[len-1]<<endl;
}

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        char s[100];
        for (int i = 0; i < n; ++i) {
            cin>>s[i];
        }
        stone_sort(s, n);
    }
    return 0;
}