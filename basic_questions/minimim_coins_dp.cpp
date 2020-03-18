#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()
#define INF 1000000


int solve(int curr, vector <int> coins, map <int, int> &dp){
    if(curr < 0) return INF;
    if(curr == 0) return 0;
    if(dp.find(curr) != dp.end()) return dp[curr];
    int ans = INF;
    for(int i = 0; i < sz(coins); i++){
        ans = min(ans, solve(curr - coins[i], coins, dp) + 1);
    }
    dp[curr] = ans;
    return ans;
}


int no_of_ways(int curr, vector <int> coins, map <int, int> &dp){
    if(curr < 0) return 0;
    if(curr == 0) return 1;
    if(dp.find(curr) != dp.end()) return dp[curr];
    
    for(int i = 0; i < sz(coins); i++){
        dp[curr] += no_of_ways(curr - coins[i], coins, dp);
    }
    return dp[curr];
}

int main(){
    int N, input, val;
    vector <int> denominations;
    // Taking input
    cin >> N >> val;
    for(int i = 0; i < N; i++){
        cin >> input; denominations.push_back(input);
    }

    map <int, int> dp; dp[0] = 0;
    // cout << solve(val, denominations, dp) << endl;
    cout << no_of_ways(val, denominations, dp) << endl;

    return 0;
}