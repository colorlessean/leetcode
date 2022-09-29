// #define VERBOSE

class Solution {
public:
/*
    // adjacency map for the complete depedency graph
    unordered_map<int, vector<int>> adj;
    
    // all will be init to empty
    unordered_map<int, bool> visited;
    
    // queue for to visits
    queue<int> visit;
    
    // the actual solution which is just the results of BFS
    vector<int> ans;
    
    void bfs(int start) {
        // add the start to the visited map
        visited[start] = true;
        // add the start to the back of the queue
        visit.push(start);
        
        while(!visit.empty()) {
            int curr = visit.front();
            #ifdef VERBOSE
            cout << curr << endl;
            #endif
            visit.pop();
            ans.push_back(curr);
            
            // get all adjacent nodes of the curr
            // if not visited add to the queue
            // mark as visited
            for (int i = 0; i < adj[curr].size(); i++) {
                if (!visited[adj[curr][i]]) {
                    visited[adj[curr][i]] = true;
                    visit.push(adj[curr][i]);
                }
            } 
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // fill up the adjacency table with all the values
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // print function to see our adjacency table
        #ifdef VERBOSE
        for (auto iter = adj.begin(); iter != adj.end(); iter++) {
            cout << iter->first << ": ";
            for (int i = 0; i < iter->second.size(); i++) {
                cout << iter->second[i] << " ";
            }
            cout << endl;
        }
        #endif
        
        // now we can call BFS and see the courses
        // we always need to start with course 0
        bfs(0);
        
        // need to add any unused ones to the end since we can do them in any order
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    */
    
    // Need to use a topological sort not just a BFS (it uses BFS but still need more)
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // need an adjacency table
        map<int, vector<int>> adj_list;
        for (int i = 0; i < prerequisites.size(); i++) {
            // gives us the edge from ai to bi 
            adj_list[prerequisites[i][1]].push_back(prerequisites[i][0]); 
        }
        
        // this is the special part of the topological algorithm which is the indegree list of each node
        vector<int>indegree(numCourses, 0);
        for (auto x: adj_list) {
            for (auto node: x.second) {
                // every neighbour of the node will be incremented as they are being directed
                indegree[node]++;
            }
        }
        
        #ifdef VERBOSE
        for (int i = 0; i < numCourses; i++) {
            cout << indegree[i] << " ";
        }
        cout << endl;
        #endif
        
        // TOPOLOGICAL SORT
        // keep the nodes with an indegree of 0 (so "ground-level" nodes)
        queue<int> q;
        // add all the 0 indegree nodes to the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // the sort itself using a BFS approach
        vector<int> topology;
        while (!q.empty()) {
            int curr = q.front();
            topology.push_back(curr);
            q.pop();
            
            // traverse the neighbours
            for (auto x: adj_list[curr]) {
                // decrease the indegree of each neighbour node
                indegree[x]--;
                // if the indegree becomes 0 then add it to the queue
                if (indegree[x] == 0) {
                    q.push(x);
                } 
            }
        }
        
        if (topology.size() == numCourses) {
            return topology;
        }
        
        return {};
    }
};

