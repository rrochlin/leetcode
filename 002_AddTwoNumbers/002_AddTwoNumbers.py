# Definition for singly-linked list.
from typing import Union
Optional = Union[None, object]
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = []
        num2 = []
        while(True):
            if l1:
                num1.append(str(l1.val))
                l1=l1.next
            if l2:
                num2.append(str(l2.val))
                l2=l2.next
            if not (l1 or l2):
                break
        total = int("".join(num1[::-1])) + int("".join(num2[::-1]))
        tlist = str(total)
        head = ListNode(val=int(tlist[0]))
        for i in tlist[1:]:
            print(i)
            tmp = head
            head = ListNode(val=int(i))
            head.next = tmp
        return head

def addTwoNumbersFaster(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head1 = l1
        head2 = l2
        head3 = ListNode(0)
        ans = head3
        res = 0
        while head1 or head2:
            if head1 and head2:
                temp = head1.val+head2.val+res
                res = 0
                if temp>9:
                    res = temp//10
                    temp = temp%10
                head3.next = ListNode(temp)
                head3 = head3.next
            if head1 is not None and head2 is None:
                temp = head1.val+res
                res = 0
                if temp>9:
                    res = temp//10
                    temp = temp%10
                head3.next = ListNode(temp)
                head3 = head3.next

            if head1 is None and head2 is not None:
                temp = head2.val+res
                res = 0
                if temp>9:
                    res = temp//10
                    temp = temp%10
                head3.next = ListNode(temp)
                head3 = head3.next
            if head1:
                head1 = head1.next
            if head2:
                head2 = head2.next

        if res:
            head3.next = ListNode(res)

        return ans.next
