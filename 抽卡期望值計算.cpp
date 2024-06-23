// 抽卡期望值計算.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
int main()
{
    int rounds , sum = 0;
    srand(time(NULL));                                                  //生成亂數種子
    cout << "請輸入抽獎次數: ";
    cin >> rounds;
    int time_list[1000] = {};                                           //紀錄每一輪中獎所花的次數
    for (int i = 0; i < rounds; i++)
    {
        int times = 1;
        int rate = 2;
        cout << "第" << i << "輪" << "抽卡" << endl;
        cout << "次數 " << "該次機率" << ' ' << "抽中號碼" << endl;
        while (true)
        {
            int test;
            test = rand() % 100 + 1;                                   //生成隨機數字
            cout << setfill(' ') << setw(4) << times;
            cout << setfill(' ') << setw(8) << rate << "%";
            cout << setfill(' ') << setw(9) << test << endl;
            if (test <= rate)                                          //當test <= rate 意即 抽中目標範圍 表示中獎
            {
                cout << "第" <<  times << "次" << "抽中\n" << endl;
                break;
            }
            times += 1;
            if (times > 50)                                            //當抽數 > 50次 每多抽一次中獎機率多 2%
            {
                rate += 2;
            }
        }
        time_list[i] = times;                                          //紀錄此輪花費多少抽數
    }
    for (int o = 0; o < rounds; o++)
        sum += time_list[o];
    cout << "平均每" << (float)sum / rounds << "次中一次" << endl;     //計算中獎期望值
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
