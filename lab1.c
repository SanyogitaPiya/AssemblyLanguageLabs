#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>

extern uint64_t add32(uint32_t x, uint32_t y); // returns x + y
extern uint64_t sub64(uint64_t x, uint64_t y); // returns x - y
extern uint16_t minU16(uint16_t x, uint16_t y); // returns the minimum of x, y
extern int32_t minS32(int32_t x, int32_t y); // returns the minimum of x, y
extern bool isLessThanU16(uint16_t x, uint16_t y); // returns 1 if x < y, 0 else
extern bool isLessThanS16(int16_t x, int16_t y); // returns 1 if x < y, 0 else
extern uint16_t shiftLeftU16 (uint16_t x, uint16_t p); // returns x << p = x * 2p for p = 0 .. 31
extern uint32_t shiftU32(uint32_t x, int32_t p); // return x * 2p for p = -31 .. 31
extern int8_t shiftS8(int8_t x, int8_t p); // return x * 2p for p = -31 .. 31
extern bool isEqualU32(uint32_t x, uint32_t y); // returns 1 if x = y, 0 if x != y
extern bool isEqualS8(int8_t x, int8_t y); // returns 1 if x = y, 0 if x != y

int main(void) {
	
	uint32_t a = 4000000000;
	uint32_t b = 3000000000;
	
	printf("Question 1, add32: Correct answer = %lld\n", 7000000000);
	printf("Question 1, add32: Student answer = %lld\n\n", add32(a, b));
	
	uint64_t c = 9000000000;
	uint64_t d = 8000000000;
	
	printf("Question 2, sub64: Correct answer = %lld\n", c - d);
	printf("Question 2, sub64: Student answer = %lld\n\n", sub64(c, d));
	
	uint8_t e = 254;
	uint8_t f = 4;
	
	printf("Question 3, minU16, test 1: Correct answer = %hhu\n", f);
	printf("Question 3, minU16, test 1: Student answer = %hu\n\n", minU16(e, f));
	
	printf("Question 3, minU16, test 2: Correct answer = %hhu\n", f);
	printf("Question 3, minU16, test 2: Student answer = %hu\n\n", minU16(f, e));
	
	int32_t g = -8;
	int32_t h = 8;
	
	printf("Question 4, minS32, test 1: Correct answer = %d\n", g);
	printf("Question 4, minS32, test 1: Student answer = %d\n\n", minS32(g, h));
	
	printf("Question 4, minS32, test 2: Correct answer = %d\n", g);
	printf("Question 4, minS32, test 2: Student answer = %d\n\n", minS32(g, h));
	
	uint16_t i = 32;
	uint16_t j = 16;
	
	printf("Question 5, isLessThanU16, test 1: Correct answer = %d\n", 0);
	printf("Question 5, isLessThanU16, test 1: Student answer = %d\n\n", isLessThanU16(i, j));
	
	printf("Question 5, isLessThanU16, test 2: Correct answer = %d\n", 1);
	printf("Question 5, isLessThanU16, test 2: Student answer = %d\n\n", isLessThanU16(j, i));
	
	int16_t k = -3;
	int16_t l = 2;
	
	printf("Question 6, isLessThanS16, test 1: Correct answer = %d\n", 1);
	printf("Question 6, isLessThanS16, test 1: Student answer = %d\n\n", isLessThanS16(k, l));
	
	printf("Question 6, isLessThanS16, test 2: Correct answer = %d\n", 0);
	printf("Question 6, isLessThanS16, test 2: Student answer = %d\n\n", isLessThanS16(l, k));
	
	uint16_t m = 3;
	uint16_t n = 4;
	
	printf("Question 7, shiftLeftU16: Correct answer = %hu\n", 48);
	printf("Question 7, shiftLeftU16: Student answer = %hu\n\n", shiftLeftU16(m, n));

	uint32_t m_a = 8;
	uint32_t n_a = 12;
	
	printf("Question 8, shiftU32, test 1: Correct answer = %u\n", 32768);
	printf("Question 8, shiftU32, test 1: Student answer = %u\n\n", shiftU32(m_a, n_a));
	
	printf("Question 8, shiftU32, test 2: Correct answer = %u\n", 2);
	printf("Question 8, shiftU32, test 2: Student answer = %u\n\n", shiftU32(m_a, -2));
	
	int8_t o = -4;
	int8_t p = 4;
	
	printf("Question 9, shiftS8, test 1: Correct answer = %hhd\n", -64);
	printf("Question 9, shiftS8, test 1: Student answer = %hhd\n\n", shiftS8(o, p));
	
	printf("Question 9, shiftS8, test 2: Correct answer = %hhd\n", -2);
	printf("Question 9, shiftS8, test 2: Student answer = %hhd\n\n", shiftS8(o, -1));
	
	uint32_t q = 32;
	uint32_t r = 16;
	
	printf("Question 10, isEqualU32, test 1: Correct answer = %d\n", 0);
	printf("Question 10, isEqualU32, test 1: Student answer = %d\n\n", isEqualU32(q, r));
	
	printf("Question 10, isEqualU32, test 2: Correct answer = %d\n", 1);
	printf("Question 10, isEqualU32, test 2: Student answer = %d\n\n", isEqualU32(q, q));
	
	int8_t s = 32;
	int8_t t = 16;
	
	printf("Question 11, isEqualS8, test 1: Correct answer = %d\n", 0);
	printf("Question 11, isEqualS8, test 1: Student answer = %d\n\n", isEqualS8(s, t));
	
	printf("Question 11, isEqualS8, test 2: Correct answer = %d\n", 1);
	printf("Question 11, isEqualS8, test 2: Student answer = %d\n\n", isEqualS8(s, s));
	
	return EXIT_SUCCESS;
}
