#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		size_t writeIndex = 0;

		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (i == 0 || nums[i] != nums[i - 1])
			{
				nums[writeIndex++] = nums[i];
			}
		}

		nums.resize(writeIndex);
		return writeIndex;
	}
};

// Test
int main()
{
	Solution sol;
	vector<int> a;

	a = {0,0,1,1,1,2,2,3,3,4};
	sol.removeDuplicates(a);

	for (auto i : a)
	{
		cout << i << " ";
	}
}