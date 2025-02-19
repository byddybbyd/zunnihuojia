// Created by DeepSeek
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

using namespace std;
using namespace std::this_thread;
using namespace chrono;

// 定义动画帧
const string frames[] = {
    // 初始状态
    R"(
      老爷爷趴在草地上...
         O 
        /|\  
        / \          
               /\_/\ 
              ( o.o ) 
               > ^ < 
    )",

    // 大象抬脚
    R"(
      老爷爷趴在草地上...
         O 
        /|\  
        / \          
               /\_/\ 
              ( o O ) 
               > ^ < 
                | 
    )",

    // 踩中背部
    R"(
      老爷爷：啊啊啊！！！
         O 
        /|\# 
        / \          
               /\_/\ 
              ( X.X ) 
               > ^ < 
    )"
};

int main() {
    try {
        for (int i = 0; i < 3; ++i) {
            system(CLEAR);
            cout << frames[i] << endl;
            sleep_for(milliseconds(1000));
        }

        // 保持踩中状态
        for (int j = 0; j < 2; ++j) {
            for (int i = 2; i > 1; --i) {
                system(CLEAR);
                cout << frames[i] << endl;
                sleep_for(milliseconds(500));
            }
        }

        // 恢复初始状态
        system(CLEAR);
        cout << frames[0] << endl;
    } catch (...) {
        cerr << "动画播放出错！" << endl;
        return 1;
    }
    return 0;
}