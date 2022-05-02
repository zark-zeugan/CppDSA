#include <iostream>
#include <vector>

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};




ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  
     if(!list1)
        return list2;
     if(!list2)
        return list1;
  
     ListNode* temp = nullptr; 

     if(list1->val > list2->val)
     {
        temp = list1;
        list1 = list2;
        list2 = temp;
     }
     
     ListNode* res = list1;
     while(list1 != nullptr && list2 != nullptr)
     {
        ListNode* temp0 = nullptr;
        while(list1 != nullptr && list1->val <= list2->val)
        {
           temp0 = list1;
           list1 = list1->next;
        }
        temp0->next = list2;
        temp = list1;
        list1 = list2;
        list2 = temp;
     }

     return res;
  
}




int main(int argc, char const *argv[])
{
   std::vector<int> v1 = {5,7,9};
   std::vector<int> v2 = {3,4,8,10};

   ListNode* list1 = nullptr;
   ListNode* list2 = nullptr;

   for(auto val: v1)
   {
      if(!list1)
      {
         list1 = new ListNode(val);
      }
      else
      {
         ListNode* current = list1;
         while(current->next != nullptr)
         {
            current = current->next;
         }
         current->next = new ListNode(val); 
      }
   }

   for(auto val:v2)
   {
      if(!list2)
      {
         list2 = new ListNode(val);
      }
      else
      {
         ListNode* current = list2;
         while(current->next != nullptr)
         {
            current = current->next;
         } 
         current->next = new ListNode(val);
      }

   }


   // std::cout << list1->next->val << std::endl;
   // std::cout << list2->next->val << std::endl;

   mergeTwoLists(list1,list2);


   return 0;
}


