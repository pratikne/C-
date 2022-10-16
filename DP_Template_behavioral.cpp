/**Behavioral design pattern
 * 
 * The Abstract Class defines a template method that contains a skeleton of some
 * algorithm, composed of calls to (usually) abstract primitive operations.
 *
 * Concrete subclasses should implement these operations, but leave the template
 * method itself intact.
 * 
Standardize the skeleton of an algorithm in a base class "template method"
Steps requiring peculiar implementations are "placeholders" in base class
Derived classes implement placeholder methods
 */
// https://refactoring.guru/design-patterns/template-method/cpp/example
// https://sourcemaking.com/design_patterns/template_method/cpp/1

#include <iostream>

class AbstractClass
{
    /**
     * The template method defines the skeleton of an algorithm.
     */
public:
    void TemplateMethod()  
    {
        this->BaseOperation1();
        this->RequiredOperations1();
        this->BaseOperation2();
        this->Hook1();
        this->RequiredOperation2();
        this->BaseOperation3();
        this->Hook2();
    }
    /**
     * These operations already have implementations.
     */
protected:
    void BaseOperation1()  
    {
        std::cout << "AbstractClass says: I am doing the bulk of the work\n";
    }
    void BaseOperation2()  
    {
        std::cout << "AbstractClass says: But I let subclasses override some operations\n";
    }
    void BaseOperation3()  
    {
        std::cout << "AbstractClass says: But I am doing the bulk of the work anyway\n";
    }
    /**
     * These operations have to be implemented in subclasses.
     */
    virtual void RequiredOperations1()   = 0;
    virtual void RequiredOperation2()   = 0;
    /**
     * These are "hooks." Subclasses may override them, but it's not mandatory
     * since the hooks already have default (but empty) implementation. Hooks
     * provide additional extension points in some crucial places of the
     * algorithm.
     */
    virtual void Hook1()   {}
    virtual void Hook2()   {}
};
/**
 * Concrete classes have to implement all abstract operations of the base class.
 * They can also override some operations with a default implementation.
 */
class ConcreteClass1 : public AbstractClass
{
protected:
    void RequiredOperations1()   override
    {
        std::cout << "ConcreteClass1 says: Implemented Operation1\n";
    }
    void RequiredOperation2()   override
    {
        std::cout << "ConcreteClass1 says: Implemented Operation2\n";
    }
};
/**
 * Usually, concrete classes override only a fraction of base class' operations.
 */
class ConcreteClass2 : public AbstractClass
{
protected:
    void RequiredOperations1()   override
    {
        std::cout << "ConcreteClass2 says: Implemented Operation1\n";
    }
    void RequiredOperation2()   override
    {
        std::cout << "ConcreteClass2 says: Implemented Operation2\n";
    }
    void Hook1()   override
    {
        std::cout << "ConcreteClass2 says: Overridden Hook1\n";
    }
};
/**
 * The client code calls the template method to execute the algorithm. Client
 * code does not have to know the concrete class of an object it works with, as
 * long as it works with objects through the interface of their base class.
 */
void clientCode(AbstractClass *class_)
{
    // ...
    class_->TemplateMethod();
    // ...
}

int main()
{
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass1 *concreteClass1 = new ConcreteClass1;
    clientCode(concreteClass1);
    std::cout << "\n";
    std::cout << "Same client code can work with different subclasses:\n";
    ConcreteClass2 *concreteClass2 = new ConcreteClass2;
    clientCode(concreteClass2);
    delete concreteClass1;
    delete concreteClass2;
    return 0;
}

/**The template pattern defines the skeleton of an algorithm in an operation deferring some steps to sub-classes. The template method lets subclasses redefine certain steps of an algorithm without changing the algorithm structure. For example, in your project, you want the behavior of the module to be able to extend, such that we can make the module behave in new and different ways as the requirements of the application change, or to meet the needs of new applications. However, no one is allowed to make source code changes to it, i.e you can add but can’t modify the structure in those scenarios a developer can approach template design pattern.*/