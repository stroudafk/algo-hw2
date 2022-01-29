#include <vector>
#include <stdexcept>
#include <iostream>

/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *
 */
int countFives(int num) {
  if(num < 10 && num != 5)
    return 0;
  if(num % 10 == 5)
    return 1 + countFives(num/10);
  else
    return countFives(num/10);
}


/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 */

int findSum(int start, const std::vector<int>& vec){
  //am I missing the edge case where the vector is size 1?
  if(start >= vec.size()){
    return 0;
  }
  if(vec[start]+findSum(start+2, vec) > findSum(start+1, vec))
   return vec[start]+findSum(start+2, vec);
  else 
    return findSum(start+1, vec);
  
}

int pickTrees(const std::vector<int>& vec) {
  return findSum(0, vec);
}
