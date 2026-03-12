#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "AlchemyWorkshop.h"



void AlchemyWorkshop::addRecipe(const string& name, const vector<string>& ingredients)
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

    // 스택 3개 고정 추가
    stockManager_.InitializeStock(name);
    cout << ">> 기본지급으로 " << name << "'의 재고가 3병 추가되었습니다." << endl;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    const vector<PotionRecipe> recipes = recipeManager_.GetAllRecipe();

    if (recipes.empty()) 
    {
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) 
    {
        displayRecipe(recipes[i]);
    }
    std::cout << "---------------------------\n";
}

PotionRecipe AlchemyWorkshop::SearchCopyRecipeByName(string _name)
{
    PotionRecipe* SearchRecipe = recipeManager_.FindRecipeByName(_name);

    if (SearchRecipe == nullptr)
    {
        cout << "해당 레시피는 존재하지 않습니다." << endl;

        // 더미 데이터 반환
        return PotionRecipe();
    }

    displayRecipe(*SearchRecipe);

    //레시피가 발견되었다면 해당 레시피 반환
    return *SearchRecipe;
}

vector<PotionRecipe> AlchemyWorkshop::SearchCopyRecipeByingred(string _name)
{
    vector<PotionRecipe> SearchRecipes = recipeManager_.FindRecipeByingredients(_name);

    if (SearchRecipes.empty())
    {
        cout << "해당 레시피는 존재하지 않습니다." << endl;

        // 빈 벡터 건네줌
        return SearchRecipes;
    }

    for (PotionRecipe pr : SearchRecipes)
    {
        displayRecipe(pr);
    }

    // 비어있다면 알아서 빈벡터 보냄
    return SearchRecipes;
}

bool AlchemyWorkshop::DispensePotionByName(const string& _name)
{
    // 이름으로 재고 검색
    PotionRecipe* SearchRecipe = recipeManager_.FindRecipeByName(_name);

    // 없는포션은 재고감소못함
    if (SearchRecipe == nullptr)
    {
        cout << "해당 포션은 존재하지 않습니다." << endl;

        return false;
    }

    // 재고감소진행
    if (stockManager_.dispensePotion(_name))
    {
        // 정상적으로 감소
        cout << "해당 포션을 넘겨줍니다. 현재 해당 포션의 재고는 [" << stockManager_.getStock(_name) << "] 입니다." << endl;
    }
    else
    {
        // 이미 재고가 없다면 실패로 false
        cout << "해당 포션의 재고가 없습니다." << endl;

        return false;
    }


    return true;

}

vector<PotionRecipe> AlchemyWorkshop::DispensePotionByingred(const string& _name)
{
    string findname;

    vector<PotionRecipe> finalSearch; // 찐 넘겨준 목록

    // 레시피에 해당 재료로 쓴 포션 검색
    vector<PotionRecipe> SearchRecipes = recipeManager_.FindRecipeByingredients(_name);

    // 그런 포션이 없다면 종료
    if (SearchRecipes.empty())
    {
        cout << "해당 재료를 사용한 포션들은 존재하지 않습니다." << endl;

        return SearchRecipes;
    }

    // 포션들을 검사해서 줄수잇는건주고 못주는건 못주게한다.
    cout << "해당 재료를 사용한 포션들을 넘겨줍니다." << endl;
    for (PotionRecipe pr : SearchRecipes)
    {
        // 해당 포션재고감소
        findname = pr.GetName();
        if (stockManager_.dispensePotion(findname))
        {
            // 성공적으로 재고 처리된 놈만 보냄
            finalSearch.push_back(pr);

            cout << findname <<"을(를) 넘겨줍니다. 남은 재고는 " << stockManager_.getStock(findname) << " 입니다." << endl;
        }
        else
        {
            cout << findname <<"은(는) 재고가 없습니다." << endl;
        }

    }

    return finalSearch;
}

bool AlchemyWorkshop::ReturnPotionByName(const string& _name)
{
    // 이름으로 재고 검색
    PotionRecipe* SearchRecipe = recipeManager_.FindRecipeByName(_name);

    // 없는포션은 재고감소못함
    if (SearchRecipe == nullptr)
    {
        cout << "해당 포션은 존재하지 않습니다." << endl;

        return false;
    }

    if (stockManager_.returnPotion(_name))
    {
        // 스택오름
        cout << _name << "을(를) 창고에 넣어 재고가 " << stockManager_.getStock(_name) << "개 되었습니다." << endl;
        return true;
    }
    else
    {
        // 꽉차서 못넣음
        cout << _name << "은(는) 이미 창고에 가득차 넣을 수 없습니다." << endl;

        return false;
    }

}

