
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	int  t,d,n;
	cin>>t;
	while(t--)
	{
	    cin>>n>>d;
	    int arr[n];
	    int temp[d];
	    for(int i=0; i<n; i++) cin>>arr[i];
	    for(int i=0; i<d; i++) temp[i]=arr[i];
	    for(int i=d; i<n; i++) arr[i-d]=arr[i];
	    for(int i=0; i<d; i++) arr[(n-d)+i]=temp[i];
	    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
