//console tester - Compile with gcc test.c -o test

#include <stdio.h>
#include <stdint.h>
#include <math.h>

void rescaleAnalogs(uint8_t *x, uint8_t *y, int dead) {
	//radial and scaled deadzone
	//http://www.third-helix.com/2013/04/12/doing-thumbstick-dead-zones-right.html
	//input and output values go from 0...255;
	
	if (dead == 0) return;
    if (dead > 126) {
        *x = 127;
        *y = 127;
        return;
    } 

	float analogX = (float) *x - 127.0f;
    float analogY = (float) *y - 127.0f;
    float deadZone = (float) dead;
    float magnitude = sqrt(analogX * analogX + analogY * analogY);
    if (magnitude >= deadZone){
        //adjust maximum magnitude
        float absAnalogX = fabs(analogX);
        float absAnalogY = fabs(analogY);
        float maximum;
        if (absAnalogX > absAnalogY)
            maximum = sqrt(127.0f * 127.0f + ((127.0f * analogY) / absAnalogX) * ((127.0f * analogY) / absAnalogX));
        else
            maximum = sqrt(127.0f * 127.0f + ((127.0f * analogX) / absAnalogY) * ((127.0f * analogX) / absAnalogY));
 
        if (maximum > 1.25f * 127.0f) maximum = 1.25f * 127.0f;
        if (maximum < magnitude) maximum = magnitude;
       
        // find scaled axis values with magnitudes between zero and maximum
        float scalingFactor = maximum / magnitude * (magnitude - deadZone) / (maximum - deadZone);     
        analogX = (analogX * scalingFactor);
        analogY = (analogY * scalingFactor);
 
        // clamp to ensure results will always lie between 0 and 255
        float clampingFactor = 1.0f;
        absAnalogX = fabs(analogX);
        absAnalogY = fabs(analogY);
        if (absAnalogX > 127.0f || absAnalogY > 127.0f){
            if (absAnalogX > absAnalogY)
                clampingFactor = 128.0f / absAnalogX; // o/p 255 for 255 i/p (was 127.0f)
            else
                clampingFactor = 128.0f / absAnalogY; // o/p 255 for 255 i/p (was 127.0f)
        }
		*x = (uint8_t) ((clampingFactor * analogX) + 127.0f);
		*y = (uint8_t) ((clampingFactor * analogY) + 127.0f);
    }else{
        *x = 127;
        *y = 127;
    }
}

int main()
{
	uint8_t x=255;
	uint8_t y=255;
	int i=0;
	int j=0;
	printf("dz,");
	for(i=0;i<=255;i++)
	{
		printf("%d,",i);
	}
	printf("\r\n");
	for(j=0;j<64;j++)
	{
		printf("%d,",j);
		for(i=0;i<=255;i++)
		{
			x=i;
			y=i;
			rescaleAnalogs(&x,&y,j);
			//printf("%d,%d,%d\r\n",i,x,y);
			//printf("%d\r\n",y);
			printf("%d,",x);
		}
		printf("\r\n");
	}
}
