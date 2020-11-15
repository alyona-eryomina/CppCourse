const float pi = 3.1416f;

class Visitor;

class Curve {
protected:
	float area = 0;
public:
	virtual ~Curve() {};
	virtual float get_area() = 0;
	virtual void accept(Visitor &visitor) = 0;
};

class Circle : public Curve {
private:
	float r;
public:
	Circle();
	Circle(const float _r);
	float get_radius();
	float get_area();
	void accept(Visitor &visitor);
};

class Ellipse : public Curve {
private:
	float a, b;
public:
	Ellipse();
	Ellipse(const float _a, const float _b);
	float get_major_axis();
	float get_minor_axis();
	float get_area();
	void accept(Visitor &visitor);
};

class Visitor {
public:
	virtual ~Visitor() {};
	virtual void visit(Circle* circle) = 0;
	virtual void visit(Ellipse* ellipse) = 0;
};

class RadiusVisitor : public Visitor {
public:
	RadiusVisitor() {};
	void visit(Circle* circle);
	void visit(Ellipse* ellipse);
};
