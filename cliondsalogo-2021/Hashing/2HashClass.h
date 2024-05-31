#ifndef HASHING_2HASHCLASS_H
#define HASHING_2HASHCLASS_H
#include<iostream>
using namespace std;

template<typename V>
class Map;

template<typename V>
class MapNode{
private:
    string key;
    V value;
    MapNode<V>* next;
public:
    MapNode(string key,V value):key{key},value{value}{}
    ~MapNode(){
        delete next;
    }
    friend Map<V>;
};

template<typename V>
class Map{
private:
    MapNode<V>** buckets;
    int count;
    int numOfBuckets;

    int getBucketIndex(string key){
        int hashCode = 0;
        int p = 37;
        int base = 1;
        for(int i = key.length()-1;i>=0;i--){
            hashCode += key[i]*base;
            base = p*base;
            hashCode = hashCode%numOfBuckets;
            base = base%numOfBuckets;
        }
        return hashCode%numOfBuckets;
    }
    void rehash(){
        MapNode<V>** oldBuckets = buckets;
        buckets = new MapNode<V>*[2*numOfBuckets];
        int oldNumOfBuckets = numOfBuckets;
        numOfBuckets = 2*numOfBuckets;
        for(int i = 0;i<numOfBuckets;i++){
            buckets[i] = NULL;
        }
        count =0;
        for(int i = 0;i<oldNumOfBuckets;i++){
            MapNode<V>* curHead = oldBuckets[i];
            while(curHead!=NULL){
                insert(curHead->key,curHead->value);
                curHead=curHead->next;
            }
            delete oldBuckets[i];
        }
        delete []oldBuckets;
    }
public:
    Map(){
        count = 0;
        numOfBuckets = 5;
        buckets = new MapNode<V>*[numOfBuckets];
        for(int i = 0;i<numOfBuckets;i++){
            buckets[i] = NULL;
        }
    }
    ~Map(){
        for(int i = 0;i<numOfBuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    int size(){
        return count;
    }

    V getValue(string key){
         int bucketIndex = getBucketIndex(key);
         MapNode<V>* head = buckets[bucketIndex];
         while(head != NULL){
             if(head->key == key){
                 return head->value;
             }
             head = head->next;
         }
         return 0;
    }
    void insert(string key,V value){
         int bucketIndex = getBucketIndex(key);
         MapNode<V>* head = buckets[bucketIndex];
         while(head!=NULL){
             if(head->key == key){
                 head->value = value;
                 return;
             }
             head = head->next;
         }
         MapNode<V>* newNode = new MapNode<V>(key,value);
         newNode->next = buckets[bucketIndex];
         buckets[bucketIndex] = newNode;
         count++;
         double loadFactor = (1.0*count)/numOfBuckets;
         if(loadFactor>0.7){
             rehash();
         }
    }
    V remove(string key){
       int bucketIndex = getBucketIndex(key);
       MapNode<V>* head = buckets[bucketIndex];
       MapNode<V>* prev = NULL;
       while(head != NULL){
           if(head->key == key){
               if(prev == NULL){
                   buckets[bucketIndex] = head->next;
               }else{
                  prev->next = head->next;
               }
               V val = head->value;
               head->next = NULL;
               delete head;
               count--;
               return val;
           }
           prev = head;
           head=head->next;
       }
       return 0;
    }
    double getLoadFactor(){
        return (1.0*count)/numOfBuckets;
    }
};

#endif //HASHING_2HASHCLASS_H
