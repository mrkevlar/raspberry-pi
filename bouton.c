#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int	main()
{
	int		val = 0;
	int		state = 0;
	int		state2 = 0;
	const int	butPin1 = 17;
	const int	butPin2 = 27;
	const int	ledPin1 = 18; //pwm led

	if (wiringPiSetupGpio() == -1)
		exit(0);
	pinMode(butPin1, INPUT);
	pinMode(butPin2, INPUT);
	pullUpDnControl(butPin1, PUD_UP);
	pullUpDnControl(butPin2, PUD_UP);
	pinMode(ledPin1, PWM_OUTPUT);
	printf("%s\n", "QUIT WITH ctrl + C");
	while (42)
	{
		state2 = digitalRead(butPin2);
		state = digitalRead(butPin1);
		if (state == 0)
		{
			if (val == 1020)
				printf("MAX");
			else
			{
				pwmWrite(ledPin1, val);
				val += 10;
				printf("val+ = %d\n", val);
				delay(40);
			}
		}
		if (state2 == 0)
		{
			if (val == 0)
				printf("MIN");
			else
			{
				pwmWrite(ledPin1, val);
				val -= 10;
				printf("val- = %d\n", val);
				delay(40);
			}
		}
	}
	return (0);
}
