#include <iostream>
#include <math.h>

using std::cout;
using std::cin;

void main()
{
	long double userQuaternion[4][1] = { 0 };
	long double userGlobal[3][3] = { 0 };

	cout << "Please enter your quaternion:";
	cout << "\nReal part:";
	cin >> userQuaternion[0][0];
	cout << "\nX:";
	cin >> userQuaternion[1][0];
	cout << "\nY:";
	cin >> userQuaternion[2][0];
	cout << "\nZ:";
	cin >> userQuaternion[3][0];
	cout << "\n\n";
	long double quaternionNormal =abs( sqrt(userQuaternion[0][0] * userQuaternion[0][0] + userQuaternion[1][0] * userQuaternion[1][0] + userQuaternion[2][0] * userQuaternion[2][0]));
	userQuaternion[0][0] = userQuaternion[0][0] / quaternionNormal;
	userQuaternion[1][0] = userQuaternion[1][0] / quaternionNormal;
	userQuaternion[2][0] = userQuaternion[2][0] / quaternionNormal;

	userGlobal[0][0] =2 * (userQuaternion[0][0] * userQuaternion[0][0] + userQuaternion[1][0] * userQuaternion[1][0])-1;
	userGlobal[0][1] = 2 * (userQuaternion[1][0] * userQuaternion[2][0] - userQuaternion[0][0] * userQuaternion[3][0]);
	userGlobal[0][2] = 2 * (userQuaternion[1][0] * userQuaternion[3][0] + userQuaternion[0][0] * userQuaternion[2][0]);

	userGlobal[1][0] = 2 * (userQuaternion[1][0] * userQuaternion[2][0] + userQuaternion[0][0] * userQuaternion[3][0]);
	userGlobal[1][1] =2 * (userQuaternion[0][0] * userQuaternion[0][0] + userQuaternion[2][0] * userQuaternion[2][0])-1;
	userGlobal[1][2] = 2 * (userQuaternion[2][0] * userQuaternion[3][0]- userQuaternion[0][0] * userQuaternion[1][0]);

	userGlobal[2][0] = 2 * (userQuaternion[1][0] * userQuaternion[3][0]- userQuaternion[0][0] * userQuaternion[2][0]);
	userGlobal[2][1] = 2 * (userQuaternion[2][0] * userQuaternion[3][0] + userQuaternion[0][0] * userQuaternion[1][0]);
	userGlobal[2][2] =2 * (userQuaternion[0][0] * userQuaternion[0][0] + userQuaternion[3][0] * userQuaternion[3][0])-1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << userGlobal[i][j] << "\t";
		}
		cout << "\n";
	}
	system("pause");
}