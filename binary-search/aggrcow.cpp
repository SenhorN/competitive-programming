//source: http://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>

using namespace std;

long int stalls[100000];
long int c, n;

bool distPossb(int dist){ //if it's possible to assign 'c' cows with distance 'dist' between them
	long int assigned = 1, last = stalls[0]; //assign to the first stall
	
	for(long int i = 1; i < n; i++){
		if(stalls[i] - last >= dist){ //assign to the most left stall after the last assigned		
			assigned++;
			if(assigned == c) //if the cows was all assigned
				return 1;
			
			last = stalls[i];
		}
	}
	
	return 0; //it were not possible to assign all cows
}

int main(){
	int t;
	long int x, start, end, mid;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n >> c;
		
		for(long int j = 0; j < n; j++){
			cin >> x;
			
			stalls[j] = x;
		}
		
		sort(stalls, stalls + n); //monotonic
		
		start = 0, end = stalls[n - 1] - stalls[0];
		
		if(c > 2){
			while(start <= end){ //binary search algorithm for distances
				mid = (start + end) >> 1;
			
				if(distPossb(mid)) //trying to improve the distances between the cows
					start = mid + 1;
				else
					end = mid - 1;
			}
		
			cout << mid;
		} else
			cout << end; //largest minimum distance for 2 cows is the distance between the first and the last stall 
		
		if(i != t - 1)
			cout << endl;
	}
	
	return 0;
}
