#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()


typedef struct task{
    int duration;
    int deadline;
    bool operator<(task t){
        if(duration < t.duration) return 1;
        else return 0;
    }
}task;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N, x, y;
    vector <task> tasks;
    
    // taking input
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        task temp; temp.duration = x; temp.deadline = y;
        tasks.push_back(temp);
    }

    // Greedy Solution is taking the task with least duration. So we sort it.
    sort(tasks.begin(), tasks.end());
    int curr_pos = 0, ans = 0;
    for(int i = 0; i < N; i++){
        curr_pos += tasks[i].duration;
        ans += (tasks[i].deadline - curr_pos);
    }
    cout << ans << endl;
    return 0;
}
