#include <iostream>
#include <string>

using namespace std;

struct Node {
    string priority;
    string operation;
    int number;
    Node *next;

    Node(string priority, const string& operation, int number) : priority(priority), operation(operation), number(number), next(nullptr) {}
};

struct Count
{
    int S = 0;
    int D = 0;
    int E = 0;
    int F = 0;
    Count() : S(0), D(0), E(0), F(0) {};
};


class PriorityQueue{
    private:
        Node* front;
        Count* P;
        Count* N;
    
    public:
        PriorityQueue(){
            front = nullptr;
            P = new Count();
            N = new Count();
        }
    
    void enqueue(string priority, const string& operation){
        int number;
        if (priority  == "P") {
            if (operation == "S") {
                P->S++;
                number = P->S;
            } else if (operation == "D") {
                P->D++;
                number = P->D;
            } else if (operation == "E") {
                P->E++;
                number = P->E;
            } else if (operation == "F") {
                P->F++;
                number = P->F;
            }
        } else {
            if (operation == "S") {
                N->S++;
                number = N->S;
            } else if (operation == "D") {
                N->D++;
                number = N->D;
            } else if (operation == "E") {
                N->E++;
                number = N->E;
            } else if (operation == "F") {
                N->F++;
                number = N->F;
            }
        }

        Node* newNode = new Node(priority, operation, number);
        if(front == nullptr){
            newNode->next = front;
            front = newNode;
        } else {
            Node* current = front;
            if(current->next == nullptr){
                while (current->next != nullptr){
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;   
            } else {
                Node* current = front;
                int i = current->priority == "P" ? 0 : 1;
                while (current->next != nullptr){
                    if (current->next->priority == "P") {
                        i = 0;    
                    } else if (i == 2) {
                        newNode->next = current->next;
                        current->next = newNode;
                        break;
                    } else {
                        i++;
                    }      
                    current = current->next;
                    if(current->next == nullptr){
                        newNode->next = current->next;
                        current->next = newNode;
                        break;
                    }
                }      
            }    
        } 
    }

    void dequeue(){
        Node* nodeToDelete = front;
        front = front->next;
        delete nodeToDelete;
    }

    void fulldequeue(){
        Node* nodeToDelete = front;
        while(front->next != nullptr)
        {
            front = front->next;
            delete nodeToDelete;
        }
        
        front = front->next;
        delete nodeToDelete;
    }

        void print(){
            Node* current = front;
            int i = 0;
            while (current != nullptr && i < 5) {
                int n = current->number;
                char buffer[256]; sprintf(buffer, "%03d", n);
                string str(buffer);
                cout << current->priority << current->operation << str << endl;
                current = current->next;
                i++;
        }
    }

};

int main(){
    PriorityQueue priorityQueue;
    while (true) {
        cout << "============================" << endl;
        cout << "1 - Retirar senha" << endl;
        cout << "2 - Chamar senha" << endl;
        cout << "3 - Mostrar painel" << endl;
        cout << "4 - Sair" << endl;
        cout << "============================" << endl;

        int option;
        cin >> option;

        if (option == 1) {
            string priority;
            string operation;
            cout << "Informe a prioridade: ";
            cin >> priority;
            cout << "Informe a operação: ";
            cin >> operation;
            priorityQueue.enqueue(priority, operation);
        } else if (option == 2) {
            priorityQueue.dequeue();
        } else if (option == 3) {
            priorityQueue.print();
        } else {
            break;
        }
    }

    // priorityQueue.enqueue("P", "D");
    // priorityQueue.enqueue("N", "S");
    // priorityQueue.enqueue("N", "E");
    // priorityQueue.enqueue("N", "D");   
    // priorityQueue.enqueue("N", "D");   
    // priorityQueue.enqueue("N", "E");   
    // priorityQueue.enqueue("P", "D");
    // priorityQueue.enqueue("P", "D");
    // priorityQueue.enqueue("P", "D");
    // priorityQueue.enqueue("P", "F");
    // priorityQueue.enqueue("P", "F");
    // priorityQueue.enqueue("N", "F");
    // priorityQueue.print();
}