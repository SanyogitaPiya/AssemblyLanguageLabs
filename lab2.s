.global add32
.global sub64
.global minU16
.global minS32
.global isLessThanU16
.global isLessThanS16
.global shiftLeftU16
.global shiftU32
.global shiftS8
.global isEqualU32
.global isEqualS8

.text

add32:
      @uint64_t add32(uint32_t x, uint32_t y); // returns x + y
	  @   R1:R0           R0         R1
	  ADDS R0, R0, R1
	  MOV R1, #0
	  ADC R1, R1, #0
	  BX LR
	  
sub64:
      @uint64_t sub64(uint64_t x, uint64_t y); // returns x - y
      @ R1:R0            R1:R0      R3:R2
      SUBS R0, R0, R2
      SBC R1, R1, R3
      BX LR

minU16:
       @uint16_t minU16(uint16_t x, uint16_t y); // returns the minimum of x, y
       @  R0                R0         R1 
       CMP R0, R1
	   BMI END
	   MOV R0, R1
	   
END:
	   BX LR
		 
minS32:
       CMP R0, R1
	   BMI END2
	   MOV R0, R1
	   
END2:
	   BX LR
		   
isLessThanU16:
              @ bool isLessThanU16(uint16_t x, uint16_t y); // returns 1 if x < y, 0 else
              @ R0                     R0          R1
              CMP R0, R1 
              BMI END3
			  MOV R0, #0
              BX LR 			  
END3:
              MOV R0, #1
              BX LR

isLessThanS16:
              @ bool isLessThanS16(int16_t x, int16_t y); // returns 1 if x < y, 0 else
              @  R0                    R0        R1 
			  CMP R0, R1 
              BMI END4
			  MOV R0, #0
              BX LR 			  
END4:
              MOV R0, #1
              BX LR
	
shiftLeftU16:
             @ uint16_t shiftLeftU16 (uint16_t x, uint16_t p); // returns x << p = x * 2p for p = 0 .. 31
             @   R0                       R0        R1 
             MOV R0, R0, LSL R1
             BX LR

shiftU32:
         @ uint32_t shiftU32(uint32_t x, int32_t p); // return x * 2p for p = -31 .. 31
         @   R0                R0           R1 
		 CMP R1, #0
         BMI RIGHT
		 MOV R0, R0, LSL R1
		 BX LR
		 
RIGHT:
		 MOV R2, #0
		 SUB R1, R2, R1 
         MOV R0, R0, LSR R1
         BX LR

shiftS8:
        @ int8_t shiftS8(int8_t x, int8_t p); // return x * 2p for p = -31 .. 31
		@   R0             R0         R1
		CMP R1, #0
        BMI RIGHT2
	    MOV R0, R0, LSL R1
	    BX LR
		
RIGHT2:
		SUB R1, #0, R1 
        MOV R0, R0, ASR R1
        BX LR
			   
isEqualU32:
           @bool isEqualU32(uint32_t x, uint32_t y); // returns 1 if x = y, 0 if x != y
		   @ R0               R0          R1 
		   CMP R0, R1
		   MOV R0, #1
		   BEQ EQUAL
		   MOV R0, #0
EQUAL:
           BX LR
		   
isEqualS8:
          @ bool isEqualS8(int8_t x, int8_t y); // returns 1 if x = y, 0 if x != y
          @	R0               R0        R1 
          CMP R0, R1
          MOV R0, #1
		  BEQ EQUAL2
		  MOV R0, #0
EQUAL2:
          BX LR		  
		   
		   