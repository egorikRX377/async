#include <iostream>
#include <future>

int foo(int x, int y) {
    return x + y;
}

int main() {
    std::future<int> result = std::async(foo, 10, 5);
    std::cout << "Result is: " << result.get() << std::endl;
    return 0;
}