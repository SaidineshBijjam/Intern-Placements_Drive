#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll power(ll b,ll n,ll m)
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
typedef struct node{
	struct node* children[2];//Have pointers to beautiful children
	int num_leaves;
	int leaf_freq;	
	//Do we need is end node shit? - No need i guess.
}Node;

void add(Node* curr,ll num, int pos){
	//First find the posth bit; 
	if( pos < 0){
		curr->num_leaves = 1;	
		curr->leaf_freq +=1;
		return;
	}
	int bit = (num >> pos)&1;
	if(curr->children[bit] == NULL)
		curr->children[bit] = (Node*)malloc(1*sizeof(Node));

	add(curr->children[bit], num, pos-1);
		
	curr->num_leaves = 0;
	curr->leaf_freq = 0;
	if(curr->children[0]!=NULL){
		curr->num_leaves+=curr->children[0]->num_leaves;	
		curr->leaf_freq+=curr->children[0]->leaf_freq;	
		
	}
	if(curr->children[1]!=NULL){
		curr->num_leaves+=curr->children[1]->num_leaves;	
		curr->leaf_freq+=curr->children[1]->leaf_freq;	
	}

	return;	
}

void free_all(Node* curr,  int pos){
	if (curr==NULL or pos<0){
		return;
	}
	
	free_all(curr->children[0], pos-1);
	free(curr->children[0]);
	curr->children[0] = NULL;
	
	free_all(curr->children[1], pos-1);
	free(curr->children[1]);
	curr->children[1] = NULL;
		
	return;
}
int solve(Node* curr, ll R, int pos){
	if(curr==NULL or pos<0)
		return 0;	
	int bit = (R >> pos) &1;
	ll ans = 0;
	if(curr->children[bit]!=NULL and curr->children[bit]->num_leaves == (1<<pos)){
		bit = 1 - bit;
		ans |= (1<<pos); 
	}
	ans|= solve(curr->children[bit], R, pos-1);
	return ans;
} 
int main(){
	int N_bits = 32;
	int N,Q;
	
	cin >> N >> Q;
	ll arr[N];
	//Make root
	Node* root = (Node*)malloc(1*sizeof(Node));
	root->children[0] = NULL;
	root->children[1] = NULL;
	root->num_leaves = 0;
	root->leaf_freq = 0;

	for (int i=0;i<N;i++){
		scanf("%lld ",&arr[i]);
		//Add element to trie
		add(root, arr[i],N_bits-1);
	}
	
	ll R = 0;
	ll final_ans = 1;
	ll base = 1e8;
	ll P = 1e9+7;
	while(Q--){
		ll x,j, y;
		int type = 1;
		cin >> type;
		if(type == 1){
			cin >> x;
			R = R^x;
		}else{
			cin >> x >> y;
		}
		ll ans1 = solve(root, R,N_bits-1);
		printf("%lld\n",ans1);
	}  
	free_all(root,N_bits-1);	
	return 0;
}
