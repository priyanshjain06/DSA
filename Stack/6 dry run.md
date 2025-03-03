Call # Stack (Before Pop) Top Element (Popped) Recursive Call Stack (After Push Back)
1 {4, 3, 2, 1, 8} 8 insertAtBottom({4,3,2,1}, 2) {4, 3, 2, 1, 2, 8}
2 {4, 3, 2, 1} 1 insertAtBottom({4,3,2}, 2) {4, 3, 2, 2, 1, 8}
3 {4, 3, 2} 2 insertAtBottom({4,3}, 2) {4, 3, 2, 2, 1, 8}
4 {4, 3} 3 insertAtBottom({4}, 2) {4, 3, 2, 2, 1, 8}
5 {4} 4 insertAtBottom({}, 2) {4, 3, 2, 2, 1, 8}
6 (Base Case) {} Empty Stack Push 2 {2}
