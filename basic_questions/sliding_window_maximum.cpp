#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define sz(A) (int)A.size()

int main(){
	int N, x, k;
	cin >> N >> k;
	
	vector <int> arr;
	for(int i = 0; i < N; i++){
		cin >> x;
		arr.push_back(x);
	}
	
	deque <int> req;
	for(int i = 0; i < N; i++){
		if(!req.empty()) {
			while(!req.empty() && i - req.front() + 1 >= k) req.pop_front();
			while(!req.empty() && arr[req.back()] > arr[i]) req.pop_back();
		}
		req.push_back(i);	
		cout << arr[req.front()] << " ";
	}
	
	cout << endl;	
	return 0;
}
