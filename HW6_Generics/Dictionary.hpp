//
// Created by Brady Bodily on 4/5/17.
//

#ifndef HW6_GENERICS_DICTIONARY_HPP
#define HW6_GENERICS_DICTIONARY_HPP

#include "KeyValue.hpp"
#include <exception>
#include <iostream>
#include <string>
template  <typename K, typename V>
class Dictionary{
    int DEFAULTSIZE = 10;
public:
    Dictionary();
    ~Dictionary();
    Dictionary(int size);
    Dictionary(const Dictionary &object);
    //add
    void add(const K& key, const V &value);
    //count
    int getCount() const {return m_count;}

   //search
    const KeyValue<K, V> & searchByKey(const K& key) const;
    const KeyValue<K, V> &searchByInd(int index) const;

    //remove
    void deleteByKey(const K& key);
    void deleteByInd(int index);

    const KeyValue<K, V> &operator [](int index) const;

private:
    KeyValue<K,V>** m_keyValuePair = nullptr;
    int m_availibleSpace = 0;
    int m_count = 0;
    bool realKey(const K& key) const;
    void increase();
};


template <typename K, typename V>
Dictionary<K, V>::Dictionary(){};


template <typename K, typename V>
Dictionary<K, V>::Dictionary(int size) {
    m_availibleSpace = size;
    m_keyValuePair = new KeyValue<K, V>*[m_availibleSpace];
}

template <typename K, typename V>
bool Dictionary<K,V>::realKey(const K& key) const {
    bool result = false;
    try {
        searchByKey(key);
        result = true;
    }
    catch (...) {}
    return result;
}


template <typename K, typename V>
Dictionary<K, V>::Dictionary(const Dictionary &object) {
    m_availibleSpace= object.m_availibleSpace;
    m_count = object.m_count;
    m_keyValuePair = new KeyValue<K, V> *[m_availibleSpace];

    for(int i = 0; i < m_count; i++){
        m_keyValuePair[i] = new KeyValue<K, V>(*object.m_keyValuePair[i]);
    }
}


template <typename K, typename V>
Dictionary<K, V>::~Dictionary(){
    if(m_availibleSpace != 0){
        for (int i = 0; i < m_count; i++){
            delete m_keyValuePair[i];
        }
        delete [] m_keyValuePair;
        m_keyValuePair = nullptr;
    }
}

template <typename K, typename V>
void Dictionary<K,V>::increase(){
    m_availibleSpace *= 2;
    KeyValue<K,V>** newElements = new KeyValue<K,V>*[m_availibleSpace];

    for (int i=0; i<m_availibleSpace; i++) {
        newElements[i] = m_keyValuePair[i];
    }
    delete [] m_keyValuePair;

    m_keyValuePair = newElements;
}


template <typename K, typename V>
void Dictionary<K, V>::add(const K& key, const V &value){

     KeyValue<std::string, std::string> test = searchByKey(key);

     if (m_availibleSpace == 0){
        m_keyValuePair = new KeyValue<K, V>*[DEFAULTSIZE];
        m_keyValuePair[m_count] = new KeyValue<K,V>(key, value);
        m_availibleSpace = DEFAULTSIZE;
        m_count +=1;
    }
    else if (m_count < m_availibleSpace){
        m_keyValuePair[m_count] = new KeyValue<K,V>(key, value);
        m_count += 1;
    }else{
        increase();
        m_keyValuePair[m_count] = new KeyValue<K,V>(key, value);
        m_count += 1;
    }
}


template <typename K, typename V>
const KeyValue<K, V>& Dictionary<K, V>::searchByKey(const K& key) const{
    for(int i=0; i < m_count; i++) {
        if(key == m_keyValuePair[i] -> getKey()){
            return *m_keyValuePair[i];
        }
    }
}


template <typename K, typename V>
const KeyValue<K,V> &Dictionary<K,V>::searchByInd(int index) const {
    if(index<m_count){
        return *m_keyValuePair[index];
    }
    throw std::out_of_range("Out of range index");
}


template <typename K, typename V>
const KeyValue<K,V>& Dictionary<K,V>::operator [](int index) const {
    return searchByInd(index);
}

template <typename K, typename V>
void Dictionary<K,V>::deleteByKey(const K& key) {

    int index = -1;
    for (int i = 0; i < m_count && index == -1; i++) {
        if (key == m_keyValuePair[i]->getKey()) {
            index = i;
        }
    }
    if (index >= 0) {
        deleteByInd(index);
    } else {
        throw std::out_of_range("Key Does Not Exist!");
    }
}

template <typename K, typename V>
void Dictionary<K,V>::deleteByInd(int index){
    if (index <= m_count) {
        delete m_keyValuePair[index];
        for (int i = index; i < m_count - 1; i++) {
            m_keyValuePair[index] = m_keyValuePair[index + 1];
        }
        m_count--;
    } else {
        throw std::out_of_range("Index Does Not Exist!");
    }
}



#endif //HW6_GENERICS_DICTIONARY_HPP