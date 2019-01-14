#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    int val;
    struct tree* left;
    struct tree* right;
};
struct tree* newnode(int d, int hd)
{
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = d;
    nn->val = hd;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct tree* createTree(struct tree* root, int d, int hd)
{
    if(root == NULL)
    {
        return newnode(d,hd);
    }
    if(d < root->data)
    root->left = createTree(root->left, d, hd-1);
    else
    root->right = createTree(root->right, d, hd+1);
    return root;
}
// Creating queue and implementing it
struct queue
{
    struct tree* arr[50];
    int front;
    int rear;
};
void initializeQueue(struct queue *q)
{
    int i;
    for(i = 0; i < 50; i++)
    {
        q->arr[i] = NULL;
        q->front = -1;
        q->rear = -1;
    }
}
void add(struct queue* q, struct tree* root)
{
    q->rear = q->rear+1;
    q->arr[q->rear] = root;
    if(q->front == -1)
    q->front = q->rear;
}
struct tree* moll(struct queue* q)
{
    struct tree* temp = q->arr[q->front];
    if(q->front == q->rear)
    q->front = q->rear=-1;
    else
    q->front++;
    return temp;
}
int isEmpty(struct queue* q)
{
    if(q->front == -1 && q->rear == -1)
    return 1;
    return 0;
}
// top view function
void topview(struct tree* root, int* arr, int *l, int *r)
{
    struct queue q;
    initializeQueue(&q);
    add(&q,root);
    while(!isEmpty(&q))
    {
        struct tree* temp = moll(&q);
        if(temp->left)
        add(&q, temp->left);
        if(temp->right)
        add(&q, temp->right);
        // assuming this code for just 50 elements only that's why adding 50
        // updating only once for below condition
        if(arr[temp->val + 50] == -1)
        arr[temp->val + 50] = temp->data;
        // changing positions of left and right for the top view elements
        if(*l > temp->val + 50)
        *l = temp->val + 50;
        if(*r < temp->val + 50)
        *r = temp->val + 50;
    }
}
int main()
{
    struct tree *root = NULL;
    root = createTree(root,50,0);
    root = createTree(root,30,0);
    root = createTree(root,20,0);
    root = createTree(root,40,0);
    root = createTree(root,70,0);
    root = createTree(root,60,0);
    root = createTree(root,80,0);
    int l = 50, r = 50;
    int arr[100], i;
    // initialising array with -1
    for (i = 0; i < 100; i++)
    {
        arr[i] = -1;
    }
    // calling topview function
    topview(root, arr, &l, &r);
    // printing topview of tree
    for (i = l; i <= r; i++)
    printf(" %d ", arr[i]);
    return 0;
}


