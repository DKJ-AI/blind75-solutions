// Problem: Add Two Numbers
// Difficulty: Medium
// Topic: Linked Lists
// Approach: Traverse both lists simultaneously, track carry
// Time: O(max(m,n)) | Space: O(max(m,n))

#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────
// Definition for singly-linked list
// ─────────────────────────────────────────
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ─────────────────────────────────────────
// Solution — Dummy Head + Carry
// ─────────────────────────────────────────
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

// ─────────────────────────────────────────
// Helper: build list from vector
// ─────────────────────────────────────────
ListNode* build(vector<int> nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for (int n : nums) { cur->next = new ListNode(n); cur = cur->next; }
    return dummy->next;
}

// Helper: print list
void print(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << " -> "; head = head->next; }
    cout << "\n";
}

// ─────────────────────────────────────────
// Test
// ─────────────────────────────────────────
int main() {
    // 342 + 465 = 807 → [7, 0, 8]
    ListNode* l1 = build({2, 4, 3});
    ListNode* l2 = build({5, 6, 4});

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    print(result); // Expected: 7 -> 0 -> 8

    return 0;
}