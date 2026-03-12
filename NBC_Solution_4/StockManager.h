#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

class StockManager
{
private:
    map<string, int> potionStock_;
    static const int MAX_STOCK = 3;

public:
    // 레시피 등록시 호출.스택이 3개가된다.
    void InitializeStock(const string& _name) { potionStock_.insert(make_pair(_name, MAX_STOCK)); }

    // 포션 제공. 해당 포션이 없거나 건네줄게 없다면 fasle
    bool dispensePotion(const string& _name)
    {
        auto it = potionStock_.find(_name);

        // 없는 놈이거나 재고가없다면 false
        if (it == potionStock_.end() || it->second <= 0)
        {
            return false;
        }
        else
        {
            --(it->second);
            return true;
        }
    }

    // 포션을 돌려받아 재고쌓음. 리스트에 없는 포션이거나 이미꽉차있다면 false
    bool returnPotion(const string& _name)
    {
        auto it = potionStock_.find(_name);

        // 없거나 재고가 꽉차서 못넣음
        if (it == potionStock_.end() || it->second >= MAX_STOCK)
        {
            return false;
        }
        // 재고 쌓음
        else
        {
            ++(it->second);
            return true;
        }
    }

    // 현재 스톡을 알려준다.
    // 없는걸차으려하는 문제 막기용으로 없는건 -1로 반환
    int getStock(const string& _name)
    {
        map<string, int>::iterator iter = potionStock_.find(_name);

        // 실제존재
        if (iter != potionStock_.end())
        {
            return iter->second;
        }
        // 없는걸달라했음
        else
        {
            return -1;
        }
    }
};