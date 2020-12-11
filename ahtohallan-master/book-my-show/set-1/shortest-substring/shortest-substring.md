

[Editorial Page](../book-my-show-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
This is a pretty standard question on **LeetCode** by the name, **Minimum window substring containing all characters of other string**. The original question is **LC-Hard** (as we also need to match characters with their frequency). You can find good solutions in the **Discuss** section. I'll just briefly outline my approach.

**Note** : The current (easy) version can be solved by creating the second string as the concatenation of all unique characters with frequency 1. Hence, we'll just focus on the hard version.

**Notation** : We need to accomodate `target` inside `source`.

First, let us convert `target` to a frequency hash-map. Now, notice that we cannot do anything untill and unless we have found a window in `source` which contains every character of `target-hash-map` with frequency atleast as large as the original. So, as we do in sliding-window questions, we'll keep expanding the window to the right till we get our desired window. We also keep track of the frequency of characters in the winodw. Of course, we ignore the characters not present in `target`.

Once we've found such a window, we can update our global minimum length and try to contract it. But before that, how do you ensure that the window is found without iterating the hashmap over and over again?

Maintain a counter `matched` and increment it as soon as the frequency of any character in the window becomes *exactly* the desired frequency. Once `matched` reaches the size of `target-hash-map`, we know that we've found our window.

Back to contracting the window : Keep incrementing the left end, and decreasing the frequencey of the character (if it was present in the hash-map). Once the frequency of any character becomes strictly less than the desired frequency, you know that window is destroyed. So, you can hand back the control to the first process (which would eventually give you a correct window).

Finally, remember to keep updating global min length each time, or you might run into corner cases.

**Tip** : Avoid using `for` loops with sliding-window technique. I prefer 2 `while` loops as it gives me complete control over the increment-decrement in each iteration, thus reducing the chances of off-by-one error.

I'd suggest you to submit the hard version on LeetCode as they have good corner cases.

----

# Code
* [Sliding Window](solution.cpp)
