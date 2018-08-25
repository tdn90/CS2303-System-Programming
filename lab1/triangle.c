#include <stdio.h>
#include <math.h>

double square(double base) {
	return base * base;
}

double getLength(double Ax, double Ay, double Bx, double By) {
	return sqrt(square(Ax - Bx) + square(Ay - By));
}

double getCircum(double len1, double len2, double len3) {
	return len1 + len2 + len3;
}

double getArea(double len1, double len2, double len3) {
	double halfCircum = getCircum(len1, len2, len3) / 2.0; 
	return sqrt(halfCircum * (halfCircum - len1) * (halfCircum - len2) * (halfCircum - len3));
}

int main() {
	double Ax, Ay, Bx, By, Cx, Cy;

	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%lf %lf", &Ax, &Ay);

	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%lf %lf", &Bx, &By);

	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%lf %lf", &Cx, &Cy);

	double ab_len, bc_len, ca_len;
	ab_len = getLength(Ax, Ay, Bx, By);
	bc_len = getLength(Bx, By, Cx, Cy);
	ca_len = getLength(Cx, Cy, Ax, Ay);

	printf("Length of AB is %lf\n", ab_len);
	
	printf("Length of BC is %lf\n", bc_len);
	
	printf("Length of CA is %lf\n", ca_len);


	double circum, area; 
	circum = getCircum(ab_len, bc_len, ca_len);
	printf("Circumference is %lf\n", circum);

	area = getArea(ab_len, bc_len, ca_len);
	printf("Area is %lf\n", area);
}


