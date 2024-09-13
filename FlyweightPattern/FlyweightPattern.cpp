#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class Flyweight
{
public:
    virtual void Operation(const string& extrinsicState) = 0;
    
    Flyweight() = default;
    virtual ~Flyweight() = default;
};

class ConcreteFlyweight final : public Flyweight
{
private:
    string intrinsicState;

public:
    explicit ConcreteFlyweight(string state) : intrinsicState(std::move(state)) { }

    void Operation(const string& extrinsicState) override
    {
        cout << "Intrinsic State: " << intrinsicState << ", Extrinsic State: " << extrinsicState << '\n';
    }
};

class FlyweightFactory
{
private:
    // 동일한 객체에 대한 요청이 있으면 포인터 공유
    unordered_map<string, shared_ptr<Flyweight>> flyweights;

public:
    shared_ptr<Flyweight> getFlyweight(const string& key)
    {
        if(flyweights.find(key) == flyweights.end())
        {
            flyweights[key] = make_shared<ConcreteFlyweight>(key);
        }

        return flyweights[key];
    }
};

int main()
{
    FlyweightFactory factory;

    const auto flyweight1 = factory.getFlyweight("A");
    const auto flyweight2 = factory.getFlyweight("B");
    const auto flyweight3 = factory.getFlyweight("A"); // 1과 같은 객체 공유

    flyweight1->Operation("First Call");
    flyweight2->Operation("Second Call");
    flyweight3->Operation("Third Call");
    
    return 0;
}
