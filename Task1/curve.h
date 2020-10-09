const float pi = 3.1416f;

class Curve {
protected:
	float area = 0;
public:
	virtual ~Curve() {};
	virtual float get_area() { area = 1.0f; return area; };
};

class Circle : public Curve {
private:
	float r;
public:
	Circle() { r = 0.1f; }
	Circle(const float _r) {
		if (_r <= 0) throw - 1;
		r = _r;
	};
	float get_area() override {
		area = pi * r * r;
		return area;
	}
};

class Ellipse : public Curve {
private:
	float a, b;
public:
	Ellipse() { a = b = 0.1f; }
	Ellipse(const float _a, const float _b) {
		if (_a <= 0 || _b <= 0)
			throw - 1;
		a = _a; b = _b;
	}
	float get_area() override {
		if (area == 0) area = pi * a * b;
		return area;
	}
};