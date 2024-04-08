class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count1 {}, count2 {};
        for(auto x: students) {
            count1 += x;
        }
        for(auto x: sandwiches) {
            count2 += x;
        }
        
		// If count of circular sandwiches and students wanting circular sandwiches is same (and same for square sandwiches, then all the students eventually will get the desired sandwich.
		
        if(count1 == count2) {
            return 0;
        }
        
        queue <int> q;
        unordered_set <int> s;
		// Push all the indexes of the students in the queue
        for(int i=0; i<students.size(); i++) {
            q.push(i);
        }
        
        int pos = 0; 
        while(q.empty() == false) {
			// If student wants a sandwiches which is on the top of the stack, student will leave the queue and take the sandwich
            if(students[q.front()] == sandwiches.at(pos)) {
                int temp = q.front();
                q.pop(); // Student is removed from the queue
                pos++; // Sandwich is taken by the student
                s.erase(s.begin(), s.end()); // We also delete all the students, who didn't want this particular sandwich, because that sandwich has been processed
            } else { 
				// If student want a sandwich which is not on the top of the stack, studnet will go back to end of the queue
                int temp = q.front(); 
                if(s.find(temp) != s.end()) { // If same student is again coming for the same sandwich, we break the loop because rest of the sandwiches can not be taken by any student
				//If student wanted this particular sandwich, he/she should have taken it first time only, If he is coming again in front of the line mean, he/she doesn't want that sandwich, and all the students after him/her. If anyone wanted this particular sandwich it would have been taken by someone.
                    break;
                }
                q.pop();
                q.push(temp);
                s.insert(temp); // Add it to the hash set to keep track of what all students has already come for this sandwich
            }
        }
        
        int ans = sandwiches.size()-pos; // No of sandwiches left directly gives the no of students unable to eat lunch
		// int ans = q.size(); we can know by this also, no of students unable to eat lunch
        return ans; // Return the answer
        
    }
};
