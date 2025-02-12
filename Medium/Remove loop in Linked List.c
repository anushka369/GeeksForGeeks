struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution 
{
    public:     
        void removeLoop(Node* head) 
        {
            Node *fast, *slow;
            fast = slow = head;
            
            while (fast != NULL && fast -> next != NULL)
            {
                fast = fast -> next -> next;
                slow = slow -> next;
                
                if (fast == slow)
                {
                    slow = head;
                    
                    if (slow == fast) 
                    {
                        while(fast -> next != slow) 
                        {
                            fast = fast -> next;
                        }
                    }
                    
                    else 
                    {
                        while (slow -> next != fast -> next) 
                        {
                            slow = slow -> next;
                            fast = fast -> next;
                        }
                    }
 
                    fast -> next = NULL;
                }
            }
        }
};

// Link to the problem: https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1/
