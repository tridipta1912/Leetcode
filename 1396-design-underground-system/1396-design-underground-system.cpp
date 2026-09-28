class UndergroundSystem {
map<string, int> ide;
map<pair<int, int>, int> tot_time, tot_travel;
unordered_map<int, int> start_loc;
unordered_map<int, int> start_time;
int cur;
public:
    UndergroundSystem() : cur{0} {
        tot_time.clear();
        tot_travel.clear();
        start_loc.clear();
        start_time.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(ide[stationName] == 0)    ide[stationName] = ++cur;
        start_loc[id] = ide[stationName];
        start_time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        if(ide[stationName] == 0)    ide[stationName] = ++cur;
        int from = start_loc[id];
        int to = ide[stationName];
        int total_time = (t - start_time[id]);
        tot_time[{from, to}] += total_time;
        tot_travel[{from, to}]++;
        start_loc.erase(id);
        start_time.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double avg = tot_time[{ide[startStation], ide[endStation]}];
        avg /= (double)(tot_travel[{ide[startStation], ide[endStation]}]);
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