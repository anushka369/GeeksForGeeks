// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node 
{
    int data;
    Node* next;

    Node(int x) 
    {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) 
{
    while (node != NULL) 
    {
        printf("%d ", node -> data);
        node = node -> next;
    }
    cout << endl;
}

class Solution 
{
    public:
        Node* mergeKLists(vector<Node*>& arr) 
        {
            // Min-heap to store the nodes
            priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> minHeap;
    
            // Insert the head of each linked list into the min-heap
            for (Node* head : arr) 
            {
                if (head != NULL) 
                {
                    minHeap.push({head -> data, head});
                }
            }
    
            // Dummy node to help with the merged list
            Node* dummy = new Node(0);
            Node* tail = dummy;
    
            // While there are nodes in the min-heap
            while (!minHeap.empty()) 
            {
                // Get the smallest node
                Node* smallestNode = minHeap.top().second;
                minHeap.pop();
    
                // Add the smallest node to the merged list
                tail -> next = smallestNode;
                tail = tail -> next;
    
                // If there is a next node in the same list, add it to the heap
                if (smallestNode->next != NULL) 
                {
                    minHeap.push({smallestNode -> next -> data, smallestNode -> next});
                }
            }
    
            // The merged list starts from the next of the dummy node
            return dummy -> next;
        }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
  
    while (t--) 
    {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) 
        {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) 
            {
                Node* newNode = new Node(x);
                temp -> next = newNode;
                temp = temp -> next;
            }
            v[i] = head -> next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }
    return 0;
}

// Link to the problem: https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1/
