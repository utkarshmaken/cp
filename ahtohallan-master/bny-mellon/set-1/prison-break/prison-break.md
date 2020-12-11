[Editorial Page](../bny-mellon-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
You just need to observe that the answer would be the maximal gap in the rows multiplied by the maximal gap in the columns. To calculate the maximal gap between the rows, create an array, where `avail[i]` is true if the row hasn't been destroyed yet, and false otherwise. Iterate over the rows with a variable denoting the last seen row, and keep taking the difference and updating the global maxima (assuming that the current row hasn't been destroyed yet).

Mirror the same process for columns and then multiply the result.

Finally, take care to handle overflows (and avoid creating the matrix, as it would lead to MLE).

Also, thanks to *Lavish* for providing the test cases which contains no horizontal/vertical bars removed. This would result in RE if you try to create an array of size 0. (Vectors are fine though). Depending on how you are taking the input, it might also result in TLE if you keep waiting for the next line.

----

# Code
[Code](prison-break.cpp)

