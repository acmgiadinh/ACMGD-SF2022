/**
 * This code either generates number of villages, the coordinates of each and the corresponding time of attacks
 * or solve an instance of the problem.
 * 
 * Author: Khau Dang Nhat Minh
 **/
 
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <string>
 
using namespace std;

/*****Macros*******************/
// #define SOLVE_INSTANCE
// #define ALLOW_VILLAGE_AT_CURRENT_POSITION
// #define RANDOM_VELOCITY
#define PRINT_ANSWER
/******************************/
 
/*****Configuration************/

#ifdef RANDOM_VELOCITY
const int MIN_V = 1;
const int MAX_V = 10;
#else
const int V = 5;
#endif

const int MIN_N = 20;
const int MAX_N = 30;

const int MIN_X = -30;
const int MAX_X = 30;

const int MIN_T = 1;
const int MAX_T = 50;
/******************************/
 
int n, v;
long long x[MAX_N + 1], y[MAX_N + 1];
int id[MAX_N + 1];
long long y_vals[MAX_N + 1];
int FT[MAX_N + 1];
bool occupied[MAX_X - MIN_X + 1];
int dp[MAX_N + 1];

int random(int l, int r) {
	return rand() % (r - l + 1) + l;
}

template<typename T>
void reorder(T *a, int *id, int n) {
	T* b = new T[n];
	for (int i = 0; i < n; ++i)
		b[i] = a[i];
	for (int i = 0; i < n; ++i)
		a[i] = b[id[i]];
	delete[] b;
}
 
int get(int y) {
	int i = lower_bound(y_vals, y_vals + n + 1, y) - y_vals + 1;
	int res = -1e9;
	for (; i > 0; i -= i & -i)
		res = max(res, FT[i - 1]);
	return res;
}
 
void update(int y, int v) {
	int i = lower_bound(y_vals, y_vals + n + 1, y) - y_vals + 1;
	for (; i <= n + 1; i += i & -i)
		FT[i - 1] = max(FT[i - 1], v);
}
 
int main(int argc, char **argv) {
	srand(time(NULL));
	
    // Inputting or generating instance
#ifdef SOLVE_INSTANCE
	if (argc == 1) {
		cin >> v >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
			cin >> y[i];
	}
	else {
		ifstream fi("problem instances/" + string(argv[1]) + ".inp");
		fi >> v >> n;
		for (int i = 0; i < n; ++i)
			fi >> x[i];
		for (int i = 0; i < n; ++i)
			fi >> y[i];
		fi.close();
	}
#else
#ifdef RANDOM_VELOCITY
	v = random(MIN_V, MAX_V);
#else
	v = V;
#endif // RANDOM_VELOCITY
	n = random(MIN_N, MAX_N);
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
	occupied[-MIN_X] = true;
#endif // ALLOW_VILLAGE_AT_CURRENT_POSITION
	for (int i = 0; i < n; ++i) {
		do {
			x[i] = random(MIN_X, MAX_X);
		} while (occupied[x[i] - MIN_X]);
		occupied[x[i] - MIN_X] = true;
		y[i] = random(MIN_T, MAX_T);
	}
#endif // SOLVE_INSTANCE

    // Preprocessing
    for (int i = 0; i < n; ++i) id[i] = i;
	sort(id, id + n, [](int i, int j) {
		return x[i] < x[j];
	});
	reorder(x, id, n);
	reorder(y, id, n);
	
    // Current instance
	cout << "Van toc toi da cua Anh hung: " << v << endl;
	cout << "So ngoi lang bi tan cong: " << n << endl;
	cout << "Toa do:   ";
	for (int i = 0; i < n; ++i) {
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[i] > 0 && (i == 0 || x[i - 1] < 0))
			printf("   0");
#endif
		printf(" %3d", x[i]);
	}
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[n - 1] < 0)
			printf("   0");
#endif
	cout << endl;
	cout << "Thoi diem:";
	for (int i = 0; i < n; ++i) {
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[i] > 0 && (i == 0 || x[i - 1] < 0))
			printf("  AH");
#endif
		printf(" %3d", y[i]);
	}
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[n - 1] < 0)
			printf("  AH");
#endif
	cout << endl;

    // Solving
	for (int i = 0; i < n; ++i)
		y[i] = y_vals[i] = x[i] + v * y[i],
		x[i] = y[i] - 2 * x[i];
	sort(id, id + n, [](int i, int j) {
		return x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]);
	});
	y_vals[n] = 0;
	sort(y_vals, y_vals + n + 1);
 
	for (int i = 0; i <= n; ++i)
		FT[i] = -1e9;
	update(0, 0);
	for (int i = 0; i < n; ++i) {
		if (x[id[i]] >= 0)
			dp[id[i]] = get(y[id[i]]) + 1,
			update(y[id[i]], dp[id[i]]);
		else
			dp[id[i]] = -1;
	}

    // Answer
#ifdef PRINT_ANSWER
	cout << "DP:       ";
	for (int i = 0; i < n; ++i) {
		x[i] = y[i] - (x[i] + y[i]) / 2;
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[i] > 0 && (i == 0 || x[i - 1] < 0))
			printf("   0");
#endif
		if (dp[i] >= 0) printf(" %3d", dp[i]);
		else printf("   X");
	}
#ifndef ALLOW_VILLAGE_AT_CURRENT_POSITION
		if (x[n - 1] < 0)
			printf("   0");
#endif
	cout << endl;
	cout << "So luong toi da cac ngoi nha co the cuu: " << get(y_vals[n]) << endl;
#endif
}
