m>
#include<vector>
using namespace std;

int partition(vector<int> &a,int p,int r);
void quicksort(vector<int> &a,int p,int r);

int main() {
	vector<int> a= {18,27,32,11,25,73,42,12,44,55,27,98,67};
	quicksort(a,0,a.size()-1);
	for(int i=0; i!=a.size(); ++i) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

int partition(vector<int> &a,int p,int r) {
	int x,i,temp;
	x=a[r];
	i=p-1;
	for(int j=p; j!=r; ++j) {
		if(a[j]<=x) {
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	int temp1;
	temp1=a[i+1];
	a[i+1]=a[r];
	a[r]=temp1;
	return i+1;
}

void quicksort(vector<int> &a,int p,int r) {
	if(p<r) {
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
