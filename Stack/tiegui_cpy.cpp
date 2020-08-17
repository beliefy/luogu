#include<iostream>
#include<stack>
using namespace std;

int n,target[1005];

void decision(){
    stack<int> s;
    int A=1,B=1;
    while(B<=n){
        if(A==target[B]) {
            ++A;
            ++B;
        }
        else if((!s.empty())&&(s.top()==target[B])){
            s.pop();
            ++B;
        }
        else if(A<=n) s.push(A++);
        else {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}

int main(){
    while((cin >> n)&&(n)){
        while((cin >> target[1])&&(target[1])){
            for(int i=2;i<=n;i++) cin >> target[i];
            decision();
        }
        putchar('\n');
    }
    return 0;
}

