#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=dUkRI0R3sg8&ab_channel=CodingDecoded
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

SegmentTree* buildTree(const vector<int>& nums, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    else {
        auto newNode = new SegmentTree(start, end);
        if (start == end) {
            newNode->sum = nums[start];
        }
        else {
            int mid = start + (end - start) / 2;
            newNode->left = buildTree(nums, start, mid);
            newNode->right = buildTree(nums, mid + 1, end);
            newNode->sum = newNode->left->sum + newNode->right->sum;
        }
        return newNode;
    }
}

int sumRangeHelper(SegmentTree* root, int start, int end) {
    if (root->start == start && root->end == end) {
        return root->sum;
    }
    else {
        int mid = root->start + (root->end - root->start) / 2;

        if (end <= mid) {
            return sumRangeHelper(root->left, start, end);
        }
        else if (start >= mid + 1) {
            return sumRangeHelper(root->right, start, end);
        }
        else {
            return sumRangeHelper(root->left, start, mid) + sumRangeHelper(root->right, mid + 1, end);
        }
    }
}

void updateHelper(SegmentTree* root, int index, int val) {
    if (root->start == root->end) {
        root->sum = val;
    }
    else {
        int mid = root->start + (root->end - root->start) / 2;

        if (index <= mid) {
            updateHelper(root->left, index, val);
        }
        else {
            updateHelper(root->right, index, val);
        }
        root->sum = root->left->sum + root->right->sum;
    }
}

class NumArray {
    SegmentTree* root {nullptr};
public:
    NumArray(vector<int>& nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        updateHelper(root, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRangeHelper(root, left, right);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    {
        vector<int> v{1, 3, 5};
        NumArray sln(v);
        assert(9 == sln.sumRange(0, 2));
        
        sln.update(0, 2);
        assert(10 == sln.sumRange(0, 2));

        sln.update(2, 1);
        assert(6 == sln.sumRange(0, 2));
    }
    return 0;
}