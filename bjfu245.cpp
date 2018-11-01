//bjfu245
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    while (1){
        string str;
        cin>>str;
        if (str.size()==1&&str[1]==0){
            break;
        }
        int top=-1;
        int len=str.size();
        int flag=1;
        for (int i = 0; i < len; ++i) {
            if(str[i]=='O'){
                if (top==-1){
                    flag=0;
                    break;
                } else{
                    top--;
                }
            } else if(str[i]=='I'){
                top++;
            } else{
                flag=0;
                break;
            }
        }
        if (flag&&top==-1){
            cout<<"TRUE"<<endl;
        } else{
            cout<<"FALSE"<<endl;
        }
    }
    return 0;
}