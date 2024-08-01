#include "../exercise.h"
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
    DynFibonacci(int capacity): cache(new size_t[capacity]{0, 1}), cached(2) {}

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci(){delete[] cache;}

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        for (;cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

