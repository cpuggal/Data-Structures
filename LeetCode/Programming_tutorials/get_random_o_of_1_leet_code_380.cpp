// https://www.youtube.com/watch?v=sta2-XpNNa4
// https://leetcode.com/problems/insert-delete-getrandom-o1/
//
//

#include<iostream>
#include<bits/stdc++.h>

#define DEBUG       0

using namespace std;


class RandomizedSet {
  private:
    map<int, int> randomMap;
    vector<int> randomVector;
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public:
      bool insert(int val) {
        auto it = randomMap.find(val);
        if (it != randomMap.end()) // element is already present in map, don't insert again
          return false;
        else
        {
          randomVector.insert(randomVector.end(), val);
          int index = randomVector.size() - 1;
          randomMap.insert(make_pair(val, index));
          return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
         auto it = randomMap.find(val);
         if (it == randomMap.end()) // element is not present in map, hence can't delete anything
          return false;
        else
        {
          int curr_element_index = it->second;
          int last_element = randomVector[randomVector.size() - 1];
          int last_element_index = randomVector.size() - 1;
          randomVector[curr_element_index] = last_element;
          randomMap[last_element] = curr_element_index;
          randomVector.erase(randomVector.begin() + last_element_index);
          randomMap.erase(val);
          return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (randomVector.size() == 0)
            return -1;
        srand(time(0));
        int vectorSizeRange = randomVector.size();
        int index = rand() % vectorSizeRange;
        return randomVector[index];
    }
};

int main()
{
  int val = 10;
  RandomizedSet* obj = new RandomizedSet();
  bool param_1 = obj->insert(val);
  cout << param_1 << endl;
  int param_2 = obj->getRandom();
  cout << param_2 << endl;  
  bool param_3 = obj->remove(val);
  cout << param_3 << endl;
  int param_4 = obj->getRandom();
  cout << param_4 << endl;
}

