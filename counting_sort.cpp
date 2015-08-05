#include<iostream>
#include<vector>
using namespace std;

class CountingSort {
	public:
		CountingSort(vector<int> va,vector<int> vb,int k);
};

CountingSort::CountingSort(vector<int> va,vector<int> vb,int k){
	vector<int> vc(k+1,0);
	for(size_t i=0; i!=va.size(); i++) {
		vc[va[i]]+=1;
	}
	for(size_t j=1; j!=vc.size(); j++) {
		vc[j]+=vc[j-1];
	}

	for(size_t k=va.size()-1; k!=-1; k--) {
		vb[vc[va[k]]]=va[k];
		vc[va[k]]-=1;
	}
	for(vector<int>::iterator iter=vb.begin(); iter!=vb.end(); iter++) {
		cout<<(*iter)<<" ";
	}
	cout<<endl;
}

int main(){
	vector<int> va= {2,5,3,0,2,3,0,3},vb;
	vb.resize(va.size()+1);
	CountingSort cs(va,vb,5);
	return 0;
}
