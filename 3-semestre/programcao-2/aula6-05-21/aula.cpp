#include <iostream>
#include <memory>
int main(){
    //std::unique_ptr
    //std::shared_ptr
    //std::weak_ptr

    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << *ptr <<std::endl;

    std::shared_ptr<int> a = std::make_shared<int>(10);
    std::shared_ptr<int> b = a;
    return 0;
}