// #define VERBOSE

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // int coin_index = coins.size() - 1;
        
        /*
        int coin_amount = amount / coins[coin_index];
        
        #ifdef VERBOSE
        cout << coin_amount << endl;
        #endif
        
        int remainder = amount / coins[coin_index];
        
        #ifdef VERBOSE
        cout << remainder << endl;
        #endif
        */
        
        /*
        while (coin_index >= 0) {
            
        }
        */
        /*
        sort(coins.begin(), coins.end());
        
        int nums_of_coins = 0;
        
        for (int i = coins.size()-1; i >= 0; i--) {
            int coin_amount = amount / coins[i];
            #ifdef VERBOSE
            cout << coin_amount << " ";
            #endif
            nums_of_coins += coin_amount;
            amount -= coin_amount * coins[i];
            #ifdef VERBOSE
            cout << amount << endl;
            #endif
        }
        
        return amount == 0 ? nums_of_coins : -1;
        */
        
        // make sure they are in ascending order
        sort(coins.begin(), coins.end());
        
        int dp[++amount];
        dp[0] = 0;
        
        for (int i = 1; i < amount; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                // this coin is too big and all next coins will be too big too
                if (i - coins[j] < 0) {
                    break;
                }
                // if we have visited the dp location for the amount at the currently targeted amount minus the current coin value
                // we don't want to go to an un-visited amount since it was impossible to make
                // so if the previous was impossible to make so too will the current target
                if (dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
                }
            }
        }
        
        return dp[--amount] == INT_MAX ? -1 : dp[amount];
    }
};

