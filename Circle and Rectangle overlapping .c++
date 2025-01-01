/*
You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.
*/

/*
Example 1:


Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).
*/

//BRUTE APPROCH
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
              int c1=i-xCenter;
              int c2=j-yCenter;
              if(c1*c1 + c2*c2 <= radius * radius)
                  return true;
            }
        }
        return false;
        
    }
};
// TC = O(N);
//SC = O(N);

//OPTIMAL APPROCH
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // closest point:rectangle -> center of the circle.
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
    
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;

        return distX * distX + distY * distY <= radius * radius;       
    }
}; 
//TC = O(1);
//SC = O(1);
