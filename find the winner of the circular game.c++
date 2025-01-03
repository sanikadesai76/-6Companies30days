/*
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.

 

Example 1:


Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
*/

//approch 1
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> nums;
        // Initialize nums with 1 to n
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        int i = 0; // Start from the first person
        while (nums.size() > 1) {
            // Calculate the index of the person to be removed
            int idx = (i + k - 1) % nums.size();

            // Remove the person at idx
            nums.erase(nums.begin() + idx);

            // Update the starting index for the next round
            i = idx;
        }

        return nums[0];
    }
};

//approch 2
//using queue

//approch 3 ideal recursion
class Solution {
public:
    int findWinner(int n,int k){
        if(n == 1) return 0;

        int idx = findWinner(n-1,k);
        idx = (idx + k) % n;

        return idx; 
    } 

    int findTheWinner(int n, int k) {
        
        int resultIndex = findWinner(n,k);

        return resultIndex + 1;
    }
};

/*
quite intersting

Historical Background:
Flavius Josephus was involved in the Jewish-Roman War (66–70 AD). According to historical accounts, he and a group of 40 soldiers were trapped in a cave, surrounded by Romans. To avoid capture, the group decided to commit mass suicide in a particular sequence.

They arranged themselves in a circle, and every 
𝑘
k-th person was executed until only one person remained. Josephus, not wanting to die, cleverly positioned himself to be the last survivor.
*/