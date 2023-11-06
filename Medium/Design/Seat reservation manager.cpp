class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            available_seats.push(i);
        }
        
    }
    
    int reserve() {
        int seatNumber = available_seats.top();
        available_seats.pop();
        return seatNumber;
        
    }
    
    void unreserve(int seatNumber) {
        available_seats.push(seatNumber);
    }

private:
    priority_queue<int, vector<int>, greater<int>> available_seats;

};


