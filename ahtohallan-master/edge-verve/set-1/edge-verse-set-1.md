You can find the codes in the respective folders.

# Coloring the Blocks
This is a simple DP question. Let us define `dp[i][color]` as the minimum cost to colour `a[0...i]` when we **necessarily** colour the `i-th` block with colour `color`.

The transistions are easy. You look at the dp values `dp[i - 1][last_color]`, where `last_color != color` and just take the minimum out of them.

# Scatter Palindromes
An `O(n^3 * log(n))` algorithm is apparent. Consider all `O(n^2)` substrings, sort each of them, and check the parity of each consecutive characters. There should be atmost one character with odd parity.

You can improve this to `O(n^3 * 26)` by just storing the counts of characters instead of sorting.

You can further improve it to `O(n^2 * 26)` by calculating the answer for each `dp[i]`, where `dp[i]` represents the number of substrings which are scatter palindromes and start at `i`. Each `dp[i]` can be filled in `O(26 * n)`. Just start at `i` and keep inserting characters in a freuency hashmap/array. Upon reaching any new index, traverse the entire hashmap (of length atmost 26) and get the parity of each character. Once you know the parity of each character, determining the answer is trivial.

We can further optimize it to `O(n^2)`. Notice that we are only interested in the parity and not the actual frequency. Also, the size of hashmap can be atmost 26. Hence, we can use a 26 bit integer to store this information concisely. Each set bit denotes that the corresponding parity is 'odd' (or 'even'). We just need to efficiently toggle the bit using`xor` operations.

# Arbitrary Shopping
An `O(n^3)` solution is apparent. Consider all `O(n^2)` subarrays, get the sum and check if it is within the limits.

We can optimize it to `O(n^2)` by using the **Prefix-Sum-Trick** (which can tell us the sum of any static subarray in `O(1)`).

We can further optimize it to `O(n log(n))` by calculating the answer for each `dp[i]`, where `dp[i]` represents the longest subarray which start at `i` and satisfies the money conditions. We can find `dp[i]` in `O(log (n) )` by noticing the fact that the prefix sum array of a positive array is sorted. Hence, we can apply binary search to find the first position where the sum exceeds the given money. We need to fill `n` dp values, each taking `O(log (n) )` time, hence total time complexity is `O(n log(n))`.

The intended solution is `O(n)`. We need to use simple sliding window approach for this problem. Keep expanding the window as long as you have money. Once you are out of money, keep contracting from left (or start over).

# Angry Animals
Did your approach fail on Test Case 12? Well, you didn't formulate the DP correctly.

What about the test 251? Did you take care of large inputs? Did you take care of overflow?

A lot of people (including me) come up with this DP definition intially. First find out for each index, the minimum element which is conflicting with the current index and then update the contribution of this index as `min_conflict_right[i] - i`. Finally, sum up all values.

This approach fails for this simple test case. There are 4 animals. `1 2 3 4`. `2 and 3` conflict with each other, while `1 4` conflict with each other. However, while filling the DP value for the first index, you'd think that `4` is the first index which collides with `1`, so you'd be tempted to put `1 2 3` in one group. However, this is wrong as `2 3` are colliding.

**Correct Solution** : Define a DP `conflict_right[i]` denotes the minimum index to the right which conflicts with `i`. The default is set to `n` (assuming there is an extra sentinel at the end which conflicts with everyone). Filling this is easy, iterate over all pairs of conflicts, and update the `conflict_right` for the minimum of the two.

Then, define a DP `safe[i]`, where `safe[i] = j` means `j` is the first index to the right of `i` which conlicts with some element in the segment `a[i...j-1]`. We default it to sentinel). Filling this is easy, you just look for the minimum of `safe[i+1]` and `conflict_right[i]`.

Finally, define `ways[i]` as the number of valid groups starting at `i`. Clearly, `ways[i] = safe[i] - i`. To get the answer, sum up all the values in the `ways` array.

**P.S** : There also exist an `O(n log(n))` heap based solution, but I don't know how it works. If someone solved it using heaps, please share your solution below.

Feel free to share your approach in the comments.
