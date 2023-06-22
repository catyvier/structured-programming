

void MyList::tambahBelakang(int databaru) {
    Node *baru = new Node;
    baru->data = databaru;
    baru->next = nullptr;
    
    if (isEmpty()) {
        head = baru;
        return;
    }
    
    else {
        Node *bantu = head;
        
        while(bantu->next) {
            bantu = bantu->next;
        }
        
        bantu->next = baru;
    }
}

void MyList::hapusDepan() {
    if (isEmpty()) {
        cout << "List kosong" << endl;
        return;
    }
    
    else {
        Node *next = head->next;
        head = next;
    }
}

void MyList::hapusBelakang() {
    if (isEmpty()) {
        cout << "List kosong" << endl;
        return;
    }
    
    else {
        Node *bantu = head;
        
        if (bantu->next == nullptr) {
            head = nullptr;
            return;
        }
        
        else {
            Node *bantu2 = nullptr;
            
            while(bantu->next) {
                bantu2 = bantu;
                bantu = bantu->next;
            }
            
            bantu2->next = nullptr;
        }
    }
}

void MyList::hapus(int data){
    
    if (isEmpty()) {
        cout << "List kosong" << endl;
        return;
    }
    
 	Node *curr = head;
 	Node *prev = head;
 	
 	bool found = false;
 	
 	while(curr) {
 	    if (curr->data == data) {
 	        found = true;
 	        break;
 	    }
 	    
 	    prev = curr;
 	    curr = curr->next;
 	    
 	}
 	
 	
 	if (!found) {
 	    cout <<  "Data tidak ditemukan" << endl;
 	    return;
 	}
 	
 	else {
 	    if (curr == head) {
 	        head = head->next;
 	    }
 	    
 	    else {
 	        prev->next = curr->next;
 	    }
 	}
}




class Job {
public:
    string name;
    int id;
    
    Job() {}
    
    Job(string n, int i) : name(n), id(i) {}
    
    void cetak() {
        cout << name << " " << id << endl;
    }
};


class MyQueue {
public:
    static const int MAX_QSIZE = 10;
    Job data[MAX_QSIZE];
    int front;
    int rear;
    
    MyQueue() {
        front = rear = -1;
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return rear == (MAX_QSIZE-1);
    }
    
    void enq(string name, int id) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        
        else {
            rear++;
            rear %= MAX_QSIZE;
            
            data[rear] = Job(name, id);
        }
    }
    
    void deq() {
        if(isEmpty()) {
            cout << "Antrian Kosong" << endl;
            return;
        }
        
        else {
            front++;
            front %= MAX_QSIZE;
            
            cout << data[front].name << " keluar dari antrian" << endl;
        }
    }
    
    void depan() {
        if (isEmpty()) {
            cout << "Antrian Kosong" << endl;
            return;
        }
        
        else {
            int tmp = front;
            tmp++;
            tmp %= MAX_QSIZE;
            
            cout << data[tmp].name << " " << data[tmp].id << endl;
            
            tmp = front;
        }
    }
    
};







class Mahasiswa {
public:
    string nama;
    double ipk;
    
    Mahasiswa() {}
    Mahasiswa(string n, double val) : nama(n), ipk(val) {}
    
    
};


class MyStack {
public:
    static const int SIZE = 10;
    Mahasiswa items[SIZE];
    int top;
    
    MyStack() {
        this->top = -1;
    }
    
    bool isEmpty() {
        return this->top < 0;
    }
    
    bool isFull() {
        return this->top >= (SIZE-1);
    }
    
    void push(string nama, double ipk) {
        
        if (isFull()) {
            cout << "Stack penuh" << endl;
            return;
        }
        
        else {
            top += 1;
            items[top] = Mahasiswa(nama, ipk);
            
        }
    }
    
    Mahasiswa pop() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return Mahasiswa();
        }
        
        return items[top--];
        
    }
    
    void cetakTop() {
        if (isEmpty()) {
            cout << "Stack kosong" << endl;
            return;
        }
        
        cout << items[top].nama << endl;
    }
};






class Persegi {
public:
    double sisi;
    
    double keliling() {
        return 4*sisi;
    }
    
    double luas() {
        return sisi*sisi;
    }
};

int sum(int *p, int sz) {
    int res = 0;
    
    for (int i = 0; i < sz; ++i) {
        res += p[i];
    }
    
    return res;
} 
