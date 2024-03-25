#include "MyStack.h"

template <typename T>
class LargeStack {
private:
	Stack<T> smain, saux;
public:
	void push(T value) {
        smain.push(value);
	}
	T pop() {
        return smain.pop();
	}
	void swap(int i, int j){
	    if (j < i) {swap(j, i);}
	    int k = 0, valueI, valueJ;

        while(!smain.isEmpty()) {
            if(k == i) {
                valueI = smain.pop();
            } else if(k == j) {
                valueJ = smain.pop();
            } else {
                int x = smain.pop();
                saux.push(x);
            }
            k++;
        }
        k = 0;
        while(!saux.isEmpty()) {
            if(k == i) {
                smain.push(valueI);
            } else if(k == j) {
                smain.push(valueJ);
            } else {
                smain.push(saux.pop());
            }
            k++;
        }
	}
	int isEmpty() {
        return smain.isEmpty();
	}
};
