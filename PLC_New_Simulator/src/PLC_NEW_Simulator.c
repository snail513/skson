/*
, ============================================================================
, Name, , , , , , , , :, PLC_NEW_Simulator.c
, Author, , , , , , :, skson
, Version, , , , , :
, Copyright, , , :, NaraControls
, Description, :, Hello, World, in, C,, Ansi-style
, ============================================================================
, */



#ifndef PLC_NEW_SIMULATOR_H_
#include "PLC_NEW_SImulator.h"
#endif


//static int PLC_DEFINATION_SCANTIME_INTERVAL;


#ifdef USE_CUNIT_TEST_DEF
#include "PLC_ListOfTestSuite.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#endif

char* PLC_SIMULATOR_VERSION =
		"**************************\n"
		"PLCSim\n"
		"(c)Nara Controls\n"
		"Modefied by : SKSon\n"
		"Last Modefied date :2015.2.5\n"
		"Version : v0.1.1\n"
		"**************************\n";

char* PLC_SIMULATOR_HISTORY =


		"**************************\n"
		"HISTORY\n"
		"created : 2014.9.18\n"
		"[9.18]\n"
		"	구현 : LD, OUT, END\n"
		"[9.22] \n"
		"	if case 문으로 동작하던 각 PLC명령을 함수로 빼고 함수참조형 동작으로 변경.\n"
		"	R10 Register를 Temp로 사용하도록 동작 변경\n"
		"	구현 : LDI\n"
		"[9.25] \n"
		"	1. 연산 동작 방식 변경. 각 경우마다 구현하는 형태가 지나치게 많은 코드를 양산한다고 판단.\n"
		"		operator set, operand set을 등록하고 CMD SET에 등록한 유효한 operand type인지 확인하는 형태로.\n"
		"	2. New Structure : PLC_Executor 로 동작함수를 분리하고 PLC_Device에는 레지스터 입출력함수만 남김.\n"
		"		더불어 Executor에서 static으로 device를 선언하고 단 하나의 device로만 동작하게 변경.\n"
		"	3. 테스트 방식이 지나치게 복잡했던 부분 수정.\n"
		"		외부 사용자에게 지나치게 복잡해 보이던 동작과 무관해보이는 함수를 모두 Hide\n"
		"		Device 초기 상태 설정 함수와 PLC 동작함수만 노출되도록 변경.\n"
		"[9.26] \n"
		"	1. CUnit을 이용한 테스트 코드 첨부\n"
		"	2. Executor 코드 중 일부 device io 관련 함수를 Device 파일로 롤백하고, Device에 새 함수인 setValue 추가.\n"
		"	Type을 인식하고 알아서 해당 register에 set, get을 실시.\n\n"
		"[10.31] \n"
		"	1. Device 모듈에 Current Time의 속성과 Time시점에서의 Direct Device Control 인풋을 구현 내용에 포함\n"
		"	2. Excel 리스트를 기준으로 PLC를 계속 유지/관리하기 위해서, 달라진 부분을 모두 재구현\n"
		"	3. IL 중심으로 동작하던 Sim을 향후 실제 PLC에서 동작할 수 있는 ML 코드 중심으로 변경\n"
		"	4. Ladder instruction + Control => 실시간 시뮬레이션\n"
		"[12.09]\n"
		"	1. 메인함수의 실행방식 변경 : 기본 설정은 무한실행\n"
		"	2. 실행옵션 추가 : PLC_NEW_Simulator [absolute file path name] [-option]\n"
		"		-options : \n"
		"			-us (u-second scantime interval)\n"
		"			-ms (m-second scantime interval)\n"
		"			-ds (0.1 second scantime interval)\n"
		"			-s (1 second scantime interval)\n"
		"			-zdly (zero delay scantime interval)\n"
		"			-test (test mode)\n"
		"	3. test suite removal : kill USE_CUNIT_DEF flag.\n"
		"[12.22]\n"
		"	1. Debug 용 기능인 사용자 컨트롤 파일 추가\n"
		"		- Debug/control.txt 파일\n"
		"		- 형식[예시] : \n"
		"			100 		:: 첫 줄  - 최대로 수행할 스캔타임 횟수. 현재는 100회 수행.\n"
		"			T1 X0 1 	:: 두번째 줄 이후 - arg[0] = 수행할 scantime. arg[1] = 수행할 register. arg[2] = register에 들어갈 값 \n"
		"					::1회차에 X0 = 1을 입력\n"
		"			T2 X1 1	::2회차에 X1 = 1을 입력\n"
		"			T3 WX0 4	::3회차에 WX0 = 4을 입력\n"
		"			T10 WY10 200 :: 10회차에 WY10 = 200을 입력\n"
		"			...\n"
		"[12.24]\n"
		"	1. MultiTasking 추가\n"
		"		2개 이상의 END를 가진 MultiTasking ML파일을 인식하고 분리하여 각 스캔타임마다 수행가능\n"
		"[2015.02.05]\n"
		"	1. Fixed Errors\n"
		"		Float / Double 변수의 디버깅과 연산이 가능하도록 추가.\n"
		"	2. Fixed Code Reproduction rate.\n"
		"		일부 함수의 비슷한 구조를 리펙토링하여 통합하고 축약\n"
		"**************************\n";


static char* filePathName ;
static uint8 inputInstructions[INSTRUCTION_MEMORY_SIZE];


#define address_test 105
#define address_test2 101
#define address_test3 100

static int timeCount = -1;
static int controlCount = 0;
static int instPoint = 0;
int init_suite_exec_duration()
{
	PLC_TaskExecutor_readFromFileToBuffer(filePathName, (char*)inputInstructions);
	init_suite_EXEC_SUITE();
	return 0;
}
int clean_suite_exec_duration()
{
	PLC_DEVICE_Init();
	return 0;
}
void test_suite_exec_duration()
{
	//device action : manual control, Not coursed by ml code,

	PLC_DEVICE_Controller* controller = (PLC_DEVICE_Controller*)PLC_TaskExecutor_readFromFileToControl();
	if(controller==NULL)
	{
		DBG_LOG("[CONTROL] control file is not found! Doing not load from file!\n");
	}
	//memset(dev.internalInstructions, 0, INSTRUCTION_MEMORY_SIZE);
	//memcpy(dev.internalInstructions, inputInstructions, getMemSize());

	if(!Task_loadTasksFromBuffers(inputInstructions, INSTRUCTION_MEMORY_TASK_SIZE, 1, CONDITION_ALWAYS_EXEC))
	{
		DBG_LOGPRINT("[TASK ERROR]!\n");
		return ;
	}
	int taskIdx;
	for(taskIdx=0; taskIdx<MAX_TASK_COUNT; taskIdx++)
	{
		//DBG_LOGPRINT("curr %d task!\n", taskIdx);
		if(TaskList_getInstance()->list[taskIdx].nLaunchingCondition!=CONDITION_ALWAYS_EXEC)
		{
			//DBG_LOGPRINT("Skip %d task!\n", taskIdx);
			continue;
		}
		uint16 rst = PLC_TaskExecutor_execOneScanTime(taskIdx, 0, EVENT_NONE);
		if(rst!=ML_CODE_END && rst!=ML_CODE_FEND)
		{
			//PLC_LOG_addLog("\n[ERROR] PLC_TaskExecutor_execOneScanTime  : execution error.\n");
			DBG_LOGPRINT("\tPLC_TaskExecutor_execOneScanTime Error!\n");
			return ;
		}
	}


}
void setTestMode(){
	timeCount=4;
	controlCount=4;

	uint8 inPosition[] = {OPERAND_ML_CODE_X, address_test, 0};
	uint32 inValue = 1;
	if(!PLC_DEVICE_setDeviceValue(inPosition, inValue, 0))
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);

}
void addOperator(uint8 dst[], uint16 operator_ml)
{
	memcpy(&dst[instPoint], &operator_ml, sizeof(uint16));
	instPoint+=2;
	//dst[instPoint++] = (operator_ml/256)&0x0FF;
	//dst[instPoint++] = (operator_ml%256)&0x0FF;
}
void addOperand(uint8 dst[], uint8 type, uint16 value){
	dst[instPoint++] = type;
	memcpy(&dst[instPoint], &value, sizeof(uint16));
	instPoint+=2;
}

uint8 loadInput(char* controlFilePathName)
{
	FILE* file = fopen(controlFilePathName, "rb");
	int idx = 0;
	int boolRst;
	memset(inputInstructions, 0, INSTRUCTION_MEMORY_SIZE);

	if(!file)
	{
		return FALSE;
	}

	fseek (file , 0 , SEEK_END);
	idx = ftell (file);
	rewind (file);

	boolRst =(fread (inputInstructions,1,idx,file)!=idx);
	fclose(file);
	return boolRst;

}

int t_main(int argc, char* argv[]) {
	//DBG_LOGPRINT("%s\n", PLC_SIMULATOR_VERSION); /*, prints, !!!Hello, World!!!, */
	//DBG_LOGPRINT("%s\n", PLC_SIMULATOR_HISTORY); /*, prints, !!!Hello, World!!!, */
	DBG_LOGPRINT("argc = %d\n", argc);
	PLC_LOG_createDebugBuffer();
	int PLC_DEFINATION_SCANTIME_INTERVAL =100000;
#if 1
#ifdef USE_CUNIT_TEST_DEF
	//run testSuite.
	//PLC_DEVICE_readFromFileToControl();

	run_suite_EXEC_SUITE();

	PLC_LOG_Free();
	return EXIT_SUCCESS;
#endif
#else
	//run ml file.
	uint8 isLoadFromFile = FALSE;


	uint8 fileCount = 1;
	if(argc>=2)
	{
		DBG_LOGPRINT("External ML instruction setting is loading : argv[1] = %s...\n", argv[1]);
		char* tarFileNames[8];
		filePathName = argv[1];
		tarFileNames[0] = filePathName;
		if(PLC_TaskExecutor_readFromFilesToBuffer(tarFileNames, fileCount, (char*)inputInstructions))
		{
			isLoadFromFile = TRUE;
			DBG_LOGPRINT(" Succeed! \n");
		}
		else{
			DBG_LOGPRINT(" Failed!\n");
		}
	}
	if(argc>=3)
	{
		DBG_LOGPRINT("External ML instruction test is setting : argv[2] = %s\n", argv[2]);
		char* str = argv[2];

		if(strcmp(str, "-test")==0)
			setTestMode();//set limited scan-time environment.
		else if(strcmp(str, "-ms")==0)
			PLC_DEFINATION_SCANTIME_INTERVAL = 1000;
		else if(strcmp(str, "-us")==0)
			PLC_DEFINATION_SCANTIME_INTERVAL = 1;
		else if(strcmp(str, "-s")==0)
			PLC_DEFINATION_SCANTIME_INTERVAL = 1000000;
		else if(strcmp(str, "-ds")==0)
			PLC_DEFINATION_SCANTIME_INTERVAL = 100000;
		else if (strcmp(str, "-zdly")==0)
			PLC_DEFINATION_SCANTIME_INTERVAL = 0;
	}
	if(argc>=4)
	{
		DBG_LOGPRINT("External control input is loading : argv[3] = %s\n", argv[3]);
		if(!loadInput(argv[3]))
		{
			DBG_LOGPRINT("Control file is Invalid! :: %s\n", argv[3]);
			//return FALSE;
		}
	}

	if(!isLoadFromFile){
		//when ml loading is failed, load dummy ml commands.
		uint16 instructionSize = 256;
		uint8 inputInstruction_[instructionSize];
		DBG_LOGPRINT("Internal ML instruction setting is loading.\n");
		addOperator(inputInstruction_,ML_CODE_LD);addOperand(inputInstruction_,OPERAND_ML_CODE_X, 0);
		addOperator(inputInstruction_,ML_CODE_MPS);
		addOperator(inputInstruction_,ML_CODE_OUT);addOperand(inputInstruction_,OPERAND_ML_CODE_Y, 0);
		addOperator(inputInstruction_,ML_CODE_MRD);
		addOperator(inputInstruction_,ML_CODE_OUT);addOperand(inputInstruction_,OPERAND_ML_CODE_Y, 1);
		addOperator(inputInstruction_,ML_CODE_MPP);
		addOperator(inputInstruction_,ML_CODE_OUT);addOperand(inputInstruction_,OPERAND_ML_CODE_Y, 2);
		addOperator(inputInstruction_,ML_CODE_END);

		addOperator(inputInstruction_,ML_CODE_LD);addOperand(inputInstruction_,OPERAND_ML_CODE_X, 0);
		addOperator(inputInstruction_,ML_CODE_OUT);addOperand(inputInstruction_,OPERAND_ML_CODE_Y, 2);
		addOperator(inputInstruction_,ML_CODE_END);
		memcpy(inputInstructions, inputInstruction_, instructionSize);
		setTestMode();//set limited scan-time environment.
	}

	init_suite_exec_duration();
	DBG_LOGPRINT("INIT END.\n");
	test_suite_exec_duration();
	DBG_LOGPRINT("RUN END.\n");
	clean_suite_exec_duration();
	PLC_LOG_Free();
	DBG_LOGPRINT("SAFELY END SIM...\n");
	return EXIT_SUCCESS;

#endif


//	TEST_PLC_Register();
}
