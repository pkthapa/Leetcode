#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=dw-tlJYjzco&ab_channel=CodingDecoded
class SegmentTree {
public:
    int sum;
    int start, end;
    SegmentTree* left, * right;
    SegmentTree(int start, int end) {
        sum = 0;
        this->start = start;
        this->end = end;
        left = nullptr;
        right = nullptr;
    }
};

SegmentTree* buildTree(int start, int end) {
    if (start > end) {
        return nullptr;
    }
    SegmentTree* newNode = new SegmentTree(start, end);
    
    if (start == end) {
        return newNode;
    }

    int mid = start + (end - start)/2;
    newNode->left = buildTree(start, mid);
    newNode->right = buildTree(mid + 1, end);

    return newNode;
}

void update(SegmentTree* root, int index) {
    if (nullptr == root) {
        return;
    }
    if (root->start == index && root->end == index) {
        root->sum += 1;
        return;
    }
    
    int mid = root->start + (root->end - root->start)/2;
    if (index <= mid) {
        update(root->left, index);
    }
    else {
        update(root->right, index);
    }
    root->sum = root->left->sum + root->right->sum;
}

int sumRange(SegmentTree* root, int start, int end) {
    if (nullptr == root || start > end) {
        return 0;
    }
    if (root->start == start && root->end == end) {
        return root->sum;
    }
    
    int mid = root->start + (root->end - root->start)/2;
    if (end <= mid) {
        return sumRange(root->left, start, end);
    }
    else if (start > mid) {
        return sumRange(root->right, start, end);
    }
    return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> result(nums.size());
        int min = INT32_MAX;
        int max = INT32_MIN;

        for (auto i : nums) {
            min = std::min(min, i);
            max = std::max(max, i);
        }

        SegmentTree* root = buildTree(min, max);

        for (int i = nums.size() - 1; i >= 0; --i) {
            update(root, nums[i]);
            result[i] = sumRange(root, min, nums[i] - 1);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {5, 2, 6, 1};
        vector<int> result {2, 1, 1, 0};
        assert(result == sln.countSmaller(nums));
    }
    {
        vector<int> nums {-1};
        vector<int> result {0};
        assert(result == sln.countSmaller(nums));
    }
    {
        vector<int> nums {-1, -1};
        vector<int> result {0, 0};
        assert(result == sln.countSmaller(nums));
    }
    return 0;
}