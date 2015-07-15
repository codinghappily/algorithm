#include<iostream>
#include<vector>
using namespace std;
void insert_sort(vector<int> iv);
int main(){
	int i;
	vector<int> iv;
	while(cin>>i){
		iv.push_back(i);
	}
	insert_sort(iv);
	return 0;
}
void insert_sort(vector<int> iv){
	for(vector<int>::size_type j=1;j!=iv.size();j++){
		int key=iv[j];
		vector<int>::size_type i=j-1;
		while((i>=0)&&(iv[i]>key)){
			int temp;
			temp=iv[i+1];
			iv[i+1]=iv[i];
			iv[i]=temp;
			i--;
		}
	}
	for(vector<int>::iterator iter=iv.begin();iter!=iv.end();iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
}
