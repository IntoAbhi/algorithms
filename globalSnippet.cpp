#include <bits/stdc++.h>
#define ll long long int
const int MOD=1000000007;
ll fact[100001];
bool prime[100001];
using namespace std;

int gcd(int a, int b) {
    if (!a) return b;
    return gcd(b % a, a);
}

void sieve() {
	memset(prime, true, sizeof(prime)); prime[1]=false;
	for (int p=2; p*p<=100001; p++) {
		if (prime[p] == true) for (int i=p*p; i<=100001; i += p) prime[i] = false;
	}
}

void factorial(){
    fact[0]=1;
    for(int i=1;i<100001;i++) fact[i]=(fact[i-1]*i)%MOD;
}

ll power(ll x,ll y){
    if(y==0)return 1;
    if(y%2==0) x = power((x*x)%MOD,y/2);
    else x = x*power(x,y-1)%MOD;

    return x;
}

ll ncr(int n,int r){
    ll ans=fact[n]%MOD;
    ans=((ans*(power(fact[r],MOD-2)%MOD)%MOD)*(power(fact[n-r],MOD-2)%MOD))%MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//factorial(); sieve(); ncr(); power(); gcd();



}
