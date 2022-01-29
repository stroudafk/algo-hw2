# HW2: Time/Space Complexity & Recursion

This homework is meant to practice time / space complexity analysis and recursion. **This assignment is due on February 3 at 11:59PM Central Time.**

### Submitting

In order to submit this assignment, you must download your code as a ZIP file and upload it to Gradescope. There will be an autograded component and a manually graded component.

### Corrections
*If you miss points on this assignment,* there will be an opportunity to earn half of them back by doing homework corrections, so don't worry so much about the grade if you're having a tough time on some of the questions. More information will be posted on Piazza.


### Academic Integrity
Remember that you can consult outside resources and work with other students as long as you write up your own solutions and cite any links or people you received help from within `citations.txt`.

## Part 1: Conceptual

This section does not require coding, but instead, expects you to analyze existing code. Please read each question carefully as these examples are meant to be more difficult than traditional examples you will be exposed to. The point values of each problem are listed in the title. We will use manual inspection and written rubrics to assign points in a fair, standardized way. **We've provided an example question and ideal answer in `example.txt` to help you get started on the complexity analysis questions.**


## Q1 (3 points)
What is the worst case time complexity and space complexity of the following function? Please remember to define n, provide a tight upper bound, and justify your answer in `Q1.txt`
```cpp
  void doSomethingQ1(int n) {
    for (int i = 1; i < n; i *= 2) {
      std::cout << i << std::endl;
    }
  }
```
## Q2 (3 points)
What is the worst case time complexity and space complexity of the following function? Please remember to define n, provide a tight upper bound, and justify your answer in `Q2.txt`
```cpp
  void doSomethingQ2(int z) {
    std::cout << z << std::endl;
    std::vector<int> values = {};
    while(z >= 10) {
      std::cout << z << std::endl;
      values.push_back(z);
      z /= 10;
    }
  }
```
## Q3 (3 points)
What is the worst case time complexity and space complexity of the following function? Please remember to define n, provide a tight upper bound, and justify your answer in `Q3.txt`
```cpp
  std::string doSomethingQ3(int n) {
    if (n % 7 == 0) {
      return "Bzzzt!";
    }
    return doSomethingQ3(n-1);
  }
```
## Q4 (9 points)

```
algorithm pow
  Input: positive integer b, non-negative integer p
  Output: computing b^p (i.e. b raised to power of p)

  if p = 0
    return 1
  else if p = 1
    return b
  else if p is even
    temp = pow(b, p / 2)
    return temp * temp
  else
    return b * b * pow(b, p-2)
```
**Q4.A** What’s the best case, worst case, and average case time complexity of `pow`? **Assume
 n = power**.
 Please remember to define n, provide a tight upper bound, and justify your answer in `Q4.txt`. Hint: when thinking of the best-case input, recall that it should *still be large*, i.e. "when power is 0 or 1" would be incorrect.
 
**Q4.B** What one-line change could you make to improve the worst case? You must provide a written explanation of why your  change works in order to receive full credit.

Write your answers in `Q4.txt`.

## Part 2: Coding

The below will be graded by:
- Autograder (12 points)
- Code style (2 points)
- Documentation (4 points)
- Q5 LeetCode (3 points)

## Q5. LeetCode: Stock Buying

Problem: [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

I am okay if you give your best effort, then explore other solutions online to understand better afterward, but your final submission should be **fully written, character-by-character, by you, and you should be able to fully explain and reproduce what you did to me in an interview-style setting.** You should also add what you referenced in citations.txt.

It is normal to struggle with these questions at first. But if you are more experienced, I challenge you to write the code without looking up any syntax, inspect your code carefully to find any bugs (without ever running it) and trying to get it to work completely correctly on the first or second run - it's harder you might initially think.

The problem you'll solve is classified as an "Easy" question on the LeetCode platform, but it was used as a Google Software Engineering interview question. Most interviews, even in the most selective tech companies, ask questions about as difficult as LeetCode "Easy" and "Medium" questions (only rarely an easier "Hard"). Outside of Big Tech companies, it is almost exclusively LeetCode "Easy". Do not waste your time on mastering "Hard" questions and focus mostly on mastering LeetCode "Easy" and, later, some "Medium"!

**Instructions**

Answer the following in `Q5.txt`:

**Q5.A** Provide one set of expected inputs (prices) and outputs (profit) with an explanation that is not provided in the example to be sure you understand the question.

**Q5.B** Describe your approach in words here. Then, solve the problem. After clicking "Submit" and getting status "Accepted", take a screenshot of the entire window (with the time submitted and your code). Attach the complete and successful screenshot as an image named Q5.jpg in your code submissions.

**Q5.C** What is the worst case time and space complexity of your approach?  Please remember to define n, provide a tight upper bound, and justify your answer.

For those curious, there is an O(n) solution where n is the length of prices, but that solution is not required to receive full credit here.


## Q6. countFives
Write `countFives`, which takes in an integer and returns the number of times 5 appears as a digit within the number. Examples:
```
std::cout << countFives(123467890) << std::endl;  // should output 0
std::cout << countFives(555555) << std::endl;  // should output 6
std::cout << countFives(15354) << std::endl;  // should output 2
```
**In order to receive full credit for this problem, you must use recursion.**
i.e. using `=`, `for`, `while`, etc. is prohibited.

Hint: recall the `%` and `/` operators:
```
  123 % 10 // evaluates to 3
  123 / 10 // evaluates to 12
```
(As some guidance, the recursive staff solution to both this question and pickTrees each have <10 lines of code)

## Q7. pickTrees
You build homes out of wood and you need material from a nearby forest. However,
you want to avoid deforestation, so you decide for each tree you cut down,
you'll leave its neighbors alone, giving the forest time to recover. However,
you still need as much wood as possible, so you have to be careful about which
trees you pick to cut down.

Write `pickTrees`, which takes in a vector of N trees `vec` where `vec[i]`
represents how much wood you can harvest by cutting down tree `i`. It should
return the max amount of wood you can harvest while following the rule of
skipping neighbors:

```
// pick tree 0, tree 2, and tree 4 => 1 + 3 + 5 = 9 wood total
std::cout << pickTrees({1, 2, 3, 4, 5}) << std::endl;

// pick tree 1 and tree 3 => 3 + 3 = 6 wood total
std::cout << pickTrees({1, 3, 4, 3}) << std::endl;

// pick tree 0 and tree 3 => 5 + 9 = 14 wood total
std::cout << pickTrees({5, 1, 4, 9}) << std::endl;
```

**In order to receive full credit for this problem, you must use recursion.**
i.e. using `=`, `for`, `while`, etc. is prohibited. You may find it helpful to create a helper function.

