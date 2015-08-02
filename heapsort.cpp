#include<iostream>
#include<vector>
using namespace std;

class HeapSort {
	public:
		inline int left(int i) {
			return 2*i+1;
		}
		inline int right(int i) {
			return 2*(i+1);
		}
		HeapSort(vector<int> &iv);
		void build_max_heap(vector<int> &iv);
		void max_heapify(vector<int> &iv,int i);
	private:
		vector<int> iv1;
		int l,r,largest,temp;
};

HeapSort::HeapSort(vector<int> &iv)
{
	build_max_heap(iv);
	for(size_t i=iv.size()-1; i!=0; i--) {
		temp=iv[0];
		iv[0]=iv[i];
		iv[i]=temp;
		iv1.push_back(*(iv.end()-1));
		iv.pop_back();
		max_heapify(iv,0);
	}
	iv1.push_back(iv[0]);
	for(size_t i=iv1.size()-1; i!=-1; --i) {
		cout<<iv1[i]<<" ";
	}
	cout<<endl;
}

void HeapSort::build_max_heap(vector<int> &iv)
{
	for(size_t i=(int)(iv.size()/2.0-1); i!=-1; --i) {
		max_heapify(iv,i);
	}
}

void HeapSort::max_heapify(vector<int> &iv,int i)
{
	l=left(i);
	r=right(i);
	if((l<iv.size())&&(iv[l]>iv[i])) {
		largest=l;
	} else {
		largest=i;
	}
	if((r<iv.size())&&(iv[r]>iv[largest])) {
		largest=r;
	}
	if(largest!=i) {
		temp=iv[i];
		iv[i]=iv[largest];
		iv[largest]=temp;
		max_heapify(iv,largest);
	}
}

int main()
{
	vector<int> iv= {4,1,3,2,16,9,10,14,8,7};
	HeapSort hs(iv);
	return 0;
}
