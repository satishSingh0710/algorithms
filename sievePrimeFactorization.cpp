int ar[1000001];
void sieve(){
    int maxN = 1000000; 
    for (int i = 1;i<=maxN;i++){
        ar[i] = -1; 
    }
    
    for (int i = 2;i<=maxN;i++){
        if(ar[i] == -1){
            for (int j = i;j<=maxN;j+=i){
                if(ar[j] == -1){
                    ar[j] = i; 
                }
            }
        }
    }
}
