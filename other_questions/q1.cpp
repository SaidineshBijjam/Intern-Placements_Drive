#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
typedef struct node{
	node* a[2];
	ll count;
	ll total_count;	
	ll nos_ending;
}node;
node* make(ll i)
{
	node* new1=(node*)malloc(sizeof(node));
	new1->a[0]=NULL;
	new1->a[1]=NULL;
	new1->count=0;
	new1->total_count=(1ll<<(31ll-i));
	new1->nos_ending=0;
	return new1;
}
node* insert(node* root,ll x, ll flag)
{
	node* temp=(node*)malloc(sizeof(node));
	temp=root;
	ll i,val;
	for (i = 0; i < 32; ++i)
	{
		val=(x>>(31ll-i))&1;
		if (temp->a[val]==NULL)
		{
			temp->a[val]=make(i);
		}
		if(flag==0){
			temp->a[val]->count++;
		}
		if (i==31)
		{
			temp->a[val]->nos_ending++;
		}
		temp=temp->a[val];
	}
return root;
}
ll query_for_val(node* root,ll x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp=root;
	ll i,val;
	for (i = 0; i < 32; ++i)
	{
		val=(x>>(31ll-i))&1;
		if (temp->a[val]==NULL)
		{
			return 0;
		}
		if (i==31)
		{
			return temp->a[val]->nos_ending;
		}
		temp=temp->a[val];
	}
return 0;
}

node* delete_val(node* root,ll x, ll flag)
{
	node* temp=(node*)malloc(sizeof(node));
	temp=root;
	ll i,val;
	for (i = 0; i < 32; ++i)
	{
		val=(x>>(31ll-i))&1;
		// if (temp->a[val]==NULL)
		// {
		// 	break;
		// }
		if(flag==1){
			temp->a[val]->count--;
		}
		if (i==31)
		{
			temp->a[val]->nos_ending--;
		}
		if (temp->a[val]->count==0)
		{
			temp->a[val]=NULL;
			break;
		}
		temp=temp->a[val];
	}
return root;
}
ll ans;
node* query(node* root,ll x)
{
  node* temp=(node*)malloc(sizeof(node));
  temp=root;
  node* temp1=(node*)malloc(sizeof(node));
  ll i,val;
  ans=0;
  for (i = 0; i < 32; ++i)
  { 
  	ll f=(x>>(31ll-i))&1;
  	if (temp->a[f]==NULL)
  	{
  		ans=ans<<(31ll-i);
  		return root;
  	}
  	if (temp->a[1-f]==NULL&&temp->a[f]->count>=temp->a[f]->total_count)
  	{
  		ans+=1;
  		ans=ans<<(31ll-i);
  		return root;
  	}
  	if (temp->a[f]->count<temp->a[f]->total_count)
  	{
  		temp=temp->a[f];
  	}
  	else
  	{
  		temp=temp->a[1-f];
  		ans+=1;
  	}
  	ans=ans<<1;
 }
return root;
}
ll expo(ll b,ll n,ll m)
{
 ll r,p;
	p=1;
	 b=b%m;
	while(n>0)
	{ 
		r=n%2;
		if(r==1)
		   p=((p)*(b))%m;
		b=((b)*(b))%m; 
		n=n/2;		
	}
 return (p%m);
}
ll arr[100002];
int main()
{	 ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
  	ll mod=1e9+7;
  	ll base=1e8;
	ll i,n,q,x,y,z=0,type,final_ans;
	cin>>n>>q;
//	cout<<q<<endl;
	node* root;
	root=make(0);
	for (i = 1; i <= n; i++)
	{ 
		cin>>x;
		arr[i]=x;
		root=insert(root,x, query_for_val(root,x));
	}
	final_ans=1;
	ll xorval=0;
	ll maxx=0, minn=(ll)1e10;
	while(q--)
	{
	 cin>>type;	
	  ans=0;
	 if(type==1){
	 	cin>>x;
	 	xorval^=x;
	 }
	 else{
	 	cin>>x>>y;
	 	y^=xorval;
	 	ll coun_curr=query_for_val(root, arr[x]);
	 	root=delete_val(root, arr[x], coun_curr);
	 	root=insert(root, y, query_for_val(root,y));
		// cout << query_for_val(root,y) << endl;
	 	arr[x]=y;
	 }
	 root=query(root,xorval);
	 cout << ans << endl;
	 final_ans=(final_ans*expo(base, ans, mod))%mod;
	}
	cout<<final_ans<<endl;
	// for(auto x:answers)
	// {
	// 	cout<<x<<endl;
	// }
//	for(auto m:m_ans)
//	 {
	 //	cout<<m.ff<<" "<<m.ss<<endl;
//	 }
// //	cout<<maxx<<" "<<minn<<endl;

	return 0;
}
