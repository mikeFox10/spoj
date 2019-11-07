#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define N 1000000
#include <bits/stdc++.h> 
using namespace std;
class SkyCr{
public:
  int h;
  int penal;
  SkyCr(int i, int j){
    h = i;
    penal = j;
  }
};

bool cmp( SkyCr a, SkyCr b){
  return a.h<b.h;
}

int A[N];
int main(){
       // added the two lines below 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
  int t,i,n,ti,d,j,k,ans;
  cin>>t;
  while(t--){
     cin>>k>>d;
    vector<SkyCr> v;
    cin>>A[0];
    n = 1;
    for(i=1;i<k;i++){
      cin>>j;
      if(j!=A[n-1])
	    A[n++]=j;
    }
    if( n > 1 && A[0]>A[1] )
      v.push_back(SkyCr(A[0],-1 ));
    else if (n==1)
      v.push_back(SkyCr(A[0],-1));
    for(i=1;i<n-1;i++){
      if( A[i]< A[i-1] && A[i]<A[i+1])
	v.push_back(SkyCr(A[i],1));
      else if( A[i]>A[i-1] && A[i]>A[i+1] )
	v.push_back(SkyCr(A[i],-1));
    }
    if( n>=2 && A[n-1]>A[n-2] )
      v.push_back(SkyCr(A[n-1],-1));
    sort(v.begin(),v.end(),cmp);
    ans = 1;
    i = 0;
    for(j=0;j<d;j++){
      cin>>ti;
      for(;i<v.size()&& v[i].h<=ti;i++)
	    ans+=v[i].penal;
      printf("%d ",ans);
    }
    printf("\n");
  }
}