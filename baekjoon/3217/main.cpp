#include <bits/stdc++.h>

using namespace std;

struct heap
{
    heap *prev;
    heap *next;
    bool isAlloc;
    string name;
    int size;
};

void debug(heap *head)
{
    heap *now = head;
    while (1)
    {
        cout << now->name << ":" << now->size << " ";
        if (now->next == 0)
        {
            break;
        }
        else
        {
            now = now->next;
        }
    }
    cout << "\n";
}

int allocate(heap *head, int size, string var_name, heap **index)
{
    heap *now = head;
    int offset = 1;

    while (1)
    {
        if (!now->isAlloc)
            if (now->size >= size)
                break;

        offset += now->size;

        if (now->next != 0)
            now = now->next;
        else
            break;
    }

    if (now->size >= size && !now->isAlloc)
    {
        int remain_size = now->size - size;

        now->name = var_name;
        now->size = size;
        now->isAlloc = true;

        if (remain_size)
        {
            heap *temp_heap = new heap();
            temp_heap->name = "unallocated";
            temp_heap->size = remain_size;
            temp_heap->isAlloc = false;
            temp_heap->next = now->next;
            if (now->next != 0)
                now->next->prev = temp_heap;
            temp_heap->prev = now;
            now->next = temp_heap;
        }

        *index = now;
        return offset;
    }

    return 0;
}

void free_sim(heap *node)
{
    node->isAlloc = false;
    node->name = "unallocated";

    if (node->next != 0 && !node->next->isAlloc)
    {
        node->size += node->next->size;
        node->next = node->next->next;
        if (node->next != 0)
            node->next->prev = node;
    }

    if (node->prev != 0 && !node->prev->isAlloc)
    {
        node->prev->size += node->size;
        node->prev->next = node->next;
        if (node->next != 0)
        {
            node->next->prev = node->prev;
        }
    }
}

int main()
{
    int N;
    cin >> N;

    heap *head = new heap();
    head->size = 100000;
    head->name = "unallocated";
    head->isAlloc = false;
    head->next = 0;
    map<string, int> heap_map;
    map<string, heap *> heap_index;

    for (int i = 0; i < N; i++)
    {
        string expression;
        cin >> expression;

        string op = expression.substr(0, 4);

        if (op == "prin")
        {
            string var_name = expression.substr(6, 4);
            cout << heap_map[var_name] << "\n";
        }
        else if (op == "free")
        {
            string var_name = expression.substr(5, 4);
            if (heap_map[var_name] != 0)
            {
                free_sim(heap_index[var_name]);
                heap_index.erase(var_name);
                heap_map.erase(var_name);
            }
        }
        else
        {
            int first_bracket = expression.find("(");
            int last_bracket = expression.find(")");
            int number_range = last_bracket - first_bracket - 1;
            int size = stoi(expression.substr(first_bracket + 1, number_range));
            int result = allocate(head, size, op, &heap_index[op]);
            heap_map.insert(make_pair(op, result));
        }
    }
}