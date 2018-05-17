/*
NAYAN KHANNA
BITS PILANI UNDERGRADUATE
AIDapp Internship Code
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// n is the number of monkeys
	long int n;
	cin>>n;
	long int i=0, arr[n];
	long int k;
	// k is the max life i.e here 2000.
	for (i=0; i<n;i++)
	cin>>arr[i];
	//Formatting not needed in case of integers
	//taken the damage of each monkey.

	long int cnt=0, sum=0, maxcnt=0, d=1, D;
	// D is the max number of injuries possible here it is 1000000
	// d is the injuries variable. 
    for (int i = 0; i < n; i++) {
         
        // If current monkey's damage is within range 
        // then fight the monkey
        if ((sum + arr[i]) <= k && (arr[i]*d)<=D) {
            sum += arr[i]; 
            d*= arr[i];
            cnt++;
        } 
        // cnt is the counter of maximum monkeys which can be fighted.
 
        // Else, remove the first monkey of this window
        // add the current monkey 
        else if(sum!=0)
        {
            sum = sum - arr[i - cnt] + arr[i];
	    d /= arr[i-cnt];
            d *= arr[i];
        }
 
        // keep track of max length.
        maxcnt = max(cnt, maxcnt); 
    }

    cout << maxcnt;
    // print the number of max monkeys which can be fought
	return 0;
} 
