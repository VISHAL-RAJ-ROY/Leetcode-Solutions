class Solution {
public:
    int nx, ny, vx[410], vy[410], l, r, x, y, xx, yy, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<int> *t;
    bool vis[410][410];
    
    inline void expand(int *v, int &n) {
        sort(v, v + n);
        n = unique(v, v + n) - v;
        int m = n, last = -1;
        for (int i = 0; i < m; i++) {
            if (last + 1 != v[i])
                v[n++] = last + 1;
            last = v[i];
        }
        if (last != 999999)
            v[n++] = 999999;
        sort(v, v + n);
    }
    int dfs(int x, int y) {
        xx = x + (int((*t)[0]>x)<<1) - 1;
        yy = y;
        
        if (xx < 0 || yy < 0 || xx >= nx || yy >= ny || vis[xx][yy]);
        else {
            if (xx == (*t)[0] && yy == (*t)[1])
                return true;
            vis[xx][yy] = true;
            if (dfs(xx, yy))
                return true;
        }
        
        xx = x;
        yy = y + (int((*t)[1]>y)<<1) - 1;
        if (xx < 0 || yy < 0 || xx >= nx || yy >= ny || vis[xx][yy]);
        else {
            if (xx == (*t)[0] && yy == (*t)[1])
                return true;
            vis[xx][yy] = true;
            if (dfs(xx, yy))
                return true;
        }
        
        
        for (int d = 0; d < 4; d++) {
            xx = x + dx[d], yy = y + dy[d];
            if (xx < 0 || yy < 0 || xx >= nx || yy >= ny || vis[xx][yy])
                continue;
            if (xx == (*t)[0] && yy == (*t)[1])
                return true;
            vis[xx][yy] = true;
            if (dfs(xx, yy))
                return true;
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        t = &target;
        nx = ny = 0;
        for (auto b: blocked) {
            vx[nx++] = b[0];
            vy[ny++] = b[1];
        }
        vx[nx++] = source[0];
        vy[ny++] = source[1];
        vx[nx++] = target[0];
        vy[ny++] = target[1];
        
        expand(vx, nx);
        expand(vy, ny);
        
        
        for (int i = 0; i < nx; i++)
            memset(vis, 0, ny);
        
        for (auto &b: blocked)
            vis[lower_bound(vx, vx + nx, b[0]) - vx][lower_bound(vy, vy + ny, b[1]) - vy] = 1;
        
        source[0] = lower_bound(vx, vx + nx, source[0]) - vx;
        source[1] = lower_bound(vy, vy + ny, source[1]) - vy;
        target[0] = lower_bound(vx, vx + nx, target[0]) - vx;
        target[1] = lower_bound(vy, vy + ny, target[1]) - vy;
        
        vis[source[0]][source[1]] = 1;
        return dfs(source[0], source[1]); 
    }
};
