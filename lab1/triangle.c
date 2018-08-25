/* triangle.c -- Written by Kevin Nguyen */

#include <stdio.h>
#include <math.h>

int main() {
	double Ax, Ay, Bx, By, Cx, Cy;

	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%lf %lf", &Ax, &Ay);

	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%lf %lf", &Bx, &By);

	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%lf %lf", &Cx, &Cy);

	double ab_len, bc_len, ca_len;
	ab_len = sqrt((Ax - Bx)*(Ax - Bx) + (Ay - By)*(Ay - By));
	bc_len = sqrt((Bx - Cx)*(Bx - Cx) + (By - Cy)*(By - Cy));
	ca_len = sqrt((Cx - Ax)*(Cx - Ax) + (Cy - Ay)*(Cy - Ay));

	printf("Length of AB is %0.3lf\n", ab_len);
	
	printf("Length of BC is %0.3lf\n", bc_len);
	
	printf("Length of CA is %0.3lf\n", ca_len);


	double circum, area; 
	circum = ab_len + bc_len + ca_len;

	printf("Circumference is %0.3lf\n", circum);
	double halfCircum = circum / 2.0;

	area = sqrt(halfCircum * (halfCircum - ab_len) * (halfCircum - bc_len) * (halfCircum - ca_len));
	printf("Area is %0.3lf\n", area);
}

