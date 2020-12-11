[Editorial Page](../clumio-set-1.md)

<!-- vim-markdown-toc GFM -->

* [Intuition](#intuition)
* [Code](#code)

<!-- vim-markdown-toc -->

----

# Intuition
Looks like we under-estimated the difficulty of this question. It had fewer submissions than **Image Matching**.

In the feedback form circulated, a lot of you requested for `related problems` for each question. Although I can't guarantee that for the upcoming rounds, I've colllected some questions which might help build your intuition/thought-process and hopefully help you see the connection between them.

At this point, you might want to try out [Distinct Subsequences]() from Leetcode, which basically tells you to find the number of subsequences of a particular string which matches a fixed string.

My solution for this problem was originally motivated by the above problem from Leetcode. Recalling the DP definition for the classical question, `dp[len_first][len_second]` represents the number of subsequences of the first `len_first` elements of `str_1` which exactly matches the first `len_second` elements of `str_2`. To perform the transistions, you need to check whether the last characters match. If they do, you have a choice of leaving it or taking it. If not, you have to ignore it.

Coming on to the original problem, we'd like to see the connection between them. Don't get lost in the wording of the question.

Observe that all the strings are of the same length, so let us stack all strings vertically. This would result in a matrix, where each row represents the original string and each column represents the characters staying at the specific index (column number in all of the strings).

Now that we have the matrix representation, we'd like to simplify the constraints. If you notice carefully, you'll realize that the rules are "You are allowed to pick atmost one character from each column". If the resulting string matches the `target`, you have an answer. Notice that the wording `increasing_order` means we have to select a subsequence of the columns.

Now that we have reduced the problem to a familiar subsequence problem, we'd like to get rid of the matrix. Realize that each column would only contain lowercase-alphabets. So, we want to compress everything into a **mega-node**. What's the best way? If we just wanted to store the presence/absence of each character in a column, we could just use the bitmasking technique (as discussed in **Scatter Palindromes**). However, we'd also like to record the frequency of each character in each column.

Maintain a DP, `freq[col][char-ind]` represents the frequency of the `char-ind` character of the alphabet in the `col` column. Filling this is easy, I leave it upto you.

The last observation is : Say a column (which is now a mega node) has frequency of a character as `5`. As per the description of the question, it should be clear there are now 5 ways to convert this mega node into the said character.

Now, we've finally reduced our question :
> Given 2 strings, where the first string consists of mega nodes, find out how many subsequences of the first string is equal to the second string.

To solve this, define the same **Prefix DP** `dp[col][p_len]` represents the number of ways to produce a subsequence which matches the first `p_len` characters of target using only the first `col` columns. 

To perform the transistions, notice that as soon as you get a match, you should multiply the frequency of the character just matched to the answer (as discussed above). 

If you've understood the concepts behind the Leetcode problem, you shouldn't have trouble implementing the above discussion. Hence, I won't discuss it further. 

Make sure to handle modulo properly.

----

# Code
[Code](string-formation.cpp)
