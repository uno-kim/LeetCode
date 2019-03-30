class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> mm;
        multimap<int, int>::iterator iter, lower_iter, upper_iter;
        vector<int> ret;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            mm.insert(pair<int, int>(nums[i], i));
        for (int i = 0; i < size; ++i)
        {
            int second = target - nums[i];
            if (second == nums[i])
            {
                if (mm.count(second) == 2)
                {
                    lower_iter = mm.lower_bound(second);
                    upper_iter = mm.upper_bound(second);
                    for (iter = lower_iter; iter != upper_iter; ++iter)
                        ret.push_back(iter->second);
                    return ret;
                }
                else
                    continue;
            }
            else
            {
                iter = mm.find(second);
                if (iter != mm.end())
                {
                    ret.push_back(i);
                    ret.push_back(iter->second);
                    return ret;
                }
            }
        }
        return ret;
    }
};
