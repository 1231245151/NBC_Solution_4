#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "PotionRecipe.h"

using namespace std;

class RecipeManager
{
private:
    vector<PotionRecipe> recipes;

public:
    const vector<PotionRecipe>& GetAllRecipe() const
    {
        return recipes;
    }

public:
    // 중복된 레시피는 덮어씌움. 덮어씌움작업이 있다면 true 없다면 false
    bool AddRecipe(const string& name, const vector<string>& ingredients)
    {
        // 이름으로 레시피 검색
        PotionRecipe* Recipe = FindRecipeByName(name);

        // 존재하지않는 레시피면 등록
        if (Recipe == nullptr)
        {
            recipes.push_back(PotionRecipe(name, ingredients));
            return false;
        }
        // 존재하는 레시피라면 해당 주소로 접근하여 데이터 변경
        else
        {
            *Recipe = PotionRecipe(name, ingredients);
            return true;
        }


    }

    // 해당 이름을 가진 레시피 반환. 없다면 nullptr반환
    PotionRecipe* FindRecipeByName(const string& _name)
    {
        PotionRecipe* SearchRecipe = nullptr;

        for (vector<PotionRecipe>::iterator it = recipes.begin(); it != recipes.end(); ++it)
        {
            // 해당 레시피 발견시 즉시 종료
            if (it->GetName() == _name)
            {
                SearchRecipe = &(*it);
                break;
            }
        }

        return SearchRecipe;
    }

    // 재료를 가진 모든 레시피 반환. 없다면 빈 vector반환
    vector<PotionRecipe> FindRecipeByingredients(const string& _name)
    {
        vector<PotionRecipe> SearchRecipes;

        for (PotionRecipe it : recipes)
        {
            const vector<string>& ingredients = it.Getingredients();

            //재료검색
            for (const string& stringit : ingredients)
            {
                // 해당재료가진 레시피 발견햇으면 해당레시피로 저장후 나오기
                if (stringit == _name)
                {
                    SearchRecipes.push_back(it);
                    break;
                }
            }
        }



        return SearchRecipes;
    }

};