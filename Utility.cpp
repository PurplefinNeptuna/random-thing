#include<cmath>
#include<cassert>
#include"Utility.hpp"

bool FEqual(float A, float B, int maxUlps) {
	assert(maxUlps > 0 && maxUlps < 4 * 1024 * 1024);
	int aInt = *(int*)&A;
	if (aInt < 0)
		aInt = 0x80000000 - aInt;
	int bInt = *(int*)&B;
	if (bInt < 0)
		bInt = 0x80000000 - bInt;
	int intDiff = std::abs(aInt - bInt);
	if (intDiff <= maxUlps)
		return true;
	return false;
}

float ToRadian(float degree) {
	return degree / 180.f * 3.141592653589793238462643383f;
}

float ToDegree(float radian) {
	return radian / 3.141592653589793238462643383f * 180.f;
}
