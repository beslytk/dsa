#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    n cars 1 road, diff pos/speeds, faster cars slow down -> car fleet, return # fleets
    Ex. target = 12, pos = [10,8,0,5,3], speeds = [2,4,1,1,3] -> 3 (10 & 8, 0, 5 & 3)
    Sort by start pos, calculate time for each car to finish, loop backwards
    If car behind finishes faster then catches up to fleet, else creates new fleet
    Time: O(n log n)
    Speed: O(n)
    https://leetcode.com/problems/car-fleet/
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // create a pair out of position and time values
        vector<pair<int, double> > cars;
        for (int i = 0; i < n; i++) {
            // time to reach the target from current position
            double time = (double) (target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        // sort based on position
        sort(cars.begin(), cars.end());
        
        double maxTime = 0.0;
        int result = 0;
        // car taking the maxtime to reach target will stall the  
        // cars behind and form a fleet of cars
        for (int i = n - 1; i >= 0; i--) {
            double time = cars[i].second;
            if (time > maxTime) {
                maxTime = time;
                // new fleet 
                result++;
            }
        }
        
        return result;
    }
}; 
//https://leetcode.com/problems/car-fleet/discuss/2183237/C%2B%2B-O(nlog(n))-%2B-Visual-Explanation-and-Clean-code
// Monotonic Decreasing Stack
class Solution2 {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        stack<float> fleets;
        vector<pair<int, float>> pos_time; // { {position_i, timeLeft_i}, {...}, ... }
         
        for(int i = 0; i < position.size(); i++)
            pos_time.push_back({ position[i], float(target - position[i]) / speed[i] });
        
        sort(pos_time.begin(), pos_time.end());
                   
        
        for(int i = 0; i < position.size(); i++){
            float fleet_i = pos_time[i].second;
            // if existing items in stack have shorter time to finish, 
            // they will get merged with current fleet     
            while(fleets.size() && (fleet_i >= fleets.top()))
                fleets.pop();
            
            fleets.push(fleet_i);
        }
        
        return fleets.size();
    }
};
int main(){
    Solution sol;
    int target =12;
    vector<int> position{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};
    cout<< "number of car fleet is: "<< sol.carFleet(target, position, speed);
    return 0;
}

// compute time taken for each car to reach target
// store pair of position and time in a vector
// sort the vector
// Push cars to stack, but pop if we ecounter any slower (higher time) car in front. CARS until this slower car become a FLEET.
// No. of cars in stack after full iteration implies numbr of FLEETS.