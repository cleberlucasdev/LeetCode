struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
      // The cursor will iterate through each node of all lists we're going to use. We'll first set it to list 1's head
    struct ListNode* cursor = l1;
  
    // Putting the value of each list's node in its corresponding array
    int l1_elements[100] = {0};
    int l1_idx = 0;

    while (cursor != NULL) 
    {
        l1_elements[l1_idx] = cursor->val;
        cursor = cursor->next;    
        l1_idx++;
    }

    // Once we've finished using it on list 1, set it to list 2's head
    cursor = l2;

    int l2_elements[100] = {0};
    int l2_idx = 0;
    
    while (cursor != NULL) 
    {
        l2_elements[l2_idx] = cursor->val;
        cursor = cursor->next;    
        l2_idx++;
    }

    // Evaluating which linked list is greater 
    int arr_length;
    if(l1_idx > l2_idx || l1_idx == l2_idx)
    {
        arr_length = l1_idx;
    }
    else
    {
        arr_length = l2_idx;
    }

    // Setting all elements in the resultas array to zero
    int l3_elements[arr_length + 1];
    for(int i = 0; i < arr_length + 1; i++)
    {
        l3_elements[i] = 0;
    }

    // Assembling the new list based on the previous ones' sum
    int curr_value;
    for(int i = 0; i < arr_length + 1; i++)
    {
        curr_value = l3_elements[i] + l1_elements[i] + l2_elements[i];
        // If the current node's value has 1 digit
        if(curr_value < 10)
            // Define it as the corresponding element
            l3_elements[i] = curr_value;
            
        // If it has 2
        else
        {
            // Subtract 10 from the value, converting it into a single-digit integer
            l3_elements[i] = curr_value - 10;
            // Add the remainder (1) to the next node's value
            l3_elements[i + 1] = 1;
        }
    }

    // Create the resulting Linked List's head
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    
    // Cursor now points to it
    cursor = l3;

    for(int i = 0; i < arr_length + 1; i++)
    {
        /* Define the current node's value to its corresponding
         * value in the array 
         */
        cursor->val = l3_elements[i];

        if(i == arr_length - 1)
        {   
            if(l3_elements[arr_length] != 0)
            {
                cursor->next = malloc(sizeof(struct ListNode));
                cursor = cursor->next;
                cursor->val = l3_elements[arr_length];
            }
            cursor->next = NULL;
            break;
        }
        else
        {   
            // Create another node and iterate the pointer to it
            cursor->next = malloc(sizeof(struct ListNode));
            cursor = cursor->next;
        }
    }

    return l3;
}
