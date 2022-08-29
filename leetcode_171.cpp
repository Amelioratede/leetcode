#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
	int result = 0;
	for(int i = columnTitle.length()-1; i>=0 ; i-- ){
		result += (columnTitle[i]-'A'+1)*pow(26,columnTitle.length()-i-1);
	}
	cout<<result<<endl;
	return 0;
}

int main(int argc, char const *argv[])
{
	string s = "AA";
	titleToNumber(s);
	return 0;
}
