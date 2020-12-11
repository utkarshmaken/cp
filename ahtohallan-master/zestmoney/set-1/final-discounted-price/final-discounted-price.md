[Editorial Page](../zestmoney-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Practice Problems](#practice-problems)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is a classical question which goes by the name [Next Greater Element](https://practice.geeksforgeeks.org/problems/next-larger-element/0). 

The basic idea is to maintain an **indicial monotonic** stack (as we did in **Cereal Segments**). We iterate the elements of the array in a reverse manner. To calculate the answer for any index `i`, we keep popping all the elements which are strictly greater than `i`. At the end of the process, the element at the top of the stack would be the NSE for the current element. Once we are done, we push the current element onto the stack.

Do we lose any information by deleting some of the elements from the stack (which might never come back)? Well, the answer is `No`. Say, there are a couple of missing elements between `current` and `next`. Now, any element which can pop `current` from the stack could've also popped the intermediate elements, were they to be present. And if the element can't even pop `current` from the stack, we don't really care about the intermediate missing elements. So, it doesn't affect us in any way.

The time complexity is **O(n)** even though it might look as **O(n^2)**.

Finally, remember to handle the case of empty stack.

**P.S** : This was in no way meant to be a detailed editorial for the said problem. Please refer to other online resources to learn about these kind of stack manipulations.



# Practice Problems
Since the topic of stacks has come up, I'd like to re-iterate some easy questions utilizing the idea. You can easily find them on **Leetcode** via a simple google search.

1. Valid Parentheses
2. Longest Valid Parentheses
3. Min Stack
4. Merge Overlapping Intervals
	* Can also be done without stacks
5. Stock Span
6. Infix to Postfix
	* Requires careful understanding/implementation
7. Largest Rectange under histogram
	* Can be quite tricky
8. Maximal Rectangle in a matrix
	* A great use-case of the last question	 


----

# Code
* [Stack Based Approach](solution.cpp)
