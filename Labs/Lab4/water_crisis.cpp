#include<iostream>
#include<stack>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

struct person{
	string name;
	int arrival, unitsReq;
};

bool cmp(person p1, person p2){
		return p1.arrival < p2.arrival;
}

class NeighbourHood{
	int n,q,k;
	vector<person> people;
public:

	NeighbourHood(int n, int q, int k){
		this->n = n;
		this->q = q;
		this->k = k;
		people.resize(n);
	}

	void input(){
		for(int i=0; i<n; i++){
			cin>>people[i].name;
		}
		for(int i=0; i<n; i++){
			cin>>people[i].arrival;
		}
		for(int i=0; i<n; i++){
			cin>>people[i].unitsReq;
		}
	}

	void water_crisis(){
		stack<string> s;
		queue<person> line;
		//sort according the arrival
		sort(people.begin(), people.end(), cmp);

		//keep a check on the number of unique visitors
		int x = 0;

		//push the first person to take water
		line.push(people[0]);
		x++;
		//initially time is 1
		int t = 1;

		while(!line.empty() || x<n){
			if(line.empty()){
				t++;
				while(x<n){
					if(people[x].arrival <= t){
						line.push(people[x]);
						x++;
					}
					else{
						break;
					}
				}
			}
			else{
				person current = line.front();
				line.pop();
				t = current.arrival;
				//update the time and the unitsReq
				if(current.unitsReq > q){
					current.unitsReq -= q;
					t += q;
				}
				else{
					t += current.unitsReq;
					current.unitsReq = 0;
					s.push(current.name);
				}

				//let the other people come if they haven't already
				while(x<n){
					if(people[x].arrival <= t){
						line.push(people[x]);
						x++;
					}
					else{
						break;
					}
				}

				//next push the current guy at the back if he still wants mnore
				if(current.unitsReq){
					line.push(current);
				}
			}

		}
		//output the names of last k pepole
		while(k--){
			string name = s.top();
			s.pop();
			cout << name << " ";
		}
		cout << endl;
	}
};	

int main(){
	int n,q,k;
	cin >> n >> q >> k;

	NeighbourHood N(n,q,k);

	N.input();
	N.water_crisis();
}