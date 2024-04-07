#include <iostream>
using namespace std;

struct Stack {
    int top;
    int* array;
};

struct Queue {
    int front, rear, size;
    int* array;
};

struct Stack* createStack(int d) {
    struct Stack* stack = new Stack;
    stack->top = -1;
    stack->array = new int[d];
    return stack;
}

struct Queue* createQueue(int d) {
    struct Queue* queue = new Queue;
    queue->front = queue->size = 0;
    queue->rear = d - 1;
    queue->array = new int[d];
    return queue;
}

bool isStackFull(struct Stack* stack) {
    return (stack->top == sizeof(stack->array) / sizeof(stack->array[0]) - 1);
}

bool isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

bool isQueueFull(struct Queue* queue) {
    return (queue->size == sizeof(queue->array) / sizeof(queue->array[0]));
}

bool isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void push(struct Stack* stack, int item) {
    if (isStackFull(stack)) {
        cout << "Stack Overflow\n";
        return;
    }
    stack->array[++stack->top] = item;
    cout << item << " pushed into stack\n";
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return stack->array[stack->top--];
}

void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue)) {
        cout << "Queue Overflow\n";
        return;
    }
    queue->rear = (queue->rear + 1) % (sizeof(queue->array) / sizeof(queue->array[0]));
    queue->array[queue->rear] = item;
    queue->size++;
    cout << item << " enqueued to queue\n";
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        cout << "Queue Underflow\n";
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % (sizeof(queue->array) / sizeof(queue->array[0]));
    queue->size--;
    return item;
}

int main() {
    int choice;
    int item;
    struct Stack* stack = createStack(100);
    struct Queue* queue = createQueue(100);

    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Enqueue\n";
    cout << "4. Dequeue\n";
    cout << "5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> item;
                push(stack, item);
                break;
            case 2:
                item = pop(stack);
                if (item != -1)
                    cout << "Popped element: " << item << endl;
                break;
            case 3:
                cout << "Enter element to enqueue: ";
                cin >> item;
                enqueue(queue, item);
                break;
            case 4:
                item = dequeue(queue);
                if (item != -1)
                    cout << "Dequeued element: " << item << endl;
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
