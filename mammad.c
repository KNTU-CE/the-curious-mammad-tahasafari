#include <stdio.h>
#include <stdlib.h>


int Crossingarray(int arr[], int l, int m, int h,int k)
{

	int j,i,p,q,sum = 0,z=0;
	int maxnum = arr[l];
	
	
	
	for(i=m;i>=l;i--){
		for(p=i;p<=m;p++){
			sum=sum+arr[p];
		}
		maxnum=arr[i];
		for(j=m+1;j<=h;j++){
			for(q=i+1;q<=j;q++){
				if(maxnum<arr[q]){
					maxnum=arr[q];
				}
			}
			sum=sum+arr[j];
			if((sum-maxnum)%k==0){
				z++;
			}
		}
		sum=0;
	}
	
	return z;
	
	
}

int findarray(int arr[], int l, int h, int k)
{
	if (l==h){
		return 0;	
	}
		
	int m = (l + h) / 2;

	return findarray(arr, l, m ,k)+findarray(arr, m + 1, h, k)+Crossingarray(arr, l, m, h, k);
}

int main()
{
	int i,n,k;
	scanf("%d %d", &n,&k);
	int A[n];
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	int possibility=findarray(A,0,n-1,k);
	
	printf("%d", possibility);
	
	return 0;
}

