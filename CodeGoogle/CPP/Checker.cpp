#include<bits/stdc++.h>
using namespace std;
ifstream W ("/home/anushi/CLionProjects/Complete/Wrong.txt");
ifstream C ("/home/anushi/CLionProjects/Complete/Correct.txt");

int main(){
	cout<<"CHECKER\n";
	long long int shi,glt;
	int i=1;
	while(W>>glt && C>>shi){
		// cout<<shi<<" "<<glt<<" ";
		if(shi!=glt){
			cout<<shi<<" "<<glt<<endl;
			return 1;
		}
		// i++;
	}
	return 0;
}

