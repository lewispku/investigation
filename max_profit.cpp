/*
给你一个整数数组prices，其中prices[i]表示某支股票第i天的价格。在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。你也可以先购买，然后在同一天出售。要求输入是一串","分开的整数序列，
输出是最大利润，请用C++编写实现，要求程序包含处理输入价格序列部分和最终结果输出部分。
示例
输入：4,1,5,3,6,4
输出：7
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string token;
    vector<int> prices;
    while (getline(ss, token, ',')) {
        prices.push_back(stoi(token));
    }
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }
    cout << maxProfit << endl;
    return 0;
}
