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
    void addRecipe(const string& name, const vector<string>& ingredients)
    {
        bool overlap = recipeManager_.AddRecipe(name, ingredients);
        // 중복된 레시피등록 시 판정
        if (overlap)
        {
            cout << ">> 중복된 레시피입니다. '" << name << "'이(가) 기존 레시피에서 덮어씁니다." << endl;
        }
        else
        {
            cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl;
        }
    }

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const
    {
        const vector<PotionRecipe>& recipes = recipeManager_.GetAllRecipe();

        if (recipes.empty())
        {
            cout << "아직 등록된 레시피가 없습니다." << endl;
            return;
        }

        cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
        for (size_t i = 0; i < recipes.size(); ++i)
        {
            recipes[i].displayRecipe();
        }
        cout << "---------------------------\n";
    }

    // 포션 이름 검색
    PotionRecipe SearchCopyRecipeByName(string _name)
    {
        PotionRecipe* SearchRecipe = recipeManager_.FindRecipeByName(_name);

        if (SearchRecipe == nullptr)
        {
            cout << "해당 레시피는 존재하지 않습니다." << endl;

            // 더미 데이터 반환
            return PotionRecipe();
        }

        SearchRecipe->displayRecipe();

        //레시피가 발견되었다면 해당 레시피 반환
        return *SearchRecipe;
    }


    // 포션 재료 검색
    vector<PotionRecipe> SearchCopyRecipeByingred(string _name)
    {
        // 현재 제작중
        vector<PotionRecipe> SearchRecipes = recipeManager_.FindRecipeByingredients(_name);

        if (SearchRecipes.empty())
        {
            cout << "해당 레시피는 존재하지 않습니다." << endl;

            return SearchRecipes;
        }

        for (PotionRecipe pr : SearchRecipes)
        {
            pr.displayRecipe();
        }

        return SearchRecipes;
    }

};