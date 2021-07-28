int Heap_Idx = 0;
int Heap_Arr[10];

void Swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void Heap_push(int Data){
    int Idx = ++Heap_Idx;
    Heap_Arr[Idx] = Data;
    while ((Idx != 1) && (Data > Heap_Arr[Idx / 2]))
    {
        Swap(Heap_Arr[Idx], Heap_Arr[Idx / 2]);
        Idx = Idx / 2;
    }
}

int Heap_pop(){
    int Result = Heap_Arr[1];
    Heap_Arr[1] = Heap_Arr[Heap_Idx--];
    
    int Parent = 1;
    int Child;
    while (1){
        Child = Parent * 2;
        if (Child + 1 <= Heap_Idx && Heap_Arr[Child] < Heap_Arr[Child + 1]) Child++;
        if (Child > Heap_Idx || Heap_Arr[Child] < Heap_Arr[Parent]) break;
        Swap(Heap_Arr[Child], Heap_Arr[Parent]);
        Parent = Child;
    }
    return Result;
}

