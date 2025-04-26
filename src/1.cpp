#include <vector>
#include <unordered_map>

using namespace std;

vector<int> x = { 2,7,11,15 };

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numParts;

    for (int i = 0; i < nums.size(); i++) {
        const int diff = target - nums[i];
        auto numPart = numParts.find(diff);

        if (numPart != numParts.end()) return {numPart->second, i};

        numParts[nums[i]] = i;
    }

    return {};
}


