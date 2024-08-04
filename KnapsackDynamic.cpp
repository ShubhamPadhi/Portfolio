#include <iostream>
#include <vector>


using namespace std;

int solve(vector<int>& weight, vector<int>& value, int n, int capacity) {
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = 0; w <= capacity; w++) {
        if (weight[0] <= w) {
            dp[0][w] = value[0];
        } else {
            dp[0][w] = 0;
        }
    }

  
    for (int i = 1; i < n; ++i) {
        for (int w = 0; w <= capacity; w++) {
            int include = 0;
            if (weight[i] <= w) {
                include = value[i] + dp[i - 1][w - weight[i]];
            }
            int exclude = dp[i - 1][w];
            dp[i][w] = max(include, exclude);
        }
    }
     cout << "DP Table:" << endl;
    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

   
    return dp[n-1][capacity];
}

int main() {
    int capacity, n;

    cout << "Enter capacity: ";
    cin >> capacity;
    
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int profit = solve(weight, value, n, capacity);
    cout << "Maximum profit is: " << profit << endl;

    return 0;
}