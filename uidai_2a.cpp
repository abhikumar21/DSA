#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool prime[100005];
int dp[100005];
ll answer;
bool visited[100005];
vector<int>adjacent[100005];

void dfs1(int u)
{
    visited[u] = true;
    int sum = prime[u] ? 0 : 1;
    for(int i = 0 ; i < adjacent[u].size() ; i++)
    {
        int v = adjacent[u][i];

        if(!visited[v])
        {
            dfs1(v);
            sum += dp[v];
        }
    }

    dp[u] = sum;

    if(prime[u]) dp[u] = 0;
}

void dfs2(int u, int p, int dv)
{
    visited[u] = true;

    if(prime[u])
    {
        vector<ll>pp;
        ll sum = dv;
        pp.push_back(dv);
        for(int i = 0 ; i < adjacent[u].size() ; i++)
        {
            int v = adjacent[u][i];

            if(!visited[v] && v != p)
            {
                dfs2(v, u, 0);
                pp.push_back(dp[v]);
                sum += dp[v];
            }
        }

        ll val = 0;
        for(int i = 0 ; i < pp.size() ; i++)
        {
            val += (sum-pp[i])*pp[i];
        }

        val /= 2;
        answer += val;
        answer += sum;
    }
    else
    {
        for(int i = 0 ; i < adjacent[u].size() ; i++)
        {
            int v = adjacent[u][i];

            if(!visited[v] && v != p)
            {
                dfs2(v, u, dv + dp[u] - dp[v]);
            }
        }
    }
}

void Sieve()
{
    for(int i = 1 ; i <= 100000 ; i++)
    {
        prime[i] = true;
    }

    prime[1] = false;

    for(int i = 2 ; i*i <= 100000 ; i++)
    {
        if(prime[i])
        {
            for(int j = i*i ; j <= 100000 ; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main(){

    Sieve();

    int n;
    cin>>n;
    assert(1 <= n && n <= 100000);

    for(int i = 0 ; i < n - 1 ; i++)
    {
        int u,v;
        cin>>u>>v;
      assert(1 <= u && u <= n);
      assert(1 <= v && v <= n);

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    dfs1(1);
    for(int i = 1 ; i <= n ; i++) visited[i] = false;

    dfs2(1,0,0);

    cout<<answer<<endl;

} 
//prime pairs