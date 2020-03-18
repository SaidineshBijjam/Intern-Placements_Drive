#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()

typedef struct task{
    int start; int end;

    bool operator<(task p){
        if(end < p.end) return 1;
        else return 0; 
    }
}task;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, x, y;
    vector <task> tasks;
    
    //Taking Input 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        task temp; temp.start = x; temp.end = y;
        tasks.push_back(temp);
    }

    // Sorting according to end times
    sort(tasks.begin(), tasks.end());

    // Finding no of tasks possible
    int curr_end = tasks[0].end, ans = 1;
    for(int i = 1; i < N; i++){
        if(curr_end < tasks[i].start){
            ans++;
            curr_end = tasks[i].end;
        }
    }

    cout << ans << endl;
    return 0;
}