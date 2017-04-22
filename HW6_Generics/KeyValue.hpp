//
// Created by Brady Bodily on 4/5/17.
//

#ifndef HW6_GENERICS_KEYVALUE_HPP
#define HW6_GENERICS_KEYVALUE_HPP
template <typename K, typename V>
class KeyValue{
public:
    KeyValue(K key, V value):
            m_key(key),
            m_value(value)
    {}
    KeyValue (const KeyValue& object);
    K getKey() const {return m_key;}
    V getValue() const { return m_value;}

private:
    K m_key;
    V m_value;
};
template <typename K, typename V>

KeyValue<K,V>:: KeyValue(const KeyValue &object) {
    m_key = object.m_key;
    m_value = object.m_value;
};
#endif //HW6_GENERICS_KEYVALUE_HPP
