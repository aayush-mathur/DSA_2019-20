#include<iostream>
#include<stack>
using namespace std;

void pass_through_the_doors(int Aj[], int n, int k){
	stack<int> store;
	stack<int> bag;
	int cost = 0;

	char c;
	for(int i=0; i<n; i++){
		cin >> c;
		bool found = false;
		int depth = 1;
		// cout <<"index i: " << i <<  " bag size: " << bag.size() << endl;
		while(bag.size() && depth<=k){
			//start checking the bag from top
			// cout<<"depth is: " << depth << endl;
			int ticket = bag.top();
			bag.pop();
			// cout << "checking " << c-'A' << " with " << ticket << endl;
			if(ticket == c -'A'){
				// cout << "found\n";
				//if you find the ticket then put back the stuff in store into the bag
				while(store.size()){
					int storetp = store.top();
					store.pop();
					bag.push(storetp);
				}
				found = true;
				break;
			}
			//else put the ticket into the store and continue till depth k
			store.push(ticket);
			// cout << "bag size: " << bag.size() << endl;
			depth++;
		}
		//if you don't find the ticket in depth k then buy it
		if(!found){
			while(store.size()){
				int storetp = store.top();
				store.pop();
				bag.push(storetp);
			}
			//add the cost
			cost += Aj[c-'A'];
			// cout <<"current cost at number "<<i+1 <<" is " << cost <<endl;
			//put one extra ticket which is left
			bag.push(c-'A');
		}
	}

	cout << cost << " " << bag.size() << endl;

	// cout <<"bag\n";
	// while(bag.size()){
	// 	cout << bag.top()<< " ";
	// 	bag.pop();
	// }
	// cout <<endl;
}

int main(){
	int n, t, k;
	cin >>  n  >> t >> k;

	int Aj[26];
	
	char c;
	int x;
	for(int i=0; i<t; i++){
		cin >> c >> x;
		// cout << "c-'A' and x: "  << c -'A'<< " " << x << endl;
		Aj[c-'A'] = x;
		// cout << "Aj: " << Aj[i] << endl;
	}

	// for(int i=0; i<n; i++){
	// 	cout << Aj[i] << " ";
	// }
	// cout << endl;


	pass_through_the_doors(Aj, n, k);
	return 0;
}
