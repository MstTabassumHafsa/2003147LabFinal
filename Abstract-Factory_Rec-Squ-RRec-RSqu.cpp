// main.cpp
#include <iostream>
#include <string>

using namespace std;

// Step 1: Abstract Product
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// Step 2: Concrete Products
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Drawing Square" << endl;
    }
};

class RoundedRectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing RoundedRectangle" << endl;
    }
};

class RoundedSquare : public Shape {
public:
    void draw() override {
        cout << "Drawing RoundedSquare" << endl;
    }
};

// Step 3: Abstract Factory
class AbstractFactory {
public:
    virtual Shape* getShape(const string& shapeType) = 0;
    virtual ~AbstractFactory() = default;
};

// Step 4: Concrete Factories
class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const string& shapeType) override {
        if (shapeType == "RECTANGLE") return new Rectangle();
        else if (shapeType == "SQUARE") return new Square();
        else return nullptr;
    }
};

class RoundedShapeFactory : public AbstractFactory {
public:
    Shape* getShape(const string& shapeType) override {
        if (shapeType == "RECTANGLE") return new RoundedRectangle();
        else if (shapeType == "SQUARE") return new RoundedSquare();
        else return nullptr;
    }
};

// Step 5: Factory Producer
class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool rounded) {
        if (rounded) return new RoundedShapeFactory();
        else return new ShapeFactory();
    }
};

// Step 6: Client (Demo)
int main() {
    AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);
    Shape* shape1 = shapeFactory->getShape("RECTANGLE");
    shape1->draw();
    delete shape1;

    Shape* shape2 = shapeFactory->getShape("SQUARE");
    shape2->draw();
    delete shape2;
    delete shapeFactory;

    AbstractFactory* roundedFactory = FactoryProducer::getFactory(true);
    Shape* shape3 = roundedFactory->getShape("RECTANGLE");
    shape3->draw();
    delete shape3;

    Shape* shape4 = roundedFactory->getShape("SQUARE");
    shape4->draw();
    delete shape4;
    delete roundedFactory;

    return 0;
}
