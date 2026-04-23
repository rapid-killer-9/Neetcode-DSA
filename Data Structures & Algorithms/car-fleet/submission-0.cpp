class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Step 1: store {position, time}
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Step 2: sort by position descending
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double prevTime = 0;

        // Step 3: process cars
        for (auto& car : cars) {
            double currTime = car.second;

            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }

        return fleets;
    }
};