#include <bits/stdc++.h>

using namespace std;

struct Segment {
	int n;
	vector<int> arr, seg;
	void Init(vector<int>& vec) {
		n = vec.size();
		arr.assign(vec.begin(), vec.end());
		seg.resize(4 * n);
	}

	int SetTree(int num, int s, int e) {
		if (s == e) return seg[num] = arr[s];
		
		int mid = (s + e) / 2;
		return seg[num] = SetTree(2 * num, s, mid) + SetTree(2*num+1, mid+1, e);
	}
	void SetTree() { SetTree(1, 0, n - 1); }

	int update(int num, int s, int e, int idx, int diff) {
		if (idx < s || e < idx) return seg[num];
		if (s == e) return seg[num] = diff;

		int mid = (s + e) / 2;
		return seg[num] = update(2 * num, s, mid, idx, diff) +
			update(2*num+1, mid+1, e, idx, diff);
	}
	void update(int idx, int diff) { update(1, 0, n - 1, idx, diff); }

	int query(int num, int s, int e, int l, int r) {
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) return seg[num];

		int mid = (s + e) / 2;
		return query(2 * num, s, mid, l, r) + query(2 * num + 1, mid + 1, e, l, r);
	}
}; 