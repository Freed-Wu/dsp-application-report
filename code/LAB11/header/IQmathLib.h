//###########################################################################
//
// FILE:	IQmathLib.h
//
// TITLE:	IQ Math library functions definitions.
//
//###########################################################################
//
// Ver  | dd-mmm-yyyy |  Who  | Description of changes
// =====|=============|=======|==============================================
//  1.3 | 19 Nov 2001 | A. T. | Original Release.
// -----|-------------|-------|----------------------------------------------
//  1.4 | 17 May 2002 | A. T. | Added new functions and support for
//      |             |       | intrinsics IQmpy, IQxmpy, IQsat.
// -----|-------------|-------|----------------------------------------------
//  1.4a| 12 Jun 2002 | A. T. | Fixed problem with _IQ() operation on
//      |             |       | variables.
// -----|-------------|-------|----------------------------------------------
//  1.4b| 18 Jun 2002 | A. T. | Fixed bug with _IQtoIQN() and _IQNtoIQ()
//      |             |       | operations.
// -----|-------------|-------|----------------------------------------------
//  1.4d| 30 Mar 2003 | DA/SD | 1. Added macro parameters in parentheses
//      |             |       |    in number of places where it matters
//      |             |       | 2. Added macro definition to include header
//      |             |       |    file multiple times in the program.
// -----|-------------|-------|----------------------------------------------
//
//###########################################################################
//
// User needs to configure "MATH_TYPE" and "GLOBAL_Q" values:
//
//---------------------------------------------------------------------------
// Select math type, IQ_MATH or FLOAT_MATH:
//

#ifndef __IQMATHLIB_H_INCLUDED__
#define __IQMATHLIB_H_INCLUDED__


#define   FLOAT_MATH     1
#define   IQ_MATH        0

#ifndef   MATH_TYPE
	#define   MATH_TYPE      IQ_MATH
#endif

//---------------------------------------------------------------------------
// Select global Q value and scaling. The Q value is limited to the
// following range for all functions:
//
//        30 <= GLOBAL_Q <=  1
//
#ifndef   GLOBAL_Q
	#define   GLOBAL_Q       24
#endif

//---------------------------------------------------------------------------
// Various Usefull Constant Definitions:
//
#define   QG          GLOBAL_Q
#define   Q30         30
#define   Q29         29
#define   Q28         28
#define   Q27         27
#define   Q26         26
#define   Q25         25
#define   Q24         24
#define   Q23         23
#define   Q22         22
#define   Q21         21
#define   Q20         20
#define   Q19         19
#define   Q18         18
#define   Q17         17
#define   Q16         16
#define   Q15         15
#define   Q14         14
#define   Q13         13
#define   Q12         12
#define   Q11         11
#define   Q10         10
#define   Q9          9
#define   Q8          8
#define   Q7          7
#define   Q6          6
#define   Q5          5
#define   Q4          4
#define   Q3          3
#define   Q2          2
#define   Q1          1

#define   MAX_IQ_POS  2147483647
#define   MAX_IQ_NEG  -2147483648
#define   MIN_IQ_POS  1
#define   MIN_IQ_NEG  -1

//###########################################################################
#if MATH_TYPE == IQ_MATH
//###########################################################################
// If IQ_MATH is used, the following IQmath library function definitions
// are used:
//===========================================================================
typedef   long    _iq;
typedef   long    _iq30;
typedef   long    _iq29;
typedef   long    _iq28;
typedef   long    _iq27;
typedef   long    _iq26;
typedef   long    _iq25;
typedef   long    _iq24;
typedef   long    _iq23;
typedef   long    _iq22;
typedef   long    _iq21;
typedef   long    _iq20;
typedef   long    _iq19;
typedef   long    _iq18;
typedef   long    _iq17;
typedef   long    _iq16;
typedef   long    _iq15;
typedef   long    _iq14;
typedef   long    _iq13;
typedef   long    _iq12;
typedef   long    _iq11;
typedef   long    _iq10;
typedef   long    _iq9;
typedef   long    _iq8;
typedef   long    _iq7;
typedef   long    _iq6;
typedef   long    _iq5;
typedef   long    _iq4;
typedef   long    _iq3;
typedef   long    _iq2;
typedef   long    _iq1;
//---------------------------------------------------------------------------
#define   _IQ30(A)      (long) ((A) * 1073741824.0L)
#define   _IQ29(A)      (long) ((A) * 536870912.0L)
#define   _IQ28(A)      (long) ((A) * 268435456.0L)
#define   _IQ27(A)      (long) ((A) * 134217728.0L)
#define   _IQ26(A)      (long) ((A) * 67108864.0L)
#define   _IQ25(A)      (long) ((A) * 33554432.0L)
#define   _IQ24(A)      (long) ((A) * 16777216.0L)
#define   _IQ23(A)      (long) ((A) * 8388608.0L)
#define   _IQ22(A)      (long) ((A) * 4194304.0L)
#define   _IQ21(A)      (long) ((A) * 2097152.0L)
#define   _IQ20(A)      (long) ((A) * 1048576.0L)
#define   _IQ19(A)      (long) ((A) * 524288.0L)
#define   _IQ18(A)      (long) ((A) * 262144.0L)
#define   _IQ17(A)      (long) ((A) * 131072.0L)
#define   _IQ16(A)      (long) ((A) * 65536.0L)
#define   _IQ15(A)      (long) ((A) * 32768.0L)
#define   _IQ14(A)      (long) ((A) * 16384.0L)
#define   _IQ13(A)      (long) ((A) * 8192.0L)
#define   _IQ12(A)      (long) ((A) * 4096.0L)
#define   _IQ11(A)      (long) ((A) * 2048.0L)
#define   _IQ10(A)      (long) ((A) * 1024.0L)
#define   _IQ9(A)       (long) ((A) * 512.0L)
#define   _IQ8(A)       (long) ((A) * 256.0L)
#define   _IQ7(A)       (long) ((A) * 128.0L)
#define   _IQ6(A)       (long) ((A) * 64.0L)
#define   _IQ5(A)       (long) ((A) * 32.0L)
#define   _IQ4(A)       (long) ((A) * 16.0L)
#define   _IQ3(A)       (long) ((A) * 8.0L)
#define   _IQ2(A)       (long) ((A) * 4.0L)
#define   _IQ1(A)       (long) ((A) * 2.0L)

#if GLOBAL_Q == 30
	#define   _IQ(A)  _IQ30(A)
#endif
#if GLOBAL_Q == 29
	#define   _IQ(A)  _IQ29(A)
#endif
#if GLOBAL_Q == 28
	#define   _IQ(A)  _IQ28(A)
#endif
#if GLOBAL_Q == 27
	#define   _IQ(A)  _IQ27(A)
#endif
#if GLOBAL_Q == 26
	#define   _IQ(A)  _IQ26(A)
#endif
#if GLOBAL_Q == 25
	#define   _IQ(A)  _IQ25(A)
#endif
#if GLOBAL_Q == 24
	#define   _IQ(A)  _IQ24(A)
#endif
#if GLOBAL_Q == 23
	#define   _IQ(A)  _IQ23(A)
#endif
#if GLOBAL_Q == 22
	#define   _IQ(A)  _IQ22(A)
#endif
#if GLOBAL_Q == 21
	#define   _IQ(A)  _IQ21(A)
#endif
#if GLOBAL_Q == 20
	#define   _IQ(A)  _IQ20(A)
#endif
#if GLOBAL_Q == 19
	#define   _IQ(A)  _IQ19(A)
#endif
#if GLOBAL_Q == 18
	#define   _IQ(A)  _IQ18(A)
#endif
#if GLOBAL_Q == 17
	#define   _IQ(A)  _IQ17(A)
#endif
#if GLOBAL_Q == 16
	#define   _IQ(A)  _IQ16(A)
#endif
#if GLOBAL_Q == 15
	#define   _IQ(A)  _IQ15(A)
#endif
#if GLOBAL_Q == 14
	#define   _IQ(A)  _IQ14(A)
#endif
#if GLOBAL_Q == 13
	#define   _IQ(A)  _IQ13(A)
#endif
#if GLOBAL_Q == 12
	#define   _IQ(A)  _IQ12(A)
#endif
#if GLOBAL_Q == 11
	#define   _IQ(A)  _IQ11(A)
#endif
#if GLOBAL_Q == 10
	#define   _IQ(A)  _IQ10(A)
#endif
#if GLOBAL_Q == 9
	#define   _IQ(A)  _IQ9(A)
#endif
#if GLOBAL_Q == 8
	#define   _IQ(A)  _IQ8(A)
#endif
#if GLOBAL_Q == 7
	#define   _IQ(A)  _IQ7(A)
#endif
#if GLOBAL_Q == 6
	#define   _IQ(A)  _IQ6(A)
#endif
#if GLOBAL_Q == 5
	#define   _IQ(A)  _IQ5(A)
#endif
#if GLOBAL_Q == 4
	#define   _IQ(A)  _IQ4(A)
#endif
#if GLOBAL_Q == 3
	#define   _IQ(A)  _IQ3(A)
#endif
#if GLOBAL_Q == 2
	#define   _IQ(A)  _IQ2(A)
#endif
#if GLOBAL_Q == 1
	#define   _IQ(A)  _IQ1(A)
#endif
//---------------------------------------------------------------------------
extern    float _IQ30toF( long A );
extern    float _IQ29toF( long A );
extern    float _IQ28toF( long A );
extern    float _IQ27toF( long A );
extern    float _IQ26toF( long A );
extern    float _IQ25toF( long A );
extern    float _IQ24toF( long A );
extern    float _IQ23toF( long A );
extern    float _IQ22toF( long A );
extern    float _IQ21toF( long A );
extern    float _IQ20toF( long A );
extern    float _IQ19toF( long A );
extern    float _IQ18toF( long A );
extern    float _IQ17toF( long A );
extern    float _IQ16toF( long A );
extern    float _IQ15toF( long A );
extern    float _IQ14toF( long A );
extern    float _IQ13toF( long A );
extern    float _IQ12toF( long A );
extern    float _IQ11toF( long A );
extern    float _IQ10toF( long A );
extern    float _IQ9toF( long A );
extern    float _IQ8toF( long A );
extern    float _IQ7toF( long A );
extern    float _IQ6toF( long A );
extern    float _IQ5toF( long A );
extern    float _IQ4toF( long A );
extern    float _IQ3toF( long A );
extern    float _IQ2toF( long A );
extern    float _IQ1toF( long A );

#if GLOBAL_Q == 30
	#define   _IQtoF(A)  _IQ30toF(A)
#endif
#if GLOBAL_Q == 29
	#define   _IQtoF(A)  _IQ29toF(A)
#endif
#if GLOBAL_Q == 28
	#define   _IQtoF(A)  _IQ28toF(A)
#endif
#if GLOBAL_Q == 27
	#define   _IQtoF(A)  _IQ27toF(A)
#endif
#if GLOBAL_Q == 26
	#define   _IQtoF(A)  _IQ26toF(A)
#endif
#if GLOBAL_Q == 25
	#define   _IQtoF(A)  _IQ25toF(A)
#endif
#if GLOBAL_Q == 24
	#define   _IQtoF(A)  _IQ24toF(A)
#endif
#if GLOBAL_Q == 23
	#define   _IQtoF(A)  _IQ23toF(A)
#endif
#if GLOBAL_Q == 22
	#define   _IQtoF(A)  _IQ22toF(A)
#endif
#if GLOBAL_Q == 21
	#define   _IQtoF(A)  _IQ21toF(A)
#endif
#if GLOBAL_Q == 20
	#define   _IQtoF(A)  _IQ20toF(A)
#endif
#if GLOBAL_Q == 19
	#define   _IQtoF(A)  _IQ19toF(A)
#endif
#if GLOBAL_Q == 18
	#define   _IQtoF(A)  _IQ18toF(A)
#endif
#if GLOBAL_Q == 17
	#define   _IQtoF(A)  _IQ17toF(A)
#endif
#if GLOBAL_Q == 16
	#define   _IQtoF(A)  _IQ16toF(A)
#endif
#if GLOBAL_Q == 15
	#define   _IQtoF(A)  _IQ15toF(A)
#endif
#if GLOBAL_Q == 14
	#define   _IQtoF(A)  _IQ14toF(A)
#endif
#if GLOBAL_Q == 13
	#define   _IQtoF(A)  _IQ13toF(A)
#endif
#if GLOBAL_Q == 12
	#define   _IQtoF(A)  _IQ12toF(A)
#endif
#if GLOBAL_Q == 11
	#define   _IQtoF(A)  _IQ11toF(A)
#endif
#if GLOBAL_Q == 10
	#define   _IQtoF(A)  _IQ10toF(A)
#endif
#if GLOBAL_Q == 9
	#define   _IQtoF(A)  _IQ9toF(A)
#endif
#if GLOBAL_Q == 8
	#define   _IQtoF(A)  _IQ8toF(A)
#endif
#if GLOBAL_Q == 7
	#define   _IQtoF(A)  _IQ7toF(A)
#endif
#if GLOBAL_Q == 6
	#define   _IQtoF(A)  _IQ6toF(A)
#endif
#if GLOBAL_Q == 5
	#define   _IQtoF(A)  _IQ5toF(A)
#endif
#if GLOBAL_Q == 4
	#define   _IQtoF(A)  _IQ4toF(A)
#endif
#if GLOBAL_Q == 3
	#define   _IQtoF(A)  _IQ3toF(A)
#endif
#if GLOBAL_Q == 2
	#define   _IQtoF(A)  _IQ2toF(A)
#endif
#if GLOBAL_Q == 1
	#define   _IQtoF(A)  _IQ1toF(A)
#endif
//---------------------------------------------------------------------------
#define   _IQsat(A, Pos, Neg)  __IQsat(A, Pos, Neg)
//---------------------------------------------------------------------------
#define   _IQtoIQ30(A)  ((long) (A) << (30 - GLOBAL_Q))
#define   _IQ30toIQ(A)  ((long) (A) >> (30 - GLOBAL_Q))

#define   _IQtoIQ29(A)  ((GLOBAL_Q >= 29) ? ((long) (A) >> (GLOBAL_Q - 29)):((long) (A) << (29 - GLOBAL_Q)))
#define   _IQ29toIQ(A)  ((GLOBAL_Q >= 29) ? ((long) (A) << (GLOBAL_Q - 29)):((long) (A) >> (29 - GLOBAL_Q)))

#define   _IQtoIQ28(A)  ((GLOBAL_Q >= 28) ? ((long) (A) >> (GLOBAL_Q - 28)):((long) (A) << (28 - GLOBAL_Q)))
#define   _IQ28toIQ(A)  ((GLOBAL_Q >= 28) ? ((long) (A) << (GLOBAL_Q - 28)):((long) (A) >> (28 - GLOBAL_Q)))

#define   _IQtoIQ27(A)  ((GLOBAL_Q >= 27) ? ((long) (A) >> (GLOBAL_Q - 27)):((long) (A) << (27 - GLOBAL_Q)))
#define   _IQ27toIQ(A)  ((GLOBAL_Q >= 27) ? ((long) (A) << (GLOBAL_Q - 27)):((long) (A) >> (27 - GLOBAL_Q)))

#define   _IQtoIQ26(A)  ((GLOBAL_Q >= 26) ? ((long) (A) >> (GLOBAL_Q - 26)):((long) (A) << (26 - GLOBAL_Q)))
#define   _IQ26toIQ(A)  ((GLOBAL_Q >= 26) ? ((long) (A) << (GLOBAL_Q - 26)):((long) (A) >> (26 - GLOBAL_Q)))

#define   _IQtoIQ25(A)  ((GLOBAL_Q >= 25) ? ((long) (A) >> (GLOBAL_Q - 25)):((long) (A) << (25 - GLOBAL_Q)))
#define   _IQ25toIQ(A)  ((GLOBAL_Q >= 25) ? ((long) (A) << (GLOBAL_Q - 25)):((long) (A) >> (25 - GLOBAL_Q)))

#define   _IQtoIQ24(A)  ((GLOBAL_Q >= 24) ? ((long) (A) >> (GLOBAL_Q - 24)):((long) (A) << (24 - GLOBAL_Q)))
#define   _IQ24toIQ(A)  ((GLOBAL_Q >= 24) ? ((long) (A) << (GLOBAL_Q - 24)):((long) (A) >> (24 - GLOBAL_Q)))

#define   _IQtoIQ23(A)  ((GLOBAL_Q >= 23) ? ((long) (A) >> (GLOBAL_Q - 23)):((long) (A) << (23 - GLOBAL_Q)))
#define   _IQ23toIQ(A)  ((GLOBAL_Q >= 23) ? ((long) (A) << (GLOBAL_Q - 23)):((long) (A) >> (23 - GLOBAL_Q)))

#define   _IQtoIQ22(A)  ((GLOBAL_Q >= 22) ? ((long) (A) >> (GLOBAL_Q - 22)):((long) (A) << (22 - GLOBAL_Q)))
#define   _IQ22toIQ(A)  ((GLOBAL_Q >= 22) ? ((long) (A) << (GLOBAL_Q - 22)):((long) (A) >> (22 - GLOBAL_Q)))

#define   _IQtoIQ21(A)  ((GLOBAL_Q >= 21) ? ((long) (A) >> (GLOBAL_Q - 21)):((long) (A) << (21 - GLOBAL_Q)))
#define   _IQ21toIQ(A)  ((GLOBAL_Q >= 21) ? ((long) (A) << (GLOBAL_Q - 21)):((long) (A) >> (21 - GLOBAL_Q)))

#define   _IQtoIQ20(A)  ((GLOBAL_Q >= 20) ? ((long) (A) >> (GLOBAL_Q - 20)):((long) (A) << (20 - GLOBAL_Q)))
#define   _IQ20toIQ(A)  ((GLOBAL_Q >= 20) ? ((long) (A) << (GLOBAL_Q - 20)):((long) (A) >> (20 - GLOBAL_Q)))

#define   _IQtoIQ19(A)  ((GLOBAL_Q >= 19) ? ((long) (A) >> (GLOBAL_Q - 19)):((long) (A) << (19 - GLOBAL_Q)))
#define   _IQ19toIQ(A)  ((GLOBAL_Q >= 19) ? ((long) (A) << (GLOBAL_Q - 19)):((long) (A) >> (19 - GLOBAL_Q)))

#define   _IQtoIQ18(A)  ((GLOBAL_Q >= 18) ? ((long) (A) >> (GLOBAL_Q - 18)):((long) (A) << (18 - GLOBAL_Q)))
#define   _IQ18toIQ(A)  ((GLOBAL_Q >= 18) ? ((long) (A) << (GLOBAL_Q - 18)):((long) (A) >> (18 - GLOBAL_Q)))

#define   _IQtoIQ17(A)  ((GLOBAL_Q >= 17) ? ((long) (A) >> (GLOBAL_Q - 17)):((long) (A) << (17 - GLOBAL_Q)))
#define   _IQ17toIQ(A)  ((GLOBAL_Q >= 17) ? ((long) (A) << (GLOBAL_Q - 17)):((long) (A) >> (17 - GLOBAL_Q)))

#define   _IQtoIQ16(A)  ((GLOBAL_Q >= 16) ? ((long) (A) >> (GLOBAL_Q - 16)):((long) (A) << (16 - GLOBAL_Q)))
#define   _IQ16toIQ(A)  ((GLOBAL_Q >= 16) ? ((long) (A) << (GLOBAL_Q - 16)):((long) (A) >> (16 - GLOBAL_Q)))

#define   _IQtoIQ15(A)  ((GLOBAL_Q >= 15) ? ((long) (A) >> (GLOBAL_Q - 15)):((long) (A) << (15 - GLOBAL_Q)))
#define   _IQ15toIQ(A)  ((GLOBAL_Q >= 15) ? ((long) (A) << (GLOBAL_Q - 15)):((long) (A) >> (15 - GLOBAL_Q)))

#define   _IQtoIQ14(A)  ((GLOBAL_Q >= 14) ? ((long) (A) >> (GLOBAL_Q - 14)):((long) (A) << (14 - GLOBAL_Q)))
#define   _IQ14toIQ(A)  ((GLOBAL_Q >= 14) ? ((long) (A) << (GLOBAL_Q - 14)):((long) (A) >> (14 - GLOBAL_Q)))

#define   _IQtoIQ13(A)  ((GLOBAL_Q >= 13) ? ((long) (A) >> (GLOBAL_Q - 13)):((long) (A) << (13 - GLOBAL_Q)))
#define   _IQ13toIQ(A)  ((GLOBAL_Q >= 13) ? ((long) (A) << (GLOBAL_Q - 13)):((long) (A) >> (13 - GLOBAL_Q)))

#define   _IQtoIQ12(A)  ((GLOBAL_Q >= 12) ? ((long) (A) >> (GLOBAL_Q - 12)):((long) (A) << (12 - GLOBAL_Q)))
#define   _IQ12toIQ(A)  ((GLOBAL_Q >= 12) ? ((long) (A) << (GLOBAL_Q - 12)):((long) (A) >> (12 - GLOBAL_Q)))

#define   _IQtoIQ11(A)  ((GLOBAL_Q >= 11) ? ((long) (A) >> (GLOBAL_Q - 11)):((long) (A) << (11 - GLOBAL_Q)))
#define   _IQ11toIQ(A)  ((GLOBAL_Q >= 11) ? ((long) (A) << (GLOBAL_Q - 11)):((long) (A) >> (11 - GLOBAL_Q)))

#define   _IQtoIQ10(A)  ((GLOBAL_Q >= 10) ? ((long) (A) >> (GLOBAL_Q - 10)):((long) (A) << (10 - GLOBAL_Q)))
#define   _IQ10toIQ(A)  ((GLOBAL_Q >= 10) ? ((long) (A) << (GLOBAL_Q - 10)):((long) (A) >> (10 - GLOBAL_Q)))

#define   _IQtoIQ9(A)   ((GLOBAL_Q >= 9) ? ((long) (A) >> (GLOBAL_Q - 9)):((long) (A) << (9 - GLOBAL_Q)))
#define   _IQ9toIQ(A)   ((GLOBAL_Q >= 9) ? ((long) (A) << (GLOBAL_Q - 9)):((long) (A) >> (9 - GLOBAL_Q)))

#define   _IQtoIQ8(A)   ((GLOBAL_Q >= 8) ? ((long) (A) >> (GLOBAL_Q - 8)):((long) (A) << (8 - GLOBAL_Q)))
#define   _IQ8toIQ(A)   ((GLOBAL_Q >= 8) ? ((long) (A) << (GLOBAL_Q - 8)):((long) (A) >> (8 - GLOBAL_Q)))

#define   _IQtoIQ7(A)   ((GLOBAL_Q >= 7) ? ((long) (A) >> (GLOBAL_Q - 7)):((long) (A) << (7 - GLOBAL_Q)))
#define   _IQ7toIQ(A)   ((GLOBAL_Q >= 7) ? ((long) (A) << (GLOBAL_Q - 7)):((long) (A) >> (7 - GLOBAL_Q)))

#define   _IQtoIQ6(A)   ((GLOBAL_Q >= 6) ? ((long) (A) >> (GLOBAL_Q - 6)):((long) (A) << (6 - GLOBAL_Q)))
#define   _IQ6toIQ(A)   ((GLOBAL_Q >= 6) ? ((long) (A) << (GLOBAL_Q - 6)):((long) (A) >> (6 - GLOBAL_Q)))

#define   _IQtoIQ5(A)   ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _IQ5toIQ(A)   ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoIQ4(A)   ((GLOBAL_Q >= 4) ? ((long) (A) >> (GLOBAL_Q - 4)):((long) (A) << (4 - GLOBAL_Q)))
#define   _IQ4toIQ(A)   ((GLOBAL_Q >= 4) ? ((long) (A) << (GLOBAL_Q - 4)):((long) (A) >> (4 - GLOBAL_Q)))

#define   _IQtoIQ3(A)   ((GLOBAL_Q >= 3) ? ((long) (A) >> (GLOBAL_Q - 3)):((long) (A) << (3 - GLOBAL_Q)))
#define   _IQ3toIQ(A)   ((GLOBAL_Q >= 3) ? ((long) (A) << (GLOBAL_Q - 3)):((long) (A) >> (3 - GLOBAL_Q)))

#define   _IQtoIQ2(A)   ((GLOBAL_Q >= 2) ? ((long) (A) >> (GLOBAL_Q - 2)):((long) (A) << (2 - GLOBAL_Q)))
#define   _IQ2toIQ(A)   ((GLOBAL_Q >= 2) ? ((long) (A) << (GLOBAL_Q - 2)):((long) (A) >> (2 - GLOBAL_Q)))

#define   _IQtoIQ1(A)   ((long) (A) >> (GLOBAL_Q - 1))
#define   _IQ1toIQ(A)   ((long) (A) << (GLOBAL_Q - 1))
//---------------------------------------------------------------------------
#define   _IQtoQ15(A)   ((GLOBAL_Q >= 15) ? ((long) (A) >> (GLOBAL_Q - 15)):((long) (A) << (15 - GLOBAL_Q)))
#define   _Q15toIQ(A)   ((GLOBAL_Q >= 15) ? ((long) (A) << (GLOBAL_Q - 15)):((long) (A) >> (15 - GLOBAL_Q)))

#define   _IQtoQ14(A)   ((GLOBAL_Q >= 14) ? ((long) (A) >> (GLOBAL_Q - 14)):((long) (A) << (14 - GLOBAL_Q)))
#define   _Q14toIQ(A)   ((GLOBAL_Q >= 14) ? ((long) (A) << (GLOBAL_Q - 14)):((long) (A) >> (14 - GLOBAL_Q)))

#define   _IQtoQ13(A)   ((GLOBAL_Q >= 13) ? ((long) (A) >> (GLOBAL_Q - 13)):((long) (A) << (13 - GLOBAL_Q)))
#define   _Q13toIQ(A)   ((GLOBAL_Q >= 13) ? ((long) (A) << (GLOBAL_Q - 13)):((long) (A) >> (13 - GLOBAL_Q)))

#define   _IQtoQ12(A)   ((GLOBAL_Q >= 12) ? ((long) (A) >> (GLOBAL_Q - 12)):((long) (A) << (12 - GLOBAL_Q)))
#define   _Q12toIQ(A)   ((GLOBAL_Q >= 12) ? ((long) (A) << (GLOBAL_Q - 12)):((long) (A) >> (12 - GLOBAL_Q)))

#define   _IQtoQ11(A)   ((GLOBAL_Q >= 11) ? ((long) (A) >> (GLOBAL_Q - 11)):((long) (A) << (11 - GLOBAL_Q)))
#define   _Q11toIQ(A)   ((GLOBAL_Q >= 11) ? ((long) (A) << (GLOBAL_Q - 11)):((long) (A) >> (11 - GLOBAL_Q)))

#define   _IQtoQ10(A)   ((GLOBAL_Q >= 10) ? ((long) (A) >> (GLOBAL_Q - 10)):((long) (A) << (10 - GLOBAL_Q)))
#define   _Q10toIQ(A)   ((GLOBAL_Q >= 10) ? ((long) (A) << (GLOBAL_Q - 10)):((long) (A) >> (10 - GLOBAL_Q)))

#define   _IQtoQ9(A)    ((GLOBAL_Q >= 9) ? ((long) (A) >> (GLOBAL_Q - 9)):((long) (A) << (9 - GLOBAL_Q)))
#define   _Q9toIQ(A)    ((GLOBAL_Q >= 9) ? ((long) (A) << (GLOBAL_Q - 9)):((long) (A) >> (9 - GLOBAL_Q)))

#define   _IQtoQ8(A)    ((GLOBAL_Q >= 8) ? ((long) (A) >> (GLOBAL_Q - 8)):((long) (A) << (8 - GLOBAL_Q)))
#define   _Q8toIQ(A)    ((GLOBAL_Q >= 8) ? ((long) (A) << (GLOBAL_Q - 8)):((long) (A) >> (8 - GLOBAL_Q)))

#define   _IQtoQ7(A)    ((GLOBAL_Q >= 7) ? ((long) (A) >> (GLOBAL_Q - 7)):((long) (A) << (7 - GLOBAL_Q)))
#define   _Q7toIQ(A)    ((GLOBAL_Q >= 7) ? ((long) (A) << (GLOBAL_Q - 7)):((long) (A) >> (7 - GLOBAL_Q)))

#define   _IQtoQ6(A)    ((GLOBAL_Q >= 6) ? ((long) (A) >> (GLOBAL_Q - 6)):((long) (A) << (6 - GLOBAL_Q)))
#define   _Q6toIQ(A)    ((GLOBAL_Q >= 6) ? ((long) (A) << (GLOBAL_Q - 6)):((long) (A) >> (6 - GLOBAL_Q)))

#define   _IQtoQ5(A)    ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _Q5toIQ(A)    ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoQ5(A)    ((GLOBAL_Q >= 5) ? ((long) (A) >> (GLOBAL_Q - 5)):((long) (A) << (5 - GLOBAL_Q)))
#define   _Q5toIQ(A)    ((GLOBAL_Q >= 5) ? ((long) (A) << (GLOBAL_Q - 5)):((long) (A) >> (5 - GLOBAL_Q)))

#define   _IQtoQ4(A)    ((GLOBAL_Q >= 4) ? ((long) (A) >> (GLOBAL_Q - 4)):((long) (A) << (4 - GLOBAL_Q)))
#define   _Q4toIQ(A)    ((GLOBAL_Q >= 4) ? ((long) (A) << (GLOBAL_Q - 4)):((long) (A) >> (4 - GLOBAL_Q)))

#define   _IQtoQ3(A)    ((GLOBAL_Q >= 3) ? ((long) (A) >> (GLOBAL_Q - 3)):((long) (A) << (3 - GLOBAL_Q)))
#define   _Q3toIQ(A)    ((GLOBAL_Q >= 3) ? ((long) (A) << (GLOBAL_Q - 3)):((long) (A) >> (3 - GLOBAL_Q)))

#define   _IQtoQ2(A)    ((GLOBAL_Q >= 2) ? ((long) (A) >> (GLOBAL_Q - 2)):((long) (A) << (2 - GLOBAL_Q)))
#define   _Q2toIQ(A)    ((GLOBAL_Q >= 2) ? ((long) (A) << (GLOBAL_Q - 2)):((long) (A) >> (2 - GLOBAL_Q)))

#define   _IQtoQ1(A)    ((GLOBAL_Q >= 1) ? ((long) (A) >> (GLOBAL_Q - 1)):((long) (A) << (1 - GLOBAL_Q)))
#define   _Q1toIQ(A)    ((GLOBAL_Q >= 1) ? ((long) (A) << (GLOBAL_Q - 1)):((long) (A) >> (1 - GLOBAL_Q)))
//---------------------------------------------------------------------------
#define   _IQmpy(A,B)    __IQmpy(A,B,GLOBAL_Q)
#define   _IQ30mpy(A,B)  __IQmpy(A,B,30)
#define   _IQ29mpy(A,B)  __IQmpy(A,B,29)
#define   _IQ28mpy(A,B)  __IQmpy(A,B,28)
#define   _IQ27mpy(A,B)  __IQmpy(A,B,27)
#define   _IQ26mpy(A,B)  __IQmpy(A,B,26)
#define   _IQ25mpy(A,B)  __IQmpy(A,B,25)
#define   _IQ24mpy(A,B)  __IQmpy(A,B,24)
#define   _IQ23mpy(A,B)  __IQmpy(A,B,23)
#define   _IQ22mpy(A,B)  __IQmpy(A,B,22)
#define   _IQ21mpy(A,B)  __IQmpy(A,B,21)
#define   _IQ20mpy(A,B)  __IQmpy(A,B,20)
#define   _IQ19mpy(A,B)  __IQmpy(A,B,19)
#define   _IQ18mpy(A,B)  __IQmpy(A,B,18)
#define   _IQ17mpy(A,B)  __IQmpy(A,B,17)
#define   _IQ16mpy(A,B)  __IQmpy(A,B,16)
#define   _IQ15mpy(A,B)  __IQmpy(A,B,15)
#define   _IQ14mpy(A,B)  __IQmpy(A,B,14)
#define   _IQ13mpy(A,B)  __IQmpy(A,B,13)
#define   _IQ12mpy(A,B)  __IQmpy(A,B,12)
#define   _IQ11mpy(A,B)  __IQmpy(A,B,11)
#define   _IQ10mpy(A,B)  __IQmpy(A,B,10)
#define   _IQ9mpy(A,B)   __IQmpy(A,B,9)
#define   _IQ8mpy(A,B)   __IQmpy(A,B,8)
#define   _IQ7mpy(A,B)   __IQmpy(A,B,7)
#define   _IQ6mpy(A,B)   __IQmpy(A,B,6)
#define   _IQ5mpy(A,B)   __IQmpy(A,B,5)
#define   _IQ4mpy(A,B)   __IQmpy(A,B,4)
#define   _IQ3mpy(A,B)   __IQmpy(A,B,3)
#define   _IQ2mpy(A,B)   __IQmpy(A,B,2)
#define   _IQ1mpy(A,B)   __IQmpy(A,B,1)
//---------------------------------------------------------------------------
extern    long _IQ30rmpy( long A, long B );
extern    long _IQ29rmpy( long A, long B );
extern    long _IQ28rmpy( long A, long B );
extern    long _IQ27rmpy( long A, long B );
extern    long _IQ26rmpy( long A, long B );
extern    long _IQ25rmpy( long A, long B );
extern    long _IQ24rmpy( long A, long B );
extern    long _IQ23rmpy( long A, long B );
extern    long _IQ22rmpy( long A, long B );
extern    long _IQ21rmpy( long A, long B );
extern    long _IQ20rmpy( long A, long B );
extern    long _IQ19rmpy( long A, long B );
extern    long _IQ18rmpy( long A, long B );
extern    long _IQ17rmpy( long A, long B );
extern    long _IQ16rmpy( long A, long B );
extern    long _IQ15rmpy( long A, long B );
extern    long _IQ14rmpy( long A, long B );
extern    long _IQ13rmpy( long A, long B );
extern    long _IQ12rmpy( long A, long B );
extern    long _IQ11rmpy( long A, long B );
extern    long _IQ10rmpy( long A, long B );
extern    long _IQ9rmpy( long A, long B );
extern    long _IQ8rmpy( long A, long B );
extern    long _IQ7rmpy( long A, long B );
extern    long _IQ6rmpy( long A, long B );
extern    long _IQ5rmpy( long A, long B );
extern    long _IQ4rmpy( long A, long B );
extern    long _IQ3rmpy( long A, long B );
extern    long _IQ2rmpy( long A, long B );
extern    long _IQ1rmpy( long A, long B );

#if GLOBAL_Q == 30
	#define   _IQrmpy(A,B)  _IQ30rmpy(A,B)
#endif
#if GLOBAL_Q == 29
	#define   _IQrmpy(A,B)  _IQ29rmpy(A,B)
#endif
#if GLOBAL_Q == 28
	#define   _IQrmpy(A,B)  _IQ28rmpy(A,B)
#endif
#if GLOBAL_Q == 27
	#define   _IQrmpy(A,B)  _IQ27rmpy(A,B)
#endif
#if GLOBAL_Q == 26
	#define   _IQrmpy(A,B)  _IQ26rmpy(A,B)
#endif
#if GLOBAL_Q == 25
	#define   _IQrmpy(A,B)  _IQ25rmpy(A,B)
#endif
#if GLOBAL_Q == 24
	#define   _IQrmpy(A,B)  _IQ24rmpy(A,B)
#endif
#if GLOBAL_Q == 23
	#define   _IQrmpy(A,B)  _IQ23rmpy(A,B)
#endif
#if GLOBAL_Q == 22
	#define   _IQrmpy(A,B)  _IQ22rmpy(A,B)
#endif
#if GLOBAL_Q == 21
	#define   _IQrmpy(A,B)  _IQ21rmpy(A,B)
#endif
#if GLOBAL_Q == 20
	#define   _IQrmpy(A,B)  _IQ20rmpy(A,B)
#endif
#if GLOBAL_Q == 19
	#define   _IQrmpy(A,B)  _IQ19rmpy(A,B)
#endif
#if GLOBAL_Q == 18
	#define   _IQrmpy(A,B)  _IQ18rmpy(A,B)
#endif
#if GLOBAL_Q == 17
	#define   _IQrmpy(A,B)  _IQ17rmpy(A,B)
#endif
#if GLOBAL_Q == 16
	#define   _IQrmpy(A,B)  _IQ16rmpy(A,B)
#endif
#if GLOBAL_Q == 15
	#define   _IQrmpy(A,B)  _IQ15rmpy(A,B)
#endif
#if GLOBAL_Q == 14
	#define   _IQrmpy(A,B)  _IQ14rmpy(A,B)
#endif
#if GLOBAL_Q == 13
	#define   _IQrmpy(A,B)  _IQ13rmpy(A,B)
#endif
#if GLOBAL_Q == 12
	#define   _IQrmpy(A,B)  _IQ12rmpy(A,B)
#endif
#if GLOBAL_Q == 11
	#define   _IQrmpy(A,B)  _IQ11rmpy(A,B)
#endif
#if GLOBAL_Q == 10
	#define   _IQrmpy(A,B)  _IQ10rmpy(A,B)
#endif
#if GLOBAL_Q == 9
	#define   _IQrmpy(A,B)  _IQ9rmpy(A,B)
#endif
#if GLOBAL_Q == 8
	#define   _IQrmpy(A,B)  _IQ8rmpy(A,B)
#endif
#if GLOBAL_Q == 7
	#define   _IQrmpy(A,B)  _IQ7rmpy(A,B)
#endif
#if GLOBAL_Q == 6
	#define   _IQrmpy(A,B)  _IQ6rmpy(A,B)
#endif
#if GLOBAL_Q == 5
	#define   _IQrmpy(A,B)  _IQ5rmpy(A,B)
#endif
#if GLOBAL_Q == 4
	#define   _IQrmpy(A,B)  _IQ4rmpy(A,B)
#endif
#if GLOBAL_Q == 3
	#define   _IQrmpy(A,B)  _IQ3rmpy(A,B)
#endif
#if GLOBAL_Q == 2
	#define   _IQrmpy(A,B)  _IQ2rmpy(A,B)
#endif
#if GLOBAL_Q == 1
	#define   _IQrmpy(A,B)  _IQ1rmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30rsmpy( long A, long B );
extern    long _IQ29rsmpy( long A, long B );
extern    long _IQ28rsmpy( long A, long B );
extern    long _IQ27rsmpy( long A, long B );
extern    long _IQ26rsmpy( long A, long B );
extern    long _IQ25rsmpy( long A, long B );
extern    long _IQ24rsmpy( long A, long B );
extern    long _IQ23rsmpy( long A, long B );
extern    long _IQ22rsmpy( long A, long B );
extern    long _IQ21rsmpy( long A, long B );
extern    long _IQ20rsmpy( long A, long B );
extern    long _IQ19rsmpy( long A, long B );
extern    long _IQ18rsmpy( long A, long B );
extern    long _IQ17rsmpy( long A, long B );
extern    long _IQ16rsmpy( long A, long B );
extern    long _IQ15rsmpy( long A, long B );
extern    long _IQ14rsmpy( long A, long B );
extern    long _IQ13rsmpy( long A, long B );
extern    long _IQ12rsmpy( long A, long B );
extern    long _IQ11rsmpy( long A, long B );
extern    long _IQ10rsmpy( long A, long B );
extern    long _IQ9rsmpy( long A, long B );
extern    long _IQ8rsmpy( long A, long B );
extern    long _IQ7rsmpy( long A, long B );
extern    long _IQ6rsmpy( long A, long B );
extern    long _IQ5rsmpy( long A, long B );
extern    long _IQ4rsmpy( long A, long B );
extern    long _IQ3rsmpy( long A, long B );
extern    long _IQ2rsmpy( long A, long B );
extern    long _IQ1rsmpy( long A, long B );

#if GLOBAL_Q == 30
	#define   _IQrsmpy(A,B)  _IQ30rsmpy(A,B)
#endif
#if GLOBAL_Q == 29
	#define   _IQrsmpy(A,B)  _IQ29rsmpy(A,B)
#endif
#if GLOBAL_Q == 28
	#define   _IQrsmpy(A,B)  _IQ28rsmpy(A,B)
#endif
#if GLOBAL_Q == 27
	#define   _IQrsmpy(A,B)  _IQ27rsmpy(A,B)
#endif
#if GLOBAL_Q == 26
	#define   _IQrsmpy(A,B)  _IQ26rsmpy(A,B)
#endif
#if GLOBAL_Q == 25
	#define   _IQrsmpy(A,B)  _IQ25rsmpy(A,B)
#endif
#if GLOBAL_Q == 24
	#define   _IQrsmpy(A,B)  _IQ24rsmpy(A,B)
#endif
#if GLOBAL_Q == 23
	#define   _IQrsmpy(A,B)  _IQ23rsmpy(A,B)
#endif
#if GLOBAL_Q == 22
	#define   _IQrsmpy(A,B)  _IQ22rsmpy(A,B)
#endif
#if GLOBAL_Q == 21
	#define   _IQrsmpy(A,B)  _IQ21rsmpy(A,B)
#endif
#if GLOBAL_Q == 20
	#define   _IQrsmpy(A,B)  _IQ20rsmpy(A,B)
#endif
#if GLOBAL_Q == 19
	#define   _IQrsmpy(A,B)  _IQ19rsmpy(A,B)
#endif
#if GLOBAL_Q == 18
	#define   _IQrsmpy(A,B)  _IQ18rsmpy(A,B)
#endif
#if GLOBAL_Q == 17
	#define   _IQrsmpy(A,B)  _IQ17rsmpy(A,B)
#endif
#if GLOBAL_Q == 16
	#define   _IQrsmpy(A,B)  _IQ16rsmpy(A,B)
#endif
#if GLOBAL_Q == 15
	#define   _IQrsmpy(A,B)  _IQ15rsmpy(A,B)
#endif
#if GLOBAL_Q == 14
	#define   _IQrsmpy(A,B)  _IQ14rsmpy(A,B)
#endif
#if GLOBAL_Q == 13
	#define   _IQrsmpy(A,B)  _IQ13rsmpy(A,B)
#endif
#if GLOBAL_Q == 12
	#define   _IQrsmpy(A,B)  _IQ12rsmpy(A,B)
#endif
#if GLOBAL_Q == 11
	#define   _IQrsmpy(A,B)  _IQ11rsmpy(A,B)
#endif
#if GLOBAL_Q == 10
	#define   _IQrsmpy(A,B)  _IQ10rsmpy(A,B)
#endif
#if GLOBAL_Q == 9
	#define   _IQrsmpy(A,B)  _IQ9rsmpy(A,B)
#endif
#if GLOBAL_Q == 8
	#define   _IQrsmpy(A,B)  _IQ8rsmpy(A,B)
#endif
#if GLOBAL_Q == 7
	#define   _IQrsmpy(A,B)  _IQ7rsmpy(A,B)
#endif
#if GLOBAL_Q == 6
	#define   _IQrsmpy(A,B)  _IQ6rsmpy(A,B)
#endif
#if GLOBAL_Q == 5
	#define   _IQrsmpy(A,B)  _IQ5rsmpy(A,B)
#endif
#if GLOBAL_Q == 4
	#define   _IQrsmpy(A,B)  _IQ4rsmpy(A,B)
#endif
#if GLOBAL_Q == 3
	#define   _IQrsmpy(A,B)  _IQ3rsmpy(A,B)
#endif
#if GLOBAL_Q == 2
	#define   _IQrsmpy(A,B)  _IQ2rsmpy(A,B)
#endif
#if GLOBAL_Q == 1
	#define   _IQrsmpy(A,B)  _IQ1rsmpy(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30div( long A, long B );
extern    long _IQ29div( long A, long B );
extern    long _IQ28div( long A, long B );
extern    long _IQ27div( long A, long B );
extern    long _IQ26div( long A, long B );
extern    long _IQ25div( long A, long B );
extern    long _IQ24div( long A, long B );
extern    long _IQ23div( long A, long B );
extern    long _IQ22div( long A, long B );
extern    long _IQ21div( long A, long B );
extern    long _IQ20div( long A, long B );
extern    long _IQ19div( long A, long B );
extern    long _IQ18div( long A, long B );
extern    long _IQ17div( long A, long B );
extern    long _IQ16div( long A, long B );
extern    long _IQ15div( long A, long B );
extern    long _IQ14div( long A, long B );
extern    long _IQ13div( long A, long B );
extern    long _IQ12div( long A, long B );
extern    long _IQ11div( long A, long B );
extern    long _IQ10div( long A, long B );
extern    long _IQ9div( long A, long B );
extern    long _IQ8div( long A, long B );
extern    long _IQ7div( long A, long B );
extern    long _IQ6div( long A, long B );
extern    long _IQ5div( long A, long B );
extern    long _IQ4div( long A, long B );
extern    long _IQ3div( long A, long B );
extern    long _IQ2div( long A, long B );
extern    long _IQ1div( long A, long B );

#if GLOBAL_Q == 30
	#define   _IQdiv(A,B)  _IQ30div(A,B)
#endif
#if GLOBAL_Q == 29
	#define   _IQdiv(A,B)  _IQ29div(A,B)
#endif
#if GLOBAL_Q == 28
	#define   _IQdiv(A,B)  _IQ28div(A,B)
#endif
#if GLOBAL_Q == 27
	#define   _IQdiv(A,B)  _IQ27div(A,B)
#endif
#if GLOBAL_Q == 26
	#define   _IQdiv(A,B)  _IQ26div(A,B)
#endif
#if GLOBAL_Q == 25
	#define   _IQdiv(A,B)  _IQ25div(A,B)
#endif
#if GLOBAL_Q == 24
	#define   _IQdiv(A,B)  _IQ24div(A,B)
#endif
#if GLOBAL_Q == 23
	#define   _IQdiv(A,B)  _IQ23div(A,B)
#endif
#if GLOBAL_Q == 22
	#define   _IQdiv(A,B)  _IQ22div(A,B)
#endif
#if GLOBAL_Q == 21
	#define   _IQdiv(A,B)  _IQ21div(A,B)
#endif
#if GLOBAL_Q == 20
	#define   _IQdiv(A,B)  _IQ20div(A,B)
#endif
#if GLOBAL_Q == 19
	#define   _IQdiv(A,B)  _IQ19div(A,B)
#endif
#if GLOBAL_Q == 18
	#define   _IQdiv(A,B)  _IQ18div(A,B)
#endif
#if GLOBAL_Q == 17
	#define   _IQdiv(A,B)  _IQ17div(A,B)
#endif
#if GLOBAL_Q == 16
	#define   _IQdiv(A,B)  _IQ16div(A,B)
#endif
#if GLOBAL_Q == 15
	#define   _IQdiv(A,B)  _IQ15div(A,B)
#endif
#if GLOBAL_Q == 14
	#define   _IQdiv(A,B)  _IQ14div(A,B)
#endif
#if GLOBAL_Q == 13
	#define   _IQdiv(A,B)  _IQ13div(A,B)
#endif
#if GLOBAL_Q == 12
	#define   _IQdiv(A,B)  _IQ12div(A,B)
#endif
#if GLOBAL_Q == 11
	#define   _IQdiv(A,B)  _IQ11div(A,B)
#endif
#if GLOBAL_Q == 10
	#define   _IQdiv(A,B)  _IQ10div(A,B)
#endif
#if GLOBAL_Q == 9
	#define   _IQdiv(A,B)  _IQ9div(A,B)
#endif
#if GLOBAL_Q == 8
	#define   _IQdiv(A,B)  _IQ8div(A,B)
#endif
#if GLOBAL_Q == 7
	#define   _IQdiv(A,B)  _IQ7div(A,B)
#endif
#if GLOBAL_Q == 6
	#define   _IQdiv(A,B)  _IQ6div(A,B)
#endif
#if GLOBAL_Q == 5
	#define   _IQdiv(A,B)  _IQ5div(A,B)
#endif
#if GLOBAL_Q == 4
	#define   _IQdiv(A,B)  _IQ4div(A,B)
#endif
#if GLOBAL_Q == 3
	#define   _IQdiv(A,B)  _IQ3div(A,B)
#endif
#if GLOBAL_Q == 2
	#define   _IQdiv(A,B)  _IQ2div(A,B)
#endif
#if GLOBAL_Q == 1
	#define   _IQdiv(A,B)  _IQ1div(A,B)
#endif
//---------------------------------------------------------------------------
extern    long _IQ30sin( long A );
extern    long _IQ29sin( long A );
extern    long _IQ28sin( long A );
extern    long _IQ27sin( long A );
extern    long _IQ26sin( long A );
extern    long _IQ25sin( long A );
extern    long _IQ24sin( long A );
extern    long _IQ23sin( long A );
extern    long _IQ22sin( long A );
extern    long _IQ21sin( long A );
extern    long _IQ20sin( long A );
extern    long _IQ19sin( long A );
extern    long _IQ18sin( long A );
extern    long _IQ17sin( long A );
extern    long _IQ16sin( long A );
extern    long _IQ15sin( long A );
extern    long _IQ14sin( long A );
extern    long _IQ13sin( long A );
extern    long _IQ12sin( long A );
extern    long _IQ11sin( long A );
extern    long _IQ10sin( long A );
extern    long _IQ9sin( long A );
extern    long _IQ8sin( long A );
extern    long _IQ7sin( long A );
extern    long _IQ6sin( long A );
extern    long _IQ5sin( long A );
extern    long _IQ4sin( long A );
extern    long _IQ3sin( long A );
extern    long _IQ2sin( long A );
extern    long _IQ1sin( long A );

#if GLOBAL_Q == 30
	#define   _IQsin(A)  _IQ30sin(A)
#endif
#if GLOBAL_Q == 29
	#define   _IQsin(A)  _IQ29sin(A)
#endif
#if GLOBAL_Q == 28
	#define   _IQsin(A)  _IQ28sin(A)
#endif
#if GLOBAL_Q == 27
	#define   _IQsin(A)  _IQ27sin(A)
#endif
#if GLOBAL_Q == 26
#define   _IQs