#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;
	v.reserve(10);
	for(int i=0;i<10;i++)
		v.push_back(i);

	for(vector<int>::const_iterator iter=v.begin();iter!=v.end();) {
		if(*iter==5)
			iter = v.erase(iter);
		else
			iter++;
	}

	for(vector<int>::const_iterator iter=v.begin();iter!=v.end();iter++)
		cout<<*iter<<endl;

	return 0;
}
