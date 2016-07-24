#include <iostream>
#include <string>
#include <vector>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.inl"
#include <conio.h>

using namespace std;

//t = dot(planeNormal, pointOnPlane – p0) / dot(planeNormal, p1 – p0)
/*If: • t > 0 and t < 1: Intersection has occurred between the end points. 
• t == 0: Intersection at first end point. 
• t == 1: Intersection at second end point. 
• t > 1: Intersection beyond second end point. 
• t < 0: Intersection before first end point.
*/

bool linePlaneIntersect (glm::vec3 N, glm::vec3 P, glm::vec3 P0, glm::vec3 P1)
{
	float t = glm::dot(N, (P - P0)) / glm::dot(N, (P1 - P0));
	cout << "Value of t is " << t << endl;

	if (t > 0 && t < 1)
	{
		cout << "Intersection has occurred between the end points." << endl;
		return true;
	}

	if (t == 0)
	{
		cout << "Intersection at first end point." << endl;
		return true;
	}

	if (t == 1)
	{
		cout << "Intersection at second end point." << endl;
		return true;
	}

	if (t > 1)
	{
		cout << "Intersection beyond second end point." << endl;
	}

	if (t < 0)
	{
		cout << "Intersection before first end point" << endl;
	}
	return false;
}

int main()
{
	{
		glm::vec3 Np = glm::vec3(-1.0, 0.0, 2.0); // invented normal
		glm::vec3 Pp = glm::vec3(0.0, 1.0, 0.0); // made up point on a plane?
		glm::vec3 P0 = glm::vec3(0.0, 1.0, 5.0);
		glm::vec3 P1 = glm::vec3(0.0, 1.0, 5.0);

		bool t = linePlaneIntersect(Np, Pp, P0, P1);
		if (t == true)
		{
			cout << "Collision detected. " << endl;
		}
		else
		{
			cout << "No collision detected. " << endl;
		}
		
	}

	{
		glm::vec3 Np = glm::vec3(-1.0, 0.0, 2.0); // invented normal
		glm::vec3 Pp = glm::vec3(0.0, 1.0, 0.0); // made up point on a plane?
		glm::vec3 P0 = glm::vec3(0.0, 1.0, 0.0); // definitly on the plane P0
		glm::vec3 P1 = glm::vec3(0.0, 1.0, 5.0);

		bool t = linePlaneIntersect(Np, Pp, P0, P1);
		if (t == true)
		{
			cout << "Collision detected. " << endl;
		}
		else
		{
			cout << "No collision detected. " << endl;
		}
	}

	{
		glm::vec3 Np = glm::vec3(-1.0, 0.0, 2.0); // invented normal
		glm::vec3 Pp = glm::vec3(0.0, 1.0, 0.0); // made up point on a plane?
		glm::vec3 P0 = glm::vec3(0.0, 1.0, 5.0); // dont know where is?
		glm::vec3 P1 = glm::vec3(0.0, 1.0, 0.0); // definitly on the plane P0

		bool t = linePlaneIntersect(Np, Pp, P0, P1);
		if (t == true)
		{
			cout << "Collision detected. " << endl;
		}
		else
		{
			cout << "No collision detected. " << endl;
		}
	}
	
	cout << "Press any key: ";
	_getch();

	return (0);
}