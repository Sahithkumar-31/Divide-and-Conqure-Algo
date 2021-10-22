#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int bs(const vector<int> &a, int left, int right, int k) 
{
	if (left < 0 || right > a.size() || left > right) 
	return -1;
	int mid = left + (right - left) / 2;
	if (a[mid] == k) {
		return mid;
	} 
	else if (a[mid] > k) {
		return bs(a, left, mid - 1, k);
	} else{
		return bs(a, mid + 1, right, k);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++)
	 {
	    cin >> a[i]; 
	 }
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) 
	{ 
	    cin >> b[i]; 
	}
	for (int i = 0; i < m; ++i) {
	    int	j= bs(a, 0, a.size() - 1, b[i]);
	    cout<<j<<" ";
	}
}
