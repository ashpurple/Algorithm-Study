#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;

Node* head;
Node* tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{   
    nodeCnt = 0;
	head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}


void addNode2Head(int data)
{
    Node* n = getNode(data);
    head->next->prev = n;
    n->next = head->next;
    head->next = n;
    n->prev = head;
    
    n = head;
    while(n->next != tail){
        n = n->next;
    }
    
}

void addNode2Tail(int data)
{
    Node* n = getNode(data);
    tail->prev->next = n;
    n->prev = tail->prev;
    tail->prev = n;
    n->next = tail;
}

void addNode2Num(int data, int num)
{
    Node* n = getNode(data);
    Node* ptr = head;
    for(int i = 1 ; i < num && ptr->next != tail ; i++){
        ptr = ptr->next;
    }
    n->next = ptr->next;
    ptr->next->prev = n;
    ptr->next = n;
    n->prev = ptr;
}

int findNode(int data)
{
    int i = 0;
    Node* ptr = head;
    while(ptr->next != tail && ptr->next->data != data){
        ptr = ptr->next;
        i++;
    }
    return i;
}

void removeNode(int data)
{
    Node* ptr = head;
    while(ptr->next != tail && ptr->next->data != data){
        ptr = ptr->next;
    }
    if(ptr->data == data){
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }
}

int getList(int output[MAX_NODE])
{
    Node* n = head;
    int cnt = 0;
    while(n->next != tail){
        output[cnt++] = n->next->data;
        n = n->next;
    }
    return cnt;
}

int getReversedList(int output[MAX_NODE])
{
    Node* n = tail;
    int cnt = 0;
    while(n->prev != head){
        output[cnt++] = n->prev->data;
        n = n->prev;
    }
    return cnt;
}