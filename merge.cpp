include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> iv,vector<int>::size_type p,vector<int>::size_type q,vector<int>::size_type r);
int main()
{
	int i;
	vector<int> iv;
	while(cin>>i)
	{
		iv.push_back(i);
	}
	vector<int>::size_type p=0;
	vector<int>::size_type r=iv.size()-1;
	vector<int>::size_type q=(p+r)/2;
	merge(iv,p,q,r);
	return 0;
}
void merge(vector<int> iv,vector<int>::size_type p,vector<int>::size_type q,vector<int>::size_type r)
{
	vector<int> iv1,iv2;
	for(vector<int>::size_type i=0;i!=q+1;i++)
	{
		iv1.push_back(iv[i]);
	}
	iv1.push_back(100);
	for(vector<int>::size_type i=q+1;i!=r+1;i++){
		iv2.push_back(iv[i]);
	}
	iv2.push_back(100);
	vector<int>::iterator iter1=iv1.begin(),iter2=iv2.begin();
	for(vector<int>::size_type i=0;i!=iv.size();i++)
	{
		if(*iter1!=100||*iter2!=100)
		{
			if(*iter1>=*iter2)
			{
				iv[i]=*iter2;
			    iter2++;
			}
			else
			{
				iv[i]=*iter1;
				iter1++;
			}
		}
	}
	for(vector<int>::iterator iter=iv.begin();iter!=iv.end();iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
}
