#include <wiringPi.h>
#include <stdio.h>

void	seq1(const int ledPin1, const int ledPin2, const int ledPin3, const int ledPin4, const int ledPin5)
{
	digitalWrite(ledPin1, HIGH);
	delay(100);
	digitalWrite(ledPin1, LOW);
	delay(100);
	digitalWrite(ledPin2, HIGH);
	delay(100);
	digitalWrite(ledPin2, LOW);
	delay(100);
	digitalWrite(ledPin3, HIGH);
	delay(100);
	digitalWrite(ledPin3, LOW);
	delay(100);
	digitalWrite(ledPin4, HIGH);
	delay(100);
	digitalWrite(ledPin4, LOW);
	delay(100);
	digitalWrite(ledPin5, HIGH);
	delay(100);
	digitalWrite(ledPin5, LOW);
	delay(100);
}

void	seq2(const int ledPin1, const int ledPin2, const int ledPin3, const int ledPin4)
{
	digitalWrite(ledPin1, HIGH);
	delay(100);
	digitalWrite(ledPin1, LOW);
	delay(100);
	digitalWrite(ledPin3, HIGH);
	delay(100);
	digitalWrite(ledPin3, LOW);
	delay(100);
	digitalWrite(ledPin4, HIGH);
	delay(100);
	digitalWrite(ledPin4, LOW);
	delay(100);
	digitalWrite(ledPin2, HIGH);
	delay(100);
	digitalWrite(ledPin2, LOW);
	delay(100);
}

void	seq3(const int ledPin1, const int ledPin2, const int ledPin3, const int ledPin4, const int ledPin5)
{
	digitalWrite(ledPin1, HIGH);
	digitalWrite(ledPin2, HIGH);
	digitalWrite(ledPin3, HIGH);
	digitalWrite(ledPin4, HIGH);
	digitalWrite(ledPin5, LOW);
	delay(100);
	digitalWrite(ledPin1, LOW);
	digitalWrite(ledPin2, LOW);
	digitalWrite(ledPin3, LOW);
	digitalWrite(ledPin4, LOW);
	digitalWrite(ledPin5, HIGH);
	delay(100);
}

int	main()
{
	const int	ledPin1 = 18;//pwm
	const int	ledPin2 = 22;
	const int	ledPin3 = 24;
	const int	ledPin4 = 25;
	const int	ledPin5 = 5;
	const int	butPin1 = 23;
	const int	butPin2 = 17;
	const int	butPin3 = 27;
	int		state1 = 0;
	int		state2 = 0;
	int		state3 = 0;

	wiringPiSetupGpio();
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	pinMode(ledPin3, OUTPUT);
	pinMode(ledPin4, OUTPUT);
	pinMode(ledPin5, OUTPUT);
	pinMode(butPin1, INPUT);
	pinMode(butPin2, INPUT);
	pinMode(butPin3, INPUT);
	pullUpDnControl(butPin1, PUD_UP);
	pullUpDnControl(butPin2, PUD_UP);
	pullUpDnControl(butPin3, PUD_UP);
	printf("Program is running ! Press ctrl + C to Quit \n");
	while (42)
	{
		state1 = digitalRead(butPin1);
		state2 = digitalRead(butPin2);
		state3 = digitalRead(butPin3);
		if (state1 == 0)
		{
			while (state2 != 0 && state3 != 0)
			{
				state2 = digitalRead(butPin2);
				state3 = digitalRead(butPin3);
				seq1(ledPin1, ledPin2, ledPin3, ledPin4, ledPin5);
				printf("1");
			}
		}
		if (state2 == 0)
		{
			while (state1 != 0 && state3 != 0)
			{
				state1 = digitalRead(butPin1);
				state3 = digitalRead(butPin3);
				seq2(ledPin1, ledPin2, ledPin3, ledPin4);
				printf("2");
			}
		}
		if (state3 == 0)
		{
			while (state1 != 0 && state2 != 0)
			{
				state1 = digitalRead(butPin1);
				state2 = digitalRead(butPin2);
				seq3(ledPin1, ledPin2, ledPin3, ledPin4, ledPin5);
			}
		}
		if (state1 == 0 && state2 == 0 && state3 == 0)
		{
			state1 = 1;
			state2 = 1;
			state3 = 1;
		}
	}
	return (0);
}
