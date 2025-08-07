#include<iostream>
#include<string>
using namespace std;

template<typename V>
class MapNode{ // for linked list- separate chaining
    string key;
    V value;
    MapNode* next;

    public:
    MapNode(string key, V val) : key(key), value(val), next(nullptr) {}
    ~MapNode(){
        delete next;
    }
    template<typename T>
    friend class ourmap;
};

template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets; // size of array which we take
    
    int getBucketIndex(string k){ // hash function
        int hashCode = 0;
        const int p = 37;
        int currCoeff = 1;
        // consider key = base p logic 
        for(int i = k.length()-1; i >= 0; --i){
            hashCode += (k[i] * currCoeff)%numBuckets;
            currCoeff = (currCoeff*p)%numBuckets;
        }
        return hashCode% numBuckets; // compression function
    }

    void reHash(){
        MapNode<V>** temp = buckets;
        int oldNum = numBuckets;
        numBuckets *= 2;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; ++i){
            buckets[i] = nullptr;
        }
        count = 0;
        for(int i =0; i<oldNum;++i){
            MapNode<V>* head = temp[i];
            while(head != nullptr){
                insert(head->key,head->value);
                head = head->next;
            }
        }
        for(int i = 0; i<oldNum; ++i){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
        cout << "rehashing done" << endl;
    }

    public:
    ourmap() : count(0), numBuckets(5){
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i<numBuckets; ++i ){
            buckets[i] = nullptr;
        }
    }

    ~ourmap(){
        for(int i = 0; i<numBuckets;++i){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }
    double loadFactor(){
        return 1.0*count/numBuckets;
    }

    void insert(string k, V val){
        int index = getBucketIndex(k);
        MapNode<V>* head = buckets[index];

        while(head != nullptr){ // update val if key exists already
            if(head->key == k){
                head->value = val;
                return;
            }
            head = head->next;
        }

        head = buckets[index];
        MapNode<V>* node = new MapNode<V>(k,val);
        node->next = head;
        buckets[index] = node;
        ++count;

        double loadF = 1.0*count/numBuckets;
        if(loadF>0.7)
            reHash();
    }
    V getValue(string k){
        int index = getBucketIndex(k);
        MapNode<V>* head = buckets[index];
        while(head != nullptr){
            if(head->key == k){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string k){
        int index = getBucketIndex(k);
        MapNode<V>* curr = buckets[index];

        if(curr->key == k){
            buckets[index] = curr->next;
            V val = curr->value;
            curr->next = nullptr;
            delete curr;
            --count;
            return val;
        }

        MapNode<V>* prev = curr;
        while(curr != nullptr){
            if(curr->key == k){
                prev->next = curr->next;
                V val = curr->value;
                curr->next = nullptr;
                delete curr;
                --count;
                return val;
            }
            prev = curr;
            curr = curr->next;
        }
        return 0;
    }
    bool isPresent(string k){
        int index = getBucketIndex(k);
        MapNode<V>* head = buckets[index];
        while(head != nullptr){
            if(head->key == k)
                return true;
            head = head->next;
        }
        return false;
    }
};
