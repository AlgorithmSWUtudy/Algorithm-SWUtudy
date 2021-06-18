#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct Edge {
	int v1, v2, c;
	Edge(int v1, int v2, int c) {
		this->v1 = v1;
		this->v2 = v2;
		this->c = c;
	}
	bool operator <(const Edge& a)const {
		return c > a.c;
	}
};
int ch[10000];
int Find(int a) {
	if (a == ch[a]) return a;
	else return ch[a] = Find(ch[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) ch[a] = b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int v, e;

	cin >> v >> e;

	int a, b, c, answer = 0;
	priority_queue <Edge> q;

	for (int i = 1; i <= v; i++){
		ch[i] = i;
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		q.push(Edge(a, b, c));
	}

	while (!q.empty()) {
		Edge tmp = q.top();
		q.pop();
		if (Find(tmp.v1) != Find(tmp.v2)) {
			Union(tmp.v1, tmp.v2);
			answer += tmp.c;
		}
	}

	cout << answer;
}