#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;


Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}
Node* head = getNode(0);
void init()
{
	head->next = nullptr;
}

void addNode2Head(int data) 
{
	Node* node = getNode(data);
	node->next = head->next;
	head->next = node;
}

void addNode2Tail(int data) 
{   
    Node* node = getNode(data);
    Node* temp = head;
    while (temp->next != nullptr) {
		temp = temp->next;
	}
    node->next = temp->next;
    temp->next = node;

}

void addNode2Num(int data, int num) 
{
    Node* node = getNode(data);
    Node* temp = head->next;

    if(num == 1) {
        node->next = head->next;
        head->next = node;
    }
    else if(num == 2) {
        node->next = temp->next;
        temp->next = node;
    }
    else {
        for(int i = 0; i < num - 2; i++) {
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
    
}

void removeNode(int data) 
{
	Node* temp = head;
	while (temp->next->data != data) {
		temp = temp->next;
        if(temp->next == nullptr) return;
	}
    temp->next = temp->next->next;
}

int getList(int output[MAX_NODE]) 
{   
    int cnt = 0;
    Node* temp = head;
    while (temp->next != nullptr) {
		temp = temp->next;
        output[cnt] = temp->data;
        cnt++;
	}
    return cnt;
}