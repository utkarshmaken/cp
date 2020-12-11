
[Editorial Page](../book-my-show-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Debugging Tips](#debugging-tips)
* [Intuition](#intuition)
* [An alternate approach (by Lavish)](#an-alternate-approach-by-lavish)
* [Code](#code)
* [Credits](#credits)

<!-- vim-markdown-toc -->

----

# Debugging Tips
* If you are unable to debug your code, open the current folder in **Github** and you'll find `9` small test-cases with prefix `gen-man-num.txt`.
* If the error persists, consider [stress-testing](../../../documentation/stress-testing.md) your solution.

----

# Intuition
There are a lot of ways to solve this question. Here's how I solved it.

If you've solved **Angry Animals** and **Peaceful Groups**, the idea would seem trivial. Indeed, it is just a rewording of these 2 questions, once you've reduced it.

As we did in **Angry Animals**, let us define a DP, `max_right`, where `max_right[left]` stores the maximum rightmost co-ordinate of any fountain whose left end starts at `left`. Populating the DP is easy. For each fountain, 

```cpp
left  = max(i - location[i], 1)
right = min(i + location[i], n)
max_right[left] = max(max_right[left], right)
```

It's obvious that we need to activate a fountain that covers the first fountain and hence, the minimum cost would be 1. Obviously, we'd choose the fountain which has the largest right extent (apart from covering 1, of course).

Now, suppose, you're driving a car, and you've paid 1$ for the first fountain to be activated.. How far can you drive without needing to pay again? Clearly, it is `max_right[1] + 1`. Let call this value as a blockage.

It's obvious that you need to pay again when you reach the blockage. Once you reach the first blockage, you need to activate any fountain whose left ends starts at the blockage or earlier. Now, the cost of activating each of the fountains is 1$, so which fountain would you prefer to activate? Clearly, the one that would place the next blockage as far as possible.

So, as we did in **Peaceful Groups**, you also need to store the max of `max_right` untill you reach the blockage.

To conclude, the algorithm is :

* Activate the first fountain and record the value of `current_blockage` that you are going to encounter.
* While you do not reach the blockage, do
	* Keep preparing the `next_blockage` as far as possible.
	* You can do this by taking a running max of `max_right[ele]`.
* Once you hit the `current_blockage`, activate the best fountain that you've encounterd.
* Update `current_blockage` and repeat.

**Note** : It's guaranteed that the next blockage would be strictly to the right of current blockage. Why?

----

# An alternate approach (by Lavish)
Let us start from the left. We initially want to cover position number 1 ( Let us call this `curr`). Also, we should choose such a fountain which can sprinkle water to as much right as possible ( so we are choosing greedily the best fountain). To prove why this will work, consider number of fountains needed to cover `[a,n]` and `[a+1, n]`. You can prove that this is a non-increasing sequence.

----

# Code
* [My Solution](solution.cpp)
* [Tester's Solution](stupid.cpp)

----

# Credits
Idea borrowed from [LeetCode](https://leetcode.com/discuss/interview-question/363036/twitter-oa-2019-activate-fountain)

----
