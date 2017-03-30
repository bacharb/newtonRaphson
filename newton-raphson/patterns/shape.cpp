#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Point {
	float x,y;
};

struct Color {
};

class Shape {
	public:
		virtual Point center() const =0; // pure virtual
		virtual void move(Point to) =0;
		virtual void draw() const = 0; // draw on current "Canvas"
		virtual void rotate(int angle) = 0;
		virtual ~Shape() {} // destructor
};

void rotate_all(vector<Shape*>& v, int angle){ // rotate v’s elements by angle degrees
	for (auto p : v)
		p->rotate(angle);
}

class Circle : public Shape {
	public:
		Circle(Point p, float rr): x{p},r{rr}{} // constructor
		Circle() : x{0.,0.}, r{0.0}{}
		Point center() const { return x; }
		void move(Point to) { x=to; }
		void draw() const {};
		void rotate(int) {} // nice simple algorithm
	private:
		Point x; // center
		float r; // radius
};


namespace DrawingType {
	const int
		LINE = 1,
		POLYGON = 2,
		CIRCLE = 3;
};

Shape* Read(ifstream file) {return NULL;};

void Load(ifstream& inFile){
	// error handling omitted for simplicity
	while (inFile){
		// read object type
		int drawingType;
		inFile >> drawingType;
		// create a new empty object
		Shape* pCurrentObject;

		using namespace DrawingType;
		switch (drawingType){
					case CIRCLE:
				pCurrentObject = new Circle;
				break;
			default:
				cerr << "Unknown Type:\t" << drawingType << endl;
		}
		// read the object's contents by invoking a virtual fn
//		pCurrentObject->Read(inFile);
		// add the object to the container
	}
}

class ShapeFactory {
	public:
		typedef Shape* (*CreateShapeCallback)();
	private:
		typedef std::map<int, CreateShapeCallback> CallbackMap;
	public:
		// Returns 'true' if registration was successful
		bool RegisterShape(int ShapeId, CreateShapeCallback CreateFn);
		// Returns 'true' if the ShapeId was registered before
		bool UnregisterShape(int ShapeId);
		Shape* CreateShape(int ShapeId);
	private:
		CallbackMap callbacks_;
};

bool ShapeFactory::RegisterShape(int shapeId,CreateShapeCallback createFn){
	return callbacks_.insert(CallbackMap::value_type(shapeId, createFn)).second;
}

bool ShapeFactory::UnregisterShape(int shapeId){
	return callbacks_.erase(shapeId) == 1;
}

Shape* ShapeFactory::CreateShape(int shapeId){
	CallbackMap::const_iterator i = callbacks_.find(shapeId);
	if (i == callbacks_.end()){
		// not found
		throw std::runtime_error("Unknown Shape ID");
	}
	// Invoke the creation function
	return (i->second)();
}

Shape* CreateCircle(){
	return new Circle;
}
template <
	class AbstractProduct,
	typename IdentifierType,
	typename ProductCreator
>
class Factory {
	public:
		bool Register(const IdentifierType& id, ProductCreator creator){
			return associations_.insert(
					AssocMap::value_type(id, creator)).second;
		}

		bool Unregister(const IdentifierType& id){
			return associations_.erase(id) == 1;
		}

		AbstractProduct* CreateObject(const IdentifierType& id){
			typename AssocMap::const_iterator i = associations_.find(id);
			if (i != associations_.end()){
				return (i->second)();
			}
			else {
				cerr << "Object doesn't exist: \t" << id << endl;
			}
		}
	private:
		typedef map<IdentifierType, AbstractProduct> AssocMap;
		AssocMap associations_;
};

main () {
	using namespace DrawingType;
	ShapeFactory factory;

  const bool registered = factory.RegisterShape(CIRCLE, CreateCircle);
  factory.CreateShape(CIRCLE);

}
