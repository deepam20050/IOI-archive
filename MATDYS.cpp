// https://www.codechef.com/problems/MATDYS

/* Basically we are first checking if 2 divides the current k. If it does divide
 * then we simply reduce the current problem to that of the left subarray. 
 * But if the current k is odd (i.e, not divisible by k) then we look into the the left
 * subarray and then also add how much of deviation from that index is needed to reach
 * the index of the solution.
 */

/* The proof is that all the smaller subarrays follow a common pattern of shifting.
 * Whenever we've an even current k then its for obvious it will go to the left subarray since 
 * all even numbers goto the left subarray.
 * Now if current k is odd then we add how much of deviation (here deviation is group size i.e, 1, 2, 4, 8, ... , 2 ^ n)
 * takes place from the mirror of the current element in the left subarray (here mirror means the element with the exact same position in the array of size n / 2 ^ n but in the left subarray)
 * We are working with the left subarray as it is much easier to work with the left subarray.
 */

#include "bits/stdc++.h"

using namespace std;
using ll = unsigned long long;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		ll k;
		scanf("%d %llu", &n, &k);
		ll rem = 1LL << (n - 1);
		ll dx = 0;
		for (int i = 0; i <= 64; ++i) {
			if (k & 1) {
				dx += rem;
			}
			k >>= 1;
			rem >>= 1;
		}
		printf("%llu\n", k + dx);
	}
	return 0;
}