#include<iostream>

class Shape{
	private:
		float m_width,m_height;
	public:
		Shape(float width, float height){
			m_width=width;
			m_height=height;
		}
		
};
class Triangle : public Shape{
	public:
		float area(){
			return (m_width*m_height)/2;
				}
}

class Rectangle: public Shape{
	public:
		float area(){
			return  m_width*m_height;
		}
}

int main(){
	Triangle t(10,5);
	Rectangle r(10,5);
	std::cout<<t.area()<<std::endl<<r.area();
	return 0;
}
