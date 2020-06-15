#include <iostream>
using namespace std;

#include <vector>

bool canBeEqual(vector<int>&, vector<int>&);

int main()
{
	vector<int> target = {1,2,3,4};
	vector<int> arr = {2,4,1,3};

	bool answer = canBeEqual(target, arr);

	cout << answer << endl;
	
	return 0;
}


bool canBeEqual(vector<int>& target, vector<int>& arr)
{
	sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        
        return (target == arr) ? true : false;
}
