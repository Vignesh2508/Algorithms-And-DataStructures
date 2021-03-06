// square root decomposition implementation
#include<iostream>
#include<cstdio>
#include<cmath>

long long query(long long arr[],long long sqrtdecom[],long long left,long long right,long long buckets);

void update(long long sqrtdecom[],long long index,long long diff,long long bucket);
int main()
{
char ch;
long long diff,buckets,sqrtdecom[1003],arr[1000001],i,j,k,l,m,n,x,y;
float bsize;
scanf("%lld%lld",&n,&m);
buckets=(long long int)sqrt(n)+1;
for(i=0;i<buckets;i++)
sqrtdecom[i]=0;
// sqrt(n)+1 buckets required
//buckets=ceil(bsize);
for(i=0;i<n;i++)
{
scanf("%lld",&arr[i]);
sqrtdecom[i/buckets]+=arr[i];//filling the buckets i.e storing sum of all 
//elements that lies in a particular bucket
}/*
for(i=0;i<buckets;i++)
printf("%lld ",sqrtdecom[i]);
printf("\n");
*/

while(m--)
{
scanf(" %c %lld%lld",&ch,&x,&y);
if(ch=='G')
{//adding y to index x i.e arr[x] if G 
arr[x]+=y;
update(sqrtdecom,x,y,buckets);
}
else if(ch=='T')
{// else if T then sub y from arr[x]
arr[x]=arr[x]-y;
update(sqrtdecom,x,-y,buckets);
}
else if(ch=='S')
{
k=query(arr,sqrtdecom,x,y,buckets);
printf("%lld\n",k);
}

}


return 0;
}
void update(long long sqrtdecom[],long long index,long long diff,long long buckets)
{
long long i;
sqrtdecom[index/buckets]+=diff;
/*
for(i=0;i<buckets;i++)
printf("%lld ",sqrtdecom[i]);
printf("\n");*/
}
long long query(long long arr[],long long sqrtdecom[],long long left,long long right,long long buckets)
{
long long sum=0,i=left;
while(i%buckets!=0&&i<=right)
{//adding elem from leftmost buckets
sum+=arr[i];
i++;
}
while((i+buckets)<=right)
{//adding whole buckets that lie within range
sum+=sqrtdecom[i/buckets];
i=i+buckets;
}

while(i<=right)
{
//adding remaining elements from rightmost buckets 
sum+=arr[i];
i++;
}

return sum;
}
