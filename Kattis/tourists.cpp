#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

#define PI atan2(0, -1)
#define epsilon 0.000000001
#define INF 5000000000000000000
#define MOD 1000000007

int N, depths [200010], parents [20][200010];
vector<int> adjacency [200010];
long long ret = 0ll;

void dfs(int curr, int prevy, int d){
    depths[curr] = d; parents[0][curr] = prevy;
    for(int i : adjacency[curr])
        if(i != prevy)
            dfs(i, curr, d+1);
}

void buildIt(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j <= N; j++)
            parents[i][j] = parents[i-1][parents[i-1][j]];
}

int findLCA(int p, int q){
    if(depths[p] < depths[q]) swap(p, q);
    for(int i = 19; i > -1; i--)
        if(depths[p]-(1<<i) >= depths[q])
            p = parents[i][p];
    if(p == q) return p;
    for(int i = 19; i > -1; i--)
        if(parents[i][p] != parents[i][q]){
            p = parents[i][p];
            q = parents[i][q];
        }
    return parents[0][p];
}


int main(){
    //freopen("dirtraverse.in", "r", stdin); freopen("dirtraverse.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(18);
    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b; cin >> a >> b;
        adjacency[a].push_back(b); adjacency[b].push_back(a);
    }
    dfs(1, 1, 0); buildIt();
    for(int i = 1; i <= N; i++)
        for(int j = 2*i; j <= N; j += i)
            ret += (long long)(depths[i]+depths[j]-2*depths[findLCA(i, j)]+1);
    cout << ret << '\n';
    return 0;
}
