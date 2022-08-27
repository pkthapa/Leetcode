#include "main.hpp"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(); // We can also consider speed.size() since both of them are same.

        // pair<carPosition, timeToReachTarget>
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            double time = static_cast<double>((target - position[i])) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort w.r.t. car's position.
        // The first car position denotes the farthest car from target.
        // The last car position denotes the nearest car from target.
        sort(cars.begin(), cars.end());

        double maxTime = 0.0F;
        int fleetCount = 0;

        // Since 'cars' is sorted, if there is a car at position far away from the 'target' and if the
        // car's time is smaller than that of cars nearer to target then the cars become a fleet.
        for (int i = n - 1; i >= 0; --i) {
            if (cars[i].second > maxTime) {
                maxTime = cars[i].second;
                ++fleetCount;
            }
        }
        return fleetCount;
    }
};

int main() {
    Solution sln;
    {
        int target = 12;
        vector<int> position {10, 8, 0, 5, 3};
        vector<int> speed {2, 4, 1, 1, 3};
        assert(3 == sln.carFleet(target, position, speed));
    }
    {
        int target = 10;
        vector<int> position {3};
        vector<int> speed {3};
        assert(1 == sln.carFleet(target, position, speed));
    }
    {
        int target = 100;
        vector<int> position {0, 2, 4};
        vector<int> speed {4, 2, 1};
        assert(1 == sln.carFleet(target, position, speed));
    }
    return 0;
}