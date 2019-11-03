#pragma config(Sensor, S1,     Touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     ColourSensor,   sensorEV3_Color)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int getTreshold();

task main()
{
	int lineCounter = 0;
	int treshold = getTreshold();

	while(true)
	{
		displayCenteredBigTextLine(4, "Lines: %d", lineCounter);

		//Stops the robot when light reading is below treshold, increments the number of (dark) lines encountered
		if(getColorAmbient(S2) < threshold)
		{
			lineCounter++;
			wait(500);
		}
		//Continues when light reading is above treshold value
		else
		{
			setMotorSyncEncoder(leftMotor, rightMotor, 0, 500, 50);
		}
	}
}

//Function to ask user to set a high brightness level and a low brightness level, calculating the treshold by getting the average of both
int getTreshold()
{
	int lowBright = 0;
	int highBright = 0;
	int threshold = 0;

	while(!getButtonPress(buttonEnter))
	{

	displayCenteredBigTextLine(4, "Press enter - low");
	lowBright = SensorValue[S2];
	displayCenteredBigTextLine(4, "Low Reading: %d", lowBright);

	}

	while(getButtonpress(buttonEnter));

	while(!getButtonPress(buttonEnter))
	{

		displayCenteredBigTextLine(4, "Press enter - high");
		highBright = SensorValue[S2];
		displayCenteredBigTextLine(4, "High Reading: %d", highBright);
	}

	while(getButtonPress(buttonEnter));

	while(!getButtonPress(buttonEnter))
	{
		threshold = (highBright + lowBright) / 2;
		//Display both readings
		displayCenteredBigTextLine(4, "Threshold = %d",threshold);
	}
	return(treshold);
}