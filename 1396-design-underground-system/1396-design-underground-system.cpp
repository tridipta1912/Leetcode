class UndergroundSystem {
map<pair<string, string>, int> tot_time, tot_travel;
unordered_map<int, string> start_loc;
unordered_map<int, int> start_time;
public:
    UndergroundSystem() {
        tot_time.clear();
        tot_travel.clear();
        start_loc.clear();
        start_time.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        start_loc[id] = stationName;
        start_time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string from = start_loc[id];
        string to = stationName;
        int total_time = (t - start_time[id]);
        tot_time[{from, to}] += total_time;
        tot_travel[{from, to}]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = tot_time[{startStation, endStation}];
        avg /= (double)(tot_travel[{startStation, endStation}]);
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */