#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main (int argc, char * const argv[]) {
	int total = 0;
	string str,stri,strF,strV;
	int numberi,numberF,numberV;
	vector<int> I; // vectors to store values of I,V,F
	vector<int> V;
	vector<int> F;

	while(getline(cin,str)){
		stri = str.substr(0,2);
		int numberi = atoi(stri.c_str()); // put every i,v,F values we get into 3 vectors
		I.push_back(numberi);
		
		strV = str.substr(3,2);
		int numberV = atoi(strV.c_str());
		V.push_back(numberV);
		
		strF = str.substr(7,1);
		int numberF = atoi(strF.c_str());
		F.push_back(numberF);
		
		total = total + 1;	
			
	}

	I.resize(total);
	V.resize(total);
	F.resize(total);
	int i2[total] ;
	int F2[total];
	int V2[total];
	int S[total];  // S is the solution array, s[i] represents the optimal solution for V[i] to V[total-1]
	bool B[total];
	for( int k = total-1; k >= 0; k--){  // put the values from the vector into 3 arrays
			i2[k] = I.back();
			I.pop_back();
			F2[k] = F.back();
			F.pop_back();
			V2[k] = V.back();
			V.pop_back();
	}
	S[total-1] = V2[total-1];  // copy the last value to S[total-1]
	B[total-1] = true;  // we select the last one]
	for ( int i = total-2;i>=0;i--){
		B[i] = true;
		if( i+F2[i]+1 >= total) S[i+F2[i]+1] = 0; // put the array indexes beyond to value 0
		S[i] = V2[i] + S[i+F2[i]+1]; // the value if we take V[i]
		if(S[i] < S[i+1]){ // if we had better not take V[i], set c[i] to false, and the opt solution now is still same as S[i+1]
			S[i] = S[i+1];
			B[i] = false;
		}
	}
	cout << S[0] << endl;
	int j = 0;int k = 0;
	while ( j < total) {
		if(B[j]){
			cout <<right << setw(2)<< i2[j] << " " << right << setw(2)<< V2[j] <<" "<< F2[j] <<" "<< "Y" << endl;
			k = j+F2[j] +1; // the next tribute we can visit is k
			j++;
			while(j<k){  // for all the tribute beween j and k, print no
				cout <<right << setw(2)<< i2[j] << " " << right << setw(2)<< V2[j] <<" "<< F2[j] <<" "<< "N" << endl;
				j ++;
			}
		}
		else { // not within the region i+f[i], but we are not taking it
			cout <<right << setw(2)<< i2[j] << " " << right << setw(2) << V2[j] <<" "<< F2[j] <<" "<< "N" << endl;
			j++;
		}
			
	}			
}

