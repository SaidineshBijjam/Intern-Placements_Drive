#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int rows, cols, x1, y1, x2, y2, sum, q;
    cin >> rows >> cols;
    
    vector <vector <int> > req;
    for(int i = 0; i < rows; i++){
        vector <int> temp;
        req.push_back(temp);
        for(int j = 0; j < cols; j++){
            cin >> x1;
            req[i].push_back(x1);
        }
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            sum = (i == 0) ? 0 : req[i - 1][j];
            sum += (j == 0) ? 0 : req[i][j - 1];
            sum -= (i == 0 || j == 0) ? 0 : req[i - 1][j - 1];
            req[i][j] += sum;
            cout << req[i][j] << " ";
        }
        cout << endl;
    }

    cin >> q;
    while(q--){
        sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        sum += req[x2][y2];
        sum -= (x1 == 0) ? 0 : req[x1 - 1][y2];
        sum -= (y1 == 0) ? 0 : req[x2][y1 - 1];
        sum += (x1 == 0 || y1 == 0) ? 0 : req[x1 - 1][y1 - 1];
        cout << sum << endl;
    }


    return 0;
}