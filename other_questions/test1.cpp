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
	if(curr->children[bit] == NULL){
		curr->children[bit] = (Node*)malloc(1*sizeof(Node));
		curr->children[bit]->children[0] = NULL;
		curr->children[bit]->children[1] = NULL;
	}
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

void remove(Node* curr, ll num, int pos){
	if (pos<0){
		curr->leaf_freq -=1;
		return;
	}
	int bit = (num>>pos)&1;
	
	remove(curr->children[bit], num, pos-1);
	if (curr->children[bit]->leaf_freq == 0){
		free(curr->children[bit]);
		curr->children[bit] = NULL;
	}
		
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
void printTrie(Node* root){
	if(root == NULL)
		return;
	
	//Left->subtree root	
	//Left subtree
	if(root->children[0] != NULL){
		printf("0 : leaves = %d freq = %d\n", root->children[0]->num_leaves, root->children[0]->leaf_freq);
		printTrie(root->children[0]);
		printf("\n");
	}
	else{
		printf("Left subtree NULL\n");
	}
	//Right subtree root
	//Right subtree
		
	if(root->children[1] != NULL){
		printf("1 : leaves = %d freq = %d\n", root->children[1]->num_leaves, root->children[1]->leaf_freq);
		printTrie(root->children[1]);
		printf("\n");
	}
	else{
		printf("Right subtree NULL\n");
	}
	return;
}
int solve(Node* curr, ll R, int pos){
	if(curr==NULL or pos<0)
		return 0;	
	int bit = (R >> pos) &1;
	ll ans = 0;
	//cout << "bit" << bit << endl;
	//cout << "curr" << curr << endl;
	//cout << "curr->children" << curr->children[bit] << endl;
	
	if(curr->children[bit]!=NULL and curr->children[bit]->num_leaves == (1<<pos)){
		bit = 1 - bit;
		ans |= (1<<pos); 
	}
	ans|= solve(curr->children[bit], R, pos-1);
	return ans;
} 
int main(){
	int N_bits = 31;
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
	ll ans;
	while(Q--){
		ll x,j, y;
		int type;
		cin >> type;
		if(type == 1){
			cin >> x;
			R = R^x;
		}				
		else{
			cin >> j >> y;
			y = y^R;
			//Delete arr[j-1]
			remove(root,arr[j-1],N_bits-1);
			//Add y
			add(root, y, N_bits-1);
			arr[j-1] = y;	
		}
		ans = 0;
		//Use the get solve function on Trie with R
		//printTrie(root);	
		ll ans1 = solve(root, R,N_bits-1);
		//Final hash = multiply and shit
		cout << ans1 << endl;
	 	final_ans=((final_ans)*power(base, ans1, P))%P;
	}  
	//Print final ans
	cout << final_ans << endl;
	return 0;
}
