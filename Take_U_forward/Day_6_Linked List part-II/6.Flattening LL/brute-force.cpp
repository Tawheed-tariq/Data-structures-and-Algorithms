class Solution {
    public:
      // Function which returns the  root of the flattened linked list.
      Node *flatten(Node *root) {
          vector<int> arr;
          Node *ptr = root;
          while(ptr != NULL){
              Node *btmPtr = ptr;
              while(btmPtr != NULL){
                  arr.push_back(btmPtr->data);
                  btmPtr = btmPtr->bottom;
              }
              ptr = ptr->next;
          }
          sort(arr.begin(), arr.end());
          Node * newList = new Node(-1), *dummy = newList;
          for(int i = 0; i < arr.size(); i++){
              dummy->bottom = new Node(arr[i]);
              dummy = dummy->bottom;
          }
          return newList->bottom;
      }
  };