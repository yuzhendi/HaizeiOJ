/*************************************************************************
	> File Name: 303.cpp
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年04月01日 星期三 18时33分35秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

int n, m;
char mmap[1005][1005];
int ans[1005][1005];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct node {
    int x, y, step;

};
queue<node>que;

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j] == '1') {
                que.push({i, j, 0});
                ans[i][j] = -1;
            }
        }
    }
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        for(int i= 0 ; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if(x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue;
            ans[x][y] = temp.step + 1;
            que.push({x, y, ans[x][y]});//以1为起点，ans = -1 来标记，区分0
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j != 1) cout <<" ";
            if(ans[i][j] == -1) {
                cout << 0;
            }else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}
