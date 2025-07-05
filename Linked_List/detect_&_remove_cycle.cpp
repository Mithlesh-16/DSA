#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode* next) : val(val), next(next){};

    ~ListNode(){};

};

// MOST EFFICIENT FOR DETECTION OF LOOP - FCD
// Floyd's detection Algorithm (FCD)
// two pointers - fast & slow; 
// fast moves 2 nodes forward
// slow moves 1 node forward
ListNode* detect_cycle_1(ListNode* head){

    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast and fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(slow == fast) return slow;
    }
    return head;

}

// Detect cycle using Maps
bool detect_cycle_2(ListNode* head){
    ListNode* temp = head;
    map <ListNode*, bool> visited;
    while(temp){
        if(visited[temp]) return true;
        visited[temp] = 1;
        temp = temp -> next;
    }
    return false;
}

// Detect cycle using dummy node
// Don't Use this method where, modifying the nodes is not allowed
// Here, Full Linked List gets modified and broken
bool detect_cycle_3(ListNode* head){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = head;
    while(temp){
        if(temp -> next == dummy) return true;
        ListNode* next_node = temp -> next;
        temp -> next = dummy;
        temp = next_node;
    }
    return false;
}

// Detect cycle using Un-Ordered set
bool detect_cycle_4(ListNode* head){
    unordered_set <ListNode* > visited;
    ListNode* temp = head;
    while(temp){
        if(visited.count(temp)) return true;
        visited.insert(temp);
        temp = temp -> next;
    }
    return false;
}

// finding starting node of cycle
ListNode* starting_node_of_loop(ListNode* head){
    // i) FCD
    // point slow to head,
    // move it, 1 step ahead
    // intersection point (where slow == fast {FCD}),
    // move intersection point 1 step ahead
    // untill slow != intersection

    ListNode* intersection = detect_cycle_1(head);
    ListNode* slow = head;
    while(intersection){
        slow = slow -> next;
        intersection = intersection -> next;
        if(slow == intersection) return slow;
    }
    return slow;
}

//remove cycle function
void remove_cycle(ListNode* head){
    // make the previous of start node of loop point to NULL.
    ListNode* start = starting_node_of_loop(head);
    ListNode* temp = start -> next;
    while(temp -> next != start){
        temp = temp -> next;
    }
    temp -> next = nullptr;
}



int main() {


return 0;
}