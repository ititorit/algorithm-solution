/*
#ifndef ONLINE_JUDGE
freopen("" , "rt", stdin);
freopen("" , "wt", stdout);
#endif
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#define max 100000
long long seq[max+5];
int n,j,i;
long long l,r;
long long sumIJ;
long long sum[max+5];
void input();
void calc();
int main() {
	 input();
	 calc();
	return 0;
}
void input(){
	cin>>n>>l>>r;
	sum[0]=0;
	for(i=1;i<=n;++i){
		scanf("%d",&seq[i]);
		sum[i]=sum[i-1]+seq[i];
		cout<<i<<' '<<sum[i]<<endl;
	}
}
void calc(){
	int count=0;
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j){
			sumIJ=sum[j]-sum[i-1];
			if(l<=sumIJ && sumIJ<=r) count++;
		}
	cout<<count<<endl;
}
