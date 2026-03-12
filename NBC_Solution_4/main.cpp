#include <iostream>
#include <vector>
#include <string>

#include "AlchemyWorkshop.h"

using namespace std;




int main()
{
    AlchemyWorkshop myWorkshop;

    while (true)
    {
        cout << "============================" << endl;
        cout << "연금술 공방 관리 시스템" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 모든 레시피 출력" << endl;
        cout << "3. 레시피 검색(이름)" << endl;
        cout << "4. 레시피 목록 검색(재료)" << endl;
        cout << "5. 포션 주기(이름)" << endl;
        cout << "6. 포션들 주기(재료)" << endl;
        cout << "7. 포션 재고 채우기" << endl;
        cout << "8. 종료" << endl;
        cout << "============================" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1)
        {
            string name;
            cout << "물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            // 여러 재료를 입력받기 위한 로직
            vector<string> ingredients_input;
            string ingredient;
            cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;

            while (true)
            {
                cout << "재료 입력: ";
                getline(cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty())
            {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else
            {
                cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
            }

        }
        else if (choice == 2)
        {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3)
        {
            string name;
            cout << "찾는 레시피의 이름을 입력하세요: ";
            cin.ignore(10000, '\n');
            getline(cin, name);
            myWorkshop.SearchCopyRecipeByName(name);

        }
        else if (choice == 4)
        {
            string name;
            cout << "찾는 레시피에 포함된 재료의 이름을 입력하세요: ";
            cin.ignore(10000, '\n');
            getline(cin, name);
            myWorkshop.SearchCopyRecipeByingred(name);

        }
        else if (choice == 5)
        {
            string name;
            cout << "모험가에게 건네줄 포션을 입력하세요: ";
            cin.ignore(10000, '\n');
            getline(cin, name);
            myWorkshop.DispensePotionByName(name);
        }
        else if (choice == 6)
        {
            string name;
            cout << "모험가에게 건네줄 포션들에 포함된 재료의 이름을 입력하세요: ";
            cin.ignore(10000, '\n');
            getline(cin, name);
            myWorkshop.DispensePotionByingred(name);

        }
        else if (choice == 7)
        {
            string name;
            cout << "돌려받을 포션의 이름을 입력하세요: ";
            cin.ignore(10000, '\n');
            getline(cin, name);
            myWorkshop.ReturnPotionByName(name);

        }
        else if (choice == 8)
        {
            cout << "공방 문을 닫습니다..." << endl;
            break;

        }
        else
        {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}