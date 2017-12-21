#include <stdio.h>

int search(int a[],int low,int high,int target)
{
	int i=low,j=high;
	while(i<=j){
		int mid=(i+j)/2;
		if(target<a[mid])
			j=mid-1;
		else if(target>a[mid])
			i=mid+1;
		else 
			return mid;
	}
	return -1;
}

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9,10};
	int len=sizeof(a)/sizeof(int);
	int target=4;
	int pos=-1;
	pos=search(a,0,len-1,target);
	printf("position = %d\n",pos);
	return 0;
}
