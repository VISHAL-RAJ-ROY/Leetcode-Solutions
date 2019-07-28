#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_map<pair<int,int>,int> p;
	p[make_pair(1,2)] = 3;
	cout<<p[make_pair(1,2)]<<"\n";
  	return 0;
}
