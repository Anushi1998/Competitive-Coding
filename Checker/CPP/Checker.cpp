#include<bits/stdc++.h>
using namespace std;
ifstream W ("..//TXT//Wrong.txt");
ifstream C ("..//TXT//Correct.txt");

int main(){
	cout<<"CHECKER\n";
	int right, wrong;
	int i=1;
	while(W>>wrong && C>>right){
		if(right!=wrong){
			cout<<right<<" "<<wrong<<endl;
			return 1;
		}
	}
	return 0;
}

