
// Reversing the Linked List Iteratively using 3 pointers
struct node* reverseListIterativelyUsingThreePointers(struct node *head)
{
    if(head == 0 || head->next == 0)
        return head;
    
    struct node *prev = 0, *curr = head, *next = head;
    while(curr!=0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


// Get length of the Linked List
int list_length(struct node* head)
{
    int n=0;
    while(head)
    {
        n++;
        head = head->next;
    }
    return n;
}


// Reverse inGroups Iteratively
struct node *reverse (struct node *head, int k)
{ 
    int l = list_length(head);
    
    if(k >= l)
    {
        head = reverseListIterativelyThreePointers(head);
        return head;
    }
    
    int n = l/k;
    if(l%k)
    {
        n++;
    }
    
    struct node *curr=head, *next, *prev = 0;
    int i, backup_k = k;
    struct node* prev_list = 0, *nh;
    
    for(i=0; i<n; i++)
    {
        k = backup_k;
        prev = 0;
        nh = curr;
        while(k!=0 && curr != 0)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        if(prev_list == 0)
        {
            prev_list = head;
            head = prev;
        }
        else
        {
            prev_list->next = prev;
            prev_list = nh;
        }
    }
    
    return head;
}


// Reverse in Groups Recursively
struct node *reverse (struct node *head, int k)
{ 
    if(head == 0)
        return head;
    
    struct node *curr = head, *prev = 0, *next;
    int backup_k = k;
    while(k!=0 && curr !=0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k--;
    }
    head->next = reverse(curr, backup_k);
    return prev;
}