#include <vector>
#include <stdexcept>
#include <iostream>

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *
 This problem was pretty straight forward as a whole. To start, I know that we want to end if the number num is less than 10 but also not a 5. 5 % 10 is still 5, so I needed no extra base case for that. I could isolate the 'tens' place from the rest of the number by using modulus and 10, and could directly see if that was a five. If not, continue on to the next order of magnitude/power of 10. If yes, add one to your end result and also carry on to the next place.
 */
int countFives(int num) {
  if (num < 10 && num != 5)
    return 0;
  if (num % 10 == 5)
    return 1 + countFives(num/10);
  else
    return countFives(num/10);
}


/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 For this problem, I first thought that all I needed to do was check the even starting position and the odd starting position, but I later realized there is no rule that says exactly every other tree must be chosen, only that you cannot choose more than 1 consecutive tree. There can however be two consecutive spaces if you get a better yield that way.

 [1, x, 1, x]
 [x, 1, x, 1]
 [1, x, x, 1]

 So, when you look at one tree, you can either choose this one, or consider choosing the next one. The only thing that could make me choose the next tree over this one is if the one next to me yields greater/larger results than the two on either side of it.

 The decision is easy if you look at sets of 2 and 3. This was my divide and conquer approach.
 */

int findSum(int start, const std::vector<int>& vec) {
  //am I missing the edge case where the vector is size 1?
  if (start >= vec.size())
    return 0;
  if (vec[start]+findSum(start+2, vec) > findSum(start+1, vec))
   return vec[start]+findSum(start+2, vec);
  else 
    return findSum(start+1, vec);
  
}

int pickTrees(const std::vector<int>& vec) {
  return findSum(0, vec);
}
