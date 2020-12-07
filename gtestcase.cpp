//
// Created by zhangyi-pc on 2020/12/2.
//
#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

std::vector<int> searchRange(std::vector<int> &nums, int target){
    int minIndex = 0;
    int maxIndex = nums.size() - 1;
    int retStart, retEnd;
    while(minIndex <= maxIndex){
        int midIndex = (minIndex + maxIndex)/2;
        if(target > nums[midIndex]){
            minIndex = midIndex + 1;
        }else if(target < nums[midIndex]){
            maxIndex = midIndex - 1;
        }else{
            retStart = midIndex;
            retEnd = midIndex;
            break;
        }
    }
    if(minIndex > maxIndex){
        retStart = -1;
        retEnd = -1;
    }else{
        while ((retStart -1) >= 0 && nums[retStart -1] == target){
            retStart --;
        }
        while ((retEnd +1)< nums.size() && nums[retEnd +1] == target){
            retEnd ++;
        }
    }

    return std::vector<int>{retStart, retEnd};
}

TEST(LeetCodeTest, bin_find_case){
    std::vector<int> nums{};
    auto result = searchRange(nums, 0);
    std::cout << result[0] << ", " << result[1] << std::endl;
}

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr || l2 == nullptr){
        return nullptr;
    }
    int sum = l1->val + l2->val;
    ListNode *result = new ListNode(sum % 10);
    int x = sum / 10;
    l1 = l1->next;
    l2 = l2->next;
    ListNode *retHead = result;
    while(l1 != nullptr && l2 != nullptr){
        int sum = l1->val + l2->val + x;
        ListNode *t = new ListNode(sum % 10);
        retHead->next = t;
        retHead = retHead->next;
        x = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != nullptr){
        int sum = l1->val + x;
        ListNode *t = new ListNode( sum % 10);
        retHead->next = t;
        retHead = retHead->next;
        x = sum / 10;
        l1 = l1->next;
    }

    while (l2 != nullptr){
        int sum = l2->val + x;
        ListNode *t = new ListNode( sum % 10);
        retHead->next = t;
        retHead = retHead->next;
        x = sum / 10;
        l2 = l2->next;
    }

    if(l1 == nullptr && l2 == nullptr && x != 0){
        ListNode *t = new ListNode(x);
        retHead->next = t;
        retHead = retHead->next;
    }

    return result;
}
TEST(LeetCodeTest, link_add_case){
    std::vector<int> a{2, 5, 9};
    std::vector<int> b{5, 8, 2};
    /// std::cout << 7321
    ListNode *alist = new ListNode(a[0]);
    ListNode *blist = new ListNode(b[0]);
    ListNode *ahead = alist;
    ListNode *bhead = blist;
    for(int i = 1; i < a.size(); ++i){
        ListNode* t = new ListNode(a[i]);
        ahead->next = t;
        ahead = ahead->next;
    }
    for(int i = 1; i < b.size(); ++i){
        ListNode* t = new ListNode(b[i]);
        bhead->next = t;
        bhead = bhead->next;
    }

    auto result = addTwoNumbers(alist, blist);
    while (result != nullptr){
        std::cout << result->val << std::endl;
        result = result->next;
    }
}

int lengthOfLongestSubstring(std::string s) {
    if(s.length() == 0){
        return 0;
    }
    int len = s.length();
    std::vector<int> recordMax(len);
    int breakIndex = 0;
    for(int i = 0; i < len; ++i){
        recordMax[i] = 1;
        for(int j = i - 1; j >= breakIndex; --j){
            if(s[j] == s[i]){
                breakIndex = j + 1;
                break;
            }else{
                recordMax[j]++;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < len; ++i){
        if(recordMax[i] > max){
            max = recordMax[i];
        }
    }

    return max;
}
TEST(LeetCodeTest, find_max_suquence_case){
    std::string str("abcabcbb");
    auto result = lengthOfLongestSubstring(str);
    std::cout << "max suquence length = " << result << std::endl;
}
