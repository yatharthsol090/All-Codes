template <typename T>
class Node {
	public :
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}
};


template <typename T>
class Queue {
	Node<T> *head;
	Node<T> *tail;
	int siz;

	public :

	Queue() {
        head = NULL;
        tail = NULL;
        siz = 0;
	}

	int getSize() {
        return siz;
	}

	bool isEmpty() {
        return siz==0;
	}

	void enqueue(T element) {
	    Node<T> *newNode = new Node<T>(element);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            siz++;
        }
        else{
        tail->next = newNode;
        tail = newNode;
        siz++;}
	}

	T Front() {
	    if(head==NULL)
        return 0;
		return head->data;
	}

	T dequeue() {
	    T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        siz--;
        return ans;
	}






};
