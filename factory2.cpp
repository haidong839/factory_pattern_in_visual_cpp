// factory2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
using namespace System;

class IAnimal
{
public:
    virtual int GetNumberOfLegs() const = 0;
    virtual void Speak() = 0;
    virtual void Free() = 0;
};

// IAnimal implementations
class Cat : public IAnimal
{
public:
    int GetNumberOfLegs() const { return 4; }
    void Speak() { cout << "Meow" << endl; }
    void Free() { delete this; }
};

class Dog : public IAnimal
{
public:
    int GetNumberOfLegs() const { return 4; }
    void Speak() { cout << "Woof" << endl; }
    void Free() { delete this; }
};

class AnimalFactory
{
private:
   
public:
	AnimalFactory(){;};
    ~AnimalFactory() { ; }
    IAnimal *CreateAnimal(System::String^  animalName);
};


IAnimal* AnimalFactory::CreateAnimal(System::String^  animalName)
{
    if(!String::Compare((System::String ^)animalName,(System::String ^)"Cat"))
		return new Cat();
	else 
		return new Dog();
}

int main(int argc, _TCHAR* argv[])
{
	IAnimal *pAnimal = NULL;
	AnimalFactory* animalFactory = NULL;
    System::String^ animalName;
	animalFactory = new AnimalFactory();
    while( pAnimal == NULL )
    {
        cout << "Type the name of an animal or 'q' to quit: ";
        animalName = Console::ReadLine();

       if(!String::Compare((System::String ^)animalName,(System::String ^)"q"))
        break;
		
        IAnimal *pAnimal = animalFactory->CreateAnimal(animalName);
        if( pAnimal )
        {
            cout << "Your animal has "<< pAnimal->GetNumberOfLegs() << "legs."<< endl;
            cout << "Your animal says: ";
            pAnimal->Speak();
        }
        else
        {
            cout << "That animal doesn’t exist in the farm! Choose another!"<< endl;
        }
        if( pAnimal )
            pAnimal->Free();
        pAnimal = NULL;
    }
    return 0;
}

