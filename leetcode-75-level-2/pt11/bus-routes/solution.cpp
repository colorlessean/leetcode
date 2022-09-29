class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // this will use a BFS where we are going to use the bus stops themselves as nodes
        unordered_map<int, vector<int>> bus_stops;
        
        // number of buses available
        int n = routes.size();
        
        // add all of our bus stops to the list with the buses that come to them
        for (int i = 0; i < n; i++) {
            int m = routes[i].size();
            for (int j = 0; j < m; j++) {
                int curr_stop = routes[i][j];
                int curr_bus = i;
                bus_stops[curr_stop].push_back(curr_bus);
            }
        }
        
        // call the bfs to do the bulk work
        return bfs(routes, bus_stops, source, target);
    }
    
    int bfs(vector<vector<int>>& routes, unordered_map<int, vector<int>>& bus_stops, int source, int target) {
        if (source == target) {
            return 0;
        }
        
        unordered_map<int, bool> visited_stops; // map to keep track of all our visted standard bfs stuff
        unordered_map<int, bool> visited_buses; // map to keep track of all the bus stops visited
        queue<pair<int, int>> q; // store the bus stop and the count of buses boarded
        
        // start at the arbitrary source
        q.push({source, 0});
        visited_stops[source] = true;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            // get the values from the front popped value
            int curr_stop = front.first;
            int count = front.second;
            // if we've reached the destination then we can return
            if (curr_stop == target) {
                return count;
            }
            // get the list of buses that can be boarded from our current stop
            vector<int> bus_options = bus_stops[curr_stop];
            // go through each option
            for (int i = 0; i < bus_options.size(); i++) {
                int curr_bus = bus_options[i];
                // we don't want to hop back on a bus we've been on
                if (visited_buses[curr_bus]) {
                    continue;
                }
                else {
                    // check the next stops for the selected bus
                    vector<int> next_stops = routes[curr_bus];
                    for (int j = 0; j < next_stops.size(); j++) {
                        int next_stop = next_stops[j];
                        // if we have already been to that stop we don't want to go again
                        if (visited_stops[next_stop]) {
                            continue;
                        }
                        else {
                            // so add to the queue so we will actually end up going to this stop
                            // and mark it as a visited stop as in BFS
                            q.push({next_stop, count+1});
                            visited_stops[next_stop] = true;
                        }
                    }
                    visited_buses[curr_bus] = true;
                }
            }
        }
        return -1;
    }
};

