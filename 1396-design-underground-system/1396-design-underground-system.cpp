class UndergroundSystem {
public:
    map<pair<string,string>,vector<int>> times; 
    map<int,pair<string,int>> travel;
  
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        travel[id]= {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int time_taken= t - travel[id].second;
        
        string from= travel[id].first;
        string to= stationName;
        
        // store the new time and increase the number count
        times[{from,to}].push_back(time_taken);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double tot_time= 0;        
        double tot_count= times[{startStation, endStation}].size();
        for(auto it: times[{startStation, endStation}]) tot_time+= it;
        return tot_time/tot_count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */