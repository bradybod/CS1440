//
// Created by Brady Bodily on 4/22/17.
//

#include "KeyValue.hpp"
#include <string>
#include <vector>
KeyValue::KeyValue(std::string key, std::vector<UserIP> value) {
    Key = key;
    Value = value; }

void KeyValue::SetValue(std::vector<UserIP> value) { Value = value; }

void KeyValue::AddValue(UserIP ValueToAdd) { Value.push_back(ValueToAdd); }

void KeyValue::AddToValue(UserIP valueToAdd) {}

void KeyValue::SetKey(std::string key) { Key = key; }

std::vector<UserIP> KeyValue::GetValue() { return Value; }

std::string KeyValue::GetKey() { return Key; }