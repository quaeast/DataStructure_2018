//bjfu256
//
#include <iostream>
#include <cstring>
using namespace std;


bool cmpS(char *s, char *l){
    int flag=1;
    for (int i = 0; i < strlen(s); ++i) {
        if(s[i]!=l[i]){
            flag=0;
            break;
        }
    }
    return flag;
}

bool cmp(char *s, char *l){
    int flag=0;
    for (int i = 0; i < strlen(l)-strlen(s)+1; ++i) {
        if(cmpS(s, l+i)){
            flag=1;
            break;
        }
    }
    return flag;
}

void move(char *s){
    char t=s[0];
    for (int i = 0; i < strlen(s)-1; ++i) {
        s[i]=s[i+1];
    }
    s[strlen(s)-1]=t;
}

int main() {
    while (1){
        char v[100],p[200];
        cin>>v>>p;
        if (v[0]=='0'&&p[0]=='0'&&strlen(v)&&strlen(p)){
            break;
        }
        int flag=0;
        for (int i = 0; i < strlen(v); ++i) {
            if(cmp(v, p)){
                flag=1;
                break;
            }
            //cout<<v<<endl;
            move(v);
        }
        if (flag){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}