#include <iostream>
#include "Dictionary.hpp"

int main()
{
    // constructors
    Dictionary<std::string,std::string> myDictionary;
    Dictionary<std::string, std::string> myDictionary2(1000);
    Dictionary<std::string, std::string> userDictionary(1000);

    // add key/value pairs to dictionaries
    myDictionary.add("hair color", "brown");
    myDictionary.add("my number", "800-800-8001");
    myDictionary2.add("eye color", "blue");



    // how many key/value pairs are there in the first and second dictionary?
    int count = myDictionary.getCount();
    if (count == 2){
        printf("Test 1: Pass\n");
    }else{printf("Test 1: Failed\n");}
    int count2 = myDictionary2.getCount();
    if(count2 == 1){
        printf("Test 2: Pass\n");
    }else{printf("Test 2: Failed\n");}


    // grabbing a key/value pair by looking up by key
    // myDictionary
    KeyValue<std::string,std::string> pair = myDictionary.searchByKey("hair color");
    if(pair.getValue() == "brown" && pair.getKey() == "hair color"){
        printf("Test 3: Pass\n");
    }else{printf("Test 3: Failed\n");}


    // myDictionary2
    KeyValue<std::string,std::string> pair2 = myDictionary2.searchByKey("eye color");
    if(pair2.getValue() == "blue" && pair2.getKey() == "eye color"){
        printf("Test 4: Pass\n");
    }else{printf("Test 4: Failed\n");}

    // grabbing a key/value pair by looking up by index
    // myDictionary
    const KeyValue<std::string, std::string>& index = myDictionary.searchByInd(1);
    if(index.getKey() == "my number" && index.getValue() == "800-800-8001"){
        printf("Test 5: Pass\n");
    }else{printf("Test 5: Failed\n");}


    // myDictionary2
    const KeyValue<std::string,std::string>& index2 = myDictionary2[0];
    if(index2.getKey() == "eye color" && index2.getValue() == "blue"){
        printf("Test 6: Pass\n");
    }else{printf("Test 6: Failed\n");}


    // remove
    myDictionary.deleteByKey("hair color");
    KeyValue<std::string,std::string> deleted = myDictionary.searchByKey("hair color");
    if(deleted.getValue() == "brown"){
        printf("Test 7: Failed\n");
    }else{printf("Test 7: Pass\n");}

    myDictionary2.deleteByInd(0);
    int count3 = myDictionary2.getCount();
    if (count3 == 0){
        printf("Test 8: Pass\n");
    }else{printf("Test 8: Failed\n");}



    //counting again
    int count4 = myDictionary.getCount();
    if (count4 == 1){
        printf("Test 9: Pass\n");
    }else{printf("Test 9: Failed\n");}
    int count5 = myDictionary2.getCount();
    if(count5 == 0){
        printf("Test 10: Pass\n");
    }else{printf("Test 10: Failed\n");}
    std::string command;
    do{
        printf("What would you like to do \n"
                       "x-exit   a-add    i-find by index    k-find by key    dk-delete by key    di-delete by index\n");
        std:: cin >> command;
        if (command ==  "x"){
            break;
        }
        else if(command == "a"){
            std::string key;
            std::string value;
            printf("Enter key: \n");
            std::cin >> key;
            printf("Enter value:\n");
            std::cin >> value;
            userDictionary.add(key, value);
        }
    }while (command != "x");
    return 0;
}