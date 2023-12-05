class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int, ll>> delayQueue, forgetQueue;

        ll totalAware = 1; // Total persons currently aware of the secret
        ll canShare = 0;   // Persons currently able to share the secret

        delayQueue.push({1 + delay, 1});
        forgetQueue.push({1 + forget, 1});

        int person = 2;
        
        while (person <= n) {
            // Check if some people have forgotten the secret at this time
            if (!forgetQueue.empty() && forgetQueue.front().first == person) {
                auto forgetEvent = forgetQueue.front();
                canShare = (canShare - forgetEvent.second + mod) % mod;
                totalAware = (totalAware - forgetEvent.second + mod) % mod;
                forgetQueue.pop();
            }

            // Check if some people can start sharing the secret after their delay time
            if (!delayQueue.empty() && delayQueue.front().first == person) {
                auto delayEvent = delayQueue.front();
                canShare += delayEvent.second;
                canShare %= mod;
                delayQueue.pop();
            }

            // Update the total number of people aware of the secret
            totalAware += canShare;
            totalAware %= mod;

            // If there are people to be added to both delay and forget queues, add them
            if (canShare != 0) {
                delayQueue.push({person + delay, canShare});
                forgetQueue.push({person + forget, canShare});
            }

            // Move to the next person
            person++;
        }

        // Ensure the result is within the specified modulo range
        totalAware %= mod;

        return totalAware;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n), where n is the input value 'n'
