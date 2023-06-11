#include <vector>
#include <map>

using namespace std;

class SnapshotArray {
    private:
    vector<map<int, int>> data; // vector of maps
    int snap_id; // current snapshot id
public:
    SnapshotArray(int length) {
        data.resize(length); // resize the vector to the given length
        snap_id = 0; // initialize the snapshot id to 0
        
    }
    
    void set(int index, int val) {
         data[index][snap_id] = val; // set the value of the index to val at the current snapshot id
        
    }
    
    int snap() {
        return snap_id++; // take a snapshot and return the previous snapshot id
        
    }
    
    int get(int index, int snap_id) {
        auto it = data[index].upper_bound(snap_id); // find the first snapshot id greater than the given snap_id
        if (it == data[index].begin()) { // if there is no snapshot with a greater snapshot id
            return 0; // return 0 (the initial value of each element)
        } else {
            --it; // go back one iterator position to find the snapshot id less or equal than the given snap_id
            return it->second; // return the value at the found snapshot id
        }
        
    }
};
