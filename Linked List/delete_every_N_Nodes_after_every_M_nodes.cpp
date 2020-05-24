void deleteLL(struct Node  *head)
{
    struct Node* temp;  
    while(head->next !=0)
    {
        temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    delete head;
}


void linkdelete(struct Node  *head, int M, int N)
{
    if(M<0 || N<0){
        cout<<"Both M and N should be Non Negative integers";
        return;
    }
    if(M==0 && N==0)
    {
        cout<<"Both M and N cannot be zero simultaneously";
        return;
    }
    
    struct Node *temp = head, *prev=0;
    int i,j;
    while(temp!=0)
    {
        i=0;
        while(i<M && temp!=0)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        
        j=0;
        while(j<N && temp!=0)
        {
            if(prev == 0)
            {
                deleteLL(head);
                return 0;
            }
            else
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            j++;
        }
    }
    return head;
}