

[Editorial Page](../flipkart-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [An Alternate Approach (by Lavish)](#an-alternate-approach-by-lavish)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
To solve this question, you must solve [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) first. I found [jeantimex's](https://leetcode.com/jeantimex/) post on [Discuss](https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/29018/AC-clean-Java-solution-using-stack) very helpful (with an additional sentinel to avoid emptying the stack manually as he does at the end).

The basic idea, 

> The indicial stack would be monotonic. The first element on the left which is smaller than the current element would be its left neighbour in the stack. 


How to find out the first element smaller than the current element and present on the right?

> If element `curr` pops the element `top` from the stack, then `top` is the first element smaller than `curr` to the right.

So, we calculate the left and right boundary of an element as soon as it is popped (and not pushed) onto the stack.

Whenever an element is popped, what is the largest rectangle that it could be a part of? Clearly, we can go as far as left-boundary and right-boundary (both exclusive). So, how many numbers are there in the open-open range `(a, b)`? Clearly, `(b - a - 1)`. Now that we have our height and width, we can easily compute area and keep a running max.

Notice that the answer for any index is computed when it is popped from the stack. How do we ensure that all the elements are popped from the stack? We can just insert a sentinel (a bar of height 0) at the end. This would pop every element.

----

The second half of the question is present [here](https://leetcode.com/problems/maximal-rectangle/).

Once you've solved the above question, all you need to do to find the maximal rectangle is to convert each row to a histogram and use the above function.

Finally, to convert to a histogram, you just need to take vertical prefix sum if the current val is `1`. (Of course, you need to continous ones and terminate when you hit 0).

To conlude, it's a lot of things to learn, but then again, how often do you find questions that teach you these many things?

# An Alternate Approach (by Lavish)
Let us say `dp[i][j]` stores the number of contiguous `1s` above `(i, j)` position (including the current cell). Also, assume that we know the length of the horizontal segment for each `(i, j)` such that `dp[i][j]` is greater than or equal to each element (`dp[i][k]`) in this segment.

Why are we calculating these values? Imagine an optimal answer, and consider the last row of the optimal rectangle. Let's say the height of the rectangle is `H` and width is `W`. Note that in the segment of `W` in the last row, all DP values must be greater than or equal to `H`. 

Also, atleast one of these values must be equal to `H` (if this is not the case, we can increase the height of the rectangle by 1, without affecting width).

So, if for this particular `dp[i][j] == H`, if I know the length of segment such that all values of DP in this segment is greater than or equal to `H`, we can calculate a possible area of rectangle by (`dp[i][j] * length of segment`).

Taking max of these areas would give us our answer.

To calculate are of square instead of rectangle, you just need a single change. Earlier, the possible area was `(dp[i][j] * length of segment`). Now, it will be `min(dp[i][j], length)^2)`.

The task that remains is to calculate the length of the segment for each `(i, j)`. This problem can be decomposed into 2 problems, calculating minimum left and right index, such that their value is less than `dp[i][j]`. This problem can be easily solved using **stacks** in `O(n)` or **segment-trees** in `O(n log(n))`.


----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](stupid.cpp)

----

