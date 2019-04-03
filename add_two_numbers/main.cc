// LeetCode problem "Add Two Numbers"
// https://leetcode.com/problems/add-two-numbers/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:

    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (l1 == nullptr || l2 == nullptr)
            throw std::runtime_error("List must not be nullptr.");

        int rest = 0;   // Remainder after digit addition
        int sum;        // Sum of digits

        auto* result = new ListNode(0);  // Pointer to final result
        ListNode* pt = result;           // Pointer to current digit of the result

        while (pt != nullptr) {
            sum = rest;              // Start with the remainder from the last addition
            if (l1 != nullptr) {     // Add digit of l1
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {     // Add digit of l2
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum >= 10) {         // Decide of there is a remainder
                rest = 1;
                sum -= 10;
            } else {
                rest = 0;
            }

            pt->val = sum;           // Assign the value

            if (l1 != nullptr || l2 != nullptr || rest > 0) {
                // Append another node if there is another digit
                pt->next = new ListNode(0);
                pt = pt->next;
            } else {
                // Set pt to nullptr if there is no other digit
                pt = nullptr;
            }

        }

        return result;
    }
};

// Helper function to convert int to ListNode list
ListNode* int_to_list(int n) {
    // Convert the result into a list
    auto* result = new ListNode(n % 10);
    ListNode* pointer = result;
    n /= 10;
    while(n > 0) {
        pointer->next = new ListNode(n % 10);
        pointer = pointer->next;
        n /= 10;
    }

    return result;
}

// Test function for Solution::addTwoNumbers
bool test(int a, int b) {
    const int sum = a + b;

    ListNode* la = int_to_list(a);
    ListNode* lb = int_to_list(b);
    ListNode* ls = int_to_list(sum);

    ListNode* solution = Solution::addTwoNumbers(la, lb);

    while (solution != nullptr) {
        if (solution->val != ls->val)
            return false;    // Wrong value
        solution = solution->next;
        ls = ls->next;
        if ((solution == nullptr && ls != nullptr) || (solution != nullptr && ls == nullptr))
            return false;    // One of the lists ended but the other didn't
    }

    return true;
}

int main() {

    // Run a few tests
    std::cout << 342 << " + " << 465 << ": " << test(342, 465) << std::endl;
    std::cout << 0 << " + " << 0 << ": " << test(0, 0) << std::endl;
    std::cout << 1 << " + " << 0 << ": " << test(1, 0) << std::endl;
    std::cout << 0 << " + " << 1 << ": " << test(0, 1) << std::endl;
    std::cout << 99 << " + " << 99 << ": " << test(99, 99) << std::endl;
    std::cout << 999 << " + " << 1 << ": " << test(999, 1) << std::endl;
    std::cout << 9 << " + " << 1 << ": " << test(9, 1) << std::endl;
    std::cout << 1 << " + " << 9 << ": " << test(1, 9) << std::endl;
    std::cout << 9 << " + " << 9 << ": " << test(1, 9) << std::endl;

    return 0;
}
