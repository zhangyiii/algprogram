//
// Created by zhangyi on 2021/4/11.
//

#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

TEST(LeetCode, testcase)
{
    std::cout << "hello, world!" << std::endl;
}

////////////////////////////////////////////////////////////////////// 简单排序  ///////////////////////////
/* 1. 优化：一次比较找出最大和最小值， 最小值与前面交换， 最大值与后面交换
 * 2. 平均复杂度=最坏复杂度=最好复杂度=O(n~2); 空间复杂度O(1); 不稳定
 * 3. 基本不用——不稳定，且慢
 * */
TEST(LeetCode, selectSort)
{
    std::vector<int> arry{4,6,7,8,1,2,3,9,5};

    for(int i = 0; i < arry.size() - 1; ++i){
        int minPose = i;
        for(int j = i + 1; j < arry.size(); j++){
            minPose = (arry[minPose] > arry[j]) ? j : minPose;
        }
        int tmp = arry[minPose];
        arry[minPose] = arry[i];
        arry[i] = tmp;
    }

    for(auto& it : arry){
        std::cout << it << ", " ;
    }
}

/* 1. 优化：最好时间复杂度O(n)
 * 2. 平均复杂度=最坏复杂度=O(n~2),最好复杂度O(n); 空间复杂度O(1); 稳定
 * 3. 基本不用——太慢
 * */
TEST(LeetCode, BubbleSort)
{
    std::vector<int> arry{4,6,7,8,1,2,3,9,5};
    //todo
}

/* 1. 优化：采用一个临时变量替换swap
 * 2. 平均复杂度=最坏复杂度=O(n~2),最好复杂度O(n); 空间复杂度O(1); 稳定
 * 3. 样本小且基本有序的时候效率比较高
 * */
TEST(LeetCode, InsertSort)
{
    std::vector<int> arry{4,6,7,8,1,2,3,9,5};
    //todo
}

////////////////////////////////////////////////////////////////////// 高级排序  ///////////////////////////
/* 1. 优化：不同的gap影响， knuth-gap: 1->3*n+1
 * 2. 平均复杂度=O(n~1.3)， 最坏复杂度=O(n~2), 最好复杂度O(n); 空间复杂度O(1); 不稳定
 * */
TEST(LeetCode, ShellSort)
{
    std::vector<int> arry{4,6,7,8,1,2,3,9,5};
    //todo
}

