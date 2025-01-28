class Solution 
{
    public:
    vector<vector<int>> neighbour{{-1,-2}, {-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
    //Function to find out minimum steps Knight needs to reach target position.
    int helper(int srcX, int srcY, int desX, int desY, int n){
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(n, false));
        q.push({srcX,srcY});
        visited[srcX][srcY]=true;
        int level =0;
        while(q.size()){
            int size = q.size();
            while(size > 0){
                pair<int,int>p = q.front();
                q.pop();
                int x = p.first, y=p.second;
                if(x==desX and y==desY){
                    return level;
                }
                for(auto it:neighbour){
                    int newX=x+it[0], newY=y+it[1];
                    if(newX>=0 and newX<n and newY>= 0 and newY<n and !visited[newX][newY]){
                        q.push({newX,newY});
                        visited[newX][newY]=1;
                    }
                }
                size--;
            }
            level++;
        }
        return level;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	      int src_x = KnightPos[0] - 1;  // Row (convert from 1-indexed to 0-indexed)
        int src_y = KnightPos[1] - 1;  // Column (convert from 1-indexed to 0-indexed)
        int des_x = TargetPos[0] - 1;  // Row
        int des_y = TargetPos[1] - 1;  // Column
    
    // Call the helper function and return the result
    return helper(src_x, src_y, des_x, des_y, N);
	}
};
