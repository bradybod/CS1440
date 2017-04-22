//
// Created by Brady Bodily on 4/22/17.
//

#ifndef ITAK_KEYCOUNT_HPP
#define ITAK_KEYCOUNT_HPP


class KeyCount {
private:
    int Key;
    int Count;
public:
    KeyCount(int key){Key = key; Count = 1;}
    int GetKey(){return Key;}
    int GetCount(){return Count;}
    void SetKey(int key){Key = key;}
    void IncrementCount(){Count++;}
};


#endif //ITAK_KEYCOUNT_HPP
