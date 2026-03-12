#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "PotionRecipe.h"
#include "RecipeManager.h"
#include "StockManager.h"

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop
{
private:
    RecipeManager recipeManager_;
    StockManager stockManager_;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const string& name, const vector<string>& ingredients);
    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 포션 이름 검색
    PotionRecipe SearchCopyRecipeByName(string _name);
    // 포션 재료 검색. 없다면 빈 벡터보냄
    vector<PotionRecipe> SearchCopyRecipeByingred(string _name);

    // 이름으로 해당 포션 재고 감소. 감소되면 true, 안되면 false 
    bool DispensePotionByName(const string& _name);
    // 재료이름으로 포션들 재고 감소. 없으면 빈 vector반환
    vector<PotionRecipe> DispensePotionByingred(const string& _name);
    // 이름으로 해당 포션 반환. 정상적으로 반환되면 true, 안되었다면 false
    bool ReturnPotionByName(const string& _name);

private:
    // 분리해봣는데 인터페이스 분리법칙에 위배인가싶어...
    void displayRecipe(PotionRecipe _recipe) const
    {

        cout << "- 물약 이름: " << _recipe.GetName() << endl;
        cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < _recipe.Getingredients().size(); ++j)
        {
            cout << _recipe.Getingredients()[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < _recipe.Getingredients().size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
};