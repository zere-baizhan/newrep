# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};



int findMaxSum(int n, Node *head) {

    int max_sum = head->val;  
    int cur_sum = head->val; 

    Node* cur = head->next; 

    while (cur != nullptr) {
        cur_sum += cur->val; 
        max_sum = max(max_sum, cur_sum);
        if (cur_sum < 0) {
            cur_sum = 0;
        }

        cur = cur->next; 
    }

    return max_sum; 
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
