#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
	int n;
	vector<int> tree;
	void Init(vector<int>& vec) {
		n = vec.size();
		tree.resize(n+1);
		for (int i = 1; i <= n; i++) update(1, vec[i-1]);
	}
	void update(int idx, int diff) {
		while (idx < tree.size()) {
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}
	int query(int idx) {
		int ans = 0;
		while (idx > 0) {
			ans += tree[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}
	int query(int l, int r) {
		return query(r) - query(l-1);
	}
};