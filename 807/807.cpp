#include <vector>
#include <iostream>
using namespace std;

int maxIncreaseKeepingSkyline(vector< vector<int> > & grid) {
    int count = 0;
    vector<int> skyline_rl;
    vector<int> skyline_tb(grid.size(), 0);

    for (int i = 0; i < grid.size(); ++i){
        int max = 0;
        for (int j = 0; j < grid[i].size(); ++j){
            if ( max < grid[i][j] ) max = grid[i][j];
            if (skyline_tb[j] < grid[i][j]) skyline_tb[j] = grid[i][j];
        }
        skyline_rl.push_back(max);
    }

    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j){
            int skyline = skyline_rl[i] > skyline_tb[j] ? skyline_tb[j] : skyline_rl[i];
            count += (skyline-grid[i][j]);
        }
    }
    return count;
}