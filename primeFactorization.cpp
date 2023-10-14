#include<bits/stdc++.h>
using namespace std; 

int main(){
   int n;
    cin >> n;
    for (int i = 2;i<=sqrt(n);i++){
        if(n%i == 0){
            while(n%i == 0){
                cout<<i<<" "; 
                n /= i; 
            }
        }
    }
    if(n >= 2){
        cout<<n<<" "; 
    }

  return 0; 
}
