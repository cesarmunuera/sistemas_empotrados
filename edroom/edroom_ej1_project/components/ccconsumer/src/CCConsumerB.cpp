#include <public/ccconsumer_iface_v1.h>

// ***********************************************************************

// class EDROOM_CTX_Top_0

// ***********************************************************************



	// CONSTRUCTORS***********************************************

CCConsumer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(CCConsumer &act ):

	EDROOMcomponent(act),
	Msg(EDROOMcomponent.Msg),
	MsgBack(EDROOMcomponent.MsgBack),
	pIn(EDROOMcomponent.pIn),
	Timer(EDROOMcomponent.Timer)
{
}

CCConsumer::EDROOM_CTX_Top_0::EDROOM_CTX_Top_0(EDROOM_CTX_Top_0 &context):

	EDROOMcomponent(context.EDROOMcomponent),
	Msg(context.Msg),
	MsgBack(context.MsgBack),
	pIn(context.pIn),
	Timer(context.Timer)
{

}

	// EDROOMSearchContextTrans********************************************

bool CCConsumer::EDROOM_CTX_Top_0::EDROOMSearchContextTrans(
			TEDROOMTransId &edroomCurrentTrans)
			{

	bool edroomValidMsg=false; 

	 switch(Msg->signal)
	{

		 case ( EDROOMSignalDestroy ): 

			 edroomValidMsg=true;
			 edroomCurrentTrans.distanceToContext = 0 ;
			 edroomCurrentTrans.localId = -1 ;
			 break;

	}

	return(edroomValidMsg);

}

	// User-defined Functions   ****************************

void	CCConsumer::EDROOM_CTX_Top_0::FConReady()

{

   //Send message 
   pIn.send(SConReady); 
}



void	CCConsumer::EDROOM_CTX_Top_0::FProgDelay()

{
   //Define interval
  Pr_Time interval;
	 
	//Timing Service useful methods
	 
	interval = Pr_Time(1, 0); // interval of X sec + Y microsec
   //Program relative timer 
   Timer.InformIn( interval ); 
}



void	CCConsumer::EDROOM_CTX_Top_0::FShowData()

{
   //Handle Msg->data
  TEDROOMByte & varSData = *(TEDROOMByte *)Msg->data;
	
		// Data access
	
	printf("Data = %c\n", varSData);

}



void	CCConsumer::EDROOM_CTX_Top_0::FShowTime()

{

Pr_Time aux;
aux.GetTime();
 
printf("Current Time %d\n", (uint32_t) aux.Secns());

}



	//********************************** Pools *************************************



// ***********************************************************************

// class EDROOM_SUB_Top_0

// ***********************************************************************



	// CONSTRUCTOR*************************************************

CCConsumer::EDROOM_SUB_Top_0::EDROOM_SUB_Top_0 (CCConsumer&act):
		EDROOM_CTX_Top_0(act)
{

}

	//***************************** EDROOMBehaviour ********************************

void CCConsumer::EDROOM_SUB_Top_0::EDROOMBehaviour()
{

	TEDROOMTransId edroomCurrentTrans;

	//Behaviour starts from Init State

	edroomCurrentTrans = EDROOMIArrival();

	do
	{

		//Take next transition

		switch(edroomCurrentTrans.localId)
		{

			//Next Transition is Init
			case (Init):
				//Next State is Ready
				edroomNextState = Ready;
				break;
			//Next Transition is ShowData
			case (ShowData):
				//Msg->Data Handling 
				FShowData();
				//Next State is HandleData
				edroomNextState = HandleData;
				break;
			//Next Transition is ShowTime
			case (ShowTime):
				//Execute Action 
				FShowTime();
				//Next State is Ready
				edroomNextState = Ready;
				break;
		}

		//Entry into the Next State 
		switch(edroomNextState)
		{

				//Go to the state I
			case (I):
				//Arrival to state I
				edroomCurrentTrans=EDROOMIArrival();
				break;

				//Go to the state Ready
			case (Ready):
				//Send Asynchronous Message at Entry
				FConReady();
				//Arrival to state Ready
				edroomCurrentTrans=EDROOMReadyArrival();
				break;

				//Go to the state HandleData
			case (HandleData):
				//Execute Entry Action 
				FProgDelay();
				//Arrival to state HandleData
				edroomCurrentTrans=EDROOMHandleDataArrival();
				break;

		}

		edroomCurrentState=edroomNextState;

	}while(Msg->signal != EDROOMSignalDestroy);

}



	// Context Init**********************************************

void CCConsumer::EDROOM_SUB_Top_0::EDROOMInit()
{

edroomCurrentState=I;

}



//	 ***********************************************************************

//	 SubState I

//	 ***********************************************************************



TEDROOMTransId CCConsumer::EDROOM_SUB_Top_0::EDROOMIArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	//Next transition is  Init
	edroomCurrentTrans.localId = Init;
	edroomCurrentTrans.distanceToContext = 0;
	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  Ready

	// ***********************************************************************



TEDROOMTransId CCConsumer::EDROOM_SUB_Top_0::EDROOMReadyArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (SData): 

				 if (*Msg->GetPInterface() == pIn)
				{

					//Next transition is  ShowData
					edroomCurrentTrans.localId= ShowData;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



	// ***********************************************************************

	// Leaf SubState  HandleData

	// ***********************************************************************



TEDROOMTransId CCConsumer::EDROOM_SUB_Top_0::EDROOMHandleDataArrival()
{

	TEDROOMTransId edroomCurrentTrans;

	bool edroomValidMsg=false;

	do
	{

		EDROOMNewMessage ();

		switch(Msg->signal)
		{

			case (EDROOMSignalTimeout): 

				 if (*Msg->GetPInterface() == Timer)
				{

					//Next transition is  ShowTime
					edroomCurrentTrans.localId= ShowTime;
					edroomCurrentTrans.distanceToContext = 0;
					edroomValidMsg=true;
				 }

				break;

		};

		if (false == edroomValidMsg)
		{
			 edroomValidMsg = EDROOMSearchContextTrans(edroomCurrentTrans);

		}

	} while (false == edroomValidMsg);

	return(edroomCurrentTrans);

}



