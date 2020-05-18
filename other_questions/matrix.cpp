#include<bits/stdc++.h>
using namespace std;

int main()
{
	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);	   	  
	int t;
	cin>>t;
	int lk=0;
	while(t--)
	{   lk++;
	int a,b,x1,y1,x2,y2;
	//cin>>a>>b>>x1>>y1>>x2>>y2;
	//x1--;y1--;x2--;y2--;
	a=2000;b=2000;
	   vector<vector<double> > mat;
	   vector<double> s;
	   for(int po=0;po<a;po++)
	   {
	   
	   for(int jo=0;jo<b;jo++)
	   s.push_back(0);
	   
	   mat.push_back(s);
      }
	 mat[0][0]=1;
	   for(long long int po=1;po<b;po++)
	   {
	   	mat[0][po]=mat[0][po-1]/2;
	   }
	   for(long long int po=1;po<a;po++)
	   {
	   	mat[po][0]=mat[po-1][0]/2;
	   }
	   
	   for(long long int po=1;po<a-1;po++)
	   {
	   	 for(long long int jo=1;jo<b-1;jo++)
	   	   {
	   		mat[po][jo]=mat[po-1][jo]+mat[po][jo-1];
	   		mat[po][jo]/=2;
		   }
	   }
	   if(a>2){
	   for(long long int po=1;po<b;po++)
	   {
	   	mat[a-1][po]+=mat[a-1][po-1];
	   	mat[a-1][po]+=mat[a-2][po]/2;
	   }
}
if(b>2)
{
	for(long long int po=1;po<a;po++)
	{
		mat[po][b-1]+=mat[po-1][b-1];
		mat[po][b-1]+=mat[po][b-2]/2;
	}
}
mat[a-1][b-1]=1;
//	double ans=0;
//	if(y1>0){
//		for(int i=x1;i<=x2;i++)
//		{
//			if(i==a-1)
//			ans+=mat[i][y1-1];
//			else
//			ans+=(mat[i][y1-1]/2);	
//		}
//	}
//	if(x1>0)
//	{
//		for(int i=y1;i<=y2;i++)
//		{
//			if(i==b-1)
//			ans+=mat[x1-1][i];
//			else
//			ans+=mat[x1-1][i]/2;
//		}
//	}
//
//	if(x1==0 && y1==0)
//	ans=1;
//	if(x2==a-1 && y2==b-1 )
//	ans=1;
//	if(a==1 || b==1)
//	ans=1;
//
//	
	
		cout<<mat[1][1]<<" "<<mat[2][2]<<endl;
		
		
		
   //cout<<"Case #"<<lk<<":"<<" "<<1-ans<<"\n";		
	}
	
	return 0;
}