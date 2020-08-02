//DP
//WA
//47 / 56 test cases passed.
/*
two pass(forward and backward),
in each pass, greedily maximize the profit it gets,
but this doesn't work for the case:
[[1,1,1,1,0,0,0],
[0,0,0,1,0,0,0],
[0,0,0,1,0,0,1],
[1,0,0,1,0,0,0],
[0,0,0,1,0,0,0],
[0,0,0,1,0,0,0],
[0,0,0,1,1,1,1]]
where in the first pass, 
we shouldn't choose the path that will maximize the profit!
*/
enum class DIR{
    NONE = 0,
    UP = 1,
    LEFT = 2
};

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 1) return max(grid[0][0], 0);
        
        vector<vector<int>> dpf(n, vector<int>(n, 0));
        vector<vector<int>> dpb(n, vector<int>(n, 0));
        vector<vector<DIR>> from(n, vector<DIR>(n, DIR::NONE));
        
        //base case
        dpf[0][0] = grid[0][0];
        grid[0][0] = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == -1){
                    dpf[i][j] = -1;
                }else{
                    if(i-1 >= 0 && dpf[i-1][j] != -1){
                        if(dpf[i-1][j]+grid[i][j] > dpf[i][j]){
                            dpf[i][j] = dpf[i-1][j]+grid[i][j];
                            from[i][j] = DIR::UP;
                        }
                    }
                    if(j-1 >= 0 && dpf[i][j-1] != -1){
                        if(dpf[i][j-1]+grid[i][j] > dpf[i][j]){
                            dpf[i][j] = dpf[i][j-1]+grid[i][j];
                            from[i][j] = DIR::LEFT;
                        }
                    }
                }
            }
        }
        
        // cout << "dpf: " << endl;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << dpf[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        // cout << "from: " << endl;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         if(from[i][j] == DIR::NONE) cout << 0;
        //         else if(from[i][j] == DIR::LEFT) cout << 1;
        //         else cout << 2;
        //         cout << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        //go backward the path and update "grid"
        // cout << "go backward: " << endl;
        int i = n-1, j = n-1;
        while(i != 0 || j != 0){
            // cout << "(" << i << ", " << j << ")" << endl;
            if(grid[i][j] > 0) grid[i][j] = 0;
            
            //go to previous position
            if(from[i][j] == DIR::LEFT){
                --j;
            }else if(from[i][j] == DIR::UP){
                --i;
            }else{
                //no way to go back!
                return 0;
            }
        }
        
        // cout << "grid: " << endl;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        for(int i = n-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                if(dpf[i][j] == -1){
                    dpb[i][j] = -1;
                }else{
                    if(i+1 < n && dpb[i+1][j] != -1){
                        dpb[i][j] = max(dpb[i+1][j]+grid[i][j], dpb[i][j]);
                    }
                    if(j+1 < n && dpb[i][j+1] != -1){
                        dpb[i][j] = max(dpb[i][j+1]+grid[i][j], dpb[i][j]);
                    }
                }
            }
        }
        
        // cout << "dpb: " << endl;
        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < n; ++j){
        //         cout << dpb[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        return dpf[n-1][n-1] + dpb[0][0];
    }
};
