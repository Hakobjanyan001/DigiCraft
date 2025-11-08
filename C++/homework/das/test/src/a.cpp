#include <../include/a.h>

float add(std::vector<float>& numbers) {
	float sum = 0.0;
	for( float num: numbers ) {
		sum += num;
	}
return sum;
}
