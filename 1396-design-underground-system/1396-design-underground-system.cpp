class UndergroundSystem {
unordered_map<int, pair<string, int>> passenger;
unordered_map<string, pair<int, int>> station;

public:
    UndergroundSystem() {
    
    }
    
    void checkIn(int id, string stationName, int t) {
        passenger[id].first = stationName;
        passenger[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string from = passenger[id].first;
        string to = stationName;
        int total_time = (t - passenger[id].second);
        string conc = from + " " + to;
        passenger.erase(id);

        if(station.find(conc) == station.end()) station[conc] = {0, 0};
        station[conc].first += total_time;
        station[conc].second++;
    }
    
    double getAverageTime(string from, string to) {
        string conc = from + " " + to;
        double avg = station[conc].first;
        avg /= (double)(station[conc].second);
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