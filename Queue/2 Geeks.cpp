void MyQueue ::push(int x) {
    arr[rear++] = x;  // Insert at the rear and move rear forward
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    if (front == rear) return -1; // Queue is empty
    return arr[front++]; // Pop from the front and move front forward
}