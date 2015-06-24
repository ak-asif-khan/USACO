/*
ID: asif.ci1
LANG: C++
TASK: gift1
*/

/*
Algorithm: Ad hoc
Complexity: O(N)
*/

// Problem Link: http://train.usaco.org/usacoprob2?a=OTYa1aYnmXk&S=gift1
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

#define MAX 15

vector< string > names;
map< string, int > nameMap;
int N;
int initialMoney[ MAX ];
int moneyValue[ MAX ];


int main() {
//	freopen("gift1.in", "r", stdin);
//	freopen("gift1.out", "w", stdout);

	int i, j, money, friends;
	string name, friendName;
	while(scanf("%d", &N) == 1) {
		nameMap.clear();
		memset(moneyValue, 0, sizeof(moneyValue));

		for(i = 0; i < N; i ++) {
			cin >> name;
			nameMap[ name ] = i + 1;
			names.push_back(name);
		}

		for(i = 0; i < N; i ++) {
			cin >> name;
			scanf("%d %d", &money, &friends);

			int senderIndex = nameMap[ name ];
			initialMoney[ senderIndex ] = money;
			moneyValue[ senderIndex ] += money;

			if(friends > 0) {
				int costPerFriend = money / friends;
				moneyValue[ senderIndex ] -= (costPerFriend * friends);

				for(j = 0; j < friends; j ++) {
					cin >> friendName;

					int friendIndex = nameMap[ friendName ];
					moneyValue[ friendIndex ] += costPerFriend;
				}
			}
		}

		for(i = 0; i < N; i ++) {
			int index = nameMap[ names[ i ] ];
			printf("%s %d\n", names[ i ].c_str(), moneyValue[ index ] - initialMoney[ index ]);
		}


	}


	return 0;
}
