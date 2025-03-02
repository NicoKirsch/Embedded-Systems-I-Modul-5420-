////
//wird gebraucht um den serialMonitor zu nutzen

#include <wiring.h>
#include<HardwareSerial.h>


#include <Arduino_FreeRTOS.h>
#include <timers.h>
#define mainAUTO_RELOAD_TIMER_PERIOD 	31
#define mainAUTO_RELOAD_TIMER_PERIOD2 	62
TimerHandle_t xAutoReloadTimer;
BaseType_t xTimer2Started;
int myTimerPeriod = 31;
bool prevT2state = 0;
bool prevT1state = 0;
bool prevT4state = 0;


//initialisieren von
static void prvTimerCallback( TimerHandle_t xTimer );


void setup()
{
	Serial.begin(9600); // Enable serial communication library.

	pinMode(11,OUTPUT);//blue LED
	pinMode(10,OUTPUT);//green LED
	pinMode(9,OUTPUT); //yellow LED
	pinMode(8,OUTPUT); //red LED
	pinMode(5,INPUT);//Taster2
	pinMode(4,INPUT);//Taster1
	pinMode(7,INPUT);//Taster4

	xAutoReloadTimer = xTimerCreate(
			/* Text name for the software timer - not used by FreeRTOS. */
			"AutoReload",
			/* The software timer's period in ticks. */
			mainAUTO_RELOAD_TIMER_PERIOD,
			/* Setting uxAutoRealod to pdTRUE creates an auto-reload timer. */
			pdTRUE,
			/* This example does not use the timer id. */
			0,
			/* The callback function to be used by the software timer being created. */
			prvTimerCallback);
	/* Check the software timers were created. */
	if(( xAutoReloadTimer != NULL ) )
	{
		/* Start the software timers, using a block time of 0 (no block time). The scheduler has
not been started yet so any block time specified here would be ignored anyway. */
		xTimer2Started = xTimerStart( xAutoReloadTimer, 0 );
		/* The implementation of xTimerStart() uses the timer command queue, and xTimerStart()
will fail if the timer command queue gets full. The timer service task does not get
created until the scheduler is started, so all commands sent to the command queue will
stay in the queue until after the scheduler has been started. Check both calls to
xTimerStart() passed. */
		if( ( xTimer2Started == pdPASS ) )
		{
			/* Start the scheduler. */
			vTaskStartScheduler();
		}
	}
}

void loop()
{
	// put your main code here, to run repeatedly:

	//increase Timer Period
	if(digitalRead(5)){

		if(prevT2state == 0)
		{
			digitalWrite(9,HIGH);
			myTimerPeriod = myTimerPeriod + 31;
			Serial.print("TimerPeriod set to :");
			Serial.print(myTimerPeriod/62);
			Serial.print("s \n");
			prevT2state = 1;
		}
	}
	else
	{
		prevT2state = 0;
		digitalWrite(9,LOW);
	}

	//decrease Timer Period
	if(digitalRead(4)){

		if(prevT1state == 0 && myTimerPeriod > 31)
		{
			digitalWrite(8,HIGH);
			myTimerPeriod = myTimerPeriod - 31;
			Serial.print("TimerPeriod set to :");
			Serial.print(myTimerPeriod/62);
			Serial.print("s \n");
			prevT1state = 1;
		}
	}
	else
	{
		prevT1state = 0;
		digitalWrite(8,LOW);
	}

	//Reset Timer
	if(digitalRead(7)){

		if(prevT4state == 0)
		{
			xTimerReset( xAutoReloadTimer, 0 );
			digitalWrite(11,HIGH);
			Serial.println("Timer Reset");
			prevT4state = 1;
		}
	}
	else
	{
		prevT4state = 0;
		digitalWrite(11,LOW);

	}
}

static void prvTimerCallback( TimerHandle_t xTimer )
{
	TickType_t xTimeNow;
	uint32_t ulExecutionCount;
	/* A count of the number of times this software timer has expired is stored in the timer's
ID. Obtain the ID, increment it, then save it as the new ID value. The ID is a void
pointer, so is cast to a uint32_t. */
	ulExecutionCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
	ulExecutionCount++;
	vTimerSetTimerID( xTimer, ( void * ) ulExecutionCount );
	/* Obtain the current tick count. */
	xTimeNow = xTaskGetTickCount();
	/* The handle of the one-shot timer was stored in xOneShotTimer when the timer was created.
Compare the handle passed into this function with xOneShotTimer to determine if it was the
one-shot or auto-reload timer that expired, then output a string to show the time at which
the callback was executed. */

	Serial.print("Auto-reload timer callback executing ");
	Serial.println( xTimeNow/31 );
	//Toggle TimerLEDstate
	digitalWrite(10,!digitalRead(10));
	if( ulExecutionCount >= 5 )
	{
		xTimerChangePeriod( xAutoReloadTimer, /* The timer being updated. */
				myTimerPeriod, /* The new period for the timer. */
				0 ); /* Do not block when sending this command. */
	}
}



int main(void){

	setup();
	for(;;){
		loop();

	}
	return(0);
}
