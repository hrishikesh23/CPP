class Shape{
public:
	int calcDistance(Shape& otherShape);
	...
};

class ClosedShape : public Shape{ ... };

class Polygon : public ClosedShape { ... };

int main()
{
	Shape* sh1;
	ClosedShape* cs1;
	Polygon* poly1 = new Polygon;
	Polygon* poly2;
	Polygon Poly3;

	cs1 = poly1;		// Valid, upcasting Polygon to ClosedShape
	sh1 = poly1;		// Valid, upcasting Polygon to Shape	
	poly2 = cs1; 		// Invalid, downcasting ClosedShape to Polygon
				// Explicit clast is required to downcast
	poly2 = (Polygon*) cs1; // Valid downcast with explicit cast
	poly3.calcDistance(*cs1); // Valid, implicit upcasting ClosedShape to Shape

	...
	return(0);
}
