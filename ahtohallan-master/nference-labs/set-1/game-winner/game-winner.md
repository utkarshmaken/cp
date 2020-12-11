
[Editorial Page](../nference-labs-set-1.md)

----

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Notice that the moves are independent. Hence, we just need to calculate the maximal possible moves for both the players.

Consider a series of `w` surrounded by `b` on either side, i.e

```
bwww...wwwb
```

Clearly, the segment is restricted due to different boundary values. Suppose the count of `w` in this segment is `n`. What is the maximal moves that a player can acquire from this segment? Noitce that each `w` which has an identical neighbour would be popped once. Hence,the maximal moves possible is `max(0, n - 2)`.

So, for each chunk of consecutive `w`, calculate the maximal moves and sum it up. Repeat the same for `b`. The person with more moves win. In case of identical moves, the player going second would win.

**Catch** : As is generally the case with sliding window techniques, people forget to update the result for the last window. So, for example if the string ends in a stream of `www....www`, you might end up just accumulating the `w` while forgetting to process them in the end. A simple workaround is to use a sentinel at the end, such as `$`, which would ensure that accumulated sum has been processed before the loop terminates.

----

# Code
* [My Solution](solution.cpp)

----

