#include <iostream>
using namespace std;

bool isPossible(int a[], int n, int m, int mid){
	int wood = 0;
	for(int i = 0; i<n; i++){
		//a[i] will represent the height of trees & mid will represent the height H where we are trying to cut
		if(a[i]>mid){
			sum+= (a[i]-mid);	//add wood greater than mid in the height of trees
		}
		else if(sum>=m)
		{
			return true; //at least m wood we need
		}
		else{
			return false;	//when the above conditions not meet, return false
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	
	int start = 0;
	int ans = -1;
	int end = *max_element(a,a+n);	//stl function to find out maximum value element inside array
	int mid = start+(end-start)/2;
	 //apply BS
	 while(start<=end){
	 	if(isPossible(a,n,m,mid)){
	 		ans=mid;
	 		start = mid+1;
	 	}
	 	else{
	 		//not a ossible solution -> move left
	 		end = mid-1;
	 	}
	 	mid = start+(end-start)/2;
	 }
	return ans;
}
