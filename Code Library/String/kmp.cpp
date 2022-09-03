#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)
#define eps 1e-11
#define DEBUG(x) cerr << #x << " = " << x << endl
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAX = 2e5 + 5, MOD = 1e9 + 7;
const ll inf = 1e18 + 5;

vector<int> prefix_function(string s) {
  int n = (int) s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

vector<vector<int>> prefix_automaton(string s) {
  s += '#';
  int n = s.size();
  vector<int> pi = prefix_function(s);
  vector<vector<int>> automaton(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && c + 'a' != s[i]) automaton[i][c] = automaton[pi[i-1]][c];
      else automaton[i][c] = i + (c + 'a' == s[i]);
    }
  }
  return automaton;
}

void add(vector<int> &pi, vector<vector<int>> &automaton, char ch) {
  int n = pi.size();
  automaton.pb(vector<int>(26));
  for (int c = 0; c < 26; c++) {
    if (c + 'a' != ch) automaton[n][c] = automaton[pi.back()][c];
    else automaton[n][c] = n + (c + 'a' == ch);
  }
  pi.pb(automaton[pi.back()][ch - 'a']);
}

int arr[MAX];
int main() {

  fastio;
  
}