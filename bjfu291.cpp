//bjfu291
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    while (1){
        string s;
        cin>>s;
        if(s=="#"){
            break;
        }
        int n=0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='#'){
                n++;
            }
        }
//        cout<<n<<endl;
        n=s.size()-n+1;
        n=log(n)/log(2);
        cout<<n+1<<endl;
    }
    return 0;
}