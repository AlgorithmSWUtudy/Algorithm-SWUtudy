#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> cur(4);
vector <string> wheel(4);


void one(int n, int d);
void two(int n, int d);
void three(int n, int d);
void four(int n, int d);

int main() {

	ios_base::sync_with_stdio(false);

	

	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}

	cur[0] = { 2, 6 };
	cur[1] = { 2, 6 };
	cur[2] = { 2, 6 };
	cur[3] = { 2, 6 };
	
	int n, arr[2];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[0] >> arr[1];
		
		if (arr[0] == 1) one(0, arr[1]);
		else if (arr[0] == 2) two(1, arr[1]);
		else if (arr[0] == 3) three(2, arr[1]);
		else four(3, arr[1]);
	}

	int answer = 0;
	int a = 1;
	for (int i = 0; i < 4; i++) {
		int n = cur[i][0] - 2;
		if (n >= 0) {
			int b = wheel[i][n];
			answer = answer + (wheel[i][n]-48) * a;
		}
		else {
			n = 8 + n;
			answer = answer + (wheel[i][n] - 48) * a;
		}
		a *= 2;
	}

	cout << answer;

	return 0;
}

void one(int n, int d){
	if (n < 3 && wheel[n][cur[n][0]] != wheel[n + 1][cur[n + 1][1]]) {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				if (cur[n][i] - 1 < 0) cur[n][i] = 7;
				else cur[n][i] = cur[n][i] - 1;
			}
			one(n + 1, -1);
		}
		else {
			for (int i = 0; i < 2; i++) {
				cur[n][i] = (cur[n][i] + 1) % 8;
			}
			one(n + 1, 1);
		}
	}
	else {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				if (cur[n][i] - 1 < 0) cur[n][i] = 7;
				else cur[n][i] = cur[n][i] - 1;
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				cur[n][i] = (cur[n][i] + 1) % 8;
			}
		}
	}
}
void two(int n, int d) {
	if (wheel[n][cur[n][1]] != wheel[n - 1][cur[n - 1][0]]) {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				cur[n - 1][i] = (cur[n - 1][i] + 1) % 8;
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				if (cur[n - 1][i] - 1 < 0) cur[n - 1][i] = 7;
				else cur[n - 1][i] = cur[n - 1][i] - 1;
			}
		}
	}
	one(n, d);
}

void three(int n, int d) {
	if (wheel[n][cur[n][0]] != wheel[n + 1][cur[n + 1][1]]) {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				cur[n + 1][i] = (cur[n + 1][i] + 1) % 8;
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				if (cur[n + 1][i] - 1 < 0) cur[n + 1][i] = 7;
				else cur[n + 1][i] = cur[n + 1][i] - 1;
			}
		}
	}
	four(n, d);
}

void four(int n, int d) {
	if (n > 0 && wheel[n][cur[n][1]] != wheel[n - 1][cur[n - 1][0]]) {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				if (cur[n][i] - 1 < 0) cur[n][i] = 7;
				else cur[n][i] = cur[n][i] - 1;
			}
			four(n - 1, -1);
		}
		else {
			for (int i = 0; i < 2; i++) {
				cur[n][i] = (cur[n][i] + 1) % 8;
			}
			four(n - 1, 1);
		}
	}
	else {
		if (d == 1) {
			for (int i = 0; i < 2; i++) {
				if (cur[n][i] - 1 < 0) cur[n][i] = 7;
				else cur[n][i] = cur[n][i] - 1;
			}
		}
		else {
			for (int i = 0; i < 2; i++) {
				cur[n][i] = (cur[n][i] + 1) % 8;
			}
		}
	}
}