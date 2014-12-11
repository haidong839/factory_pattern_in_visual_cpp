#include "stdafx.h"

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
	void Speak() { Console::Write( "Meow"); }
	void Free() { delete this; }
};

class Dog : public IAnimal
{
public:
	int GetNumberOfLegs() const { return 4; }
	void Speak() { Console::Write( "Woof"); }
	void Free() { delete this; }
};

class AnimalFactory
{
private:

public:
	AnimalFactory(){;};
	~AnimalFactory() {;}
	IAnimal *CreateAnimal(System::String^  animalName);
};


IAnimal* AnimalFactory::CreateAnimal(System::String^  animalName)
{
	if(!String::Compare(animalName,"Cat"))
		return new Cat();
	else 
		return new Dog();
}

int main(int argc, _TCHAR* argv[])
{
	IAnimal *pAnimal = NULL;
	System::String^ animalName;
	AnimalFactory* animalFactory = new AnimalFactory();

	while( pAnimal == NULL )
	{
		Console::WriteLine( "Type the name of an animal, Cat or Dog, or 'q' to quit: ");
		animalName = Console::ReadLine();

		if(!String::Compare(animalName,"q"))
		{
			break;
		}

		IAnimal *pAnimal = animalFactory->CreateAnimal(animalName);
		if( pAnimal )
		{			
			String^ valueString = ( pAnimal->GetNumberOfLegs()).ToString();
			Console::WriteLine(  "Your animal has " + valueString + " legs.");			
			Console::Write("Your animal says: ");
			pAnimal->Speak();
			Console::WriteLine();
		}
		else
		{
			Console::WriteLine( "That animal doesn’t exist in the farm! Choose another!");
		}
		if( pAnimal )
			pAnimal->Free();
		pAnimal = NULL;
	}

	return 0;
}

