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
  if(vec.size()-start == 1){
    return 0;
  }
  else if(vec.size()-start == 2){
    return vec[start];
  }
  else if(vec.size()-start == 3){
    if(vec[start+1] < vec[start]){
      return vec[start];
    }
    else{
      return vec[start+1];
    }
  }
  else if(vec.size()-start == 4){
    if(vec[start+1] > (vec[start]+vec[start+2])){
      return vec[start+1];
    }
    else{
      return vec[start]+vec[start+2];
    }
  }
  else{
    if(vec[start] + vec[start+2] > vec[start+1] + vec[start+3]){
      return vec[start] + findSum(start+2, vec);
    }
  }
}

int pickTrees(const std::vector<int>& vec) {
  return findSum(0, vec);
}
