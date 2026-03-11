#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe
{
private:
    string potionName;
    vector<string> ingredients; // 단일 재료에서 재료 '목록'으로 변경

public:
    string GetName() const { return potionName; }
    const vector<string>& Getingredients() const { return ingredients; }

    void displayRecipe() const
    {
        cout << "- 물약 이름: " << potionName << endl;
        cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < ingredients.size(); ++j)
        {
            cout << ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < ingredients.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }


    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const string& name, const vector<string>& ingredients)
        : potionName(name), ingredients(ingredients)
    {
    }
    // 더미용을 위한 기본생성자
    PotionRecipe() :potionName("WHO") {}
};