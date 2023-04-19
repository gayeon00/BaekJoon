#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int N, M, K;
int treeHeight;
int leafNodeStartIndex;
vector<long> tree;

void setTree(int i) {
	while (i!=1) {
		tree[i / 2] += tree[i];
		i--;
	}
}


void read_data() {
	cin >> N >> M >> K;

	int tmp = N;
	while (tmp!=0) {
		tmp /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	tree.resize(treeSize+1);
	leafNodeStartIndex = treeSize / 2 - 1;

	for (int i = 1; i <= N; i++) {
		cin >> tree[leafNodeStartIndex + i];
	}

	setTree(treeSize - 1);
}

void change(int index, long value) {
	long diff = value - tree[index];
	
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}

void gugan(int start, int end) {
	long result = 0;

	while (start <= end) {
		if (start % 2 == 1) {
			result += tree[start];
			start++;
		}
		if (end % 2 == 0) {
			result += tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	cout << result << '\n';
}

void solve() {
	for (int i = 0; i < M + K; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			change(leafNodeStartIndex + b, c);
		} else if (a == 2) {
			gugan(leafNodeStartIndex + b, leafNodeStartIndex + c);
		}
	}
}
int main() {
	read_data();
	solve();
}