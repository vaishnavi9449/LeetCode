
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        // Build adjacency list
        for (auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        // Push courses having indegree 0
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        // BFS
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for (int next : adj[course]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        // Check for cycle
        if (ans.size() != numCourses) {
            return {};
        }
        return ans;
    }
};