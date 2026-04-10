class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == k) 
            return nums;

        unordered_map<int,int> count;
        for(int num: nums){
            count[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for(auto entry: count){
            minHeap.push({entry.second, entry.first});
            if(minHeap.size()>k)
                minHeap.pop();
        }

        vector<int> res;
        for(int i = 0;i<k;i++){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};
