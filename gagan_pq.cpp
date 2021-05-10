#include <iostream>
#include <math.h>

using namespace std;

#define NN 20

class Heap{
    int n; //number of nodes in arrayray
    int array[NN+1]; //arrayrayray is 1 based
public:
    Heap(){ n=0 ;}
    void heapify(int index);
    void insert(int k);
    int search(int k);
    void deleteKey(int k);
    int getMin();
};

void Heap::heapify(int i){
        int l = 2*i;
        int r = 2*i+1;
        int min = i;
        if(l<n && array[l]<array[min])
            min = l;
        if(r<n && array[r]<array[min])
            min = r;
        if(min != i){
            swap(array[i],array[min]);
            heapify(min);
        }
}

void Heap::insert(int k){
        if(n==NN) return;
        n++;
        array[n]= k;
        int p= n;
        while(p>1){
            int pr= p/2;
            if(array[pr]>array[p]){
                swap(array[pr],array[p]);
                p= pr;
            }
            else break;
        }
}

int Heap::getMin(){
    if(n==0) return -1;
    else return array[1];
}

int Heap::search(int ele){
    for(int i=1;i<=n;i++){
        if(array[i] == ele)
            return i;
        }
    return -1;
}

void Heap::deleteKey(int ele){
        int index = search(ele);
        array[index] = array[n];
        n--;
        heapify(index);
}

int main(){
    Heap mH; int choice; int flag = 1;   int x;
    cout << "----- Menu -----\n"
         << "1.Enter priority\n"
         << "2.Extract data\n"
         << "3.Get Top priority.\n"
         << "4.Quit\n";
    while(flag){
        cout << "Enter your choice : ";
        cin >> choice;
        
        if(choice==1)
        {
        	cout << "Enter data : ";
            cin >> x;
            mH.insert(x);
		}
		else if(choice==2)
		{
			cout << "Enter data to be extracted : ";
            cin >> x;
            mH.insert(x);
		}
		else if(choice==3)
		{
			cout << "Top priority : " <<  mH.getMin() << endl;
		}
		else
		{
			flag=0;
		}
        
    }
    return 0;
}
