#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int dp[10000] = {0,1,2,3,4,5,4,3,2,1,1,1,2,3,4,5,5,4,3,2,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,6,6,5,5,5,5,5,5,5,5,5,5,5,4,5,6,6,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,1,2,3,4,5,5,4,3,2,1,1,2,3,4,5,6,5,4,3,2,1,1,2,3,4,5,5,4,3,2,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,6,6,6,5,6,6,6,6,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,2,3,4,5,6,7,6,5,4,3,2,2,3,4,5,6,6,5,4,3,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,7,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,6,7,7,7,7,7,7,6,6,6,5,6,7,8,8,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,4,4,4,4,4,5,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,5,5,5,5,5,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,5,5,5,5,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,4,5,6,6,6,5,4,4,4,4,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,2,1,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,1,2,3,4,5,5,4,3,2,1,1,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,1,2,3,4,5,6,5,4,3,2,1,1,2,3,4,5,5,4,3,2,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,6,6,6,5,6,6,6,6,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,2,3,4,5,6,7,6,5,4,3,2,2,3,4,5,6,6,5,4,3,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,7,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,6,7,7,7,7,7,7,6,6,6,5,6,7,8,8,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,8,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,9,8,7,6,5,5,5,5,6,7,8,8,7,6,5,5,5,5,5,6,7,7,7,6,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,6,6,7,8,9,9,9,8,7,6,6,6,6,7,8,8,8,8,7,6,6,6,6,6,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,6,5,5,5,5,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,9,9,8,7,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,6,6,6,6,6,5,6,7,7,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,7,6,6,6,6,6,5,6,7,8,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,7,7,7,7,6,7,7,7,7,6,6,6,6,6,5,6,7,8,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,6,6,6,6,6,6,7,7,7,7,6,7,7,7,7,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,2,2,3,4,5,6,6,5,4,3,2,2,2,3,4,5,6,5,4,3,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,7,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,6,7,7,7,7,7,7,6,6,6,5,6,7,8,8,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,8,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,9,8,7,6,5,5,5,5,6,7,8,8,7,6,5,5,5,5,5,6,7,8,7,6,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,6,7,8,9,9,9,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,10,10,9,8,7,6,6,6,7,8,9,10,9,8,7,6,6,6,6,7,8,9,9,8,7,6,6,6,6,6,7,8,8,8,7,6,6,6,6,6,6,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,10,10,9,8,7,7,7,7,8,9,9,9,9,8,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,6,6,6,6,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,7,7,7,7,7,6,7,8,8,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,8,8,8,8,7,8,8,8,8,7,7,7,7,7,6,7,8,9,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,8,9,9,9,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,9,8,7,7,7,7,7,7,7,8,8,8,8,7,8,8,8,8,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,6,6,6,6,6,6,7,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,3,3,3,3,4,5,6,6,5,4,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,6,7,7,7,7,7,7,6,6,6,5,6,7,8,8,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,4,4,4,4,4,5,6,7,6,5,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,8,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,9,8,7,6,5,5,5,5,6,7,8,8,7,6,5,5,5,5,5,6,7,8,7,6,5,5,5,5,5,5,6,7,7,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,6,7,8,9,9,9,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,10,10,9,8,7,6,6,6,7,8,9,10,9,8,7,6,6,6,6,7,8,9,9,8,7,6,6,6,6,6,7,8,9,8,7,6,6,6,6,6,6,7,8,8,7,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,7,7,7,8,9,9,9,9,9,9,8,7,6,7,8,9,10,10,10,9,8,7,7,7,8,9,10,11,11,10,9,8,7,7,7,8,9,10,11,10,9,8,7,7,7,7,8,9,10,10,9,8,7,7,7,7,7,8,9,9,9,8,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,8,8,8,8,9,10,10,10,10,9,8,8,8,8,8,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,7,7,7,7,6,7,8,8,8,8,7,6,6,6,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,10,10,9,8,8,8,8,8,8,9,9,9,9,9,8,9,9,9,9,8,8,8,8,8,7,8,9,9,9,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,10,10,9,8,8,8,8,8,8,9,10,10,10,9,9,9,9,9,9,9,9,9,9,9,8,9,10,10,10,9,8,8,8,8,7,8,9,10,10,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,9,9,9,8,8,8,8,8,8,8,9,9,9,9,8,9,9,9,9,9,8,8,8,8,7,8,9,10,10,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,8,9,9,9,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,7,7,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,6,7,8,9,9,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,4,4,4,4,4,5,6,6,6,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,9,8,7,6,5,5,5,5,6,7,8,8,7,6,5,5,5,5,5,6,7,7,7,6,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,10,10,9,8,7,6,6,6,7,8,9,10,9,8,7,6,6,6,6,7,8,9,9,8,7,6,6,6,6,6,7,8,8,8,7,6,6,6,6,6,6,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,6,7,8,9,10,10,10,9,8,7,7,7,8,9,10,11,11,10,9,8,7,7,7,8,9,10,11,10,9,8,7,7,7,7,8,9,10,10,9,8,7,7,7,7,7,8,9,9,9,8,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,6,7,8,9,10,10,10,9,8,7,7,7,8,9,10,11,11,10,9,8,8,8,8,9,10,11,12,11,10,9,8,8,8,8,9,10,11,11,10,9,8,8,8,8,8,9,10,10,10,9,8,8,8,8,8,8,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,8,7,7,7,6,7,8,8,8,8,8,7,6,6,6,7,8,9,9,9,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,8,8,8,8,9,10,11,11,10,9,9,9,9,9,9,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,8,9,9,9,9,9,8,8,8,8,7,8,9,9,9,9,8,7,7,7,6,7,8,9,9,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,10,10,9,8,8,8,8,8,9,10,10,10,10,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,9,10,10,10,10,10,9,9,9,9,8,9,10,10,10,10,9,8,8,8,7,8,9,10,10,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,9,9,8,7,7,7,7,7,8,9,9,9,9,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,9,9,9,9,8,9,10,11,11,10,9,8,8,8,7,8,9,10,11,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,8,8,8,8,8,9,10,10,10,10,9,8,8,8,7,8,9,10,11,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,8,9,9,9,9,8,7,7,7,7,8,9,10,10,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,6,6,6,6,6,7,8,8,8,8,7,6,6,6,6,7,8,9,9,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,5,5,5,5,5,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,5,5,5,5,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,6,6,7,8,9,9,9,8,7,6,6,6,6,7,8,8,8,8,7,6,6,6,6,6,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,6,5,5,5,5,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,10,10,9,8,7,7,7,7,8,9,9,9,9,8,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,7,6,6,6,6,5,6,7,7,7,7,6,5,5,5,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,8,8,8,8,9,10,10,10,10,9,8,8,8,8,8,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,8,7,7,7,7,6,7,8,8,8,8,7,6,6,6,5,6,7,8,8,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,8,8,8,8,9,10,11,11,10,9,9,9,9,9,9,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,8,9,9,9,9,9,8,8,8,8,7,8,9,9,9,9,8,7,7,7,6,7,8,9,9,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,10,10,9,8,8,8,8,8,8,9,10,10,10,9,9,9,9,9,9,9,9,9,9,9,8,9,10,10,10,9,8,8,8,8,7,8,9,10,10,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,9,9,8,7,7,7,7,7,8,9,9,9,9,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,9,9,9,9,8,9,10,11,11,10,9,8,8,8,7,8,9,10,11,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,8,8,8,8,8,8,9,10,10,10,9,8,8,8,8,8,9,10,11,11,10,9,8,8,8,8,9,10,11,12,11,10,9,8,8,7,8,9,10,11,11,10,9,8,7,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,8,9,9,9,8,7,7,7,7,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,7,7,7,8,9,10,11,11,10,9,8,7,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,6,6,6,6,6,6,7,8,8,8,7,6,6,6,6,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,5,6,7,7,7,6,5,5,5,5,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,4,5,6,6,6,5,4,4,4,4,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,9,9,8,7,7,7,7,7,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,7,6,6,6,6,6,5,6,7,7,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,8,8,8,8,7,7,7,7,7,6,7,8,8,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,7,7,7,7,8,9,10,10,9,8,8,8,8,8,8,9,9,9,9,9,8,9,9,9,9,8,8,8,8,8,7,8,9,9,9,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,9,9,9,8,8,8,8,8,8,8,8,8,8,8,7,8,9,9,9,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,9,9,9,8,8,8,8,8,8,8,9,9,9,9,8,9,9,9,9,9,8,8,8,8,7,8,9,10,10,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,8,8,8,8,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,8,8,8,8,8,9,10,10,10,10,9,8,8,8,7,8,9,10,11,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,7,7,7,7,7,7,8,9,9,9,8,7,7,7,7,7,8,9,10,10,9,8,7,7,7,7,8,9,10,11,10,9,8,7,7,7,8,9,10,11,11,10,9,8,7,6,7,8,9,10,10,10,9,8,7,7,7,8,9,9,9,9,9,9,8,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,6,7,8,8,7,6,6,6,6,6,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,9,9,9,8,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,7,6,6,6,6,6,5,6,7,8,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,6,6,6,6,7,8,9,9,8,7,7,7,7,7,7,8,8,8,8,8,7,8,8,8,8,7,7,7,7,7,6,7,8,9,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,9,8,7,7,7,7,7,7,7,8,8,8,8,7,8,8,8,8,8,7,7,7,7,6,7,8,9,9,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,8,8,8,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,7,8,9,9,9,9,8,7,7,7,6,7,8,9,10,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,7,7,7,7,7,8,9,9,9,9,8,7,7,7,7,8,9,10,10,10,9,8,7,7,6,7,8,9,10,10,9,8,7,6,6,7,8,9,10,10,10,9,8,7,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,6,6,6,6,6,6,7,8,8,8,7,6,6,6,6,6,7,8,9,9,8,7,6,6,6,6,7,8,9,10,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,9,9,9,8,7,7,7,7,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,2,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,8,8,7,6,6,6,6,6,6,7,7,7,7,7,6,7,7,7,7,6,6,6,6,6,5,6,7,8,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,1,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,7,6,5,5,5,5,4,5,6,7,7,6,5,4,4,4,3,4,5,6,7,6,5,4,3,3,2,3,4,5,6,6,5,4,3,2,2,3,4,5,6,7,6,5,4,3,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,6,6,6,6,6,6,7,7,7,7,6,7,7,7,7,7,6,6,6,6,5,6,7,8,8,7,6,5,5,5,4,5,6,7,8,7,6,5,4,4,3,4,5,6,7,7,6,5,4,3,3,4,5,6,7,8,7,6,5,4,3,3,4,5,6,7,7,6,5,4,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,8,7,6,6,6,6,6,6,6,7,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,8,8,8,8,7,6,6,6,5,6,7,8,9,8,7,6,5,5,4,5,6,7,8,8,7,6,5,4,4,5,6,7,8,9,8,7,6,5,4,4,5,6,7,8,8,7,6,5,4,4,4,5,6,7,8,7,6,5,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,7,7,7,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,7,7,7,6,7,8,9,9,9,8,7,6,6,5,6,7,8,9,9,8,7,6,5,5,6,7,8,9,10,9,8,7,6,5,5,6,7,8,9,9,8,7,6,5,5,5,6,7,8,8,8,7,6,5,5,5,5,6,7,7,7,7,6,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,6,6,6,6,6,7,8,8,8,8,7,6,6,6,6,7,8,9,9,9,8,7,6,6,6,7,8,9,10,10,9,8,7,6,5,6,7,8,9,10,9,8,7,6,6,6,7,8,9,9,9,9,8,7,6,6,6,7,8,8,8,8,8,7,6,6,6,6,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,5,6,7,7,7,6,5,5,5,5,5,6,7,8,8,7,6,5,5,5,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,5,4,5,6,7,8,9,8,7,6,5,5,5,6,7,8,9,9,8,7,6,6,6,6,7,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,4,3,4,5,6,7,8,7,6,5,4,4,4,5,6,7,8,8,7,6,5,5,5,5,6,7,8,8,8,7,6,6,6,6,6,7,7,7,7,7,7,6,7,7,7,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,3,2,3,4,5,6,7,6,5,4,3,3,3,4,5,6,7,7,6,5,4,4,4,4,5,6,7,8,7,6,5,5,5,5,5,6,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,5,6,7,7,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,2,1,2,3,4,5,6,5,4,3,2,2,2,3,4,5,6,6,5,4,3,3,3,3,4,5,6,7,6,5,4,4,4,4,4,5,6,7,7,6,5,5,5,5,5,5,6,6,6,6,6,5,6,6,6,6,5,5,5,5,5,4,5,6,7,6,5,4,4,4,4,3,4,5,6,6,5,4,3,3,3,2,3,4,5,6,5,4,3,2,2,1,2,3,4,5,5,4,3,2,1};

int cal(int a, int b, int c, int d) {
    return (a+10)%10*1000+(b+10)%10*100+(c+10)%10*10+(d+10)%10;
}

void dfs(int i) {
    int a = i/1000%10;
    int b = i/100%10;
    int c = i/10%10;
    int d = i%10;

    int idx = cal(a-1, b-1, c-1, d-1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a-1, b-1, c-1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b-1, c-1, d-1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a-1, b-1, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b-1, c-1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c-1, d-1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a-1, b, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b-1, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c-1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c, d-1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a+1, b+1, c+1, d+1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a+1, b+1, c+1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }
    
    idx = cal(a, b+1, c+1, d+1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a+1, b+1, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b+1, c+1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c+1, d+1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a+1, b, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b+1, c, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c+1, d);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }

    idx = cal(a, b, c, d+1);
    if (dp[idx] > dp[i]+1) {
        dp[idx] = dp[i] + 1;
        dfs(idx);
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false); 
    // fill(dp, dp+10000, 99999);
    // dp[0] = 0;
    // dfs(0);

    // freopen("J.out", "w", stdout);
    // for (int i = 0; i < 10000; ++i) {
    //     cout << dp[i] << ",";
    // }

    int T;
    cin >> T;
    while (T--) {
        int s, t;
        cin >> s >> t;
        int a = ((s/1000%10)-(t/1000%10)+10)%10;
        int b = ((s/100%10)-(t/100%10)+10)%10;
        int c = ((s/10%10)-(t/10%10)+10)%10;
        int d = ((s%10)-(t%10)+10)%10;

        cout << dp[cal(a, b, c, d)] << endl;
    }

    return 0;
}
