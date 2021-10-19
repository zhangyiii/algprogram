//
// Created by admin on 2021/10/18.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <gtest/gtest.h>

std::vector<int> findIndex(const std::vector<int>& nums, const int &target){
    std::map<int, int> mp;
    mp[nums[0]] = 0;
    for(int i = 1; i < nums.size(); ++i){
        int findValue = target - nums[i];
        if(mp.find(findValue) != mp.end()){
            return std::vector<int>{mp[findValue], i};
        }
        mp[nums[i]] = i;
    }
    return std::vector<int>{-1, -1};
}
TEST(LeetCodeTest, two_sum_case){
    std::vector<int> array{3,2,4};
    int target = 6;
    auto indexs = findIndex(array, target);
    std::cout << indexs[0] << ", " << indexs[1] << std::endl;
}

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> mergerArray;
    int i, j = 0;
    int target;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] < nums2[j]){
            target = nums1[i];
            i++;
        }else{
            target = nums2[j];
            j++;
        }
        mergerArray.push_back(target);
    }
    if(i >= nums1.size()){
        for(int r = j; r < nums2.size(); ++r){
            mergerArray.push_back(nums2[r]);
        }
    }
    if(j >= nums2.size()){
        for(int r = i; r < nums1.size(); ++r){
            mergerArray.push_back(nums1[r]);
        }
    }

    int size = mergerArray.size();
    if(size%2 == 0){
        return (mergerArray[size/2-1] + mergerArray[size/2])*1.0 / 2;
    }else{
        return mergerArray[size/2]*1.0;
    }
}

TEST(LeetCodeTest, find_middle_sum_case){
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3,4};
    auto result = findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
}


int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left < right){
        int mid = left + (right - left)/2;
        if(nums[mid] < target){
            left = mid + 1;
        }else if(nums[mid] > target){
            right = mid - 1; /// 如果right = mid -1的话，当程序退出时，left==right 或者left比right大1
                             /// 如果right = mid的话，当程序退出时，必定left == right
        }else{
            return mid;
        }
    }
    if(nums[left] == target){
        return left;
    }else{
        return -1;
    }
}
TEST(LeetCodeTest, binary_search_case){
    std::vector<int> array = {-1,0,3,5,9,12};
    int target = 2;
    auto result = search(array, target);
    std::cout << result << std::endl;
}