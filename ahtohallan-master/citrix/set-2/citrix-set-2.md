You can find the codes in the respective folders.

# Cereal Segments
For people using **Multisets**, sorry I guess? :)

This is a standard question by the name **Maximum of Every Window of Size K**.

For people using **Multisets** and getting a **WA**, you should delete via iterators and not by values (which actually deletes all the copies present in the container). But **Multisets** would time out on the last test-case.

For people using **montonic** queue, and getting a **WA**, also use an **indicial** queue alongside (in case of duplicates).

# Binary Strings (Easy)
Let us convert all ones to opening bracket `(` and all zeroes to closing brackets `)`. If you notice carefully, the rules in the question states that we can swap two adjacent **valid parenthesis**. The goal is to make the nesting as **deep** as possible. (Of course, you are given a valid parenthesis to begin with).

Notice that a valid parenthesis can be of 2 types. Either a concatenation of valid parenthesis, such as `()()` or a nesting of valid parenthesis, such as `(())`. Let us call the second type as **non-splittable** strings.

Break the original string into as many **non-splittable** strings as possible. These are the smalles valid parenthesis, and hence, we can solve solve them individually, sort them and merge them. 

The only issue is how to deal with **non-splittable** strings. Observe that you cannot do anything with the first and last element, so remove it and you have similar instance of the original problem. Hence, you just need to recurse on it.

It's difficult for me to analyze the time-complexity. I hope someone can explain it better in the comments.

**Credits** : [The Real MVP](https://leetcode.com/problems/special-binary-string/discuss/113213/12-liner-readable-clean-C%2B%2B-(with-explanation-and-comments))

# Binary Strings (Hard)

**Question Idea and Editorial by `you_know_who`**: 

**Key Terms** :- I will be using str to denote the original string. ‘N’ will denote the length of the string, and str[ i...j ] denotes substring from index i to index j (inclusive). Also I will be using 1-indexing. (so str[ 2...n ] denotes substring from 2nd char till last char). 

Hint :- Suppose dp[i] denotes optimal answer for the string str[i … n]. Can you use this to calculate dp[i-1] ?

Detailed description :- You must have noticed that swapping two adjacent good substrings of a good string will always result in a good string. This means that we can swap any two adjacent good substrings. Also, if you have (let say) 3 continuous good substrings, then the optimal answer would be to sort these 3 substrings in reverse lexicographical order and arrange them in this order.

Now consider the string str[ i..j ]. In the optimal answer, either str[i] will remain at this position, or will be shifted to some other position (By Law of Excluded Middle !!). If str[i] is in place, this means that swapping will start with a later index, and in the optimal answer, we will have str[i+1 .. j] as lexicographically largest. ( Does this problem sound similar ?). In other case, a good substring (if possible) will start from index i. We will take into account all continuous good strings and sort them to get the answer. Finally, the answer for the string str[i .. j] will be the lexicographically larger of the above two answers. Hence you can easily calculate dp[i .. n] by using the answer of dp[i+1 .. n].

A careful reader must have noticed that str[ i.. N] may not be a good substring. However note that the operations are still well defined on this string. If there is no good prefix string starting at index i, then we can assume its answer as equivalent to -inf.

**Time Complexity Analysis** : This is a bit trickier !. Having a rough time complexity analysis will say that at each step, we can have O(n) good substrings, and O(n) length. To sort them, O(n^2 logn). And finally n steps -> O(n^3 logn). However, a more detailed analysis will show that the actual complexity is O(n^2 logn). To prove this, use the fact that the total length of substrings is O(n). I will leave this detailed analysis for you. (edited) 

# SGIPC (Easy)
Define a 3D DP, with parameters as `n`, `k`, and `min_val`. The transitions are simple, just take all possible value greater than `min_val`. It'd be `O(n^4)` (assuming `k` to be as large as `n`).

If you've solved **Atcoder-Educational DP -- Candies**, you can easily optimize it to `O(n^3)` (using the prefix sum trick, as we are intereseted in a continous range of values).

# SGIPC (Hard)
First let us get rid of the constraint that we need to fill atleast one element in each box. So, we'll just insert one element in all the boxes initially.

Define `dp[n][k]` to be number of ways to distribute `n` **identical** objects into `k` **labelled** boxes. We'd like to avoid transferging the `min` parameter, but we also have to take care of **non-decreasing** trend. What choice do we have for the first box? Either stop placing objects inside it, in which case, you need `dp[n][k-1]` or place some element inside it. Here's the trick. We'll place just one element inside, but for everything to be **non-decreasing**, we also have to place 1 in all other boxes. After we've done that, we can recurse for `dp[n-k][k]` which essentially means that you can use box 1 again.


**Base Case** ? If you are out of objects, well and good. If you are out of boxes, you made a wrong decision somewhere.


**Credits** : [The Real MVP](https://stackoverflow.com/questions/58260014/number-of-ways-to-divide-n-objects-in-k-groups-such-that-no-group-will-have-few)
