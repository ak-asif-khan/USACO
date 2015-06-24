/*
ID: asif.ci1
LANG: C++
TASK: ride
*/

/* 
Algorithm: Ad hoc
Complexity: O(N+M)
*/
#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<sstream>
using namespace std;

string comet, group;

const int MOD = 47;

int main() {
//	freopen("ride.in", "r", stdin);
//	freopen("ride.out", "w", stdout);	

	int i;
	while(cin >> comet) {
		cin >> group;

		int sizeComet = comet.size();
		int sizeGroup = group.size();

		int productComet = 1, productGroup = 1;

		for(i = 0; i < sizeComet; i ++) {
			productComet = (productComet * (comet[ i ] - 'A' + 1) ) % MOD;
		}

		for(i = 0; i < sizeGroup; i ++) {
			productGroup = (productGroup * (group[ i ] - 'A' + 1) ) % MOD;
		}

		if(productComet == productGroup) printf("GO\n");
		else printf("STAY\n");
	}
	return 0;
}
