// https://www.codechef.com/JUNE18B/problems/VSN

#include <bits/stdc++.h>

using namespace std;

long double pq[3];
long double q0[3];
long double qc[3];
long double c[3];
long double q[3];
long double p[3];
long double d[3];
long double radius;

inline long double compute_cross () {
	long double x = pq[1] * qc[2] - pq[2] * qc[1];
	long double y = pq[0] * qc[2] - pq[2] * qc[0];
	long double z = pq[0] * qc[1] - pq[1] * qc[0];
	return sqrt(x * x + y * y + z * z);
}

inline long double mod () {
	return sqrt(pq[0] * pq[0] + pq[1] * pq[1] + pq[2] * pq[2]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%Lf %Lf %Lf", &p[0], &p[1], &p[2]);
		scanf("%Lf %Lf %Lf", &q0[0], &q0[1], &q0[2]);
		scanf("%Lf %Lf %Lf", &d[0], &d[1], &d[2]);
		scanf("%Lf %Lf %Lf %Lf", &c[0], &c[1], &c[2], &radius);
		long double l = 0.0;
		long double r = 1e9;
		for (int i = 0; i < 50; ++i) {
			long double t = (l + r) / 2.0;
			q[0] = q0[0] + t * d[0];
			q[1] = q0[1] + t * d[1];
			q[2] = q0[2] + t * d[2];
			pq[0] = q[0] - p[0];
			pq[1] = q[1] - p[1];
			pq[2] = q[2] - p[2];
			qc[0] = c[0] - q[0];
			qc[1] = c[1] - q[1];
			qc[2] = c[2] - q[2];
			long double cross_product = compute_cross();
			long double val = radius * mod();
			if (val < cross_product) {
				r = t;
			} else {
				l = t;
			}
		}
		printf("%.9Lf\n", l);
	}
	return 0;
}