#include <iostream>
#include <string>
#include <vector>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.inl"
#include <conio.h>

using namespace std;

// d = Ax + By + Cz
// ABC is normal
// d = shortest distance
//xyz = coords of point plane

float planeVsPoint(glm::vec3 N, glm::vec3 P, glm::vec3 C)
{
	float d = glm::dot(N, P);
	float val = glm::dot(N, C) - d;
	if (val == 0)
	{
		cout << "(" << C.x << ", " << C.y << ", " << C.z << ") is on the plane." << endl;
	}
	if (val > 0)
	{
		cout << "(" << C.x << ", " << C.y << ", " << C.z << ") is in front of the plane." << endl;
	}
	if (val < 0)
	{
		cout << "(" << C.x << ", " << C.y << ", " << C.z << ") is behind the plane." << endl;
	}
	return val;
}

int main()
{
	{
		glm::vec3 Np = glm::vec3(-1.0, 0.0, 2.0); // invented normal
		glm::vec3 Pp = glm::vec3(0.0, 1.0, 0.0); // made up point on a plane?
		glm::vec3 Ptc = glm::vec3(0.0, 1.0, 5.0); // random point probably not on the plane?


		planeVsPoint(Np, Pp, Ptc);
	}
	{
		glm::vec3 Np = glm::vec3(-1.0, 0.0, 2.0); // invented normal
		glm::vec3 Pp = glm::vec3(0.0, 1.0, 0.0); // made up point on a plane?
		glm::vec3 Ptc = glm::vec3(0.0, 1.0, 0.0); // definitly a point on the plane


		planeVsPoint(Np, Pp, Ptc);
	}
	cout << "Press any key: ";
	_getch();

	return (0);
}