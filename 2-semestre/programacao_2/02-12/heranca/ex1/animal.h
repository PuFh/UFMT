#ifndef ANIMAL__INCLUDED
#define ANIMAL__INCLUDED

#include <string>
#include <iostream>

//classe PAI
class Animal{
protected:
    std::string som;
public:

    virtual void emitirSom(){
        std::cout << " SOM "<<std::endl;
    }
    
};


#endif